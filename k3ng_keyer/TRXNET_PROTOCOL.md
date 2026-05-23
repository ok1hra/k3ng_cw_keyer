# TrxNet Protocol — OI3 Network

Reference document for implementing TrxNet communication on all devices in the OI3 network.
Every new device must follow the conventions in this document to guarantee interoperability.

---

## Network Requirements

- All devices must be in the **same L2 broadcast domain** (same switch/VLAN).
- Discovery uses UDP broadcast `255.255.255.255` — does not work across routers or
  between different subnets.
- Wi-Fi networks with AP isolation, guest VLANs, or mesh systems may block broadcasts —
  wired Ethernet connections (W5500/W5100) are recommended.
- All devices must use the **same UDP port: 5683** (TrxNet default CoAP port).

---

## Device Naming

The device name is the unique identifier of a device in the network. It is assembled at
runtime (after loading configuration from EEPROM/SD) and passed to `net.begin()`.

### Format

```
{TYPE}.{ID}
```

| Part | Description | Example |
|------|-------------|---------|
| `TYPE` | Device type, uppercase letters | `OI3`, `705`, `ROT`, `PA` |
| `.` | Separator (dot) | |
| `ID` | NET_ID as **2-digit lowercase hex** without prefix | `ff`, `01`, `0a` |

### Examples

| Device | NET_ID (byte) | Device name |
|--------|--------------|-------------|
| OI3 keyer (AVR) | `0xff` | `OI3.ff` |
| OI3 keyer (AVR) | `0x01` | `OI3.01` |
| IC-705 Interface (ESP32) | `0x01` | `705.01` |
| IC-705 Interface (ESP32) | `0x0a` | `705.0a` |

### Assembly in Code

```cpp
// ATMEGA / AVR — OI3 keyer
char deviceName[TRXNET_MAX_DEVICE_NAME];
snprintf(deviceName, sizeof(deviceName), "OI3.%02x", NET_ID);

// ESP32 — IC-705 Interface
char deviceName[TRXNET_MAX_DEVICE_NAME];
snprintf(deviceName, sizeof(deviceName), "705.%02x", NET_ID);
```

### Rules

- Maximum length 31 characters (TRXNET_MAX_DEVICE_NAME = 32 including null terminator).
- Two devices with the same device name are treated as identical — every device must
  have a **unique NET_ID** within its type.
- **NET_ID `0x00` is reserved as a "disabled" sentinel** — a device with NET_ID `0x00`
  does not call `net.begin()` and does not activate TrxNet communication. This value
  must not be used as a real ID on the network.
- Do not use `String` to assemble the name — use `snprintf` into `char[]`.

---

## Topic Map

### Publish — sent by OI3 keyer

These topics the OI3 keyer **sends**. Other devices may subscribe to them.

| Topic | Payload type | Delivery | Description |
|-------|-------------|---------|-------------|
| `/hz` | `uint32_t` LE | NON on change, **CON** on peer join | Current frequency in Hz from CAT/CI-V |
| `/mode` | `uint8_t` | NON on change, **CON** on peer join | Current operating mode |

