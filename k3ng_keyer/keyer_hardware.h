/*  keyer_hardware.h

  OI3 keyer is always HARDWARE_OPEN_INTERFACE on Arduino Mega.
  http://remoteqth.com/open-interface.php
*/

#define HARDWARE_OPEN_INTERFACE

// Do not touch anything below this line!
// Serial port class definitions
#define PRIMARY_SERIAL_CLS HardwareSerial
#define SECONDARY_SERIAL_CLS HardwareSerial
