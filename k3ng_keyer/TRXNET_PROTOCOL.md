# TrxNet protokol — OI3 síť

Referenční dokument pro implementaci TrxNet komunikace na všech zařízeních v OI3 síti.
Každé nové zařízení musí dodržovat konvence v tomto dokumentu, aby byla zaručena
vzájemná interoperabilita.

---

## Síťové požadavky

- Všechna zařízení musí být ve **stejné L2 broadcast doméně** (stejný switch/VLAN).
- Discovery funguje přes UDP broadcast `255.255.255.255` — nefunguje přes router nebo
  mezi různými podsítěmi.
- WiFi sítě s AP isolation, guest VLAN nebo mesh systémy mohou broadcast blokovat —
  doporučena drátová Ethernet připojení (W5500/W5100).
- Všechna zařízení musí používat **stejný UDP port: 5683** (výchozí CoAP port TrxNet).

---

## Pojmenování zařízení (Device Name)

Device name je jedinečný identifikátor zařízení v síti. Sestavuje se za běhu
(po načtení konfigurace z EEPROM/SD) a předává se do `net.begin()`.

### Formát

```
{TYP}.{ID}
```

| Část | Popis | Příklad |
|------|-------|---------|
| `TYP` | Typ zařízení, velká písmena | `OI3`, `705`, `ROT`, `PA` |
| `.` | Oddělovač (tečka) | |
| `ID` | NET_ID jako **2místný malý hex** bez prefixu | `ff`, `01`, `0a` |

### Příklady

| Zařízení | NET_ID (byte) | Device name |
|---|---|---|
| OI3 keyer (AVR) | `0xff` | `OI3.ff` |
| OI3 keyer (AVR) | `0x01` | `OI3.01` |
| IC-705 Interface (ESP32) | `0x01` | `705.01` |
| IC-705 Interface (ESP32) | `0x0a` | `705.0a` |

### Sestavení v kódu

```cpp
// ATMEGA / AVR — OI3 keyer
char deviceName[TRXNET_MAX_DEVICE_NAME];
snprintf(deviceName, sizeof(deviceName), "OI3.%02x", NET_ID);

// ESP32 — IC-705 Interface
char deviceName[TRXNET_MAX_DEVICE_NAME];
snprintf(deviceName, sizeof(deviceName), "705.%02x", NET_ID);
```

### Pravidla

- Délka max. 31 znaků (TRXNET_MAX_DEVICE_NAME = 32 včetně null).
- Dvě zařízení se stejným device name jsou v síti považována za totožná — každé
  zařízení musí mít **unikátní NET_ID** v rámci svého typu.
- **NET_ID `0x00` je rezervováno jako sentinel "disabled"** — zařízení s NET_ID `0x00`
  nevolá `net.begin()` a TrxNet komunikaci neaktivuje. Tato hodnota nesmí být použita
  jako skutečné ID v síti.
- Nepoužívej `String` pro sestavení jména — použij `snprintf` do `char[]`.

---

## Mapa témat (Topic Map)

### Publish — odesílá OI3 keyer

Tato témata OI3 keyer **odesílá**. Jiná zařízení je mohou odebírat.

| Téma | Typ payloadu | Delivery | Popis |
|------|-------------|---------|-------|
| `/hz` | `uint32_t` LE | NON | Aktuální frekvence v Hz z CAT/CI-V |
| `/mode` | `uint8_t` | NON | Aktuální operační mód |

### Subscribe — přijímá OI3 keyer

Tato témata OI3 keyer **odebírá**. Jiná zařízení je mohou publikovat.

| Téma | Typ payloadu | Delivery | Popis |
|------|-------------|---------|-------|
| `/s-hz` | `uint32_t` LE | NON | Příkaz: nastavit frekvenci |
| `/s-mode` | `uint8_t` | NON | Příkaz: nastavit mód |
| `/s-cw` | `char[]` max 64 B | CON | Příkaz: odklíčovat CW text |

---

## Formáty payloadu

Veškerá data jsou přenášena jako **raw bytes v nativním byte order (little-endian)**.
Serializace vždy přes `memcpy` — nikdy ne přes přímý cast pointeru.

### `uint32_t` — frekvence v Hz

```cpp
// Odesílání
uint32_t freq = 14250000UL;
net.publish("/hz", (uint8_t*)&freq, sizeof(freq));  // 4 byty LE

// Příjem
void onHz(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint32_t)) return;
    uint32_t freq;
    memcpy(&freq, data, sizeof(freq));
    // freq = 14250000
}
```

### `uint8_t` — mód

