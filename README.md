# Open Interface III
Arduino firmware modified for Open Interface III hardware - based on **K3NG Arduino CW Keyer, which in addition includes:**
![OI3](https://remoteqth.com/img/slide-open-interface-3-01.png)
- **Switch MODE -** preset board for each mode separately
- **MENU -** show many actual value and firmware preset
- **Band decoder -** sniffing CAT or generate own request for read frequency, with BCD (IP in future) output
- **FSK keying -** RTTY keying from memory button or serial line
- **FSK decode -** RTTY decode signal generate from PC (EXTFSK)

More in [wiki](https://remoteqth.com/wiki/index.php?page=Open+interface+III)

![LCD menu](https://remoteqth.com/img/wiki-open-interface-3-04.png)

## Binary upload with avrdude
```bash
$ avrdude -v -v -p atmega2560 -c wiring -P /dev/ttyUSB0 -b115200 -V -D -U flash:w:/k3ng_keyer.ino.mega.hex:i
```