On every new peer discovery the keyer sends a state snapshot (all topics above)
to the joining peer as **CON** for guaranteed delivery — so PA / antenna switch /
web UI joining mid-session do not have to wait for the operator to retune.
See [Greeting Protocol](#greeting-protocol) below.

### Subscribe — received by OI3 keyer

These topics the OI3 keyer **subscribes to**. Other devices may publish them.

| Topic | Payload type | Delivery | Description |
|-------|-------------|---------|-------------|
| `/s-hz` | `uint32_t` LE | NON | Command: set frequency |
| `/s-mode` | `uint8_t` | NON | Command: set mode |
| `/s-cw` | `char[]` max 64 B | CON | Command: key CW text; single byte `0x03` (ETX) = abort TX immediately |

---

## Payload Formats

All data is transferred as **raw bytes in native byte order (little-endian)**.
Serialisation always via `memcpy` — never via direct pointer cast.

### `uint32_t` — frequency in Hz

```cpp
// Sending
uint32_t freq = 14250000UL;
net.publish("/hz", (uint8_t*)&freq, sizeof(freq));  // 4 bytes LE

// Receiving
void onHz(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint32_t)) return;
    uint32_t freq;
    memcpy(&freq, data, sizeof(freq));
    // freq = 14250000
}
```

### `uint8_t` — mode

Mode values are **ICOM CI-V standard mode bytes**. Each device maps the CI-V byte to
its own internal representation. Using the CI-V byte eliminates conversions on the side
of devices that read/set the radio directly via CI-V (e.g. IC-705 Interface).

| Value (hex) | Mode |
|-------------|------|
| `0x00` | LSB |
| `0x01` | USB |
| `0x02` | AM |
| `0x03` | CW |
| `0x04` | RTTY / FSK |
| `0x05` | FM |
| `0x06` | WFM |
| `0x07` | CW-R (CW reverse) |
| `0x08` | RTTY-R (FSK reverse) |
| `0x17` | DV (D-STAR) |

Devices without direct CI-V access (e.g. OI3 keyer) map their internal mode to the
closest CI-V equivalent when sending, and map back when receiving.

```cpp
// Sending — CI-V byte directly (for devices with CI-V access)
uint8_t civMode = 0x03;  // CW
net.publish("/mode", &civMode, sizeof(civMode));

// Receiving — convert CI-V to device's internal representation
void onMode(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint8_t)) return;
    uint8_t civMode = data[0];
    int internalMode = civModeToInternal(civMode);  // device-specific mapping
}
```

### `char[]` — CW text

```cpp
// Sending (CON — reliable delivery)
const char* msg = "CQ CQ DE OK1HRA K";
net.publish("/s-cw", (const uint8_t*)msg, strlen(msg), TRX_CON);
// DO NOT add null terminator to len — strlen() does not include it

// Receiving — ALWAYS add null terminator manually
void onSetCw(const char* from, const uint8_t* data, size_t len) {
    char buf[65] = {};
    size_t n = (len < 64) ? len : 64;
    memcpy(buf, data, n);
    buf[n] = '\0';
    // buf contains CW text
}
```

**Maximum CW text length: 64 bytes.** Longer text will be silently truncated by TrxNet
on the sender side. The receiver gets a shorter text without an error — always check the
length.

**Abort transmission:** Send a single byte `0x03` (ASCII ETX, Ctrl+C) to immediately
clear the send buffer and stop keying. This character is not used in normal CW or RTTY
text. The k3ng keyer detects it in the serial input loop and calls `clear_send_buffer()`
before the byte reaches the CLI handler.

```cpp
// Sending abort from ESP32 (IC-705 Interface)
const uint8_t etx = 0x03;
net.publish("/s-cw", &etx, 1, TRX_CON);
```

Triggered by pressing `Esc` on the QRPLog page when no dialog is open.

---

## TrxNet Configuration

The default values in `TrxNet.h` are already tuned for ATMEGA2560 (8 KB RAM) and an
OI3 network with 3–5 peers:

| Constant | Default | Description |
|----------|---------|-------------|
| `TRXNET_MAX_PEERS` | 6 | max peers in the network |
| `TRXNET_MAX_SUBS` | 8 | max subscribe registrations |
| `TRXNET_MAX_PENDING` | 2 | outgoing CON queue (raise if the device sends CON) |
| `TRXNET_MAX_SEEN` | 16 | dedup buffer for incoming CON |

Static RAM with these values: **~920 bytes**.

No explicit `#define` overrides are needed for the OI3 keyer — the header defaults apply.
Simply include the library:

```cpp
#include <TrxNet.h>
```

For ESP32 or devices with more RAM, the defaults are sufficient or can be raised as needed.

If the device **sends CON messages** (e.g. CW text), set:
```cpp
#define TRXNET_MAX_PENDING  (TRXNET_MAX_PEERS)  // one CON publish = N slots (one per peer)
#include <TrxNet.h>
```

---

## Initialisation

`net.begin()` must be called **after** a successful network connection (Ethernet or WiFi).
If the port is configurable from EEPROM, call `net.setPort()` before `net.begin()`.

```cpp
// ATMEGA2560 + Ethernet2 (W5500)
#include <Ethernet2.h>
#include <EthernetUdp2.h>    // or EthernetUDP depending on library version
#include <TrxNet.h>

EthernetUDP trxUdp;
TrxNet      net(trxUdp);    // port 5683 (default)

uint16_t    trxPort = 5683; // can be overridden from EEPROM/settings
char        deviceName[TRXNET_MAX_DEVICE_NAME];

void setup() {
    byte mac[] = { ... };
    Ethernet.begin(mac);        // DHCP or static IP

    snprintf(deviceName, sizeof(deviceName), "OI3.%02x", NET_ID);
    net.setPort(trxPort);       // ← set port before begin() if configurable
    net.begin(deviceName);      // ← here, after Ethernet.begin()

    net.subscribe("/s-hz",   onSetHz);
    net.subscribe("/s-mode", onSetMode);
    net.subscribe("/s-cw",   onSetCw);
}
```

```cpp
// ESP32 + WiFi
#include <WiFi.h>
#include <WiFiUDP.h>
#include <TrxNet.h>

WiFiUDP trxUdp;
TrxNet  net(trxUdp);

void setup() {
    WiFi.begin(SSID, PASS);
    while (WiFi.status() != WL_CONNECTED) delay(500);

    snprintf(deviceName, sizeof(deviceName), "TRX.%02x", NET_ID);
    net.begin(deviceName);

    net.subscribe("/hz",   onHz);
    net.subscribe("/mode", onMode);
}
```

---

## Callback Pattern (ATMEGA / AVR)

On AVR, the **`String` class is strictly forbidden** in callbacks — heap fragmentation
will cause a crash after hours of operation. Use only `char[]` and `memcpy`.

Callbacks must be **short and non-blocking** — no `delay()`, no serial reads, no
long-running functions. A callback only sets a flag and stores a value; the main loop
processes it.

```cpp
// Global state for passing from callbacks to the main loop
volatile uint32_t pendingHz    = 0;
volatile uint8_t  pendingMode  = 0; // device internal mode
volatile bool     freqPending  = false;
volatile bool     modePending  = false;

char             pendingCW[65] = {};
volatile bool    cwPending     = false;

// Callbacks — store + flag only
void onSetHz(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint32_t)) return;
    memcpy((void*)&pendingHz, data, sizeof(uint32_t));
    freqPending = true;
}

void onSetMode(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint8_t)) return;
    pendingMode = (uint8_t)civModeToInternal(data[0]); // convert CI-V to internal
    modePending = true;
}

void onSetCw(const char* from, const uint8_t* data, size_t len) {
    size_t n = (len < 64) ? len : 64;
    memcpy(pendingCW, data, n);
    pendingCW[n] = '\0';
    cwPending = true;
}
```

---

## Main Loop Integration

```cpp
void loop() {
    Ethernet.maintain();    // or WiFi keepalive on ESP32
    net.loop();             // MUST be called every iteration without blocking

    // Process flags from callbacks
    if (freqPending) {
        freqPending = false;
        // process pendingHz
    }
    if (modePending) {
        modePending = false;
        // process pendingMode (already converted to internal representation)
    }
    if (cwPending) {
        cwPending = false;
        // process pendingCW[] character by character
    }

    // ... rest of loop
}
```

`net.loop()` must not be interrupted by disabling interrupts (`cli()` / `noInterrupts()`).
If code at a given point disables interrupts, call `net.loop()` outside that section.

If the device contains long operations (CW keying, SD card reads), add `net.loop()`
**inside those operations as well** — the CON retransmit window is 2 seconds.
Blocking longer than ~2 s will cause CON ACK loss and unnecessary retransmissions.

---

## Publish — When and How

Publish always **on value change**, not on a fixed time interval — unnecessary repeated
publishing wastes network bandwidth and the CON queues of receivers.

```cpp
// Correct — on change
if (freq != freqPrev) {
    uint32_t f = freq;
    net.publish("/hz", (uint8_t*)&f, sizeof(f));
    freqPrev = freq;
}

// Correct — on mode change
if (ActualMode != modePrev) {
    uint8_t m = modeToCI-V(ActualMode);  // convert internal to CI-V byte
    net.publish("/mode", &m, sizeof(m));
    modePrev = ActualMode;
}
```

If no peer is known (`net.peerCount() == 0`), `net.publish()` does nothing —
no manual guard is needed.

---

## Greeting Protocol

When a new peer joins the network, the keyer sends a **state snapshot** to that
peer — every topic the keyer normally publishes is sent once, as **CON** for
guaranteed delivery.

**Why:** without greeting, a PA / antenna switch / web UI that joins mid-session
would not learn the current frequency and mode until the operator next changes
them. That can mean the wrong antenna / wrong filter bank for an indefinite time.

**How — publisher side (this keyer):**

1. Register a peer-added callback: `net.onPeerAdded(onPeerJoined)` (must be set
   **before** `net.begin()` to catch the first probe replies).
2. The callback runs inside `net.loop()` during UDP receive — it must not call
   `publish()` directly. Instead it enqueues the peer name in a small array.
3. The main `loop()` drains the queue and calls `republishState(peerName)`,
   which sends every topic via `net.publishTo(peerName, ..., TRX_CON)`.
4. `republishState()` must stay in sync with the regular publish sites — when
   you add a new state topic, add it here too.

See the keyer source: `onPeerJoined()`, `republishState()`, and the greeting
drain block in `loop()`.

**How — subscriber side (PA, antenna switch, …):**

No action required. The greeting arrives as a normal `/hz` / `/mode` publish
on the topic the device already subscribes to. The CON delivery guarantees
the message survives a single UDP drop.

**Buffer sizing.** The keyer drains the greeting queue **one peer per loop
iteration**, so only one peer's snapshot is in flight at a time. The TrxNet
default `TRXNET_MAX_PENDING = 4` is enough: 2 slots for the snapshot + 2 slots
of retry headroom. Multi-peer joins are staggered across loop iterations
(~microseconds each) and never overlap in `_pending`.

**Greeting defers until `freq != 0`.** Before the first CAT response, the
keyer's `freq` is zero. Sending a `/hz = 0` snapshot to a peer that just joined
would mislead the antenna switch / PA. The drain therefore waits until at
least one valid CAT reading has populated `freq` — peers that join at boot
get their snapshot once the keyer knows the radio's state (worst case ~200 ms
in adaptive FAST polling, ~2 s in plain SLOW request mode, ~ms in sniff mode).