Hodnoty módu jsou **ICOM CI-V standardní mode byty**. Každé zařízení mapuje CI-V byte
na svou interní reprezentaci. Použití CI-V bytu eliminuje konverze na straně zařízení,
která přímo čte/nastavuje rádio přes CI-V (např. IC-705 Interface).

| Hodnota (hex) | Mód |
|---------------|-----|
| `0x00` | LSB |
| `0x01` | USB |
| `0x02` | AM |
| `0x03` | CW |
| `0x04` | RTTY / FSK |
| `0x05` | FM |
| `0x06` | WFM |
| `0x07` | CW-R (CW reverzní) |
| `0x08` | RTTY-R (FSK reverzní) |
| `0x17` | DV (D-STAR) |

Zařízení, která nemají přímý CI-V přístup (např. OI3 keyer), mapují svůj interní
mód na nejbližší CI-V ekvivalent při odesílání a zpětně při příjmu.

```cpp
// Odesílání — CI-V byte přímo (pro zařízení s CI-V přístupem)
uint8_t civMode = 0x03;  // CW
net.publish("/mode", &civMode, sizeof(civMode));

// Příjem
void onMode(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint8_t)) return;
    uint8_t civMode = data[0];
    // mapuj civMode na interní reprezentaci zařízení
}
```

### `char[]` — CW text

```cpp
// Odesílání (CON — spolehlivé doručení)
const char* msg = "CQ CQ DE OK1HRA K";
net.publish("/s-cw", (const uint8_t*)msg, strlen(msg), TRX_CON);
// NEPŘIDÁVEJ null terminátor do len — strlen() ho nezahrnuje

// Příjem — VŽDY přidej null terminátor ručně
void onSetCw(const char* from, const uint8_t* data, size_t len) {
    char buf[65] = {};
    size_t n = (len < 64) ? len : 64;
    memcpy(buf, data, n);
    buf[n] = '\0';
    // buf obsahuje CW text
}
```

**Maximální délka CW textu: 64 bytů.** Delší text bude TrxNet tiše oříznut na straně
odesílatele. Příjemce dostane kratší text bez chyby — vždy ověřuj délku.

---

## Konfigurace TrxNet

Definuj **před** `#include <TrxNet.h>`:

```cpp
// Pro ATMEGA2560 (8 KB RAM) — tuned pro OI3 síť s 3–5 peers
#define TRXNET_MAX_PEERS    6   // max peerů v síti
#define TRXNET_MAX_SUBS     8   // max subscribe registrací
#define TRXNET_MAX_PENDING  2   // fronta odchozích CON (zvedni pokud zařízení posílá CON)
#define TRXNET_MAX_SEEN    16   // dedup buffer příchozích CON

#include <TrxNet.h>
```

Statická RAM při těchto hodnotách: **~920 bytů**.

Pro ESP32 nebo zařízení s více RAM ponech výchozí hodnoty (TRXNET_MAX_PEERS=8,
TRXNET_MAX_PENDING=8 atd.) nebo zvedni podle potřeby.

Pokud zařízení **posílá CON zprávy** (např. CW text), nastav:
```cpp
#define TRXNET_MAX_PENDING  (TRXNET_MAX_PEERS)  // jeden CON publish = N slotů (jeden na peer)
```

---

## Inicializace

`net.begin()` musí být voláno **až po** úspěšném připojení k síti (Ethernet nebo WiFi).

```cpp
// ATMEGA2560 + Ethernet2 (W5500)
#include <Ethernet2.h>
#include <EthernetUdp2.h>    // nebo EthernetUDP dle verze knihovny
#include <TrxNet.h>

EthernetUDP trxUdp;
TrxNet      net(trxUdp);    // port 5683 (výchozí)

char deviceName[TRXNET_MAX_DEVICE_NAME];

void setup() {
    byte mac[] = { ... };
    Ethernet.begin(mac);        // DHCP nebo statická IP

    snprintf(deviceName, sizeof(deviceName), "OI3.%02x", NET_ID);
    net.begin(deviceName);      // ← až zde, po Ethernet.begin()

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

## Vzor callbacků (ATMEGA / AVR)

Na AVR platí **přísný zákaz `String` třídy** v callbackech — heap fragmentace způsobí
crash po hodinách provozu. Používej výhradně `char[]` a `memcpy`.

Callbacky musí být **krátké a neblokující** — žádný `delay()`, žádné čtení ze sériové
linky, žádné volání funkcí s dlouhou dobou běhu. Callback pouze nastaví flag a uloží
hodnotu; hlavní smyčka zpracuje.

```cpp
// Globální stav pro předávání z callbacků do hlavní smyčky
volatile uint32_t pendingHz    = 0;
volatile uint8_t  pendingMode  = 0;
volatile bool     freqPending  = false;
volatile bool     modePending  = false;