**Do not override `TRXNET_MAX_PENDING` (or other limits) from the sketch with
`#define`.** Arduino IDE compiles library `.cpp` files in a separate translation
unit that does not see sketch-level macros — the resulting class-size mismatch
causes a C++ ODR violation. Edit `TrxNet.h` directly if you need different
values, or use PlatformIO `build_flags`.

---

## Frequency Latency — Sniff vs Request

The latency between operator turning the VFO knob and a peer (e.g. antenna
switch) receiving the new `/hz` depends on the CAT mode (`BAND_DECODER_IN`):

| Mode | Latency | Notes |
|------|---------|-------|
| **Sniff** (CI-V transceive / Kenwood AI 2 / Yaesu auto-info) | ~ms | Radio pushes VFO change unsolicited; keyer parses and publishes immediately |
| **Request** (keyer polls the radio) | up to `BAND_DECODER_REQUEST` ms | Default 2000 ms in idle, adaptive (see below) |

**Recommendation for low-latency band switching:** enable transceive/auto-info
on the radio so the keyer runs in sniff mode. This eliminates the polling
latency entirely — no keyer config needed.

| Radio | Setting |
|-------|---------|
| ICOM | Menu → SET → Connectors → CI-V → "CI-V Transceive: ON" |
| Kenwood | `AI2;` command (or front-panel auto-info menu) |
| Yaesu | Menu → CAT → Auto Info: ON |