char             pendingCW[65] = {};
volatile bool    cwPending     = false;

// Callbacky — jen uložení + flag
void onSetHz(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint32_t)) return;
    memcpy((void*)&pendingHz, data, sizeof(uint32_t));
    freqPending = true;
}

void onSetMode(const char* from, const uint8_t* data, size_t len) {
    if (len < sizeof(uint8_t)) return;
    pendingMode = data[0];
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

## Integrace do hlavní smyčky

```cpp
void loop() {
    Ethernet.maintain();    // nebo WiFi keepalive na ESP32
    net.loop();             // MUSÍ být voláno každou iterací bez blokování

    // Zpracování flagů z callbacků
    if (freqPending) {
        freqPending = false;
        // zpracuj pendingHz
    }
    if (modePending) {
        modePending = false;
        // zpracuj pendingMode
    }
    if (cwPending) {
        cwPending = false;
        // zpracuj pendingCW[] char po charu
    }

    // ... zbytek smyčky
}
```

`net.loop()` nesmí být přerušeno zákazem přerušení (`cli()` / `noInterrupts()`).
Pokud kód v daném místě zakazuje přerušení, volej `net.loop()` mimo tuto sekci.

Pokud zařízení obsahuje dlouhé operace (CW klíčování, čtení SD karty), přidej
`net.loop()` i **uvnitř těchto operací** — CON retransmit okno je 2 sekundy.
Blokování delší než ~2 s způsobí ztrátu CON ACK a zbytečné retransmise.

---

## Publish — kdy a jak

Publikuj vždy **při změně hodnoty**, ne v pevném časovém intervalu — zbytečné
opakované publish zbytečně zatěžuje síť a CON frontu příjemců.

```cpp
// Správně — při změně
if (freq != freqPrev) {
    uint32_t f = freq;
    net.publish("/hz", (uint8_t*)&f, sizeof(f));
    freqPrev = freq;
}

// Správně — při změně módu
if (ActualMode != modePrev) {
    uint8_t m = ActualMode;
    net.publish("/mode", &m, sizeof(m));
    modePrev = ActualMode;
}
```

Pokud není žádný peer znám (`net.peerCount() == 0`), `net.publish()` nedělá nic —
není potřeba to hlídat ručně.

---

## Discovery a timing

| Parametr | Hodnota | Popis |
|----------|---------|-------|
| `TRXNET_ANNOUNCE_MS` | 30 000 ms | keepalive broadcast interval |
| `TRXNET_PEER_TIMEOUT_MS` | 95 000 ms | peer odstraněn po ~3 zmeškaných keepalive |
| `TRXNET_CON_TIMEOUT_MS` | 2 000 ms | CON retransmit interval |
| `TRXNET_CON_MAX_RETRIES` | 3 | počet pokusů před vzdáním |

Po `net.begin()` se rozešle **PROBE** broadcast — ostatní peers odpovědí. Za normálních
podmínek jsou peers viditelní do ~100 ms. Nečekej na peery aktivní smyčkou — publish
když nejsou žádní peers je bezpečné (zpráva se zahodí, nezakrní).

---

## Doporučení pro nová zařízení

1. **Zvol unikátní TYP** device name (`705`, `ROT`, `PA`, `LOG`, …) — nekoliduje
   s `OI3`.
2. **NET_ID** nastav tak, aby byl unikátní v rámci svého TYPu v dané síti.
   **NET_ID `0x00` nepoužívej** — je rezervováno jako sentinel "disabled".
3. Publikuj jen témata která tvoje zařízení **skutečně zná** — nekopíruj témata
   jen proto, že je jiné zařízení odebírá.
4. Subscribuj jen témata která tvoje zařízení **skutečně zpracovává**.
5. V callbacku vždy ověřuj délku payloadu (`if (len < sizeof(T)) return;`).
6. Nepoužívej `String` v callbackech na AVR.
7. Nevolej `delay()` v callbackech ani v místech kde by blokování přesáhlo 2 s
   bez `net.loop()`.
8. Otestuj discovery na cílové síti před nasazením — bench test na jiné
   infrastruktuře nezaručuje funkčnost v produkci.
9. **Mód publikuj jako CI-V byte** (viz sekce Formáty payloadu) — mapuj svůj
   interní mód na nejbližší CI-V ekvivalent. Při příjmu mapuj zpětně.