**Adaptive polling (request-mode fallback).** When sniff is not available, the
keyer reduces request-mode latency adaptively: every detected change resets a
timer and switches the poll interval to `BAND_DECODER_REQUEST_FAST` (200 ms)
for `BAND_DECODER_ACTIVITY_HOLD` (10 000 ms). After 10 s of no change, the
interval returns to the default `BAND_DECODER_REQUEST` (2000 ms) to spare the
CAT bus during quiet periods.

Constants are `#define` in [k3ng_keyer.ino](k3ng_keyer.ino#L1418-L1424) — adjust
and rebuild to tune.

---

## Public API Summary

| Method | Description |
|--------|-------------|
| `TrxNet(UDP& udp, uint16_t port = 5683)` | Constructor. Pass a WiFiUDP or EthernetUDP instance. |
| `void setPort(uint16_t port)` | Override port before `begin()`. Use when port is loaded from EEPROM. |
| `void begin(const char* name)` | Start the library after network is up. Sends PROBE broadcast. |
| `void loop()` | Process incoming packets, keepalive, CON retransmit. Call every loop iteration. |
| `void subscribe(const char* path, TrxNetCallback cb)` | Register a callback for a topic path. Registering the same path replaces the callback. |
| `void unsubscribe(const char* path)` | Remove a subscription. |
| `void publish(const char* path, const uint8_t* data, size_t len, TrxMsgType type = TRX_NON)` | Send payload to all known peers. `TRX_NON`: fire-and-forget. `TRX_CON`: retransmit until ACKed. |
| `bool publishTo(const char* peerName, const char* path, const uint8_t* data, size_t len, TrxMsgType type = TRX_NON)` | Send payload to one named peer. Returns false on unknown peer or full CON queue. |
| `int peerCount() const` | Number of currently active peers. |
| `const TrxPeer* peer(int index) const` | Read-only access to peer by index. Returns NULL if out of range. |
| `void onPeerAdded(TrxPeerCallback cb)` | Register a callback fired once per newly discovered peer. Used for state-snapshot greeting. |

---

## Discovery and Timing

| Parameter | Value | Description |
|-----------|-------|-------------|
| `TRXNET_ANNOUNCE_MS` | 30 000 ms | keepalive broadcast interval |
| `TRXNET_PEER_TIMEOUT_MS` | 95 000 ms | peer removed after ~3 missed keepalives |
| `TRXNET_CON_TIMEOUT_MS` | 2 000 ms | CON retransmit interval |
| `TRXNET_CON_MAX_RETRIES` | 3 | number of attempts before giving up |

After `net.begin()` a **PROBE** broadcast is sent — other peers respond. Under normal
conditions peers are visible within ~100 ms. Do not wait for peers in an active loop —
publishing when there are no peers is safe (the message is discarded, no harm done).

---

## Guidelines for New Devices

1. **Choose a unique TYPE** for the device name (`705`, `ROT`, `PA`, `LOG`, …) —
   must not collide with `OI3`.
2. **Set NET_ID** so it is unique within its TYPE on the given network.
   **Do not use NET_ID `0x00`** — it is reserved as the "disabled" sentinel.
3. Publish only topics that your device **actually knows** — do not copy topics just
   because another device subscribes to them.
4. Subscribe only to topics that your device **actually processes**.
5. In every callback, always validate the payload length (`if (len < sizeof(T)) return;`).
6. Do not use `String` in callbacks on AVR.
7. Do not call `delay()` in callbacks or in any place where blocking would exceed 2 s
   without a `net.loop()` call.
8. Test discovery on the target network before deployment — a bench test on different
   infrastructure does not guarantee it works in production.
9. **Publish mode as a CI-V byte** (see Payload Formats) — map your internal mode to
   the closest CI-V equivalent. On receive, map back to your internal representation.
