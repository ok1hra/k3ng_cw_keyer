/*

 K3NG Arduino CW Keyer

 Copyright 1340 BC, 2010, 2011, 2012, 2013, 2014, 2015, 2016 Anthony Good, K3NG
 All trademarks referred to in source code and documentation are copyright their respective owners.


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


If you offer a hardware kit using this software, show your appreciation by sending the author a complimentary kit or a bottle of bourbon ;-)

Full documentation can be found at http://blog.radioartisan.com/arduino-cw-keyer/ .  Please read it before requesting help.

For help, please consult http://blog.radioartisan.com/support-for-k3ng-projects/

 Command Line Interface ("CLI") (USB Port) (Note: turn on carriage return if using Arduino Serial Monitor program)

    CW Keyboard: type what you want the keyer to send (all commands are preceded with a backslash ( \ )
    \?     Help                                      (requires FEATURE_SERIAL_HELP)
    \#     Play memory #                             (requires FEATURES_MEMORIES; play memories 1 - 10 (0 = memory 10) )
    \a     Iambic A mode
    \b     Iambic B mode
    \c     Single Paddle mode
    \d     Ultimatic mode
    \e#### Set serial number to ####
    \f#### Set sidetone frequency to #### hertz
    \g     Bug mode
    \h     Toggle between CW and Hell sending                    (requires FEATURE_HELL)
    \i     Transmit enable/disable
    \j###  Dah to dit ratio (300 = 3.00, do \j alone to set to default)
    \k     Callsign receive practice
    \l##   Set weighting (50 = normal, do \l alone to set to default)
    \m###  Set Farnsworth speed
    \n     Toggle paddle reverse
    \o     Toggle sidetone on/off
    \p#(#) Program memory #
    \q##   Switch to QRSS mode, dit length ## seconds
    \r     Switch to regular speed mode
    \s     Status
    \t     Tune mode
    \u     Manual PTT toggle
    \v     Toggle potentiometer active / inactive   (requires FEATURE_POTENTIOMETER)
    \w###  Set speed in WPM
    \x#    Switch to transmitter #
    \y#    Change wordspace to # elements (# = 1 to 9)
    \z     Autospace on/off
    \+     Create prosign
    \!##   Repeat play memory
    \|#### Set memory repeat (milliseconds)
    \*     Toggle paddle echo
    \`     Toggle straight key echo
    \^     Toggle wait for carriage return to send CW / send CW immediately
    \&     Toggle CMOS Super Keyer Timing on/off
    \%##   Set CMOS Super Keyer Timing %
    \.     Toggle dit buffer on/off
    \-     Toggle dah buffer on/off
    \~     Reset unit
    \:     Toggle cw send echo
    \{     QLF mode on/off
    \>     Send serial number, then increment
    \<     Send current serial number
    \(     Send current serial number in cut numbers
    \)     Send serial number with cut numbers, then increment
    \[     Set Quiet Paddle Interruption
    \=     Toggle American Morse mode    (requires FEATURE_AMERICAN_MORSE)


 Buttons
    button 0: command mode / command mode exit
    button 0 + left paddle:  increase cw speed
    button 0 + right paddle: decrease cw speed
    button 1 - 12 hold + left paddle: repeat memory
    button 1 - 6 half second hold: switch to TX # 1 - 6

 Command Mode (press button0 to enter command mode and press again to exit)
    A  Switch to Iambic A mode
    B  Switch to Iambic B mode
    C  Switch to Single Paddle Mode
    D  Switch to Ultimatic mode
    E  Announce speed
    F  Adjust sidetone frequency
    G  Switch to bug mode
    H  Set weighting and dah to dit ratio to defaults
    I  TX enable / disable
    J  Dah to dit ratio adjust
    K  Toggle Dit and Dah Buffers on and off
    L  Adjust weighting
    N  Toggle paddle reverse
    O  Toggle sidetone on / off
    P#(#) Program a memory
    S  Alphabet code practice (FEATURE_ALPHABET_SEND_PRACTICE)
    T  Tune mode
    V  Toggle potentiometer active / inactive
    W  Change speed
    X  Exit command mode (you can also press the command button (button0) to exit)
    Y#### Change memory repeat delay to #### mS
    Z  Autospace On/Off
    #  Play a memory without transmitting
    ?  Status
         1. Speed in WPM
         2. Keyer Mode (A = Iambic A, B = Iambic B, G = Bug, S = Single Paddle, U = Ultimatic)
         3. Weighting
         4. Dah to Dit Ratio

 Memory Macros
    \#     Jump to memory #
    \c     Play serial number with cut numbers
    \d###  Delay for ### seconds
    \e     Play serial number, then increment
    \f#### Change sidetone to #### hertz (must be four digits - use leading zero below 1000 hz)
    \h     Switch to Hell sending
    \i#    Insert memory number
    \l     Switch to CW (from Hell mode)
    \n     Decrement serial number, do not send
    \q##   Switch to QRSS mode, dit length ## seconds
    \r     Switch to regular speed mode
    \s     Insert space
    \t###  Transmit for ### seconds (must be three digits, use leading zeros if necessary)
    \u     Activate PTT
    \v     Deactivate PTT
    \w###  Set regular mode speed to ### WPM (must be three digits, use leading zeros if necessary)
    \x#    Switch to transmitter # (1, 2, or 3)
    \y#    Increase speed # WPM
    \z#    Decrease speed # WPM
    \+     Prosign the next two characters

 PS2 / USB Keyboard

   CTRL-A           Iambic A
   CTRL-B           Iambic B
   CTRL-C           Single Paddle
   CTRL-D           Ultimatic
   CTRL-E           Set Serial Number
   CTRL-G           Bug
   CTRL-H           Toggle Hell Mode On/Off              (requires FEATURE_HELL)
   CTRL-I           TX enable / disable
   CTRL-O           Toggle Sidetone On/Off
   CTRL-M           Set Farnsworth Speed (0 = disabled)  (requires FEATURE_FARNSWORTH)
   CTRL-N           Paddle Reverse
   CTRL-T           Tune
   CTRL-U           Manual PTT Toggle
   CTRL-W           Set WPM
   CTRL-F1          Switch to TX #1
   CTRL-F2          Switch to TX #2
   CTRL-F3          Switch to TX #3
   CTRL-F4          Switch to TX #4
   CTRL-F5          Switch to TX #5
   CTRL-F6          Switch to TX #6
   END              Send serial number no increment
   ESC              Stop sending and clear buffer
   F1, F2, F3..     Play memory 1, 2, 3...
   DOWN ARROW       Decrease WPM
   HOME             Reset timing settings
   INSERT           Send serial number and increment
   LEFT ARROW       Decrease Dah to Dit Ratio
   PGDN             Decrease Sidetone Frequency
   PGUP             Increase Sidetone Frequency
   RIGHT ARROW      Increase Dah to Dit Ratio
   SCROLL LOCK      Prosign Next Two Characters
   SHIFT-BACKSPACE  Decrement serial number
   SHIFT-F1, F2...  Program Memory 1, 2...
   ALT-F1, F2...    Repeat Memory 1, 2...
   TAB              Pause Sending Immediately
   UP ARROW         Increase WPM
   Keypad /         Dit Paddle (USB Keyboard Only)
   Keypad *         Dah Paddle (USB Keyboard Only)
   Keypad ENTER     Tune / Straight Key (USB Keyboard Only)

 USB Mouse

   Left Button      Dit
   Right Button     Dah
   Middle Button    Tune / Straight Key

 PS2 Keyboard Notes (FEATURE_PS2_KEYBOARD)

    To use FEATURE_PS2_KEYBOARD you need the K3NG_PS2Keyboard.h and K3NG_PS2Keyboard.cpp library files from https://github.com/k3ng/k3ng_cw_keyer/tree/master/libraries

    Some keyboards may require a reset sequence upon startup.  This is activated with OPTION_PS2_KEYBOARD_RESET.

 USB Keyboard Notes (FEATURE_USB_KEYBOARD)

    To use a USB keyboard you need to download and install this library: https://github.com/felis/USB_Host_Shield_2.0 .  You may use an Arduino Mega
    ADK board (which has a built in USB host interface, get or Circuits@Home USB shield (http://www.circuitsathome.com/products-page/arduino-shields/usb-host-shield-2-0-for-arduino),
    or built your own MAX3421 based USB port.

    If you are using an Arduino Mega ADK, you must customize the USB Host Shield Library settings.h file!


    Option Usb Computer Keyboard Emulation FEATURE_CW_COMPUTER_KEYBOARD
    (Arduino Due, Leonardo only)

       You can use your cw key as a computer keyboard. Your computer recognize the K3NG keyer as a normal keyboard.
       Language available English and Italian (more languages to add)
       Use following prosign to emulate Enter Key, Caps Lock, space and backspace:
       Prosign AA "Enter"
       Prosign DO "Caps Lock" (enable and disable)
       "......" or more "Backspace"
       "------" or more "Space"



Useful Stuff
    Reset to defaults: squeeze both paddles at power up (good to use if you dorked up the speed and don't have the CLI)
    Press the right paddle to enter straight key mode at power up
    Press the left  paddle at power up to enter and stay forever in beacon mode

Recent Update History

    2.2.2015040402 More work on ARDUINO_SAM_DUE (documented)

    2.2.2015040501 Fixed bug with O command not working when any display feature was compiled in

    2.2.2015040801 FEATURE_EEPROM_E24C1024; working on FEATURE_CW_COMPUTER_KEYBOARD (documented)

    2.2.2015040901 updated serial help text with recently added commands, consolidated the three paddle echo features into one subroutine

    2.2.2015040902 Minor typos fixed

    2.2.2015042002 Eliminated keyer.h declaration (upgrade Stino if you're still using keyer.h)

    2.2.2015042301
      '#define PRIMARY_SERIAL_PORT &Serial' is now '#define PRIMARY_SERIAL_PORT &Serial' (documented on website 2015-04-25)
      OPTION_SERIAL_PORT_DEFAULT_WINKEY_EMULATION is now OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION (documented on website 2015-04-25)
      '#define default_serial_baud_rate 115200' is now '#define PRIMARY_SERIAL_PORT_BAUD 115200' (documented on website 2015-04-25)
      #define SECONDARY_SERIAL_PORT_BAUD 115200 (documented on website 2015-04-25)
      FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT  (documented on website 2015-04-25)
      FEATURE_LCD1602_N07DH (Thanks Xigco for code!)  (documented on website 2015-04-25)

    2.2.2015042302
      OPTION_CW_KEYBOARD_ITALIAN (Thanks Giorgio IZ2XBZ)  (documented on website 2015-04-25)
      FEATURE_CW_COMPUTER_KEYBOARD repeating backspace, fixed caps lock sounds

    2.2.2015042303
      Test of GitHub - no changes

    2.2.2015042501
      FEATURE_CW_COMPUTER_KEYBOARD update from Giorgio IZ2XBZ
      Website documentation up to date!  Yeahhhhhh!  :-)

    2.2.2015042901
      HARDWARE_NANOKEYER_REV_D

    2.2.2015043001
      Fixed compilation bug with FEATURE_COMMAND_LINE_INTERFACE when FEATURE_WINKEY_EMULATION not enabled

    2.2.2015051201
      OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR (website updated 2015-05-12)

    2.2.2015051301
      Improvements to FEATURE_CW_DECODER for better decoding and Goetzel settings for Arduino Due

    2.2.2015061101
      lcd_columns and lcd_rows in keyer_settings*.h files renamed to LCD_COLUMNS and LCD_ROWS
      OPTION_INVERT_PADDLE_PIN_LOGIC - paddle closed = HIGH, paddle open = LOW

    2.2.2015082801
      Added E24C1024.h and E24C1024.cpp to git
      Fixed compilation issue with Due involving E24C1024 library

    2.2.2015082802
      FEATURE_STRAIGHT_KEY  {documented on web page 2015-09-05}

    2.2.2015090501
      Memories can now be programmed in commmand mode (FEATURE_COMMAND_BUTTONS) by pressing the memory button
      FEATURE_CW_DECODER now has digital input pin (cw_decoder_pin) and if OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR is enable, cw_decoder_audio_input_pin will work in parallel

    2.2.2015090801
      Fixed issue with FEATURE_CW_DECODER + OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR and wrong GOERTZ_SAMPLING_FREQ and GOERTZ_SAMPLES used in goertzel.h causing keyer lockups after startup

    2.2.2015091301
      FEATURE_DYNAMIC_DAH_TO_DIT_RATIO (code contributed by Giorgio, IZ2XBZ)
      #ifdef FEATURE_DYNAMIC_DAH_TO_DIT_RATIO  (keyer_settings.h)
        #define DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_WPM 30
        #define DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_RATIO 300 // 300 = 3:1 ratio
        #define DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_WPM 70
        #define DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_RATIO 240 // 240 = 2.4:1 ratio
      #endif //FEATURE_DYNAMIC_DAH_TO_DIT_RATIO

    2.2.2015091302
      FEATURE_COMPETITION_COMPRESSION_DETECTION - Experimental
      Fixed compiler error when only FEATURE_COMMAND_BUTTONS was enabled

    2.2.2015091801
      OPTION_DIT_DAH_BUFFERS_OFF_BY_DEFAULT_FOR_FEATURE_DIT_DAH_BUFFER_CONTROL
      OPTION_ADVANCED_SPEED_DISPLAY (code contributed by Giorgio, IZ2XBZ)

    2.2.2015091802
      Improved handling of spaces in LCD display

    2.2.2015092101
      Fixed bugs in OPTION_CW_KEYBOARD_ITALIAN and OPTION_UNKNOWN_CHARACTER_ERROR_TONE (courtesy of Giorgio, IZ2XBZ)

    2.2.2015092301
      FEATURE_COMPETITION_COMPRESSION_DETECTION improvements

    2.2.2015092401
      #define compression_detection_pin 0
      default potentiometer_change_threshold changed to 0.9

    2.2.2015101201
      Additional DEBUG_PS2_KEYBOARD code

    2.2.2015101301
      OPTION_STRAIGHT_KEY_ECHO

    2.2.2015101302
      OPTION_STRAIGHT_KEY_ECHO is now FEATURE_STRAIGHT_KEY_ECHO
      CLI command: \`     Toggle straight key echo
      #define cli_paddle_echo_on_at_boot 1
      #define cli_straight_key_echo_on_at_boot 1
      FEATURE_STRAIGHT_KEY now works with FEATURE_CW_COMPUTER_KEYBOARD
      Straight Key can now program memories

    2.2.2015101401
      Fixed compile bug with FEATURE_DISPLAY and cli_straight_key_echo

    2.2.2015101402
      K3NG_PS2Keyboard Library: Fixed issues with CTRL and ALT key combinations with German and French keyboards

    2.2.2015101801
      OPTION_WINKEY_IGNORE_LOWERCASE

    2.2.2015111501
      Fixed storage of KN prosign in memory (Thank Stefan, DL1SMF)

    2.2.2015120401
      Fixed compiler warning: large integer implicitly truncated to unsigned type - jump_back_to_y = 99999;

    2.2.2015121901
      OPTION_PROSIGN_SUPPORT - additional prosign support for memory storage

    2.2.2015122001
      OPTION_PROSIGN_SUPPORT - updated; forgot to add functionality to paddle echo

    2.2.2015122801
      void send_the_dits_and_dahs(char * cw_to_send) compile warning fix

    2.2.2016010301
      Fixed compiler error when OPTION_SAVE_MEMORY_NANOKEYER and FEATURE_COMMAND_LINE_INTERFACE are enabled (Thanks, Gerd, DD4DA)
      void play_memory (byte memory_number) near line 10049 - static String serial_number_string - removed static declration to fix compiler warning (Thanks, Gerd, DD4DA)

    2.2.2016010302
      Winkey emulation pin config bug fix (Thanks, Gerd, DD4DA)

    2.2.2016011801
      New and improved FEATURE_SLEEP code contributed by Graeme, ZL2APV

    2.2.2016012001
      Fixed compile error involving serial_number, FEATURE_PS2_KEYBOARD, and HARDWARE_NANOKEYER_REV_D (Thanks, Kari, OH6FSG)

    2.2.2016012002
      HARDWARE_TEST
      Enhanced FEATURE_SLEEP to have pin that indicates sleep state: define keyer_awake 0 ; KEYER_AWAKE_PIN_AWAKE_STATE, KEYER_AWAKE_PIN_ASLEEP_STATE

    2.2.2016012003
      Fixed compiler warning for void play_memory() and returns; (Thanks, Gerd, DD4DA)

    2.2.2016012004
      Modified includes so library files can be put in \libraries\ folder rather than ino directory so Arduino 1.6.7 works (thanks Giorgio, IZ2XBZ))

    2.2.2016012101
      Beta testing FEATURE_INTERRUPT_PADDLE_READS

    2.2.2016012301
      Fixed compilation error: 10306: error: return-statement with no value, in function returning byte (thanks Giorgio, IZ2XBZ))

    2.2.2016012302
      Merge of bug fix from JG2RZF: Winkey - CTESTWIN sends 0x00 as "HSCW Speed Change" to keyer (thanks JG2RZF)

    2.2.2016012501
      loop_element_lengths - minor change to paddle reading that may have an effect at high speeds

    2.2.2016012502
      tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state settings
      OPTION_RUSSIAN_LANGUAGE_SEND_CLI contributed by Павел Бирюков, UA1AQC

    2.2.2016012601
      Winkey emulation support for 0x1D HSCW overloaded command to switch transmitters (thanks JG2RZF)
      Moved stuff from keyer_settings*.h to keyer.h (no need to tweak these or have different entries for different hardware)

    2.2.2016012801
      Fixed issue with goertzel.h being required for compilation even when it wasn't needed

    2.2.2016012901
      Removed experimental feature

    2.2.2016012902
      FEATURE_LCD_ADAFRUIT_BACKPACK - support for Adafruit I2C LCD Backup using MCP23008 (courtesy Josiah Ritchie, KE0BLL)

    2.2.2016020801
      PROSIGN_HH (courtesy of Vincenzo, IZ0RUS)

    2.2.2016020802
      OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION

    2.2.2016030501
      FEATURE_LCD_SAINSMART_I2C

    2.2.2016030701
      Fixed FEATURE_LCD_SAINSMART_I2C initialization

    2.2.2016030801
      Fixed FEATURE_LCD_SAINSMART_I2C again

    2.2.2016031801
      Ethernet, web server and Internet linking functionality in beta / development (DEFINEs are in HARDWARE_TEST files only right now)
      #define FEATURE_WEB_SERVER
      #define FEATURE_INTERNET_LINK

      #define OPTION_INTERNET_LINK_NO_UDP_SVC_DURING_KEY_DOWN

      #define FEATURE_ETHERNET_IP {192,168,1,179}                      // default IP address
      #define FEATURE_ETHERNET_MAC {0xDE,0xAD,0xBE,0xEF,0xFE,0xEE}

      #define FEATURE_ETHERNET_GATEWAY {192,168,1,1}                   // default gateway
      #define FEATURE_ETHERNET_SUBNET_MASK {255,255,255,0}                  // default subnet mask
      #define FEATURE_ETHERNET_WEB_LISTENER_PORT 80
      #define FEATURE_UDP_SEND_BUFFER_SIZE 128
      #define FEATURE_UDP_RECEIVE_BUFFER_SIZE 128

      #define FEATURE_INTERNET_LINK_MAX_LINKS 2
      #define FEATURE_INTERNET_LINK_DEFAULT_RCV_UDP_PORT 8888
      #define FEATURE_INTERNET_LINK_BUFFER_TIME_MS 500

    2.2.2016040501
      Fixed bug with OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION and ? character not being sent with keyboard and Winkey operation
      Still working on web server functionality

    2.2.2016042601
      More web server functionality work
      #define FEATURE_INTERNET_LINK_KEY_DOWN_TIMEOUT_SECS 8
      \P command now can program memories above #10

    2.2.2016053001
      Additional DEBUG_WINKEY messages for Winkeyer troubleshooting
      #define WINKEY_DEFAULT_BAUD 1200 (added setting for UCXLog 9600 baud Winkey setting)
      Fixed minor Winkey emulation bug with recognizing byte 0x7C as a half dit space when OPTION_WINKEY_IGNORE_LOWERCASE is enabled

    2.2.2016062101
      New CLI commands:
        \>     Send serial number, then increment
        \<     Send current serial number
        \(     Send current serial number in cut numbers
        \)     Send serial number with cut numbers, then increment


    2.2.2016070701
      Corrected Nanokeyer Rev B and Rev D configurations

    2.2.2016070702
      Setting for speed potentiometer check interval: #define potentiometer_check_interval_ms 150

    2.2.2016071001
      OPTION_WINKEY_UCXLOG_9600_BAUD for UCXLog 9600 baud support (I can't get UCXlog to work at 1200 baud)

    2.2.2016071801
      Now have FEATURE_AUTOSPACE and FEATURE_DEAD_OP_WATCHDOG disabled by default for HARDWARE_NANOKEYER_REV_D

    2.2.2016071802
      FEATURE_CAPACITIVE_PADDLE_PINS: capactive_paddle_pin_inhibit_pin

    2.2.2016072301
      Added dependency check for FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
      More Winkey emulation debugging; working on strange issues with UcxLog interoperability.  UcxLog working with normal 1200 baud mode today.  Hmmm.

    2.2.2016080101
      Troubleshooting some UCXLog Winkey weirdness some users are experiencing.  Created OPTION_WINKEY_UCXLOG_SUPRESS_C4_STATUS_BYTE

    2.2.2016080301
      Disabled echoing of 7C (half space character) byte in Winkey emulation

    2.2.2016080601
      More messing around with UCXlog...
      OPTION_WINKEY_DO_NOT_ECHO_7C_BYTE                    // Might need for UCXlog? (7C = half space character)
      OPTION_WINKEY_DO_NOT_SEND_7C_BYTE_HALF_SPACE

    2.2.2016081201
      OPTION_WINKEY_DO_NOT_ECHO_7C_BYTE is changed to OPTION_WINKEY_ECHO_7C_BYTE and only in the test feature and options file for testing/debugging purposes
      OPTION_WINKEY_DO_NOT_SEND_7C_BYTE_HALF_SPACE - not placing this into production.  this was to troubleshoot issues with UCXLog

    2.2.2016081601
      Updated paddle echo to work with bug mode

    2.2.2016090701
      More efficient code suggestion from Paul, K1XM, implemented in loop_element_lengths()

    2.2.2016090801
      Removed legacy option: OPTION_USE_ORIGINAL_VERSION_2_1_PS2KEYBOARD_LIB

    2.2.2016090802
      Corrected error in FEATURE_ROTARY_ENCODER ttable (thanks, frye.dale)

    2.2.2016091401
      More frequent PTT line tail time checking

    2.2.2016091602
      Reversing munged GitHub merge

    2.2.2016091901
      Manual merge of toyo pull request #22
      It is no longer necessary to specify HARDWARE_ARDUINO_DUE in keyer_hardware.h.  It is automatically detected now.

    2.2.2016092701
      Command Mode: command L - adjust weighting

    2.2.2016092702
      Winkey Emulation - changed paddle interrupt behavior to send 0xC2 and then 0xC0 rather than just 0xC0

    2.2.2016092801
      Winkey Emulation - changed paddle interrupt behavior to send 0xC6,0xC0 rather than 0x64,0xC0

    2.2.2016092802
      Fixed issue with configuration in eeprom colliding with memory 0 (1) (Thanks, Ivan, IX1FJG)

    2.2.2016092803
      Winkey Emulation - changed paddle interrupt behavior to also clear send buffer

    2.2.2016092901
      Improved opposite paddle dit/dah insertion in Ultimatic mode

    2.2.2016100601
      Improved paddle break in for memory playing and Winkey interruption
      Fixed various compile bugs that have crept into the code

    2.2.2016102401
      Updated \J (dah to dit ratio) and \L (weighting) CLI commands so that without arguments they set the parameters to defaults

    2.2.2016102801
      Single Paddle mode, C command

    2.2.2016103101
      Quiet Paddle Interruption feature - set with \[ command in CLI.  Value is 0 to 20 element lengths; 0 = off

    2.2.2016110801
      Integrated OK1RR Tiny Keyer hardware files - HARDWARE_TINYKEYER in keyer_hardware.h file

    2.2.2016110802
      New command mode command H - set weighting and dah to dit ratio to defaults
      New command mode command ? - Status

    2.2.2016111701
      FEATURE_CW_COMPUTER_KEYBOARD enhancements from Giorgio IZ2XBZ

    2.2.2016111702
      Eliminated FEATURE_DIT_DAH_BUFFER_CONTROL code; it's compiled in with core code now.  Also depricated OPTION_DIT_DAH_BUFFERS_OFF_BY_DEFAULT_FOR_FEATURE_DIT_DAH_BUFFER_CONTROL

    2.2.2016112301
      New command mode command K: toggle dit and dah buffer on and off

    2.2.2016112302
      Updated keyer_hardware.h to accomodate Leonardo, Yun, Esplora, and other boards to compile with Serial related functionality.

    2.2.2016112401
      Updated dit and dah buffer control to change automatically with Iambic A & B and Ultimatic

    2.2.2016112501
      Code comment update

    2.2.2016112502
      Merged in GitHub pull request 24 https://github.com/k3ng/k3ng_cw_keyer/pull/24 from Giorgio IZ2XBZ

    2.2.2016112701
      Improved performance when sending large macros from logging and contest programs using Winkey emulation.  Thanks, Martin OK1RR for discovery and testing

    2.2.2016112702
      Updated command mode K command to work only when in Ultimatic mode

    2.2.2016112901
      Fixed bug with command mode status command reporting wrong keyer mode.  Also fixed CLI status query reporting wrong keyer mode while in command mode

    2.2.2016120101
      Compilation of serial related functionality for TEENSYDUINO

    2.2.2016120102
      Comilation issue fix for ARDUINO_MAPLE_MINI.  Thanks, Edgar, KC2UEZ

    2.2.2016120401
      Added keyer_stm32duino.h with function declarations to make ARDUINO_MAPLE_MINI compilation work.  Thanks, Edgar, KC2UEZ

    2.2.2016120901
      Merged pull request STM32duino compatibilty 30. Thanks, Edgar, KC2UEZ

    2.2.2016120902
      Fixed bug in command mode when OPTION_WATCHDOG_TIMER is enabled.  Thanks, disneysw.

    2.2.2016121001
      Support for FUNtronics FK-10 contributed by disneysw. HARDWARE_FK_10 in keyer_hardware.h; files: keyer_pin_settings_fk_10.h, keyer_features_and_options_fk_10.h, keyer_settings_fk_10.h

    2.2.2016121201
      Additional work on web interface

    2.2.2016121202
      Additional work on web interface
      Mainstreamed FEATURE_HI_PRECISION_LOOP_TIMING code.  No longer an option.  (Need to clean out of keyer_feature_and_options files)

    2.2.2017010301
      FEATURE_AMERICAN_MORSE - American Morse Code sending mode.  \= command in the CLI switches to American Morse Code https://en.wikipedia.org/wiki/American_Morse_code

  This code is currently maintained for and compiled with Arduino 1.6.1.  Your mileage may vary with other versions.

  ATTENTION: LIBRARY FILES MUST BE PUT IN LIBRARIES DIRECTORIES AND NOT THE INO SKETCH DIRECTORY !!!!

  FOR EXAMPLE:

    K3NG_PS2Keyboard.h, K3NG_PS2Keyboard.cpp ----->  \Arduino\Sketchbook\libraries\K3NG_PS2Keyboard\
    Goertz.h, Gooertz.cpp ------------------------>  \Arduino\Sketchbook\libraries\Goertz\
    BasicTerm.h, BasicTerm.cpp ------------------->  \Arduino\Sketchbook\libraries\BasicTerm\


  "Make good code and share it with friends."

*/

#define CODE_VERSION "2.2.2017010301"
#define eeprom_magic_number 24

#include <stdio.h>
#include "keyer_hardware.h"

#if defined(ARDUINO_SAM_DUE)
  #include <SPI.h>
  #include <Wire.h>
  #define tone toneDUE
  #define noTone noToneDUE
#elif defined(ARDUINO_MAPLE_MINI)
  #include <SPI.h>
  #include <Wire.h>
  #include <EEPROM.h>
  #include "keyer_stm32duino.h"
#else
  #include <avr/pgmspace.h>
  #include <avr/wdt.h>
  #include <EEPROM.h>
#endif //ARDUINO_SAM_DUE

#include "keyer_features_and_options_open_interface.h"

#include "keyer.h"


#include "keyer_dependencies.h"
#include "keyer_debug.h"

#include "keyer_pin_settings_open_interface.h"
#include "keyer_settings_open_interface.h"



#if defined(FEATURE_LCD_4BIT) || defined(FEATURE_LCD1602_N07DH)
  #include <LiquidCrystal.h>
#endif








// Variables and stuff
struct config_t {  //48 bytes
  unsigned int wpm;
  byte paddle_mode;
  byte keyer_mode;
  byte sidetone_mode;
  unsigned int hz_sidetone;
  unsigned int dah_to_dit_ratio;
  byte pot_activated;
  byte length_wordspace;
  byte autospace_active;
  unsigned int wpm_farnsworth;
  byte current_ptt_line;
  byte current_tx;
  byte weighting;
  unsigned int memory_repeat_time;
  byte dit_buffer_off;
  byte dah_buffer_off;
  byte cmos_super_keyer_iambic_b_timing_percent;
  byte cmos_super_keyer_iambic_b_timing_on;
  uint8_t ip[4];
  uint8_t gateway[4];
  uint8_t subnet[4];
  uint8_t link_send_ip[4][FEATURE_INTERNET_LINK_MAX_LINKS];
  uint8_t link_send_enabled[FEATURE_INTERNET_LINK_MAX_LINKS];
  int link_send_udp_port[FEATURE_INTERNET_LINK_MAX_LINKS];
  int link_receive_udp_port;
  uint8_t link_receive_enabled;
  uint8_t paddle_interruption_quiet_time_element_lengths;
} configuration;

byte sending_mode = UNDEFINED_SENDING;
byte command_mode_disable_tx = 0;
byte current_tx_key_line = tx_key_line_1;
  unsigned int ptt_tail_time[] = {initial_ptt_tail_time_tx1,initial_ptt_tail_time_tx2,initial_ptt_tail_time_tx3,initial_ptt_tail_time_tx4,initial_ptt_tail_time_tx5,initial_ptt_tail_time_tx6};
  unsigned int ptt_lead_time[] = {initial_ptt_lead_time_tx1,initial_ptt_lead_time_tx2,initial_ptt_lead_time_tx3,initial_ptt_lead_time_tx4,initial_ptt_lead_time_tx5,initial_ptt_lead_time_tx6};
byte manual_ptt_invoke = 0;
byte qrss_dit_length = initial_qrss_dit_length;
byte keyer_machine_mode = KEYER_NORMAL;   // KEYER_NORMAL, BEACON, KEYER_COMMAND_MODE
byte char_send_mode = 0; // CW, HELL, AMERICAN_MORSE
byte key_tx = 0;         // 0 = tx_key_line control suppressed
byte dit_buffer = 0;     // used for buffering paddle hits in iambic operation
byte dah_buffer = 0;     // used for buffering paddle hits in iambic operation
byte button0_buffer = 0;
byte being_sent = 0;     // SENDING_NOTHING, SENDING_DIT, SENDING_DAH
byte key_state = 0;      // 0 = key up, 1 = key down
byte config_dirty = 0;
unsigned long ptt_time = 0;
byte ptt_line_activated = 0;
byte speed_mode = SPEED_NORMAL;
byte pause_sending_buffer = 0;
byte length_letterspace = default_length_letterspace;
byte keying_compensation = default_keying_compensation;
byte first_extension_time = default_first_extension_time;
byte ultimatic_mode = ULTIMATIC_NORMAL;
float ptt_hang_time_wordspace_units = default_ptt_hang_time_wordspace_units;
byte last_sending_mode = MANUAL_SENDING;
byte zero = 0;
byte iambic_flag = 0;
unsigned long last_config_write = 0;



#ifdef FEATURE_DISPLAY
  enum lcd_statuses {LCD_CLEAR, LCD_REVERT, LCD_TIMED_MESSAGE, LCD_SCROLL_MSG};
  #define default_display_msg_delay 1000
#endif //FEATURE_DISPLAY



#ifdef FEATURE_DISPLAY
  byte lcd_status = LCD_CLEAR;
  unsigned long lcd_timed_message_clear_time = 0;
  byte lcd_previous_status = LCD_CLEAR;
  byte lcd_scroll_buffer_dirty = 0;
  String lcd_scroll_buffer[LCD_ROWS];
  byte lcd_scroll_flag = 0;
  byte lcd_paddle_echo = 1;
  byte lcd_send_echo = 1;
#endif //FEATURE_DISPLAY

#ifdef DEBUG_VARIABLE_DUMP
  long dit_start_time;
  long dit_end_time;
  long dah_start_time;
  long dah_end_time;
#endif //DEBUG_VARIABLE_DUMP

#ifdef FEATURE_COMMAND_BUTTONS
  int button_array_high_limit[analog_buttons_number_of_buttons];
  int button_array_low_limit[analog_buttons_number_of_buttons];
#endif //FEATURE_COMMAND_BUTTONS

byte send_buffer_array[send_buffer_size];
byte send_buffer_bytes = 0;
byte send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;







#define SIDETONE_HZ_LOW_LIMIT 299
#define SIDETONE_HZ_HIGH_LIMIT 2001



#ifdef FEATURE_ROTARY_ENCODER            // Rotary Encoder State Tables
    const unsigned char ttable[7][4] = {
      {0x0, 0x2, 0x4,  0x0}, {0x3, 0x0, 0x1, 0x10},
      {0x3, 0x2, 0x0,  0x0}, {0x3, 0x2, 0x1,  0x0},
      {0x6, 0x0, 0x4,  0x0}, {0x6, 0x5, 0x0, 0x20},
      {0x6, 0x5, 0x4,  0x0},
    };

  unsigned char state = 0;
  #define DIR_CCW 0x10                      // CW Encoder Code (do not change)
  #define DIR_CW 0x20                       // CCW Encoder Code (do not change)
#endif //FEATURE_ENCODER_SUPPORT




#if defined(FEATURE_LCD_4BIT) || defined(FEATURE_LCD1602_N07DH)
  LiquidCrystal lcd(lcd_rs, lcd_enable, lcd_d4, lcd_d5, lcd_d6, lcd_d7);
#endif









PRIMARY_SERIAL_CLS * primary_serial_port;


PRIMARY_SERIAL_CLS * debug_serial_port;

#ifdef FEATURE_PTT_INTERLOCK
  byte ptt_interlock_active = 0;
#endif //FEATURE_PTT_INTERLOCK


#if defined(FEATURE_PADDLE_ECHO)
  byte paddle_echo = 0;
  long paddle_echo_buffer = 0;
  unsigned long paddle_echo_buffer_decode_time = 0;
#endif //FEATURE_PADDLE_ECHO







unsigned long automatic_sending_interruption_time = 0;



/*---------------------------------------------------------------------------------------------------------

  Open Interface III (#OI3)
  ----------------------
  https://remoteqth.com/open-interface.php
  by OK1HRA with RTTY code from JI3BNB
  TNX OK1IAK code help
  rev 3,1415

   ___               _        ___ _____ _  _
  | _ \___ _ __  ___| |_ ___ / _ \_   _| || |  __ ___ _ __
  |   / -_) '  \/ _ \  _/ -_) (_) || | | __ |_/ _/ _ \ '  \
  |_|_\___|_|_|_\___/\__\___|\__\_\|_| |_||_(_)__\___/_|_|_|


  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  Modes:
    |CWK - CW Keyer by K3NG
        WinKey/CLI emulation
        SOURCE: USB/Serial interface
        INPUTS: Paddle Interlock Encoder Set/Mem_buttons
        OUTPUTS: CW1/2 PTT1/2
    >CWD - CW Daemon
        Keyng from PC
        SOURCE: USB/Serial interface DTR/RTS
        INPUTS: DTR(CW) RTS(PTT)
        OUTPUTS: CW1 PTT1
    |SSB - SSB
        LSB USB AM FM
        SOURCE: Mic-audio
        INPUTS: FootSwitch RTS
        OUTPUTS: PTT1
    >FSK - PC FSK keying
        RTTY keying from EXTFSK with sniffing and decode signal (lowercase) by JI3BNB / OK1HRA
        SOURCE: USB/Serial interface, Memory0-2_button
        INPUTS: DTR RTS
        OUTPUTS: PTT1 FSK
    |FSK generator by JI3BNB
        generator from Serial ASCII
        SOURCE: USB/Serial interface
        INPUTS: ASCII, Memory0-2_button
        OUTPUTS: PTT1 FSK
    |DIG - Audio FSK
        AFSK PSK and any modes modulate fom audio
        SOURCE: USB souncard
        INPUTS: RTS(PTT)
        OUTPUTS: PTT
  - FSK TX code
  - FSK memory
  - FSK sniffing
  - CW K3NG code
  - Band decoder BCD output
  - Input power voltage out of range warning

  Changelog:
  ----------
  2023-09 - add http web CAT
  2022-03 - unite UDP/keyer CW speed, MQTT fast re-init, disable mqtt steper over 40m band
  2021-12 - mqtt bugfix
          - mqtt stepper support
  2020-11 - disable loop() function if PTT is active
  2020-10 - mqtt subscribe /ptt (SSB only)
          - GPS fixed
  2020-06 - show IP in menu 29-30
          - CAT disable if PTT ON
  2019-09 - Sequencer code complete redesign
          - add menu 28 - select PTT output pin, also in SD cfg
          - Interlock/PTTin bug fix
  2019-08 - add mqtt-wall
          - PTTin / Interlock choice
          - send CW transmit to mqtt
          - mqtt subscribe cw/rtty/freq/mode
          - part of configure read from SD card oi0.cfg (default),
            if press during start button, loaded another files
            SET  button > oi1.cfg
            MEM1 button > oi2.cfg
            MEM2 button > oi3.cfg
            MODE button > oi4.cfg
          - Menu numbers 6, 11, 12, 13, 14, 15, 16, 22, 26, 27 28
            may be change vlaue, after press MODE button
  2019-07 - read mode from Kenwood CAT
  2017-03 - All modified line in original code signed with #OI3
          - Fix Sequencer PTT
  2017-02 - Interlock input (cinch, UDP)
          - Stop UDP Interlock by press Mode button
          - MQTT pub support
          - Three level Sequencer
          - MqttPub rx/tx fsk ascii
          - Two fsk memory from elbug
          - Show Sequencer-PA-PTT lead/tail in menu

  TODO:
  -----
  - change PTTmodeCW output for UHF band
  - stop playng RTTY memory
  - http check new firmware (github)
  - ssb ptt from elbug
  - MqttPub tx CW ascii
  ? use interrupt function for interlock, PTT232, Foot PTT
  ? save last MODE to eeprom

  Known Bugs
  ----------
  - RTTY RX decoder not work after tx mem or change mode
  - FSK jelo, ale PTT ne, nesvitila LED, ani TRX a na LCD probliklo neco jako: subscribe test ... - po odpojeni LAN to uz neudelalo.
  - NEfunguje PTT In z toho TRX, jak zaklicuju TRX, zustane uz zaklicovano - neni nejaky problem diky casu sekvenceru? S nulama jsem nezkousel
  - při navoleném režimu SSB skutečně nefunguje PTT výstup ven... stačí vybrat třeba digi nebo cwd a PTT je OK. Pouze při SSB nic. > viz. menu 28

---------------------------------------------------------------------------------------------------------*/
const char* REV = "20260524";

// DEFINE HARDWARE
// #define FEATURE_TELNET_SERVER         // Telnet status server on port 23 (disable to save RAM/flash)
#define PCB_REV_3_1415                // revision of PCB
#define VOLTAGE_MEASURE_ADJUST 0.3    // ofset for precise adjust voltage measure
// Add-ons
bool EnableEthernet = 1;          // enable USR-ES1 ETHERNET module (must be installed)
bool EnableDHCP = 1;                 // Enable DHCP
bool ACC_KEYBOARD    = 0;          // Shift in/out register via ACC https://remoteqth.com/wiki/index.php?page=ACC+Keyboard+for+Open+Interface+III
bool RemoteSwitch    = 0;          // IP controled remote RemoteSwitch https://remoteqth.com/wiki/index.php?page=IP+Switch+with+ESP32-GATEWAY
bool KeyboardAnswLed = 0;          // Keyboard Led shown answered UDP packet from IP RemoteSwitch
                                      // + latency measure. Disable set localy
                                      // ! Need change #define SERIAL_RX_BUFFER_SIZE [GpsBufferSize variable]
                                      //   in file /home/dan/.arduino15/packages/arduino/hardware/avr/1.8.x/cores/arduino/HardwareSerial.h
                                      // also enabled SOMQ proxy (Single Operator Multi QTH) orchestra
                                      // If GPS synchronous time, received ascii on 89 UDP port formated with UTC time and send to some QTHs on command port 88
                                      // IP set manually below SOxQTH variable

// FEATURES AND OPTIONS
int DebuggingOutput  = 0;          // 0 = OFF, 1 - Serial0 KEY, 2 - Serial2 CAT, 3 - UDP
long DebuggingTimer;
bool K3NG_KEYER      = 1;          // enable CW keyer
bool FSK_TX          = 1;          // enable RTTY keying
bool FSK_RX          = 0;          // enable RTTY decoder - EXPERIMENTAL!
//=============================
byte NET_ID          = 0xff;          // NetID [hex] MUST BE UNIQUE IN NETWORK - every Open Interface own different number
//=============================
int UDP_RTTY_PORT       = 89;         // UDP port listen to CW/RTTY character
                                      // [echo -n "cq de ok1hra ok1hra test k;" | nc -u -w1 192.168.1.19 89]
int UDP_COMMAND_PORT    = 88;         /* UDP port listen to RX command

                                      m:#;   - Mode # 0-5
                                      i:#;   - INTERLOCK # 0/1 (on/off)
                                      p:#:%; - PTT # 0/1 (on/off), % 0-3 (0=PTTPA, 1=PTT1, 2=PTT2, 3=PTT3)
                                      s:###; - ### Switch0-2 binary for set LED on keyboard (if installed) and measure latency
                                               maybe used also as local Switch

                                      c:###:value; - configure
                                                   - 000-NetID ## [hex]
                                                   - 001-SERBAUD2 #
                                                         value  0=1200 1=2400 2=4800 3=9600 4=19200 5=38400 6=57600 7=115200
                                                         [echo -n "c:001:4;" | nc -u -w1 192.168.1.20 88]
                                                   - 002-CIV_ADRESS ## [hex]
                                                         [echo -n "c:002:56;" | nc -u -w1 192.168.1.20 88]
                                                   - 003-BAND_DECODER_IN #
                                                         0=disable 1=ICOM_CIV 2=KENWOOD_PC 3=YAESU_CAT 4=YAESU_CAT_OLD 5=INPUT_SERIAL
                                                   - 004-DebuggingOutput
                                                         0=disable 1=serial1(KEY) 2=serial2(CAT) 3=UDP broadcast
                                                         [echo -n "c:004:3;" | nc -u -w1 192.168.1.75 88] set
                                                         [tcpdump -A -i enp0s31f6 ether broadcast and udp port 88 | grep 'debug:' | cut -d ':' -f2 | cut -d ';' -f1] listen

                                      b:s#;  - Broadcast identify packet
                                             - s = Switch board, # = ID
                                             - o = OpenInterface, # = ID
                                             ? r = Rotator, # = ID
                                             ? c = Controller, # = ID

                                     b:o#*p0; - Broadcast Open Onterface PTT packet
                                              - b = broadcast
                                              - o = open interface
                                              - # = ID number
                                              - * = Band number
                                              - p = ptt
                                              - 0 = ptt status

                                      w:#######:[msg]; - CW transmit (not implemented yet)
                                                        [echo -n "w:000000f:cq de ok1hra ok1hra test k;" | nc -u -w1 192.168.1.19 88]
                                                        ####### UTC time when msg was be send [millis in hex]
                                                        [msg] transmit message

ToDo
- transfer wpm speed -> void speed_set(int wpm_set){ or \w### ??

*/

String YOUR_CALL        = "NONE";
int MODE_AFTER_POWER_UP = 0;          // MODE after start up
int MENU_AFTER_POWER_UP = 23;         // MENU after start up
bool BUTTON_BEEP        = 1;          // Mode button beep enable

bool InterlockEnable    = true;      // true = interlock, false = ptt in
bool PttInStatus        = false;
bool PttActive          = false;
unsigned int PTTout     = 0;
unsigned int SEQUENCERlead       = 0;        // SEQUENCER output lead delay ms between SEQ-->PA
unsigned int SEQUENCERtail       = 0;        // SEQUENCER output tail delay ms          :    :                      :     PA-->SEQ
unsigned int PAlead              = 0;        // PA output lead delay ms between         :    PA-->TRX               :     :    :
unsigned int PAtail              = 0;        // PA output tail delay ms                 :    :    :                 TRX-->PA   :
unsigned int PTTlead             = 10;       // PTT (FSK) lead delay ms between         :    :    TRX-->FSK         :     :    :
unsigned int PTTtail             = 6;        // PTT (FSK) tail delay ms                 :    :    :           FSK-->TRX   :    :
        /*                     |                                                        ^    ^    ^            ^    ^     ^
                            Master                                  SEQUENCERlead ______|    |    |            |    |     |_____ SEQUENCERtail
                            for CW                                         PAlead ___________|    |            |    |___________ PAtail
                           tail delay                                     PTTlead ________________|            |________________ PTTtail
                                      */
                                      // 1 = pin8 at DB25 | 2 = pin20 at DB25 | 3 = pin22 at DB25
 int PTTmodeCW          = 1;          // [1-3] How PTT TRX output use in mode CW
 int PTTmodeSSB         = 3;          //
 int PTTmodeFSK         = 1;          //
 int PTTmodeDIGI        = 2;          //
 int PTTbyMode[6]={PTTmodeCW, PTTmodeCW, PTTmodeSSB, PTTmodeFSK, PTTmodeFSK, PTTmodeDIGI};

/*                          ts480 RC
D41 - PTT1   >  8-DB25      3-REMOTE miniDIN (1-DATA audio input OFF) = FSK
D22 - PTT2   > 20-DB25      3-DATA miniDIN (3-MIC audio input OFF) = AFSK  <- need AFSK D29 HIGH
D25 - PTT3   > 22-DB25 MIC  5-MIC = SSB
D31 - PA-PTT >  7-DB25 PA   12-DB15
*/

// BAND DECODER Inputs
 unsigned long SERBAUD2    = 115200;  // [baud] CAT Serial port in/out baudrate
 int BAND_DECODER_IN       = 2;       // 0=disable 1=ICOM_CIV 2=KENWOOD_PC 3=YAESU_CAT 4=YAESU_CAT_OLD 5=INPUT_SERIAL (telnet ascii input - cvs format [band],[freq]\n)
                                      // 6=YAESU_BCD 7=ICOM_ACC (voltage 0-8V on ACC19 pin connector - need calibrate)
 int BAND_DECODER_WATCHDOG = 10000;   // [ms] determines the time, after which the BCD output switch to OFF and Frequency to 0 | 0=disable
 int BAND_DECODER_REQUEST  = 2000;    // [ms] use TXD output for sending frequency request, if not detect frequency in sniff mode  | 0=disable
 // Adaptive polling: after a freq/mode change, switch to FAST interval for ACTIVITY_HOLD ms.
 // Lowers band-change latency for peers (PA, antenna switch) without permanent CAT load.
 // For radios with CI-V transceive / Kenwood AI 2 / Yaesu auto-info enabled, sniff already
 // gives ~ms latency and this only affects request fallback.
 #define BAND_DECODER_REQUEST_FAST    200    // [ms] poll interval while operator is active
 #define BAND_DECODER_ACTIVITY_HOLD   10000  // [ms] stay in FAST this long after last change
 int CIV_ADRESS            = 0x56;       // CIV input HEX Icom adress (0x is prefix)

// BAND DECODER Outputs [NOT IMPLEMENTED]
// int SERBAUD3           = 115200;// [baud] CAT Serial port in/out baudrate
// #define BCD_OUT                 // output 11-14 relay used as Yaesu BCD
// #define ICOM_CIV_OUT            // send frequency to CIV on Serial3 using CIV_ADRESS from oi0.cfg // DISABLED: feedback loop when reading via Kenwood protocol - causes frequency jump-back during tuning
// #define KENWOOD_PC_OUT        // send frequency to RS232 CAT ** for operation must disable REQUEST **
// #define YAESU_CAT_OUT         // send frequency to RS232 CAT ** for operation must disable REQUEST **
// #define REMOTE_RELAY          // TCP/IP remote relay - need install and configure TCP232 module
// #define SERIAL_echo           // Feedback on serial line in same baudrate, CVS format <[band],[freq]>\n
// #define CIV_ADR_OUT  0x56     // CIV output HEX Icom adress (0x is prefix)

// BAND DECODER RULES
long Freq2Band[11][2] = {/*
Freq Hz from       to   Band number
*/   {1810000,   2000000},  // #1 [160m]
     {3500000,   3800000},  // #2  [80m]
     {7000000,   7200000},  // #3  [40m]
    {10100000,  10150000},  // #4  [30m]
    {14000000,  14350000},  // #5  [20m]
    {18068000,  18168000},  // #6  [17m]
    {21000000,  21450000},  // #7  [15m]
    {24890000,  24990000},  // #8  [12m]
    {28000000,  29700000},  // #9  [10m]
    {50000000,  52000000},  // #10  [6m]
   {144000000, 146000000},  // #11  [2m]
};

// BAND TO REMOTE SWITCH ID
int BandToRemoteSwitchID[12] = { /*
IP Switch
  ID
 0-7  */
  0,  // band 0 (no data)
  0,  // Band #1 [160m]
  0,  // Band #2  [80m]
  0,  // Band #3  [40m]
  0,  // Band #4  [30m]
  0,  // Band #5  [20m]
  0,  // Band #6  [17m]
  0,  // Band #7  [15m]
  0,  // Band #8  [12m]
  0,  // Band #9  [10m]
  0,  // Band #10  [6m]
  0,  // Band #11  [2m]
};

int IpSwBankCrange[8]= { /*
number of IP switch bank C position
 2-16 range */
  16, // ID 8
  8,  // ID 9
  8,  // ID A
  8,  // ID B
  8,  // ID C
  8,  // ID D
  8,  // ID E
  15,  // ID F
};
// for using 1 or 2 eight output modules (ip switch bank C ID 8-F, corresponds bank A/B ID 0-7)
// + need hardware debounce - add C89 C90 R53 R55 R56 R57
int IpSwitchEncoder;
byte IpSwitchBankC[2];

const int CIVModeSet[13] {
/* ICOM mode  ->  Open Interface mode
                  0|CWK     -WinKey
                  1>CWD     -cw/dtr, ptt/rts
                  2|SSB     -foot_switch/ptt, audio to mic
                  3>FSK PC  -fsk/dtr, ptt/rts
                  4|FSK     -serial 9600 baud
                  5|DIG     -AFSK, ptt/rts, audio to rear */
/* LSB        */	2,
/* USB        */	2,
/* AM         */	2,
/* CW         */	1,  //0
/* RTTY (FSK) */	4,
/* FM 	      */  2,
/* Wide FM    */	2,
/* CW-R       */	0,
/* RTTY-R     */  4,
/* not use    */  0,
/* not use    */  0,
/* S-AM       */  2,
/* PSK 	      */  5
};

const int KenwoodCatModeSet[10] {
/* KENWOOD mode  ->   Open Interface mode 0-CW Keyer, 1-CW PC, 2-SSB, 3-FSK PC, 4-FSK, 5-DIGITAL(AFSK)*/
/* No mode    */	0,
/* LSB        */	2,
/* USB        */	2,
/* CW         */	0,
/* FM 	      */  2,
/* AM         */	2,
/* RTTY (FSK) */	3,  // 3 FSK PC | 4 FSK CLI | 5 DIGITAL (AFSK)
/* CW-R       */	0,
/* Tune       */	0,
/* RTTY-R     */  3
};
const int KenwoodCatModeSetReverse[6] {
/* OI3 mode > 0 No mode | 1 LSB | 2 USB | 3 CW | 4 FM | 5 AM | 6 RTTY(FSK) | 7 CW-R | 8 Tune | 9 RTTY-R */
/* CW Keyer   */  3,
/* CW PC      */  3,
/* SSB        */  1,
/* FSK PC     */  6,
/* FSK        */  6,
/* DIG(AFSK)  */  1
};
const int YaesuModeSet[10] {
/* YAESU mode ->  Open Interface mode
                  0|CWK     -WinKey
                  1>CWD     -cw/dtr, ptt/rts
                  2|SSB     -foot_switch/ptt, audio to mic
                  3>FSK PC  -fsk/dtr, ptt/rts
                  4|FSK     -serial 9600 baud
                  5|DIG     -AFSK, ptt/rts, audio to rear */
/* LSB      */    5,
/* USB      */    5,
/* CW       */    1,
/* CW-R     */    1,
/* AM       */    2,
/* FM       */    2,
/* CW(N)    */    1,
/* CW(N)-R  */    1,
/* AM(N)    */    2,
/* FM(N)    */    2
};

// BAND DECODER antenna NAME ON LCD MENU
char* ANTname[12] = {
    "-",          // Band 0 (no data)
    "Dipole",     // Band 1
    "Vertical",   // Band 2
    "Yagi",       // Band 3
    "Windom",     // Band 4
    "DeltaLoop",  // Band 5
    "20m Stack",  // Band 6
    "-",  // Band 7
    "-",  // Band 8
    "-",  // Band 9
    "-",  // Band 10
    "-",  // Band 11
};

// ETHERNET - TrxNet / UDP
// if (EnableEthernet == true){ //--------------------------------------------------------------------------- vypnout asi
  const byte RemoteDevice PROGMEM = 's';
  const byte ThisDevice PROGMEM = 'o';
  bool EthLinkStatus = 0;
  long EthLinkStatusTimer[2]{1500,1000};
  #include <SPI.h>
  #include <Ethernet.h> // and disable on line #749
  #include <EthernetUdp.h>
  // #include <Ethernet2.h> // and disable on line #749
  // #include <EthernetUdp2.h>
  // TrxNet — P2P telemetry, replaces PubSubClient/MQTT
  // PENDING/PEERS/etc. tuned via defaults in TrxNet.h — sketch-level #define
  // is silently broken by Arduino IDE's separate library compilation (ODR).
  #include <TrxNet.h>
  EthernetUDP trxUdp;
  TrxNet      net(trxUdp);
  uint16_t    trxPort = 5683;
  char        trxDeviceName[TRXNET_MAX_DEVICE_NAME];
  // TrxNet pending state — set in callbacks, processed in loop()
  volatile uint32_t trxPendingHz      = 0;
  volatile uint8_t  trxPendingMode    = 0;
  volatile uint8_t  trxPendingCivMode = 0x01;
  volatile bool     trxFreqPending = false;
  volatile bool     trxModePending = false;
  char              trxPendingCW[65] = {};
  volatile bool     trxCwPending   = false;
  volatile bool     trxCwAbort     = false;
  // Greeting queue — onPeerJoined fills, loop() drains via republishState()
  char              trxPendingGreet[TRXNET_MAX_PEERS][TRXNET_MAX_DEVICE_NAME];
  volatile uint8_t  trxPendingGreetCount = 0;
  // Forward decl — Arduino auto-prototype may sit above TrxNet.h include otherwise
  void onPeerJoined(const TrxPeer* peer);
  void republishState(const char* peerName);
  byte LastMac = 0xFF - NET_ID;
  byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, LastMac};
  IPAddress ip(192, 168, 1, 220);         // IP
  IPAddress gateway(192, 168, 1, 1);    // GATE
  IPAddress subnet(255, 255, 255, 0);     // MASK
  IPAddress myDns(8, 8, 8, 8);            // DNS (google pub)
  unsigned int UdpCommandPort = 88;       // local UDP port listen to command
  unsigned int UdpRttyPort = 89;          // local UDP port listen to CW/RTTY transmit
  #define UDP_TX_PACKET_MAX_SIZE 40       // MIN 30
  char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
  int UDPpacketSize;
  EthernetUDP UdpCommand; // An EthernetUDP instance to let us send and receive packets over UDP
  EthernetUDP UdpRtty;
  IPAddress BroadcastIP(0, 0, 0, 0);        // Broadcast IP address
  int BroadcastPort       = 88;             // destination broadcast packet port
  IPAddress RemoteSwIP(0, 0, 0, 0);         // remote UDP IP switch - set from UDP DetectRemote array
  int RemoteSwPort         = 0;             // remote UDP IP switch port
  byte DetectedRemoteSw[16][5];             // detect by RX broadcast packet - storage by ID (ID=rows)
  int BandDecoderChange    = 0;             // If band change, send query packet to Remote IP switch
  long RemoteSwLatency[2];                  // start, stop mark
  byte RemoteSwLatencyAnsw = 1;             // answer (offline) detect
  byte TxUdpBuffer[10];
  IPAddress DebuggingIP(0, 0, 0, 0);        // Debugging broadcast IP address
  int DebuggingPort       = 66;             // destination broadcast packet port

int RandomNumber;

// microSD
#include <SD.h>
File myFile;

String ConfigFile="oi0.cfg";
char charConfigFile[8]; // length +1

// CAT (Serial3 in ACC connector)
int SERBAUD3                  = 9600;       // Serial3 in/out baudrate

// Serial2FSK (FSK TX)
int SERBAUD0               = 115200;     // Serial0 in/out baudrate (seria2fsk), if set 1200 may be controled as winkey
bool AFSK_ENABLE           = 0;          // AFSK AUDIO (serial2fsk, fsk memory)
bool SERIAL_FSK_TX_ECHO    = 0;          // enable TX echo on serial port
bool SHOW_HIDDEN_FSK_CHAR  = 0;          // show invisible TX characters on LCD
int MARK                      = 1445;       // [Hz] AFSK mark 1445 / 2295 Hz
int SPACE                     = 1275;       // [Hz] AFSK space 1275 / 2125 Hz
#define FMARK    HIGH            // FSK mark level [LOW/HIGH]
#define FSPACE   LOW             // FSK space level [LOW/HIGH]
#define BaudRate 45.45           // RTTY baud rate
#define StopBit  1.5             // stop bit long
String FSKmemory[6];

// TIMEOUTS
long Timeout[10][2] = { // [lines][rows]
    {0, 500},          // LCD   [0][0-timer/1-timeout(LCDrefresh)]
    {0, 4000},         // Menu to Mode timeout
    {0, 1000},         // Band decoder read (Icom voltage, Yaesu BCD)  [2][0-timer/1-timeout(input refresh)]
    {0, BAND_DECODER_WATCHDOG}, // Band decoder WATCHDOG [3][0-timer/1-timeout]
    {0, BAND_DECODER_REQUEST},  // Band decoder REQUEST [4][0-timer/1-timeout]
    {0, 50},           // MODE button debounce [5][0-timer/1-debounce]
    {0, 500},          // MODE button long [6][0-timer/1-long]
    {0, 1000},         // DCin voltage measure [7][0-timer/1-long]
    {0, 60000},        // UDP Broadcast packet [8][0-timer/1-timeout]
    {0, 1500},        // GPS 1 PPS timeout [9][0-timer/1-timeout]
};
long PTT_tail_timeout[5][2] = { // [lines][rows]
    {0, PTTtail},          // PTT 1
    {0, PTTtail},          // PTT 2
    {0, PTTtail},          // PTT 3
    {0, PAtail},           // PA
    {0, SEQUENCERtail},    // Sequencer
};
unsigned long LastSeqChange;
byte SequencerLevel = 0;   // 0 = off, 1-2-3 = PTT1-2-3, 4 = PA, 5 = SEQ

/*                          0   _________________________   0
                          _____|                         |_____   Sequencer
                                  5  _______________   5
                          __________|               |__________   PTT-PA
                                       4  _____   4
                          _______________| 321 |_______________   PTT-1-2-3
*/
//---------------------------------------------------------------------------------------------------------

// PIN SETTINGS https://remoteqth.com/wiki/index.php?page=Open+interface+III
#if defined(PCB_REV_3_1415) // LCD A2, 37, 6, 7, 8, 9 (RS, E, D4, D5, D6, D7)
  const int DCIN PROGMEM = A7;      // measure input voltage
  const int DC3V PROGMEM = A6;      // measure 3,3V
  const int encA PROGMEM = 24;      // encoder-A
  const int encB PROGMEM = 18;      // encoder-B
  const int MEM PROGMEM = A1;       // K3NG CW key button
  const int CW1 PROGMEM = 34;       // out
  const int CW2 PROGMEM = 35;       //
  const int PTT1 PROGMEM = 41;      //
  const int PTT2 PROGMEM = 22;      //
  const int PTT3 PROGMEM = 25;      // PTT mic
  const int MENU PROGMEM = 36;      // MODE button
  const int FSK PROGMEM = 23;       // FSK output
  const int INTERLOCK PROGMEM = 2;  // in
  const int FootSW PROGMEM = 19;    // in
  const byte BCD1 PROGMEM = 42;     // __
  const byte BCD2 PROGMEM = 43;     //   |
  const byte BCD3 PROGMEM = 44;     //   |- band data
  const byte BCD4 PROGMEM = 45;     // __|  from band decoder
  const int PADDLEL PROGMEM = 26;    // in
  const int PADDLER PROGMEM = 28;    // in
  const int SEQUENCER PROGMEM = 40; // out
  const int PTTPA PROGMEM = 31;     // out PA PTT
  const int SDPLUG PROGMEM = A5;    // in  microSD detect
  const int SDCS PROGMEM = 53;      // out
  const int AFSK PROGMEM = 29;      // out Switch TX audio path
  const int PTT232 PROGMEM = 3;     // in  PTT from USB/serial interface
  const int FSKDET PROGMEM = 33;    // in  FSK detector from USB/serial interface
  const int WINKEY PROGMEM = 27;    // out disable DTR/RTS from from USB/serial interface during run winkey emulator
  const int TONE PROGMEM = 4;       // out
  const int ACC4 PROGMEM = 47;      // if enable ACC SHIFT OUT KEYBOARD
  const int ACC5 PROGMEM = 13;      // if enable ACC SHIFT OUT KEYBOARD
  const int ACC6 PROGMEM = 5;      // if enable ACC SHIFT OUT KEYBOARD
  const int ACC7 PROGMEM = 30;       // if enable ACC SHIFT IN KEYBOARD
  const int ACC8 PROGMEM = 32;
  const int ACC9 PROGMEM = 11;       // if enable ACC SHIFT IN KEYBOARD
  const int ACC10 PROGMEM = 12;      // if enable ACC SHIFT IN KEYBOARD
  const int ACC11 PROGMEM = 38;
  const int ACC12 PROGMEM = A3;
  const int ACC13 PROGMEM = A4;
  const int ACC14 PROGMEM = A8;
  const int ACC15 PROGMEM = 21;     // SCL/interrupt/ if enable ACC SHIFT OUT KEYBOARD
  const int ACC16 PROGMEM = 20;     // SDA/interrupt (was GPS PPS — free)
  const int ACC17 PROGMEM = A9;
  const int ACC19 PROGMEM = A11;    // if define Icom ACC voltage input
  const int SelfRES PROGMEM = 39;
  const int ETHINST PROGMEM = 46;     // in Ethernet module install detect
  // const int MISO = 50;
  // const int MOSI = 51;
  // const int SCK  = 52;
  const int SMTpad1 PROGMEM = 48;   // ^ Internal SMT pad
  const int SMTpad2 PROGMEM = 49;   // -
  const int SMTpad3 PROGMEM = A0;   // v
#endif

#if defined(PCB_REV_3_141)
  const int DCIN = A7;      // measure input voltage
  const int DC3V = A6;      // measure 3,3V
  const int encA = 24;      // encoder-A
  const int encB = 23;      // encoder-B
  const int MEM = A1;       // K3NG CW key button
  const int CW1 = 11;       // out
  const int CW2 = 12;       //
  const int PTT1 = 13;      //
  const int PTT2 = 22;      //
  const int PTT3 = 25;      // PTT mic
  const int MENU = 36;      // MODE button
  const int FSK = 41;       // FSK output
  const int INTERLOCK = 21; // in
  const int FootSW = 20;    // in
  const byte BCD1 = 42;     // __
  const byte BCD2 = 43;     //   |
  const byte BCD3 = 44;     //   |- band data
  const byte BCD4 = 45;     // __|  from band decoder
  const int PADDLEL = 2;    // in
  const int PADDLER = 5;    // in
  const int SEQUENCER = 40; // out
  const int PTTPA = 31;     // out PA PTT
  const int SDPLUG = A5;    // in  microSD detect
  const int SDCS = 53;      // out
  const int AFSK = 29;      // out Switch TX audio path
  const int PTT232 = 37;    // in  PTT from USB/serial interface
  const int FSKDET = 33;    // in  FSK detector from USB/serial interface
  const int WINKEY = 27;    // out disable DTR/RTS from from USB/serial interface during run winkey emulator
  const int TONE = 4;       // out
  const int ACC4 = 47;
  const int ACC5 = 13;
  const int ACC6 = 5;
  const int ACC7 = 30;
  const int ACC8 = 32;
  const int ACC9 = 11;
  const int ACC10 = 12;
  const int ACC11 = 38;
  const int ACC12 = A2;
  const int ACC13 = A3;
  const int ACC14 = A8;
  const int ACC17 = A9;
  const int ACC19 = A11;    // if define Icom ACC voltage input
#endif
const int PTTpin[4] = {0,PTT1,PTT2,PTT3};

// SETTINGS
#include <math.h>
float DCinVoltage;
float PrevDCinVoltage;
int i = 0;
int tmp = 0;
bool LcdNeedRefresh=false;

// int Loop[3] = {MODE_AFTER_POWER_UP, MENU_AFTER_POWER_UP, MENU_AFTER_POWER_UP};     //  Mode, Menu, previous Menu
int ActualModePrev = MODE_AFTER_POWER_UP;
int ActualMode = MODE_AFTER_POWER_UP;
int ActualMenu = MENU_AFTER_POWER_UP;
int ActualMenuTmp = MENU_AFTER_POWER_UP;
int PreviousMenu = MENU_AFTER_POWER_UP;

byte EncPrev=1;
byte microSD[8] = {0b00000, 0b01111, 0b01001, 0b11111, 0b01111, 0b11111, 0b11111, 0b00000};
byte Eth[8] = {0b00000, 0b00000, 0b11111, 0b10001, 0b10001, 0b11011, 0b11111, 0b00000};
//byte InterlockChar[8] = {0b11111, 0b10001, 0b11011, 0b11011, 0b11011, 0b10001, 0b11111, 0b00000};
byte InterlockChar[8] = {0b00100, 0b01010, 0b01010, 0b11111, 0b11011, 0b11011, 0b11111, 0b00000};
byte Lpipe[8] = {0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b00000};
byte Rpipe[8] = {0b11011, 0b11011, 0b11011, 0b11011, 0b11011, 0b11011, 0b11011, 0b00000};
byte delta[8] = {0B00000, 0B00000, 0B00100, 0B01010, 0B11111, 0B00000, 0B00000, 0B00000};
byte ANT[8] = {0b10101, 0b10101, 0b10101, 0b01110, 0b00100, 0b00100, 0b00100, 0b00000};
const char* modeLCD[6][3] = {
    {"|CWK", "CW keyer  ", "CW"},
    {">CWD", "PC DTR/RTS", "CW"},
    {"|SSB", "LSB/USB/FM", "SSB"},
    {">FSK", "PC DTR/RTS", "FSK"},
    {"|FSK", "Ser. ASCII", "FSK"},
    {"|DIG", "Data  AFSK", "DIG"},
};

const char* MenuTree[33] = {
  "          ",      //  0 call
  // "PCB 3.1415",      //  1
  "rev",             //  1
  "DCin",            //  2
  "3V3",             //  3
  "CAT",             //  4
  "BAUD",            //  5
  "CIV",             //  6
  "Freq",            //  7
  "BAND",            //  8
  "",                //  9
  "FSKBd",           // 10
  "<SEQ ",         // 11
  " SEQ>",         // 12
  "<PA ",          // 13
  " PA>",          // 14
  "<PTT ",         // 15
  " PTT>",         // 16
  "",                // 17  MODE fullname
  "A",               // 18  Switch bankA - eight independent ON/OFF keyboard button
  "B",               // 19  Switch bankB - one from eight keyboard button
  "C",               // 20  Switch bankC - one from up to 16 (define in IpSwBankCrange array for each band) selected with left encoder
  "Latency ",        // 21  Last Switch changed latency [ms]
  "NetID ",          // 22  Unique network ID
  "",                // 23  (was GPS time — removed)
  "",                // 24  (was UTC diff — removed)
  "",                // 25  (was SOMQ B4TX timer — removed)
  "Debug",           // 26  Debug values on Serial2
  "",                // 27  if enable, disable Interlock
  "PTTout",          // 28  PTT outputs by mode
  "IP ",             // 29  IP 1/2
  "   ",             // 30  IP 2/2
  "TrxN ",           // 31  TrxNet device name
  "Peers",           // 32  TrxNet peer count
};
int MenuTreeSize = (sizeof(MenuTree)/sizeof(char *)); //array size
int CulumnPositionEnd;

bool ModeLastButtonState = true;
bool ModeDebouncedSignal = true;
int ModeMenuStatus = 0;  // 0-MODE | 1-MENU | 2-SET
byte Ptt232Active = LOW;
byte FootSwChange = 0;
byte InterlockFromUdpActive = LOW;
//byte ptt_interlock_active = 0;  // define in K3NG code

// FSK RX
#include <FlexiTimer2.h>
bool  dsp;
byte     ti;
uint8_t  baudot;
static bool fig;
static byte    x;
static byte    y;
static char    chIn;
static char    c[21];

// FSK TX
#include <stdio.h>
int     OneBit = 1/BaudRate*1000;
bool d1;
bool d2;
bool d3;
bool d4;
bool d5;
bool space;
bool fig1;
int     fig2;
char    ch;
int     r2;
int     positionCounter = 0;  // LCD
byte LFi[8] = {0b10111,0b10111,0b10001,0b11111,0b10001,0b10111,0b10011,0b10111};
byte CRi[8] = {0b11001,0b10111,0b10111,0b11001,0b11111,0b10001,0b10111,0b10111};
byte UPi[8] = {0b11111,0b11111,0b11011,0b10001,0b00100,0b01110,0b11111,0b11111};
byte DWNi[8] = {0b11111,0b11111,0b01110,0b00100,0b10001,0b11011,0b11111,0b11111};

// ACC SHIFT OUT KEYBOARD
#define ShiftOutDataPin ACC9
#define ShiftOutLatchPin ACC7
#define ShiftOutClockPin ACC10

// ACC SHIFT IN KEYBOARD
#define ShiftInInterruptPin ACC15   // Interrupt
#define ShiftInDataPin ACC5
#define ShiftInLatchPin ACC4
#define ShiftInClockPin ACC6
bool rxShiftInRead;
byte rxShiftInButton[3]{0,0,0};  // three button bank: 1-8 switch, 9-16 one from, encoder...

// BAND DECODER
int BAND;
unsigned long freq = 0;
unsigned long prevfreq=1;
unsigned long lastFreqChangeAt = 0;   // millis() of last detected freq/mode change — adaptive polling tracker
// #if defined(ICOM_ACC)
    const int AD PROGMEM = ACC19;
    int VALUE = 0;
    int prevVALUE=0;
    float VOLTAGE = 0;
    int band = 0;
    int counter = 0;
// #endif
// #if defined(YAESU_BCD)
    bool YBCD1;
    bool YBCD2;
    bool YBCD3;
    bool YBCD4;
    int bandBCD;
// #endif
// #if defined(KENWOOD_PC) || defined(YAESU_CAT)
    int lf = 59;  // 59 = ;
// #endif
// #if defined(KENWOOD_PC)
    char rdK[37];   //read data kenwood
    String rdS;    //read data kenwood string
// #endif
// #if defined(YAESU_CAT)
    char rdY[37];   //read data yaesu
    // String rdYS;    //read data yaesu string
// #endif
// #if defined(YAESU_CAT_OLD)
    byte rdYO[37];   //read data yaesu
    // String rdYOS;    //read data yaesu string
// #endif
// #if defined(ICOM_CIV) || defined(ICOM_CIV_OUT)
    int fromAdress = 14;              // 0E
    byte rdI[10];   //read data icom
    // String rdIS;    //read data icom string
    unsigned long freqPrev1;
    byte incomingByte = 0;
    int stateMachine = 1;  // state machine
// #endif
// #if defined(KENWOOD_PC_OUT) || defined(YAESU_CAT_OUT)
    unsigned long freqPrev2;
// #endif
// #if defined(BCD_OUT)
    char BCDout;
    bool BCDmatrixOUT[4][11] = { /*
    --------------------------------------------------------------------
    Band # to output relay   0   1   2   3   4   5   6   7   8   9  10
    (Yaesu BCD)                 160 80  40  30  20  17  15  12  10  6m
    --------------------------------------------------------------------
                             |   |   |   |   |   |   |   |   |   |   |
                             V   V   V   V   V   V   V   V   V   V   V
                        */ { 0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0 }, /* --> BCD1
                        */ { 0,  0,  1,  1,  0,  0,  1,  1,  0,  0,  1 }, /* --> BCD2
                        */ { 0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0 }, /* --> BCD3
                        */ { 0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1 }, /* --> BCD4
    */};


    unsigned long StorageFreqToStep[23][5] = {/*
                      stepper    LC impedance
          Freq Hz     0     1    H/L  0 = LC, 1 = CL
    */   //{1800000,    30,  4300,   1},
         // {2000000,    30,  3600,   1},
//                   C-0    L-1   C0   L1
         {1800000,   120,  3360,   0,   0},
         {2000000,   120,  3360,   0,   0},

         {3500000,   120,    20,   0,   0},
         {3800000,   120,    20,   0,   0},
         // {3500000,   120,   700,   1,   0},
         // {3800000,   120,   700,   1,   0},

         {7000000,   120,  1395,   0,   0},
         {7200000,   120,  1395,   0,   0},

    };
    int NumberOfMemory = ( sizeof(StorageFreqToStep) / sizeof(StorageFreqToStep[0]) ); //array size

// #endif
// #OI3 variables END

/*---------------------------------------------------------------------------------------------------------


                                    this code is a work of art.  enjoy.


---------------------------------------------------------------------------------------------------------*/

void setup()
{

  initialize_pins();
  initialize_keyer_state();
  initialize_rotary_encoder();
  initialize_default_modes();
  check_eeprom_for_initialization();
  check_for_debug_modes();
  initialize_analog_button_array();
  initialize_display();
  initialize_debug_startup();


//---------------------------------------------------------------------------------------------------------
  // #OI3 SETUP
  YOUR_CALL.reserve(10);
  ConfigFile.reserve(7);
  rdS.reserve(128);
  // FSKmemory.reserve(40);


  // Menu
  pinMode(DCIN, INPUT);
  pinMode(DC3V, INPUT);
  pinMode(encA, INPUT);
    digitalWrite (encA, HIGH);            // pull up
  pinMode(encB, INPUT);
    digitalWrite (encB, HIGH);            // pull up
  pinMode(MEM, INPUT);
  pinMode(MENU, INPUT);
  pinMode(INTERLOCK, INPUT);
  pinMode(FootSW, INPUT);
  pinMode(PADDLEL, INPUT);
  pinMode(PADDLER, INPUT);
  if (BAND_DECODER_IN == 6){  // YAESU_BCD
    pinMode(BCD1, INPUT);
    pinMode(BCD2, INPUT);
    pinMode(BCD3, INPUT);
    pinMode(BCD4, INPUT);
  }else{
    pinMode(BCD1, OUTPUT);
    pinMode(BCD2, OUTPUT);
    pinMode(BCD3, OUTPUT);
    pinMode(BCD4, OUTPUT);
  }
  pinMode(SDPLUG, INPUT);
    digitalWrite (SDPLUG, HIGH);            // pull up
  pinMode(PTT232, INPUT);
  pinMode(FSKDET, INPUT);

  pinMode(CW1, OUTPUT);
  pinMode(CW2, OUTPUT);
  pinMode(PTT1, OUTPUT);
  pinMode(PTT2, OUTPUT);
  pinMode(PTT3, OUTPUT);
  pinMode(FSK, OUTPUT);
  pinMode(SEQUENCER, OUTPUT);
  pinMode(PTTPA, OUTPUT);
  pinMode(SDCS, OUTPUT);
  pinMode(AFSK, OUTPUT);
  pinMode(WINKEY, OUTPUT);
    digitalWrite (WINKEY, HIGH);
  pinMode(TONE, OUTPUT);
  pinMode(SMTpad1, INPUT);
    digitalWrite (SMTpad1, HIGH);
  pinMode(SMTpad2, INPUT);
    digitalWrite (SMTpad2, HIGH);
  pinMode(SMTpad3, INPUT);
    digitalWrite (SMTpad3, HIGH);
  // FSK TX
  digitalWrite(FSK, LOW);
  lcd.createChar(0, CRi);
  lcd.createChar(1, LFi);
  lcd.createChar(2, UPi);
  lcd.createChar(3, DWNi);
  // FSK RX
  FlexiTimer2::set(1, timer_interrupt);
  FlexiTimer2::start();
  // BAND DECODER
  if (BAND_DECODER_IN > 0 && BAND_DECODER_IN < 4){  // YAESU_CAT_OLD
      Serial2.begin(SERBAUD2);
      Serial2.setTimeout(10);
  }else if (BAND_DECODER_IN == 4){  // YAESU_CAT_OLD
      Serial2.begin(SERBAUD2, SERIAL_8N2);
      Serial2.setTimeout(10);
  }else{
    Serial2.begin(SERBAUD2);
  }

  // #if defined(KENWOOD_PC) || defined(YAESU_CAT)
      //CATdata.reserve(200);          // reserve bytes for the CATdata
  // #endif

  // other
  lcd.createChar(4, microSD);
  lcd.createChar(5, InterlockChar);
  // lcd.createChar(6, Eth);
  lcd.createChar(7, ANT);
  // lcd.createChar(6, Lpipe);
  // lcd.createChar(7, Rpipe);
  // lcd.createChar(8, delta);
  lcd.begin(16, 2);
  lcd.setCursor(2, 1);
//            lcd.print((char)188);
//            lcd.print((char)199);
//            lcd.print((char)246);
//            lcd.print(F(" 14.023,22"));

  // CWK - loop1 preset
  digitalWrite (WINKEY, HIGH);  // disable DTR/RTS
  digitalWrite (AFSK, LOW);

  //microSD
  tmp = analogRead(MEM);

  if(tmp < 5){
    ConfigFile = "oi1.cfg";
  }else if(tmp > 45 && tmp < 130){
    ConfigFile = "oi2.cfg";
  }else if(tmp > 130 && tmp < 210){
    ConfigFile = "oi3.cfg";
  }else if(digitalRead(MENU)==LOW){
    ConfigFile = "oi4.cfg";
  }else{
    ConfigFile = "oi0.cfg";
  }
  lcd.setCursor(0, 1);
  if(analogRead(SDPLUG)>128){    // microSD unplug
    lcd.print(F(" micro SD card  "));
    lcd.setCursor(0, 1);
    delay(100);
    lcd.print(F(" not present   "));
    delay(500);
  }else{
    if (!SD.begin(SDCS)) {
      lcd.print(F("Init SDcard fail"));
      delay(1000);
      return;
    }else{
      lcd.print(F("Init SDcard done"));
      lcd.setCursor(0, 1);

      // Debug list files
      // myFile = SD.open("/");
      // printDirectory(myFile, 0);

      ConfigFile.toCharArray(charConfigFile, sizeof(charConfigFile));
      if (SD.exists(charConfigFile)){
        lcd.print(F("load "));
        lcd.print(ConfigFile);
        lcd.print(F("    "));

        readSDSettings();
    	  // initBanksFromSDCarsd();
    	  // ip[0] = getStringPartByNr(deviceIp, '.', 0).toInt();
    	  // ip[1] = getStringPartByNr(deviceIp, '.', 1).toInt();
    	  // ip[2] = getStringPartByNr(deviceIp, '.', 2).toInt();
    	  // ip[3] = getStringPartByNr(deviceIp, '.', 3).toInt();
        //
    	  // gateway[0] = getStringPartByNr(gatewayIp, '.', 0).toInt();
    	  // gateway[1] = getStringPartByNr(gatewayIp, '.', 1).toInt();
    	  // gateway[2] = getStringPartByNr(gatewayIp, '.', 2).toInt();
    	  // gateway[3] = getStringPartByNr(gatewayIp, '.', 3).toInt();

      } else {
        lcd.print(ConfigFile);
        lcd.print(F(" no found"));
        // open a new file and immediately close it:
        // Serial.println(" - creating cfg file");
        // myFile = SD.open("oi3.cfg", FILE_WRITE);
        // myFile.close();
      }
      delay(1000);
    }

    // myFile = SD.open("oi3.cfg", FILE_WRITE);
    // if(myFile){
    //   myFile.println("#");
    // }
    // myFile.close();
  }

  // ACC KEYBOARD
  if(ACC_KEYBOARD == 1){
    // SHIFT OUT
    pinMode(ShiftOutLatchPin, OUTPUT);
    pinMode(ShiftOutClockPin, OUTPUT);
    pinMode(ShiftOutDataPin, OUTPUT);
    // SHIFT IN
    pinMode (ShiftInInterruptPin, INPUT);
    pinMode(ShiftInLatchPin, OUTPUT);
    pinMode(ShiftInClockPin, OUTPUT);
    pinMode(ShiftInDataPin, INPUT);
  }

  // ETHERNET - UDP (init handled inside EthernetCheck() on link-up)
  if (EnableEthernet==1){
    IdBySmtPad();
    LastMac = 0xFF - NET_ID;
    mac[5] = LastMac;
    EthernetCheck();
  }

  #if defined(ICOM_CIV_OUT) || defined(KENWOOD_PC_OUT) || defined(YAESU_CAT_OUT) || defined(YAESU_CAT_OUT_OLD)
    Serial3.begin(SERBAUD3);
  #endif

  SwitchHardware(MODE_AFTER_POWER_UP);
  InterruptON(1,1,1); // keyb, enc, gps=off (removed), Interlock

  YOUR_CALL.toCharArray(MenuTree[0], 10);

  // #ifdef FEATURE_COMMAND_LINE_INTERFACE
  //   Serial.begin(SERBAUD0);
    Serial.begin(115200);
  // #endif
} // SETUP END

//-------------------------------------------------------------------------------------------------------

void loop() {
  if( PttActive==false ){
    EthernetCheck();
    if (EnableEthernet==1 && EthLinkStatus==1) net.loop();
    // TrxNet pending commands from callbacks
    if (trxFreqPending) {
      trxFreqPending = false;
      freq = (long)trxPendingHz;
      FreqToBandRules(freq);
      bandSET();
      // Event-driven CIV SET to radio — only on network /s-hz, never on local read (no feedback loop)
      txCIVoutSub(0x07, 0xD2, 0x00, CIV_ADRESS);              // select MAIN band (IC-7610)
      txCIVout(5, freq, CIV_ADRESS);                          // 5 = set operating frequency
      { uint32_t _f = (uint32_t)freq; net.publish("/hz", (uint8_t*)&_f, sizeof(_f)); }
    }
    if (trxModePending) {
      trxModePending = false;
      ActualMode = trxPendingMode;
      ActualModePrev = ActualMode;
      { uint8_t _m = oi3ModeToCiv(ActualMode); net.publish("/mode", &_m, sizeof(_m)); }
      SwitchHardware(ActualMode);
      // Event-driven CIV SET to radio — only on network /s-mode
      txCIVoutSub(0x07, 0xD2, 0x00, CIV_ADRESS);              // select MAIN band (IC-7610)
      txCIVoutSub(0x06, trxPendingCivMode, 0x01, CIV_ADRESS); // set mode using original CI-V byte
    }
    // Drain greeting queue — one peer per loop() iteration so _pending stays
    // bounded (each peer enqueues 2 CON slots; processing serially leaves
    // room for retries and avoids overflowing the 4-slot pending buffer).
    // Defer until freq != 0 so peers don't receive a /hz=0 snapshot before
    // the first CAT response has populated the keyer's state.
    if (trxPendingGreetCount > 0 && EnableEthernet==1 && EthLinkStatus==1 && freq != 0) {
      trxPendingGreetCount--;
      republishState(trxPendingGreet[trxPendingGreetCount]);
    }
    // Adaptive band-decoder polling — return to SLOW after ACTIVITY_HOLD ms of no change
    if (Timeout[4][1] != BAND_DECODER_REQUEST &&
        (millis() - lastFreqChangeAt) > BAND_DECODER_ACTIVITY_HOLD) {
      Timeout[4][1] = BAND_DECODER_REQUEST;
    }
    if (trxCwPending) {
      trxCwPending = false;
      InterruptON(0,0,0); // keyb, enc, gps, Interlock — prevent INTERLOCK ISR during TX
      if (ActualMode == 3 || ActualMode == 4) {
        FSKmemory[0] = trxPendingCW;
        FSKmemoryTX(0);
      } else if (ActualMode == 0 || ActualMode == 1) {
        trxCwAbort = false;
        ptt_high(PTTbyMode[ActualMode]);
        for (int _i = 0; trxPendingCW[_i] != '\0'; _i++) {
          if (EnableEthernet==1 && EthLinkStatus==1) net.loop(); // ACK CON retransmits + handle abort
          if (trxCwAbort) { trxCwAbort = false; break; }
          send_char(toUpperCase(trxPendingCW[_i]), KEYER_NORMAL);
        }
        ptt_low(PTTbyMode[ActualMode], 4);
      }
      InterruptON(1,1,1); // keyb, enc, gps, Interlock
    }
    BandDecoder();
    DCinMeasure();
    OpenInterfaceLCD();   // second line print
    OpenInterfaceMENU();  // Menu button and HW preset
    IncomingUDP();        // Incomming UDP command and transmit characters
    RemoteSwQuery();
    Watchdogs();
  }
  OpenInterfaceMODE();  // MODE in->out and features
  OpenInterfaceSequencer();
}    // end loop

// SUBROUTINES ---------------------------------------------------------------------------------------------------------
// http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/

void Watchdogs(){
}
//-------------------------------------------------------------------------------------------------------
void IdBySmtPad(){
  if(NET_ID==0xff){
    NET_ID = 0;
    if(digitalRead(SMTpad1)==0){
      NET_ID = NET_ID | (1<<0);    // Set the n-th bit
    }
    if(digitalRead(SMTpad2)==0){
      NET_ID = NET_ID | (1<<1);    // Set the n-th bit
    }
    if(digitalRead(SMTpad3)==0){
      NET_ID = NET_ID | (1<<2);    // Set the n-th bit
    }
  }
}

//-------------------------------------------------------------------------------------------------------
void AccKeyboardShift(){    // run from interrupt
  if(DetectedRemoteSw[BandToRemoteSwitchID[BAND]][4]!=0 && SequencerLevel == 0){       // if detect IP Switch for this band and PTT OFF
    digitalWrite(ShiftInLatchPin,1);   //Set latch pin to 1 to get recent data into the CD4021
    delayMicroseconds(15);
    digitalWrite(ShiftInLatchPin,0);     //Set latch pin to 0 to get data from the CD4021
    for (int i=1; i<17; i++){                // 16 = two bank
      digitalWrite(ShiftInClockPin, 0);
      rxShiftInRead = digitalRead(ShiftInDataPin);
        switch (rxShiftInRead) {
          case 1:
              switch (i) {
                case 1: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<7); break;  // invert n-th bit
                case 2: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<6); break;
                case 3: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<5); break;
                case 4: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<4); break;
                case 5: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<3); break;
                case 6: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<2); break;
                case 7: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<1); break;
                case 8: rxShiftInButton[0] = rxShiftInButton[0] ^ (1<<0); break;
                case  9: rxShiftInButton[1] = B10000000; break;                   // set n-th bit
                case 10: rxShiftInButton[1] = B01000000; break;
                case 11: rxShiftInButton[1] = B00100000; break;
                case 12: rxShiftInButton[1] = B00010000; break;
                case 13: rxShiftInButton[1] = B00001000; break;
                case 14: rxShiftInButton[1] = B00000100; break;
                case 15: rxShiftInButton[1] = B00000010; break;
                case 16: rxShiftInButton[1] = B00000001; break;
                default:
                  // if nothing else matches, do the default
                break;
              }
            break;
          case 0: break;
        }
        digitalWrite(ShiftInClockPin, 1);
    }
    Debugging("BAND: "+String(BAND));

    for (i = 0; i < 10; i++) {
      Debugging(String(i)+String(DetectedRemoteSw [i] [0])+"."+String(DetectedRemoteSw [i] [1])+"."+String(DetectedRemoteSw [i] [2])+"."+String(DetectedRemoteSw [i] [3])+":"+String(DetectedRemoteSw [i] [4]));
    }
    Debugging("  "+String(RemoteSwIP)+":"+String(RemoteSwPort)+"  ->  ");

    // SET IP:PORT from array by relay ID (id = rows)
    // RemoteSwIP = DetectedRemoteSw[packetBuffer[3]];
    // RemoteSwPort = DetectedRemoteSw[packetBuffer[3]][4];
    RemoteSwIP = DetectedRemoteSw[BandToRemoteSwitchID[BAND]];
    RemoteSwPort = DetectedRemoteSw[BandToRemoteSwitchID[BAND]][4];

    Debugging(String(RemoteSwIP)+":"+String(RemoteSwPort));

    // UDP send to Switch
    if(EnableEthernet == 1 && RemoteSwitch == 1 && EthLinkStatus==1){
      TxUdpBuffer[0] = B01110011;         // s
      TxUdpBuffer[1] = B00111010;         // :
      TxUdpBuffer[2] = rxShiftInButton[0];  // set buffer
      TxUdpBuffer[3] = rxShiftInButton[1];
      TxUdpBuffer[4] = rxShiftInButton[2];
      TxUdpBuffer[5] = B00111011;         // ;
      UdpCommand.beginPacket(RemoteSwIP, RemoteSwPort);
        UdpCommand.write(TxUdpBuffer, sizeof(TxUdpBuffer));   // send buffer
        RemoteSwLatency[0] = millis(); // set START time mark UDP command latency
      UdpCommand.endPacket();
      RemoteSwLatencyAnsw = 0;   // send command, wait to answer
    }



    // SHIFT OUT
    if(KeyboardAnswLed==0){
      digitalWrite(ShiftOutLatchPin, LOW);  // ready for receive data
      // shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, rxShiftInButton[2]);    // bank2
      shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, rxShiftInButton[1]);    // bank1
      shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, rxShiftInButton[0]);    // bank0
      digitalWrite(ShiftOutLatchPin, HIGH);    // switch to output pin
    }
    LcdNeedRefresh=true;
  }
}
//-------------------------------------------------------------------------------------------------------
void InterruptON(int keyb, int enc, int interlock){

  if(keyb==0){
    detachInterrupt(digitalPinToInterrupt(ShiftInInterruptPin));
  }else if(keyb==1){
    attachInterrupt(digitalPinToInterrupt(ShiftInInterruptPin), AccKeyboardShift, RISING);  // need detachInterrupt in IncomingUDP() subroutine
  }

  if(enc==0){
    detachInterrupt(digitalPinToInterrupt(encB));
  }else if(enc==1){
    attachInterrupt(digitalPinToInterrupt(encB), EncoderInterrupt, FALLING);
  }

  if(interlock==0){
    detachInterrupt(digitalPinToInterrupt(INTERLOCK));
  }else if(interlock==1){
    attachInterrupt(digitalPinToInterrupt(INTERLOCK), OpenInterfaceInterlock, CHANGE);
  }
}
//-------------------------------------------------------------------------------------------------------
// ENCODER
void MenuEncoder(){
  if(ActualMenu!=20 || ModeMenuStatus > 0 || DetectedRemoteSw[BandToRemoteSwitchID[BAND]+8][4]==0){   // for menu 20 activate interrupt encoder
    if(digitalRead(encB) == LOW && EncPrev == 1){
      if(ModeMenuStatus<=1){
        if(digitalRead(encA) == LOW){
          ActualMenu++;
          if(ActualMenu > MenuTreeSize-1){
            ActualMenu=0;
          }
        }else{
          ActualMenu--;
          if(ActualMenu < 0){
            ActualMenu=MenuTreeSize-1;
          }
        }
        EncPrev=0;
      }

      if(ModeMenuStatus==2){
        int step = 1;
        if(analogRead(MEM)<210){
          step = 10;
        }
        switch (ActualMenu) {
          case 6:{ // CI-V address
            if(digitalRead(encA)==LOW){CIV_ADRESS+=step;}else{CIV_ADRESS-=step;};
          break;
          }
          case 11:{ // SEQ Lead
            if(digitalRead(encA)==LOW){SEQUENCERlead+=step;}else{SEQUENCERlead-=step;};
          break;
          }
          case 12:{ // SEQ tail
            if(digitalRead(encA)==LOW){SEQUENCERtail+=step;}else{SEQUENCERtail-=step;};
          break;
          }
          case 13:{ // PA Lead
            if(digitalRead(encA)==LOW){PAlead+=step;}else{PAlead-=step;};
          break;
          }
          case 14:{ // PA tail
            if(digitalRead(encA)==LOW){PAtail+=step;}else{PAtail-=step;};
          break;
          }
          case 15:{ // PTT Lead
            if(digitalRead(encA)==LOW){PTTlead+=step;}else{PTTlead-=step;};
          break;
          }
          case 16:{ // PTT tail
            if(digitalRead(encA)==LOW){PTTtail+=step;}else{PTTtail-=step;};
          break;
          }
          case 22:{ // Network ID
            if(digitalRead(encA)==LOW){NET_ID+=step;}else{NET_ID-=step;};
          break;
          }
          case 26:{ // Debug on Serial2
            if(digitalRead(encA)==LOW){DebuggingOutput+=step;}else{DebuggingOutput-=step;};
            if(DebuggingOutput>3){
              DebuggingOutput=0;
            }
            if(DebuggingOutput<0){
              DebuggingOutput=3;
            }
          break;
          }
          case 27:{ // PTTin
            if(digitalRead(encA)==LOW){InterlockEnable=!InterlockEnable;}else{InterlockEnable=!InterlockEnable;};
          break;
          }
          case 28:{ // PTT outputs
            if(digitalRead(encA)==LOW){
              PTTbyMode[ActualMode]++;
            }else{
              PTTbyMode[ActualMode]--;
            };
            if(PTTbyMode[ActualMode]>3){
              PTTbyMode[ActualMode]=1;
            }
            if(PTTbyMode[ActualMode]<1){
              PTTbyMode[ActualMode]=3;
            }
          break;
          }
        }
        EncPrev=0;
      }
      LcdNeedRefresh=true;
    }else  if(digitalRead(encB) == HIGH && EncPrev == 0){
      EncPrev=1;
    }
  }
}
//-------------------------------------------------------------------------------------------------------
// WPM change via encoder — ISR-driven (encB FALLING). EncoderInterrupt queues +/-1 in wpm_pending,
// WpmEncoder drains the queue in main loop and applies via speed_change (which does LCD update).
// ISR-level micros() debounce filters mechanical contact bounce.
volatile int8_t wpm_pending = 0;
volatile unsigned long last_enc_isr_us = 0;

void WpmEncoder(){
  int8_t step;
  noInterrupts();
  step = wpm_pending;
  wpm_pending = 0;
  interrupts();

  if (step == 0) return;

  int sign = (step > 0) ? 1 : -1;
  int remaining = (step > 0) ? step : -step;
  while (remaining-- > 0){
    speed_change(sign);
  }
}
//-------------------------------------------------------------------------------------------------------
// ToDo: udp send only if IpSwitchEncoder variable change
void EncoderInterrupt(){
  // ISR-level debounce — ignore re-fires within 2ms (mechanical contact bounce)
  unsigned long now_us = micros();
  if (now_us - last_enc_isr_us < 2000) return;
  last_enc_isr_us = now_us;

  if(ActualMenu==20 && DetectedRemoteSw[BandToRemoteSwitchID[BAND]+8][4]!=0 && SequencerLevel == 0 && ModeMenuStatus == 0 && DetectedRemoteSw[BandToRemoteSwitchID[BAND]+8][4]!=0){       // if detect IP Switch for this band and PTT OFF
    // int IpSwBankCrange[8]= {
    // int IpSwitchEncoder;
    // byte IpSwitchBankC[2];
    if(digitalRead(encA) == LOW){
      IpSwitchEncoder++;
        if(IpSwitchEncoder > IpSwBankCrange[BandToRemoteSwitchID[BAND]]-1){
          // IpSwitchEncoder=0;
          IpSwitchEncoder=IpSwBankCrange[BandToRemoteSwitchID[BAND]]-1;
        }
    }else{
      IpSwitchEncoder--;
        if(IpSwitchEncoder < 0){
          // IpSwitchEncoder=IpSwBankCrange[BandToRemoteSwitchID[BAND]]-1;
          IpSwitchEncoder=0;
        }
    }
    RemoteSwIP = DetectedRemoteSw[BandToRemoteSwitchID[BAND]+8];
    RemoteSwPort = DetectedRemoteSw[BandToRemoteSwitchID[BAND]+8][4];
    // UDP send to Switch
    if(EnableEthernet == 1 && EthLinkStatus==1){
      TxUdpBuffer[2] = 0;
      TxUdpBuffer[3] = 0;
      TxUdpBuffer[0] = B01110011;         // s
      TxUdpBuffer[1] = B00111010;         // :
      if(IpSwitchEncoder<8){
        TxUdpBuffer[2] = TxUdpBuffer[2] | (1<<IpSwitchEncoder); // set n-th bit
      }else{
        TxUdpBuffer[3] = TxUdpBuffer[3] | (1<<(IpSwitchEncoder-8)); // set n-th bit
      }
      TxUdpBuffer[4] = B00111011;         // ;
      TxUdpBuffer[5] = 0;
      UdpCommand.beginPacket(RemoteSwIP, RemoteSwPort);
        UdpCommand.write(TxUdpBuffer, sizeof(TxUdpBuffer));   // send buffer
        RemoteSwLatency[0] = millis(); // set START time mark UDP command latency
      UdpCommand.endPacket();
      RemoteSwLatencyAnsw = 0;   // send command, wait to answer
    }


    LcdNeedRefresh=true;
  } else if (ModeMenuStatus == 0 && ActualMenu != 20) {
    // WPM change on main screen — read direction from encA (fresh after edge, before bounce)
    if (digitalRead(encA) == LOW) {
      if (wpm_pending < 100) wpm_pending++;
    } else {
      if (wpm_pending > -100) wpm_pending--;
    }
  }
}
//-------------------------------------------------------------------------------------------------------
void readSDSettings(){
 char character;
 String settingName;
 settingName.reserve(20);
 String settingValue;
 settingValue.reserve(10);
 myFile = SD.open(charConfigFile);
 if (myFile){
	while (myFile.available()){
		character = myFile.read();
		while((myFile.available()) && (character != '[')){
			character = myFile.read();
		}
		character = myFile.read();
		while((myFile.available()) && (character != '=')){
			settingName = settingName + character;
			character = myFile.read();
		}
		character = myFile.read();
		while((myFile.available()) && (character != ']')){
			settingValue = settingValue + character;
			character = myFile.read();
		}
		if(character == ']'){

    Debugging("["+String(settingName)+"="+String(settingValue)+"]");

      if(settingName == "NET_ID"){
        // NET_ID = (byte)settingValue.toInt();
        unsigned char buff[3];
        settingValue.toCharArray(buff, 3);
        NET_ID = hexToDecBy4bit(buff[0])<<4 | hexToDecBy4bit(buff[1]);
      }else if(settingName == "YOUR_CALL"){
        YOUR_CALL = String(settingValue);
      }else if(settingName == "InterlockEnable"){
        InterlockEnable = (bool)settingValue.toInt();
      }else if(settingName == "SEQUENCERlead"){
        SEQUENCERlead = settingValue.toInt();
      }else if(settingName == "SEQUENCERtail"){
        SEQUENCERtail = settingValue.toInt();
      }else if(settingName == "PAlead"){
        PAlead = settingValue.toInt();
      }else if(settingName == "PAtail"){
        PAtail = settingValue.toInt();
      }else if(settingName == "PTTlead"){
        PTTlead = settingValue.toInt();
      }else if(settingName == "PTTtail"){
        PTTtail = settingValue.toInt();
      }else if(settingName == "BAND_DECODER_IN"){
        BAND_DECODER_IN = (int)settingValue.toInt();
      }else if(settingName == "SERBAUD2"){
        SERBAUD2 = (unsigned long)settingValue.toInt();
      }else if(settingName == "CIV_ADRESS"){
        // CIV_ADRESS = settingValue.toInt();
        unsigned char buf[3];
        settingValue.toCharArray(buf, 3);
        CIV_ADRESS = hexToDecBy4bit(buf[0])<<4 | hexToDecBy4bit(buf[1]);
      }else if(settingName == "EthernetEnable"){
        EnableEthernet = (bool)settingValue.toInt();
      }else if(settingName == "MODE_AFTER_POWER_UP"){
        MODE_AFTER_POWER_UP = (int)settingValue.toInt();
      }else if(settingName == "MENU_AFTER_POWER_UP"){
        MENU_AFTER_POWER_UP = (int)settingValue.toInt();
      }else if(settingName == "PTTmodeCW"){
        PTTmodeCW = (int)settingValue.toInt();
        PTTbyMode[0]=PTTmodeCW;
        PTTbyMode[1]=PTTmodeCW;
      }else if(settingName == "PTTmodeSSB"){
        PTTmodeSSB = (int)settingValue.toInt();
        PTTbyMode[2]=PTTmodeSSB;
      }else if(settingName == "PTTmodeFSK"){
        PTTmodeFSK = (int)settingValue.toInt();
        PTTbyMode[3]=PTTmodeFSK;
        PTTbyMode[4]=PTTmodeFSK;
      }else if(settingName == "PTTmodeDIGI"){
        PTTmodeDIGI = (int)settingValue.toInt();
        PTTbyMode[5]=PTTmodeDIGI;
      }else if(settingName == "DebuggingOutput"){
        DebuggingOutput = (int)settingValue.toInt();
      }else if(settingName == "TrxNet_port"){
        trxPort = (uint16_t)settingValue.toInt();
      }

      // byte ip0 = getPartOfStringBySeperatorAndAppearance(deviceIp, '.', 0).toInt();
      // byte ip1 = getPartOfStringBySeperatorAndAppearance(deviceIp, '.', 1).toInt();
      // byte ip2 = getPartOfStringBySeperatorAndAppearance(deviceIp, '.', 2).toInt();
      // byte ip3 = getPartOfStringBySeperatorAndAppearance(deviceIp, '.', 3).toInt();
      // IPAddress ip(ip0, ip1, ip2, ip3);
      // String getPartOfStringBySeperatorAndAppearance(String data, char separator, int index)
      // {
      //   int stringData = 0;
      //   String dataPart = "";
      //   for(int i = 0; i<data.length(); i++)
      //   {
      //     if(data[i]==separator)
      //       stringData++;
      //     else if(stringData==index)
      //       dataPart.concat(data[i]);
      //     else if(stringData>index)
      //     {
      //       return dataPart;
      //       break;
      //     }
      //   }
      //   return dataPart;
      // }


			// else if(settingName == "ajaxUrl")
			// 	ajaxUrl = settingValue;
			// else if(settingName == "deviceIp")
			// 	deviceIp = settingValue;
			// else if (settingName == "gatewayIp")
			// 	gatewayIp = settingValue;
			// else if (settingName == "title")
			// 	title = settingValue;
			// else if (settingName == "jsUrl")
			// 	jsUrl = settingValue;
			// else if (settingName == "cssUrl")
			// 	cssUrl = settingValue;
			// else if (settingName == "faviconUrl")
			// 	faviconUrl = settingValue;
			// else if (settingName == "dotUrl")
			// 	dotUrl = settingValue;
			// else if (settingName == "jqueryUrl")
			// 	jqueryUrl = settingValue;
			// else if (settingName == "strpinsBank0")
			// 	strpinsBank0 = settingValue;
			// else if (settingName == "strpinsBank1")
			// 	strpinsBank1 = settingValue;
			// else if (settingName == "strpinsBank2")
			// 	strpinsBank2 = settingValue;
			// else if (settingName == "strpinsBank3")
			// 	strpinsBank3 = settingValue;
			// else if (settingName == "stris5sPinBank0")
			// 	stris5sPinBank0 = settingValue;
			// else if (settingName == "stris5sPinBank1")
			// 	stris5sPinBank1 = settingValue;
			// else if (settingName == "stris5sPinBank2")
			// 	stris5sPinBank2 = settingValue;
			// else if (settingName == "stris5sPinBank3")
			// 	stris5sPinBank3 = settingValue;
			// else if (settingName == "strisOffPinBank0")
			// 	strisOffPinBank0 = settingValue;
			// else if (settingName == "strisOffPinBank1")
			// 	strisOffPinBank1 = settingValue;
			// else if (settingName == "strisOffPinBank2")
			// 	strisOffPinBank2 = settingValue;
			// else if (settingName == "strisOffPinBank3")
			// 	strisOffPinBank3 = settingValue;
			// else if (settingName == "strindexOfOffPinPairBank0")
			// 	strindexOfOffPinPairBank0 = settingValue;
			// else if (settingName == "strindexOfOffPinPairBank1")
			// 	strindexOfOffPinPairBank1 = settingValue;
			// else if (settingName == "strindexOfOffPinPairBank2")
			// 	strindexOfOffPinPairBank2 = settingValue;
			// else if (settingName == "strindexOfOffPinPairBank3")
			// 	strindexOfOffPinPairBank3 = settingValue;
			// else if (settingName == "strpushDurationBank0")
			// 	strpushDurationBank0 = settingValue;
			// else if (settingName == "strpushDurationBank1")
			// 	strpushDurationBank1 = settingValue;
			// else if (settingName == "strpushDurationBank2")
			// 	strpushDurationBank2 = settingValue;
			// else if (settingName == "strpushDurationBank3")
			// 	strpushDurationBank3 = settingValue;
			// else if (settingName == "strToken")
			// 	settingValue.toCharArray(charToken,17);
			// else if (settingName == "intSalt")
			// 	salt = settingValue.toInt();

			settingName = "";
			settingValue = "";
		}
	} // end while
	myFile.close();
  SetVariables();   //  re-initialize variables
 }else{
 // if the file didn't open, print an error:
	//Serial.println("error opening settings.txt");
 }
 }

 //-------------------------------------------------------------------------------------------------------
  void SetVariables(){
    Serial2.end();
    delay(50),
    Serial2.begin(SERBAUD2);
    ActualMode = MODE_AFTER_POWER_UP;     //  Mode
    ActualMenu = MENU_AFTER_POWER_UP;     //  Menu
    ActualMenuTmp = MENU_AFTER_POWER_UP;     //  Menu
    PreviousMenu = MENU_AFTER_POWER_UP;     //  previous Menu
    YOUR_CALL.toCharArray(MenuTree[0], 10);
             // 0 reserve for incoming UDP string
      FSKmemory[1]= {" cq de "+YOUR_CALL+" "+YOUR_CALL+" k "};  // Memory 0 button
      FSKmemory[2]= {" "+YOUR_CALL+" "};                        // Memory 1 button
      FSKmemory[3]= {" 599 15 "};                               // Memory 2 button
      FSKmemory[4]= {" "+YOUR_CALL+" "};                        // Memory CW Left paddle
      FSKmemory[5]= {" "+YOUR_CALL+" "+YOUR_CALL+" test"};                        // Memory CW Right paddle
  }
//-------------------------------------------------------------------------------------------------------
/*void printDirectory(File dir, int numTabs) {
    while (true) {

      File entry =  dir.openNextFile();
      if (! entry) {
        // no more files
        break;
      }
      // for (uint8_t i = 0; i < numTabs; i++) {
      //   Serial.print('\t');
      // }
      Serial.print(entry.name());
      if (entry.isDirectory()) {
        // Serial.println("/");
        // printDirectory(entry, numTabs + 1);
      } else {
        // files have sizes, directories do not
        Serial.print(F("\t\t"));
        Serial.println(entry.size(), DEC);
      }
      entry.close();
    }
  }*/
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
void OpenInterfaceInterlock(){      // activate from interrupt

  if(InterlockEnable==true){   // interlock
    if (digitalRead(INTERLOCK) == ptt_interlock_active && InterlockFromUdpActive == LOW) {   // if change and not active from UDP
      ptt_interlock_active = ptt_interlock_active ^ 1;        // ivert
      if(ptt_interlock_active == 1  && SequencerLevel != 0){
        digitalWrite (SEQUENCER, LOW);  // SEQUENCER
        digitalWrite (PTTPA, LOW);      // PTT-PA
        digitalWrite (PTTpin[1], LOW);
        digitalWrite (PTTpin[2], LOW);
        digitalWrite (PTTpin[3], LOW);
        ptt_low(PTTbyMode[ActualMode],1);
        // OpenInterfaceSequencer();
        // OpenInterfaceSequencer();
        send_buffer_bytes=0;
      }
      Debugging("Interlock-" + String(ptt_interlock_active) + " " + String(millis()-DebuggingTimer));
      LcdNeedRefresh=true;
    }

  }else{        // Ptt in
    if (digitalRead(INTERLOCK) == LOW) {
      digitalWrite (SEQUENCER, HIGH);  // SEQUENCER
      digitalWrite (PTTPA, HIGH);      // PTT-PA
      PttInStatus=true;
      // ptt_high(PTTmodeCW);
      ptt_high(PTTbyMode[ActualMode]);
      Debugging("PTTin-1 "+String(millis()-DebuggingTimer));
    }else{
      PttInStatus=false;
      // ptt_low(PTTmodeCW,2);
      ptt_low(PTTbyMode[ActualMode],2);
      Debugging("PTTin-0 "+String(millis()-DebuggingTimer));
    }
  }

}
//-------------------------------------------------------------------------------------------------------
// 1 = pin8 at DB25 | 2 = pin20 at DB25 | 3 = pin22 at DB25
void ptt_high(int PTToutput){
  PttActive=true;
  LastSeqChange=millis();
  PTTout=PTToutput;
  Debugging("PTTtoH "+String(SequencerLevel)+" "+String(millis()-DebuggingTimer));
  // for pass all three state (Sequencer, PA, PTT)
  OpenInterfaceSequencer();
  OpenInterfaceSequencer();
  OpenInterfaceSequencer();
}

void ptt_high_old(int PTToutput){
  if(ptt_interlock_active == 0){
    if(SequencerLevel == 0){
      digitalWrite (SEQUENCER, HIGH);  // SEQUENCER
      if(DebuggingOutput!=0){
        DebuggingTimer=millis();
      }
      Debugging("PTTseq-H "+String(millis()-DebuggingTimer));
      if(PttInStatus==false){
        delay(SEQUENCERlead);
      }
      SequencerLevel = 5;
    }
    if(SequencerLevel == 5){
      digitalWrite (PTTPA, HIGH);      // PTT-PA
      SendBroadcastUdpPTT(1);
      Debugging("PTTpa-H "+String(millis()-DebuggingTimer));
      if(PttInStatus==false){
        delay(PAlead);
      }
      SequencerLevel = 4;
    }
    if(SequencerLevel == 4 && PttInStatus == false){
      switch (PTToutput) {
        case 1:{ // PTT-1
          digitalWrite (PTT1, HIGH);
          Debugging("PTT1-H "+String(millis()-DebuggingTimer));
          SequencerLevel = 1;
        break;
        }
        case 2:{ // PTT-2
          digitalWrite (PTT2, HIGH);
          Debugging("PTT2-H "+String(millis()-DebuggingTimer));
          SequencerLevel = 2;
        break;
        }
        case 3:{ // PTT-3
          digitalWrite (PTT3, HIGH);
          Debugging("PTT3-H "+String(millis()-DebuggingTimer));
          SequencerLevel = 3;
        break;
        }
      }
      delay(PTTlead);
    }
    if(SequencerLevel == 1 || SequencerLevel == 2 || SequencerLevel == 3){  // if PTT continue ON
      PTT_tail_timeout[0][0] = millis(); // set time mark PTT 1
      PTT_tail_timeout[1][0] = millis(); // set time mark PTT 2
      PTT_tail_timeout[2][0] = millis(); // set time mark PTT 3
    }
  }
}
//-------------------------------------------------------------------------------------------------------
void ptt_low(int PTToutput, int debug){
  if(InterlockEnable==true){
    PttActive=false;
    LastSeqChange=millis();
    PTTout=PTToutput;
    // OpenInterfaceSequencer();
    Debugging("PTTtoL "+String(SequencerLevel)+" "+String(millis()-DebuggingTimer));
  }else{ // PTT in
    if(digitalRead(INTERLOCK)==HIGH){
      PttActive=false;
      LastSeqChange=millis();
      PTTout=PTToutput;
      // OpenInterfaceSequencer();
      Debugging("PTTtoL "+String(SequencerLevel)+" "+String(millis()-DebuggingTimer));
    }
  }
}
void ptt_low_old(int PTToutput, int debug){
  switch (PTToutput) {
    case 0:{ // PTT-x
      PTT_tail_timeout[0][0] = millis(); // set time mark PTT 1
      PTT_tail_timeout[1][0] = millis(); // set time mark PTT 2
      PTT_tail_timeout[2][0] = millis(); // set time mark PTT 3
      SequencerLevel = 1;
    break;
    }
    case 1:{ // PTT-1
      PTT_tail_timeout[0][0] = millis(); // set time mark PTT 1
      SequencerLevel = 1;
    break;
    }
    case 2:{ // PTT-2
      PTT_tail_timeout[1][0] = millis(); // set time mark PTT 2
      SequencerLevel = 2;
    break;
    }
    case 3:{ // PTT-3
      PTT_tail_timeout[2][0] = millis(); // set time mark PTT 3
      SequencerLevel = 3;
    break;
    }
  }
  Debugging("PTT"+String(PTToutput)+"-to L "+String(millis()-DebuggingTimer)+" "+String(send_buffer_bytes)+" "+String(debug));
}
//-------------------------------------------------------------------------------------------------------
/*
unsigned int SEQUENCERlead       = 0;        // SEQUENCER output lead delay ms between SEQ-->PA
unsigned int SEQUENCERtail       = 0;        // SEQUENCER output tail delay ms          :    :                      :     PA-->SEQ
unsigned int PAlead              = 0;        // PA output lead delay ms between         :    PA-->TRX               :     :    :
unsigned int PAtail              = 0;        // PA output tail delay ms                 :    :    :                 TRX-->PA   :
unsigned int PTTlead             = 0;        // PTT (FSK) lead delay ms between         :    :    TRX-->FSK         :     :    :
unsigned int PTTtail             = 0;        // PTT (FSK) tail delay ms                 :    :    :           FSK-->TRX   :    :

byte SequencerLevel = 0;   // 0 = off, 1-2-3 = PTT1-2-3, 4 = PA, 5 = SEQ

                            0   _________________________   0
                          _____|                         |_____   Sequencer
                                  5  _______________   5
                          __________|               |__________   PTT-PA
                                       4  _____   4
                          _______________| 321 |_______________   PTT-1-2-3
LastSeqChange
*/

void OpenInterfaceSequencer(){
  switch (SequencerLevel) {

    case 0:{
      // if( PttActive==true && millis()-LastSeqChange>SEQUENCERlead ){
      if(PttActive==true){
        Debugging("seq0");
        digitalWrite (SEQUENCER, HIGH);  // SEQUENCER
        LastSeqChange=millis();
        delay(SEQUENCERlead);
        if(DebuggingOutput!=0){
          DebuggingTimer=millis();
        }
        Debugging("PTTseq-H "+String(millis()-DebuggingTimer));
        SequencerLevel=5;
      }
      break;
    }

    case 5:{ // PA
      // if( PttActive==true && millis()-LastSeqChange>PAlead ){
      if( PttActive==true ){
        digitalWrite (PTTPA, HIGH);      // PTT-PA
        LastSeqChange=millis();
        delay(PAlead);
        Debugging("PTTpa-H "+String(millis()-DebuggingTimer));
        SequencerLevel=4;
      }
      if( PttActive==false && millis()-LastSeqChange>SEQUENCERtail ){
        digitalWrite (SEQUENCER, LOW);      // SEQUENCER
        LastSeqChange=millis();
        Debugging("PTTseq-L "+String(millis()-DebuggingTimer));
        SequencerLevel=0;
      }
      break;
    }

    case 4:{ // PTT-123
      // if( PttActive==true && millis()-LastSeqChange>PTTlead ){
      if( PttActive==true ){
        digitalWrite (PTTpin[PTTout], HIGH);      // PTT-123
        LastSeqChange=millis();
        delay(PTTlead);
        Debugging("PTT"+String(PTTout)+"-H "+String(millis()-DebuggingTimer));
        SequencerLevel=PTTout;
      }
      if( PttActive==false && millis()-LastSeqChange>PAtail ){
        digitalWrite (PTTPA, LOW);      // PTT-PA
        LastSeqChange=millis();
        Debugging("PTTpa-L "+String(millis()-DebuggingTimer));
        SequencerLevel=5;
      }
      break;
    }

    case 1:
    case 2:
    case 3:{ // PTT-123
      if( PttActive==false && millis()-LastSeqChange>PTTtail ){
        if(PTTout>1){
          digitalWrite (PTTpin[PTTout], LOW);      // PTT-23
          LastSeqChange=millis();
          Debugging("PTT"+String(PTTout)+"-L "+String(millis()-DebuggingTimer));
          SequencerLevel=4;
        }else if(PTTout==1 && send_buffer_bytes==0 && being_sent==0 ){
          digitalWrite (PTTpin[PTTout], LOW);      // PTT-1
          LastSeqChange=millis();
          Debugging("PTT"+String(PTTout)+"-L "+String(millis()-DebuggingTimer));
          SequencerLevel=4;
        }
      }
      break;
    }

  } // end switch
}



void check_ptt_low(){
  if(SequencerLevel != 0 && PttInStatus==false){ // if Sequencer on
    switch (SequencerLevel) {
      case 1:{ // PTT-1
        if (millis() - PTT_tail_timeout[0][0] > PTT_tail_timeout[0][1] && send_buffer_bytes==0 && being_sent==0 ){
          digitalWrite (PTT1, LOW);
          SequencerLevel = 4;
          PTT_tail_timeout[3][0] = millis(); // set time mark PA
          if(PttInStatus!=true ){
            Debugging("PTT1-L "+String(millis()-DebuggingTimer));
          }
        }
      break;
      }
      case 2:{ // PTT-2
        if (millis() - PTT_tail_timeout[1][0] > (PTT_tail_timeout[1][1]) && send_buffer_bytes==0){
            digitalWrite (PTT2, LOW);
          SequencerLevel = 4;
          PTT_tail_timeout[3][0] = millis(); // set time mark PA
          Debugging("PTT2-L "+String(millis()-DebuggingTimer));
        }
      break;
      }
      case 3:{ // PTT-3
        if (millis() - PTT_tail_timeout[2][0] > (PTT_tail_timeout[2][1]) && send_buffer_bytes==0){
            digitalWrite (PTT3, LOW);
          SequencerLevel = 4;
          PTT_tail_timeout[3][0] = millis(); // set time mark PA
          Debugging("PT3-L "+String(millis()-DebuggingTimer));
        }
      break;
      }
      case 4:{ // PTT-PA
        if (millis() - PTT_tail_timeout[3][0] > (PTT_tail_timeout[3][1])){
          digitalWrite (PTTPA, LOW);
          SequencerLevel = 5;
          PTT_tail_timeout[4][0] = millis(); // set time mark PA
          Debugging("PTTpa-L "+String(millis()-DebuggingTimer));
      }
      break;
      }
      case 5:{ // SEQUENCER
        if (millis() - PTT_tail_timeout[4][0] > (PTT_tail_timeout[4][1])){
          digitalWrite (SEQUENCER, LOW);
          SequencerLevel = 0;
          PTT_tail_timeout[3][0] = millis(); // set time mark PA
          SendBroadcastUdpPTT(0);
          Debugging("PTTseq-L "+String(millis()-DebuggingTimer));
        }
      break;
      }
    }
  }
  if(SequencerLevel == 1 || SequencerLevel == 2 || SequencerLevel == 3){  // if PTT continue ON
    PTT_tail_timeout[0][0] = millis(); // set time mark PTT 1
    PTT_tail_timeout[1][0] = millis(); // set time mark PTT 2
    PTT_tail_timeout[2][0] = millis(); // set time mark PTT 3
  }
}
//-------------------------------------------------------------------------------------------------------
// If BAND change, send query packet to Remote IP switch
void RemoteSwQuery(){
  if(EnableEthernet==1 && RemoteSwitch == 1 && EthLinkStatus==1){
    if(BAND != BandDecoderChange){    // if band change, send query udp packet
      if(DetectedRemoteSw[BandToRemoteSwitchID[BAND]][4]!=0){       // if detect IP Switch for this band
        InterruptON(0,0,0); // keyb, enc, gps, Interlock
        RemoteSwIP = DetectedRemoteSw[BandToRemoteSwitchID[BAND]];
        RemoteSwPort = DetectedRemoteSw[BandToRemoteSwitchID[BAND]][4];
        // UDP send to Switch
        TxUdpBuffer[0] = B01110011;         // s
        TxUdpBuffer[1] = B00111010;         // :
        TxUdpBuffer[2] = B01110001;         // q
        TxUdpBuffer[3] = B00111011;         // ;
        TxUdpBuffer[4] = 0;
        TxUdpBuffer[5] = 0;
        UdpCommand.beginPacket(RemoteSwIP, RemoteSwPort);
          UdpCommand.write(TxUdpBuffer, sizeof(TxUdpBuffer));   // send buffer
          RemoteSwLatency[0] = millis(); // set START time mark UDP command latency
        UdpCommand.endPacket();
        RemoteSwLatencyAnsw = 0;   // send command, wait to answer
        InterruptON(1,1,1); // keyb, enc, gps, Interlock
      }else{      // if IP sw n/a on this band, clear LED keyboard
        digitalWrite(ShiftOutLatchPin, LOW);  // ready for receive data
        // shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, B00000000);    // bankC
        shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, B00000000);    // bankB
        shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, B00000000);    // bankA
        digitalWrite(ShiftOutLatchPin, HIGH);    // switch to output pin
      }
      BandDecoderChange = BAND;
    }
  }
}
//-------------------------------------------------------------------------------------------------------
int HowRemoteSwitchID(){
  for (i = 0; i < 16; i++) {
    if(UdpCommand.remoteIP() == DetectedRemoteSw[i]){
      return i;
    }
  }
}

//-------------------------------------------------------------------------------------------------------
// Last-used CW/FSK sub-mode hints for civModeToOi3() disambiguation.
// Updated as side-effect of oi3ModeToCiv() — every local mode change that is
// published via TrxNet keeps these in sync automatically.
static int s_lastCwMode  = 0; // 0=CW Keyer, 1=CW DTR
static int s_lastFskMode = 3; // 3=FSK PC,   4=FSK ASCII

// Convert OI3 internal mode (0-5) to ICOM CI-V mode byte for TrxNet /mode publish.
// Updates s_lastCwMode/s_lastFskMode so civModeToOi3() can reverse-map correctly.
// CW-R (0x07) is not emitted — OI3 CW sub-modes 0 and 1 are both plain CW from CI-V perspective.
static uint8_t oi3ModeToCiv(int oi3Mode) {
  if (oi3Mode == 0 || oi3Mode == 1) s_lastCwMode  = oi3Mode;
  if (oi3Mode == 3 || oi3Mode == 4) s_lastFskMode = oi3Mode;
  switch (oi3Mode) {
    case 0: return 0x03; // CW Keyer  → CW
    case 1: return 0x03; // CW DTR    → CW
    case 2: return 0x01; // SSB       → USB (OI3 doesn't distinguish LSB/USB)
    case 3: return 0x04; // FSK PC    → RTTY
    case 4: return 0x04; // FSK ASCII → RTTY
    case 5: return 0x05; // DIGI/AFSK → FM
    default: return 0x01;
  }
}

// Convert received CI-V mode byte to OI3 internal mode.
// CW (0x03) and RTTY (0x04) are ambiguous — resolved via s_lastCwMode/s_lastFskMode.
// CW-R (0x07) → CW DTR (1); RTTY-R (0x08) → FSK ASCII (4).
static int civModeToOi3(uint8_t civ) {
  switch (civ) {
    case 0x00: return 2;            // LSB    → SSB
    case 0x01: return 2;            // USB    → SSB
    case 0x02: return 2;            // AM     → SSB (closest)
    case 0x03: return s_lastCwMode; // CW     → last used CW sub-mode
    case 0x04: return s_lastFskMode;// RTTY   → last used FSK sub-mode
    case 0x05: return 5;            // FM     → DIGI/AFSK
    case 0x06: return 2;            // WFM    → SSB (closest)
    case 0x07: return 1;            // CW-R   → CW DTR
    case 0x08: return 4;            // RTTY-R → FSK ASCII
    case 0x17: return 2;            // DV     → SSB (closest)
    default:   return 2;
  }
}

// TrxNet callbacks — called from net.loop(), must be short and non-blocking, no String on AVR
void onSetHz(const char* from, const uint8_t* data, size_t len) {
  if (len < sizeof(uint32_t)) return;
  memcpy((void*)&trxPendingHz, data, sizeof(uint32_t));
  trxFreqPending = true;
}

void onSetMode(const char* from, const uint8_t* data, size_t len) {
  if (len < sizeof(uint8_t)) return;
  trxPendingCivMode = data[0];
  trxPendingMode = (uint8_t)civModeToOi3(data[0]);
  trxModePending = true;
}

void onSetCw(const char* from, const uint8_t* data, size_t len) {
  if (len == 1 && data[0] == 0xFF) { trxCwAbort = true; return; }
  size_t n = (len < 64) ? len : 64;
  memcpy(trxPendingCW, data, n);
  trxPendingCW[n] = '\0';
  trxCwPending = true;
}

// Fired by TrxNet when a new peer is discovered. Just enqueue the name —
// actual publishTo() runs in loop() to stay out of UDP receive re-entrancy.
void onPeerJoined(const TrxPeer* peer) {
  if (!peer) return;
  if (trxPendingGreetCount >= TRXNET_MAX_PEERS) return;
  strncpy(trxPendingGreet[trxPendingGreetCount], peer->name, TRXNET_MAX_DEVICE_NAME - 1);
  trxPendingGreet[trxPendingGreetCount][TRXNET_MAX_DEVICE_NAME - 1] = '\0';
  trxPendingGreetCount++;
}

// Send current state snapshot to a single peer (used on join).
// Must include every topic this device publishes — keep in sync with bandSET()
// and other publish sites.
void republishState(const char* peerName) {
  uint32_t f = (uint32_t)freq;
  uint8_t  m = oi3ModeToCiv(ActualMode);
  net.publishTo(peerName, "/hz",   (uint8_t*)&f, sizeof(f), TRX_CON);
  net.publishTo(peerName, "/mode", &m,            sizeof(m), TRX_CON);
}

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
void EthernetCheck(){
  if(millis()-EthLinkStatusTimer[0]>EthLinkStatusTimer[1] && EnableEthernet==1){
    if ((Ethernet.linkStatus() == Unknown || Ethernet.linkStatus() == LinkOFF) && EthLinkStatus==1) {
      EthLinkStatus=0;
      Debugging("Ethernet DISCONNECTED");
    }else if (Ethernet.linkStatus() == LinkON && EthLinkStatus==0) {
      EthLinkStatus=1;
      Debugging("Ethernet CONNECTED");
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print(F("Net-ID: "));
      lcd.print(NET_ID, HEX);
      lcd.setCursor(1, 1);
      lcd.print(F("[DHCP-"));
      if(EnableDHCP==1){
          lcd.print(F("ON]..."));
          Ethernet.begin(mac);
          Ethernet.setRetransmissionTimeout(500);   // FIX bod4: zkraceni TCP timeoutu z ~4000ms na 500ms - zabrani blokovani pri nedostupnem MQTT brokeru
          Ethernet.setRetransmissionCount(2);    // FIX bod4: 2 pokusy misto 8 - max blokace ~1s misto ~30s
          IPAddress CheckIP = Ethernet.localIP();
          if( CheckIP[0]==0 && CheckIP[1]==0 && CheckIP[2]==0 && CheckIP[3]==0 ){
            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print(F("DHCP FAIL"));
            lcd.setCursor(1, 1);
            lcd.print(F("please restart"));
            while(1) {
              // infinite loop
            }
          }
      }else{
        lcd.print(F("OFF]"));
        Ethernet.begin(mac, ip, myDns, gateway, subnet);
        Ethernet.setRetransmissionTimeout(500);   // FIX bod4: zkraceni TCP timeoutu z ~4000ms na 500ms
        Ethernet.setRetransmissionCount(2);    // FIX bod4: 2 pokusy misto 8
      }

        delay(1000);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print(F("IP address:"));
        lcd.setCursor(1, 1);
        lcd.print(Ethernet.localIP());
        IPAddress IPlocalAddr = Ethernet.localIP();                           // get
        String IPlocalAddrString = String(IPlocalAddr[0]) + "." + String(IPlocalAddr[1]) + "." + String(IPlocalAddr[2]) + "." + String(IPlocalAddr[3]);   // to string
        Debugging(IPlocalAddrString);
        delay(1500);
        lcd.clear();

      UdpCommand.begin(UdpCommandPort);   // UDP
      UdpRtty.begin(UdpRttyPort);
      // TrxNet init — po Ethernet.begin(), jmeno sestaveno z NET_ID
      snprintf(trxDeviceName, sizeof(trxDeviceName), "OI3.%02x", NET_ID);
      net.setPort(trxPort);
      net.onPeerAdded(onPeerJoined);   // must be set BEFORE begin() to catch the first probe replies
      net.begin(trxDeviceName);
      net.subscribe("/s-hz",   onSetHz);
      net.subscribe("/s-mode", onSetMode);
      net.subscribe("/s-cw",   onSetCw);
      // Start in FAST mode so the first CAT response arrives within ~200ms,
      // covering peers that join before the keyer has learned the radio's state.
      lastFreqChangeAt = millis();
      Timeout[4][1] = BAND_DECODER_REQUEST_FAST;
      Debugging("TrxNet begin: " + String(trxDeviceName));
    } // end ETH-ON
    EthLinkStatusTimer[0]=millis();
  } // end Timer
}

//-------------------------------------------------------------------------------------------------------
// Incoming UDP commands
void IncomingUDP(){
  if(EnableEthernet==1 && EthLinkStatus==1){
    // detachInterrupt because this interrupt worked with ethernet also
    InterruptON(0,0,0); // keyb, enc, gps, Interlock

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // CW/RTTY transmit incoming string [port 89]

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    UDPpacketSize = UdpRtty.parsePacket();    // if there's data available, read a packet
    if (UDPpacketSize){
      Debugging("Incoming UDP CW/RTTY string on port 89");
      if(ActualMode==3 || ActualMode==4){               // if mode FSK
        UdpRtty.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);      // read the packet into packetBufffer
        FSKmemory[0] = packetBuffer;
        FSKmemoryTX(0);
      }
      if(ActualMode==0 || ActualMode==1){               // if mode CW
        // CW transmit locally
        UdpRtty.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);      // read the packet into packetBufffer
        ptt_high(PTTbyMode[ActualMode]);
        tmp = sizeof(packetBuffer);
        Debugging("Local CW transmit (rx buffer size "+String(tmp)+")");
        for (i = 0; i < tmp; i++) {
          if(packetBuffer[i]!=0){
            send_char(toUpperCase(packetBuffer[i]),KEYER_NORMAL);
            Debugging(String(i)+"-"+String(packetBuffer[i], HEX)+" "+millis());
          }
        }
        ptt_low(PTTbyMode[ActualMode],5);
      }
      memset(packetBuffer, 0, sizeof(packetBuffer));   // if mode no FSK or after TX, clear Buffer
    }

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // COMMANDS [port 88]

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    UDPpacketSize = UdpCommand.parsePacket();    // if there's data available, read a packet
    if (UDPpacketSize){
      UdpCommand.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);      // read the packet into packetBufffer
      Debugging(String("Incoming UDP packet, port 88"));

      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // Switch ANSWER > SET LED - Bank0-2
      if (packetBuffer[0] == 's' && packetBuffer[1] == ':'){
        RemoteSwLatency[1] = (millis()-RemoteSwLatency[0])/2; // set latency (half path in ms us/2/1000)
        RemoteSwLatencyAnsw = 1;           // answer packet received

        if (ACC_KEYBOARD==1 && KeyboardAnswLed==1 && HowRemoteSwitchID()<7){ // and ID < 7 (bank A/B)
          Debugging("Remote IP switch ID: "+String(HowRemoteSwitchID()));

          // need if RX answer from band change query
          rxShiftInButton[0] = packetBuffer[2];
          rxShiftInButton[1] = packetBuffer[3];
          rxShiftInButton[2] = packetBuffer[4];

          digitalWrite(ShiftOutLatchPin, LOW);  // ready for receive data
          // shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, packetBuffer[4]);    // bankC
          shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, packetBuffer[3]);    // bankB
          shiftOut(ShiftOutDataPin, ShiftOutClockPin, MSBFIRST, packetBuffer[2]);    // bankA
          digitalWrite(ShiftOutLatchPin, HIGH);    // switch to output pin
        }
      }

      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // Switch BROADCAST - STORAGE IP by received ID in 'DetectedRemoteSw' array (rows = Switch ID)
      if (packetBuffer[0] == 'b' && packetBuffer[1] == ':' && packetBuffer[2] == 's' && packetBuffer[4] == ';'){
        IPAddress TmpAddr = UdpCommand.remoteIP();
        // DetectedRemoteSw [(int)packetBuffer[3] - 48] [0]=TmpAddr[0];     // Switch IP addres storage to array
        // DetectedRemoteSw [(int)packetBuffer[3] - 48] [1]=TmpAddr[1];     // (int)packetBuffer[3] - 48 = convert char number to DEC
        // DetectedRemoteSw [(int)packetBuffer[3] - 48] [2]=TmpAddr[2];
        // DetectedRemoteSw [(int)packetBuffer[3] - 48] [3]=TmpAddr[3];
        // DetectedRemoteSw [(int)packetBuffer[3] - 48] [4]=UdpCommand.remotePort();
        DetectedRemoteSw [hexToDecBy4bit(packetBuffer[3])] [0]=TmpAddr[0];     // Switch IP addres storage to array
        DetectedRemoteSw [hexToDecBy4bit(packetBuffer[3])] [1]=TmpAddr[1];
        DetectedRemoteSw [hexToDecBy4bit(packetBuffer[3])] [2]=TmpAddr[2];
        DetectedRemoteSw [hexToDecBy4bit(packetBuffer[3])] [3]=TmpAddr[3];
        DetectedRemoteSw [hexToDecBy4bit(packetBuffer[3])] [4]=UdpCommand.remotePort();
        RemoteSwLatencyAnsw = 1;           // answer packet received

        Debugging("RX b:s"+String(packetBuffer[3])+";");
        Debugging(String(hexToDecBy4bit(packetBuffer[3]), HEX));

        Debugging(String(packetBuffer[3], DEC));
        Debugging(String((int)packetBuffer[3] - 48, DEC));
        for (i = 0; i < 16; i++) {
          Debugging(String(i)+"  "+String(DetectedRemoteSw [i] [0])+"."+String(DetectedRemoteSw [i] [1])+"."+String(DetectedRemoteSw [i] [2])+"."+String(DetectedRemoteSw [i] [3])+":"+String(DetectedRemoteSw [i] [4]));
        }
      }

      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // INTERLOCK 1 direct
      if (packetBuffer[0] == 'i' && packetBuffer[1] == ':' && packetBuffer[3] == ';'){
        if(packetBuffer[2] == '1'){
          ptt_interlock_active = B00001;
          if(SequencerLevel != 0){   // if any PTT active
            ptt_low(0,6);
          }
          InterlockFromUdpActive = HIGH;
        }else if(packetBuffer[2] == '0'){
          ptt_interlock_active = B00000;
          InterlockFromUdpActive = LOW;
        }
        LcdNeedRefresh=true;
      }

      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // INTERLOCK 2 broadcast [b:o#*ps;]  #- open interface ID, *- band number s- PTT 0/1
      if (packetBuffer[0] == 'b' && packetBuffer[1] == ':' && packetBuffer[2] == 'o' && packetBuffer[5] == 'p' && packetBuffer[7] == ';'){
        if(packetBuffer[4] == BAND){    // if PTT on same band
          if(packetBuffer[6] == 1){     // if another OI in network PTT 1
            ptt_interlock_active = B00001;
            if(SequencerLevel != 0){   // if any PTT active
              ptt_low(0,7);
            }
            InterlockFromUdpActive = HIGH;
          }else if(packetBuffer[6] == 0){
            ptt_interlock_active = B00000;
            InterlockFromUdpActive = LOW;
          }
          LcdNeedRefresh=true;
        }
      }

      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // PTT
      if (packetBuffer[0] == 'p' && packetBuffer[1] == ':' && packetBuffer[3] == ':' && packetBuffer[5] == ';'){
        if(packetBuffer[4] == '0'){tmp = PTTPA;}
        else if(packetBuffer[4] == '1'){tmp = PTT1;}
        else if(packetBuffer[4] == '2'){tmp = PTT2;}
        else if(packetBuffer[4] == '3'){tmp = PTT3;}
        else{tmp = PTTPA;}
        if(packetBuffer[2] == '0'){
            digitalWrite (tmp, LOW);
        }else if(packetBuffer[2] == '1'){
          if(ptt_interlock_active == 0){  // if interlock not active
            digitalWrite (tmp, HIGH);
          }
        }
      }

      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // MODE
      if (packetBuffer[0] == 'm' && packetBuffer[1] == ':' && packetBuffer[3] == ';'){
        tmp = packetBuffer[2]-'0';  // convert to int for compare
        if(tmp >= 0 && tmp <= 5){
          ActualMode = tmp;
          if(ActualMode!=ActualModePrev){
            ActualModePrev=ActualMode;
            { uint8_t _m = oi3ModeToCiv(ActualMode); net.publish("/mode", &_m, sizeof(_m)); }
            SwitchHardware(ActualMode);
          }
        }
      }

      //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      // CONFIGURE c:001:value;
      if (packetBuffer[0] == 'c' && packetBuffer[1] == ':' && packetBuffer[5] == ':'){

        // 000-NetID [hex] MUST BE UNIQUE IN NETWORK - every Open Interface own different number
        if (packetBuffer[2] == '0' && packetBuffer[3] == '0' && packetBuffer[4] == '0' && packetBuffer[8] == ';'){
          NET_ID = (hexToDecBy4bit(packetBuffer[6]) << 4) | hexToDecBy4bit(packetBuffer[7]);   // 4-bit left shift to combine them
        }

        // 001-SERBAUD2 - 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200,
        if (packetBuffer[2] == '0' && packetBuffer[3] == '0' && packetBuffer[4] == '1' && packetBuffer[7] == ';'){  // SERBAUD2
          tmp = packetBuffer[6]-'0';  // convert to int for compare
          switch (tmp) {
            case 0:
              SERBAUD2 = 1200;
            break;
            case 1:
              SERBAUD2 = 2400;
            break;
            case 2:
              SERBAUD2 = 4800;
            break;
            case 3:
              SERBAUD2 = 9600;
            break;
            case 4:
              SERBAUD2 = 19200;
            break;
            case 5:
              SERBAUD2 = 38400;
            break;
            case 6:
              SERBAUD2 = 57600;
            break;
            case 7:
              SERBAUD2 = 115200;
            break;
          }
          Serial2.begin(SERBAUD2);
        } // end SERBAUD2

        // 002-CIV_ADRESS
        if (packetBuffer[2] == '0' && packetBuffer[3] == '0' && packetBuffer[4] == '2' && packetBuffer[8] == ';'){
          CIV_ADRESS = (hexToDecBy4bit(packetBuffer[6]) << 4) | hexToDecBy4bit(packetBuffer[7]);   // 4-bit left shift to combine them
        }

        //  003-BAND_DECODER_IN  0=disable 1=ICOM_CIV 2=KENWOOD_PC 3=YAESU_CAT 4=YAESU_CAT_OLD 5=INPUT_SERIAL
        if (packetBuffer[2] == '0' && packetBuffer[3] == '0' && packetBuffer[4] == '3' && packetBuffer[7] == ';'){
          tmp = packetBuffer[6]-'0';  // convert to int for compare
          if(tmp < 6){
            BAND_DECODER_IN = hexToDecBy4bit(packetBuffer[6]);
          }
        }

        //  004-debugging
        if (packetBuffer[2] == '0' && packetBuffer[3] == '0' && packetBuffer[4] == '4' && packetBuffer[7] == ';'){
          DebuggingOutput = packetBuffer[6]-'0';
          Debugging("Debug switch from IP to: "+String(DebuggingOutput));
        }

      } // end configure

  //    lcd.print(F("      "));
    memset(packetBuffer, 0, sizeof(packetBuffer));   // Clear contents of Buffer
    }
    InterruptON(1,1,1); // keyb, enc, gps, Interlock
  }
}

//-------------------------------------------------------------------------------------------------------

unsigned char hexToDecBy4bit(unsigned char hex)
// convert a character representation of a hexidecimal digit into the actual hexidecimal value
{
  if(hex > 0x39) hex -= 7; // adjust for hex letters upper or lower case
  return(hex & 0xf);
}
//-------------------------------------------------------------------------------------------------------

long hexToLong(String hexString) {
    hexString.reserve(20);
    long decValue = 0;
    int nextInt;
    for (int i = 0; i < hexString.length(); i++) {
        nextInt = int(hexString.charAt(i));
        if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
        if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
        if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
        nextInt = constrain(nextInt, 0, 15);
        decValue = (decValue * 16) + nextInt;
    }
    return decValue;
}
//-------------------------------------------------------------------------------------------------------

unsigned int hexToDec(String hexString) {
    hexString.reserve(20);
    unsigned int decValue = 0;
    int nextInt;
    for (int i = 0; i < hexString.length(); i++) {
        nextInt = int(hexString.charAt(i));
        if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
        if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
        if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
        nextInt = constrain(nextInt, 0, 15);
        decValue = (decValue * 16) + nextInt;
    }
    return decValue;
}

//-------------------------------------------------------------------------------------------------------

void SendBroadcastUdpPTT(int status){         // Measured 2 ms
  if(EnableEthernet==1 && EthLinkStatus==1){
    InterruptON(0,0,0); // keyb, enc, gps, Interlock
    BroadcastIP = ~Ethernet.subnetMask() | Ethernet.gatewayIP();
    TxUdpBuffer[0] = B01100010;         // b  - broadcast
    TxUdpBuffer[1] = B00111010;         // :
    TxUdpBuffer[2] = B01101111;         // o  - open interface device
    TxUdpBuffer[3] = NET_ID;         // ID number
    TxUdpBuffer[4] = BAND;              // Band number
    TxUdpBuffer[5] = B01110000;         // p  - PTT
    TxUdpBuffer[6] = status;
    TxUdpBuffer[7] = B00111011;         // ;
    UdpCommand.beginPacket(BroadcastIP, BroadcastPort);   // Send to IP and port from recived UDP command
      UdpCommand.write(TxUdpBuffer, sizeof(TxUdpBuffer));   // send buffer
    UdpCommand.endPacket();
    InterruptON(1,1,1); // keyb, enc, gps, Interlock
  }
}
//-------------------------------------------------------------------------------------------------------

void Debugging(String StringForDebug){
  StringForDebug.reserve(150);
  if(DebuggingOutput!=0){
    // Serial0 KEY
    if(DebuggingOutput==1){
      Serial.print(StringForDebug);
      Serial.println();
    }
    // Serial2 CAT
    if(DebuggingOutput==2){
      Serial2.print(StringForDebug);
      Serial2.println();
    }
    // UDP IP
    if(DebuggingOutput==3 && EnableEthernet==true && EthLinkStatus==1){
      InterruptON(0,0,0); // keyb, enc, gps, Interlock
      DebuggingIP = ~Ethernet.subnetMask() | Ethernet.gatewayIP();
      UdpCommand.beginPacket(DebuggingIP, DebuggingPort);
      // UdpCommand.beginMulticast(UdpCommand.BroadcastIP(), BroadcastPort, ETH.localIP()).
        UdpCommand.print(F("NET_ID"));
        UdpCommand.print(F("debug:"));
        UdpCommand.print(StringForDebug);
        UdpCommand.print(F(";"));
      UdpCommand.endPacket();
      InterruptON(1,1,1); // keyb, enc, gps, Interlock
    }
  }
}

//-------------------------------------------------------------------------------------------------------
void SendBroadcastUdp(){
  if(EnableEthernet==1 && EthLinkStatus==1){
    InterruptON(0,0,0); // keyb, enc, gps, Interlock
    BroadcastIP = ~Ethernet.subnetMask() | Ethernet.gatewayIP();

    UdpCommand.beginPacket(BroadcastIP, BroadcastPort);   // Send to IP and port from recived UDP command
    // UdpCommand.beginMulticast(UdpCommand.BroadcastIP(), BroadcastPort, ETH.localIP()).
      UdpCommand.print(F("b:o"));
      UdpCommand.write(NET_ID);
      UdpCommand.print(F(";"));
    UdpCommand.endPacket();

    Debugging("TX Broadcast "+String(BroadcastIP)+":"+String(BroadcastPort)+"   ms "+String(Timeout[8][0]));

    Timeout[8][0] = millis();                      // set time mark
    InterruptON(1,1,1); // keyb, enc, gps, Interlock
  }
}
//-------------------------------------------------------------------------------------------------------

void DCinMeasure(){
  if (millis() - Timeout[7][0] > (Timeout[7][1])){
    DCinVoltage = volt(analogRead(DCIN), 11, VOLTAGE_MEASURE_ADJUST);
    if (DCinVoltage<8){
      tone(TONE, 400, 1000);
      lcd.setCursor(3, 0);
      lcd.print(F("Power LOW!"));
      ActualMenu= 2;
    }else if (DCinVoltage>19){
      tone(TONE, 800, 1000);
      lcd.setCursor(2, 0);
      lcd.print(F("Power HIGH!"));
      ActualMenu= 2;
    }
    Timeout[7][0] = millis();                      // set time mark
    if(abs(DCinVoltage-PrevDCinVoltage)>0.5){
      PrevDCinVoltage=DCinVoltage;
    }
  }
}
//-------------------------------------------------------------------------------------------------------
void OpenInterfaceLCD(){    // LCD
    if (millis() - Timeout[0][0] > (Timeout[0][1]) || LcdNeedRefresh==true){// || (ActualMenu==20 && millis() - (Timeout[0][0]/2) > (Timeout[0][1]))){   // menu 20 with 1/3 refresh delay
      // micro SD
      lcd.setCursor(15, 1);
      if(ptt_interlock_active == 1){
          lcd.write(byte(5));               // Interlock icon
      }else if (analogRead(SDPLUG)<128){
          lcd.write(byte(4));               // microSD icon
      } else {
          lcd.print(F(" "));
      }

      // MENU
      lcd.setCursor(0, 1);
      MenuToLCD(ActualMenu);
      Timeout[0][0] = millis();                      // set time mark

      // MODE
      lcd.setCursor(11, 1);
      switch (ModeMenuStatus) {
        case 0:
          lcd.print(modeLCD[ActualMode][0]);
        break;

        case 1:
          lcd.print(F(" <"));
          if(ActualMenu<10){
            lcd.print(F("0"));
          }
          lcd.print(ActualMenu);
        break;

        case 2:
          lcd.print(F(" <+-"));
        break;

        case 3:
          lcd.print(F(" <##"));
        break;
      }

      if (LcdNeedRefresh==true){
        LcdNeedRefresh=false;
      }
    }
}
//-------------------------------------------------------------------------------------------------------
void MenuToLCD(int nr){
  String Note = MenuTree[nr];
  Note.reserve(11);
  Note.remove(11);                // fixed lenth to 11 char
    Note += " ";
  lcd.print(Note);
  int CulumnPosition = Note.length();

  switch (nr) {
    case 1:{ // rev
      lcd.setCursor(CulumnPosition-1, 1);
      lcd.print(REV);
      CulumnPosition=CulumnPosition+8;
    break;
    }
    case 2:{ // DC in
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(DCinVoltage);
      lcd.print(F("V"));
      CulumnPosition=CulumnPosition+6;
    break;
    }
    case 3:{ // DC 3V3
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(volt(analogRead(DC3V), 1, 0));
      lcd.print(F("V"));
      CulumnPosition=CulumnPosition+5;
    break;
    }
    case 4:{ // Band Decoder
      lcd.setCursor(CulumnPosition, 1);
      if (BAND_DECODER_IN == 0){  // ICOM_CIV
        lcd.print(F("none"));
        CulumnPosition=CulumnPosition+4;
      }
      if (BAND_DECODER_IN == 1){  // ICOM_CIV
        lcd.print(F("ICOM"));
        CulumnPosition=CulumnPosition+4;
      }
      if (BAND_DECODER_IN == 2){  // KENWOOD_PC
        lcd.print(F("KENWOOD"));
        CulumnPosition=CulumnPosition+7;
      }
      if (BAND_DECODER_IN == 3){  // YAESU_CAT
        lcd.print(F("YAESU2"));
        CulumnPosition=CulumnPosition+6;
      }
      if (BAND_DECODER_IN == 4){  // YAESU_CAT_OLD
        lcd.print(F("YAESU1"));
        CulumnPosition=CulumnPosition+6;
      }
      if (BAND_DECODER_IN == 5){  // INPUT_SERIAL
        lcd.print(F("Serial"));
        CulumnPosition=CulumnPosition+6;
      }
      if (BAND_DECODER_IN == 6){  // YAESU_BCD
        lcd.print(F("BCD"));
        CulumnPosition=CulumnPosition+3;
      }
      if (BAND_DECODER_IN == 7){  // ICOM_ACC
        lcd.print(F("V-IN"));
        CulumnPosition=CulumnPosition+4;
      }
    break;
    }
    case 5:{ // Baudrate
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(SERBAUD2);
      CulumnPosition=CulumnPosition+String(SERBAUD2).length();
    break;
    }
    case 6:{ // CI-V address
      lcd.setCursor(CulumnPosition, 1);
      if (BAND_DECODER_IN == 1){  // ICOM_CIV
        lcd.print(CIV_ADRESS, HEX);
        lcd.print(F("h"));
        CulumnPosition=CulumnPosition+3;
      }else{
        lcd.print(F("-"));
        CulumnPosition=CulumnPosition+1;
      }
    break;
    }
    case 7:{ // freq
      lcd.setCursor(CulumnPosition-1, 1);
      int MHZ = freq/1000000;
      if(MHZ<100 && MHZ>9){
        lcd.print(F(" "));
      }else if(MHZ<10){
        lcd.print(F("  "));
      }
      lcd.print(MHZ);
      lcd.print(F("."));
      int KHZ = freq/1000-(MHZ*1000);
      if(KHZ<100 && KHZ>9){
        lcd.print(F("0"));
      }else if(KHZ<10){
        lcd.print(F("00"));
      }
      lcd.print(KHZ);
//      lcd.print(F("."));
//      int HZ = freq-(MHZ*1000000)-(KHZ*1000);
//      HZ=HZ/10;
//      if(HZ<10){
//        lcd.print(F("0"));
//      }
//      lcd.print(HZ);
      CulumnPosition=CulumnPosition+7;
    break;
    }
    case 8:{ // BAND
      if(BAND<10){
        lcd.setCursor(CulumnPosition, 1);
      }else{
        lcd.setCursor(CulumnPosition-1, 1);
      }
      lcd.print(BAND);
      lcd.print(F(" "));
      lcd.print(BCDmatrixOUT[0][BAND]);
      lcd.print(BCDmatrixOUT[1][BAND]);
      lcd.print(BCDmatrixOUT[2][BAND]);
      lcd.print(BCDmatrixOUT[3][BAND]);
      CulumnPosition=CulumnPosition+7;
    break;
    }
    case 9:{ // ANT
      lcd.setCursor(CulumnPosition-1, 1);
      lcd.write(byte(7));               // ANT icon
      lcd.print(F(" "));
      lcd.print(ANTname[BAND]);
      CulumnPosition=CulumnPosition+String(ANTname[BAND]).length()+1;
    break;
    }
    case 10:{ // FSK baudrate
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(BaudRate);
      CulumnPosition=CulumnPosition+5;
    break;
    }
    case 11:{ // SEQ Lead
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(SEQUENCERlead);
      CulumnPosition=CulumnPosition+String(SEQUENCERlead).length();
    break;
    }
    case 12:{ // SEQ tail
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(SEQUENCERtail);
      CulumnPosition=CulumnPosition+String(SEQUENCERtail).length();
    break;
    }
    case 13:{ // PA Lead
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(PAlead);
      CulumnPosition=CulumnPosition+String(PAlead).length();
    break;
    }
    case 14:{ // PA tail
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(PAtail);
      CulumnPosition=CulumnPosition+String(PAtail).length();
    break;
    }
    case 15:{ // PTT Lead
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(PTTlead);
      CulumnPosition=CulumnPosition+String(PTTlead).length();
    break;
    }
    case 16:{ // PTT tail
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(PTTtail);
      CulumnPosition=CulumnPosition+String(PTTtail).length();
    break;
    }
    case 17:{ // MODE
      lcd.setCursor(CulumnPosition-1, 1);
      lcd.print(modeLCD[ActualMode][1]);
      CulumnPosition=CulumnPosition+String(modeLCD[ActualMode][1]).length()-1;
    break;
    }
    case 18:{ // Buttons bank A
      lcd.setCursor(CulumnPosition-1, 1);
      if(DetectedRemoteSw[BandToRemoteSwitchID[BAND]][4]!=0){       // if detect IP Switch for this band
        if(ACC_KEYBOARD == 1){                // if enable ACC shift in buttons
          if(RemoteSwLatencyAnsw==1 || (RemoteSwLatencyAnsw==0 && millis() < RemoteSwLatency[0]+RemoteSwLatency[1]*5)){ // if answer ok, or latency measure nod end
            lcd.print(BandToRemoteSwitchID[BAND]);
            lcd.print(F(":"));
            lcd.print(PrintByte(rxShiftInButton[0]));
            CulumnPosition=CulumnPosition+String(rxShiftInButton[0]).length()-1;
          }else{
            lcd.print(BandToRemoteSwitchID[BAND]);
            lcd.print(F(": OFFline"));
            CulumnPosition=CulumnPosition+String(" : OFFline").length()-1;
          }
        }else{
          lcd.print(F(" Disable"));
          CulumnPosition=CulumnPosition+String(" Disable").length()-1;
        }
      }else{
        lcd.print(BandToRemoteSwitchID[BAND]);
        lcd.print(F(":   n/a"));
        CulumnPosition=CulumnPosition+String(" :   n/a").length()-1;
      }
    break;
    }
    case 19:{ // Buttons bank B
      lcd.setCursor(CulumnPosition-1, 1);
      if(DetectedRemoteSw[BandToRemoteSwitchID[BAND]][4]!=0){       // if detect IP for this band
        if(ACC_KEYBOARD == 1){
          if(RemoteSwLatencyAnsw==1 || (RemoteSwLatencyAnsw==0 && millis() < RemoteSwLatency[0]+RemoteSwLatency[1]*5)){ // if answer ok, or latency measure nod end
            lcd.print(BandToRemoteSwitchID[BAND]);
            lcd.print(F(":"));
            lcd.print(PrintByte(rxShiftInButton[1]));
            CulumnPosition=CulumnPosition+String(rxShiftInButton[1]).length()-1;
          }else{
            lcd.print(BandToRemoteSwitchID[BAND]);
            lcd.print(F(": OFFline"));
            CulumnPosition=CulumnPosition+String(" : OFFline").length()-1;
          }
        }else{
          lcd.print(F(" Disable"));
          CulumnPosition=CulumnPosition+String(" Disable").length()-1;
        }
      }else{
        lcd.print(BandToRemoteSwitchID[BAND]);
        lcd.print(F(":   n/a"));
        CulumnPosition=CulumnPosition+String(" :   n/a").length()-1;
      }
    break;
    }
    case 20:{ // Buttons bank C
      lcd.setCursor(CulumnPosition-1, 1);
      if(DetectedRemoteSw[BandToRemoteSwitchID[BAND]+8][4]!=0){       // if detect IP for this band, +8 because bank C use upper ID 0x08-0x0F
          if(RemoteSwLatencyAnsw==1 || (RemoteSwLatencyAnsw==0 && millis() < RemoteSwLatency[0]+RemoteSwLatency[1]*5)){//(millis()-RemoteSwLatency[0]) < 500){       // if receive answer packet
            lcd.print(BandToRemoteSwitchID[BAND]+8, HEX);
            lcd.print(F(":   "));
            if(IpSwitchEncoder+1<10){
              lcd.print(F(" "));
            }
            lcd.print(IpSwitchEncoder+1);
            CulumnPosition=CulumnPosition+String(IpSwitchEncoder).length()-1+6;
          }else{
            lcd.print(BandToRemoteSwitchID[BAND]+8, HEX);
            lcd.print(F(": OFFline"));
            CulumnPosition=CulumnPosition+String(" : OFFline").length()-1;
          }
      }else{
        lcd.print(BandToRemoteSwitchID[BAND]+8, HEX);
        lcd.print(F(":   n/a"));
        CulumnPosition=CulumnPosition+String(" :   n/a").length()-1;
      }
    break;
    }
    case 21:{ // Last Switch command latency measure
      lcd.setCursor(CulumnPosition-1, 1);
      if(DetectedRemoteSw[BandToRemoteSwitchID[BAND]][4]!=0 || DetectedRemoteSw[BandToRemoteSwitchID[BAND]+8][4]!=0){       // if detect IP for this band
        if(ACC_KEYBOARD == 1 && KeyboardAnswLed == 1){
          if(RemoteSwLatencyAnsw==1 || (RemoteSwLatencyAnsw==0 && millis() < RemoteSwLatency[0]+RemoteSwLatency[1]*5)){ // if answer ok, or latency measure nod end
            lcd.print(RemoteSwLatency[1]);
            lcd.print(F("ms"));
            CulumnPosition=CulumnPosition+String(RemoteSwLatency[1]).length()-1;
          }else{
            lcd.print(F("OFF"));
            CulumnPosition=CulumnPosition+String(" : OFF").length()-1;
          }
        }else{
          lcd.print(F("Dis"));
          CulumnPosition=CulumnPosition+String("Dis").length()-1;
        }
      }else{
        lcd.print(F("n/a"));
        CulumnPosition=CulumnPosition+String("n/a").length()-1;
      }
    break;
    }
    case 22:{ // Network ID
      lcd.setCursor(CulumnPosition, 1);
      lcd.print(NET_ID, HEX);
      CulumnPosition=CulumnPosition+String(NET_ID).length();
    break;
    }
    case 23: break; // (was GpsTime UTC — GPS removed)
    case 24: break; // (was GpsTime diff — GPS removed)
    case 25: break; // (was SOMQ B4TX Timer — SOMQ removed)
    case 26:{ // Debug on Serial2
      lcd.setCursor(CulumnPosition, 1);
      switch (DebuggingOutput){
        case 0:
          lcd.print(F(" off"));
        break;
        case 1:
          lcd.print(F(" KEY"));
        break;
        case 2:
          lcd.print(F(" CAT"));
        break;
        case 3:
          lcd.print(F(" UDP"));
        break;
        case 4:
          lcd.print(F("MQTT"));
        break;
      }
      CulumnPosition=CulumnPosition+4;
    break;
    }
    case 27:{ // PTTin
      lcd.setCursor(CulumnPosition-1, 1);
      if(InterlockEnable==true){
        lcd.print("InterlockIn");
        CulumnPosition=CulumnPosition+String("InterlockIn").length();
      }else{
        lcd.print(F("PTT Input"));
        CulumnPosition=CulumnPosition+String("PTT Input").length();
      }
    break;
    }
    case 28:{ // PTT outputs
      lcd.setCursor(CulumnPosition-1, 1);
      lcd.print(modeLCD[ActualMode][2]);
      lcd.print(F(" "));
      lcd.print(PTTbyMode[ActualMode]);
      CulumnPosition=CulumnPosition+String(modeLCD[ActualMode][2]).length()+1;
    break;
    }
    case 29:{ // IP 1/2
      lcd.setCursor(CulumnPosition-1, 1);
      lcd.print(Ethernet.localIP()[0]);
      lcd.print(F("."));
      lcd.print(Ethernet.localIP()[1]);
      lcd.print(F("."));
      CulumnPosition=CulumnPosition+String(Ethernet.localIP()[0]+".."+Ethernet.localIP()[1]).length()+1;
    break;
    }
    case 30:{ // IP 2/2
      lcd.setCursor(CulumnPosition-1, 1);
      lcd.print(F("."));
      lcd.print(Ethernet.localIP()[2]);
      lcd.print(F("."));
      lcd.print(Ethernet.localIP()[3]);
      CulumnPosition=CulumnPosition+String(Ethernet.localIP()[2]+".."+Ethernet.localIP()[3]).length()+1;
    break;
    }
    case 31:{ // TrxNet device name (max 8 chars)
      lcd.setCursor(CulumnPosition-1, 1);
      char _dn[9];
      strncpy(_dn, trxDeviceName, 8);
      _dn[8] = '\0';
      lcd.print(_dn);
      CulumnPosition += strlen(_dn);
    break;
    }
    case 32:{ // TrxNet peer count
      lcd.setCursor(CulumnPosition-1, 1);
      lcd.print(net.peerCount());
      CulumnPosition += 1;
    break;
    }

  }
  if(ModeMenuStatus == 0){        // Mode
    CulumnPositionEnd = 11;
  }else{
    CulumnPositionEnd = 12;
  }
  while (CulumnPosition < CulumnPositionEnd) {    // if short, apend spaces
    lcd.print(F(" "));
    CulumnPosition++;
  }
} // END MenuToLCD
//------------------------------------------------------------------------
void Space(int MAX, int LENGHT, char CHARACTER){
  int NumberOfSpace = MAX-LENGHT;
  if(NumberOfSpace>0){
    for (int i=0; i<NumberOfSpace; i++){
      lcd.print(CHARACTER);
    }
  }
}
//-------------------------------------------------------------------------------------------------------
String PrintByte(byte ByteToPrint){
  String LCDstring = "";
  LCDstring.reserve(8);
  for (int i=0; i<8; i++){
    if (ByteToPrint & (1<<i)) {
      LCDstring += i+1;
    }
    else {
      LCDstring += " ";
    }
  }
  return LCDstring;
}
//-------------------------------------------------------------------------------------------------------
void OpenInterfaceMENUtimeout(){
  if(PreviousMenu != ActualMenu){
    ModeMenuStatus = 1;          // Menu
    PreviousMenu = ActualMenu;
    Timeout[1][0] = millis();                      // set time mark
  }
  if (millis()-Timeout[1][0] > (Timeout[1][1]) && ModeMenuStatus!=2 ){
    ModeMenuStatus = 0;         // Mode
  }
}
//-------------------------------------------------------------------------------------------------------
void OpenInterfaceMENU(){
      OpenInterfaceMENUtimeout();
      if (digitalRead(MENU) != ModeLastButtonState) {   // reading != lastbuttonstate
          Timeout[5][0] = millis();                // reset debounce timer
          ModeLastButtonState = !ModeLastButtonState;
      }
      if ((millis() - Timeout[5][0]) > Timeout[5][1]) {      // over deobounce timer
        if(digitalRead(MENU) == LOW && ModeDebouncedSignal==true){
          Timeout[6][0] = millis();                          // reset true press timer
          ModeDebouncedSignal=false;                              // flip-flop
        }
        if(digitalRead(MENU) == HIGH && ModeDebouncedSignal==false){
          ModeDebouncedSignal = true;                             // flip-flop
          if((millis() - Timeout[6][0]) < Timeout[6][1]){    // short detect
            if(ModeMenuStatus == 0){                       // if MENU disable, MODE active
              if (ptt_interlock_active == 1 && InterlockFromUdpActive == HIGH) {   // if UDP Interlock ON
                ptt_interlock_active = B00000;                            // manual UDP interlock OFF
                  LcdNeedRefresh=true;
              }else{
                // if(BAND_DECODER_IN==2 && ActualMode==2){ // kenwood && ssb > switch between fsk/dig
                //
                // }else{
                  ActualMode++;
                  if(ActualMode==6){
                    ActualMode=0;
                  }
                  if(ActualMode!=ActualModePrev){
                    ActualModePrev=ActualMode;
                    { uint8_t _m = oi3ModeToCiv(ActualMode); net.publish("/mode", &_m, sizeof(_m)); }
                    SwitchHardware(ActualMode);
                  }
                // }
              } // end if UDP Interlock ON
            }else{ // menu/set switch
              if(ModeMenuStatus==1){
                ModeMenuStatus=2;
              }else if(ModeMenuStatus==2){
                ModeMenuStatus=1;
                Timeout[1][0] = millis();
              }
              LcdNeedRefresh=true;
              // ActualMenu++;
              // if(ActualMenu > MenuTreeSize-1){
              //   ActualMenu=0;
              // }
            }
            TON(1);
          }else{                                            // Long detect
            // ModeMenuStatus = !ModeMenuStatus;               // MENU status
            if(ModeMenuStatus==0){
              ModeMenuStatus = 1;               // MENU status
            }else{
              ModeMenuStatus = 0;
            }
            if(ModeMenuStatus == 1){                     // if Menu
              Timeout[1][0] = millis();                      // set time mark
            }
            TON(0);
          }
        }
      }
}
//-------------------------------------------------------------------------------------------------------
void SwitchHardware(int SwitchHardwareMode){
  switch (SwitchHardwareMode) {
    case 0:{ // CW Keyer
        // primary_serial_port_mode = SERIAL_WINKEY_EMULATION;   // for k3ng code
        // Serial.end();
        // Serial.begin(1200);
        digitalWrite (WINKEY, HIGH);  // disable DTR/RTS
        digitalWrite (AFSK, LOW);
        break;
    }
    case 1:{ // CW DTR/RTS
        // primary_serial_port_mode = SERIAL_CLI;   // for k3ng code
        // Serial.end();
        // Serial.begin(SERBAUD0);
        digitalWrite (WINKEY, LOW);
        digitalWrite (AFSK, LOW);
        break;
    }
    case 2:{ // SSB
        digitalWrite (WINKEY, LOW);  // enable DTR/RTS for DVK
        digitalWrite (AFSK, LOW);
        break;
    }
    case 3:{ // FSK PC
        digitalWrite (WINKEY, LOW);
        digitalWrite (AFSK, LOW);
        break;
    }
    case 4:{ // FSK ASCII
        // Serial.begin(SERBAUD0);
        digitalWrite (WINKEY, HIGH);  // disable DTR/RTS
        digitalWrite (AFSK, LOW);
        Serial.flush();  // clear buffer before switch to serial2FSK
        break;
    }
    case 5:{ // DIGITAL (AFSK)
        // Serial.begin(PRIMARY_SERIAL_PORT_BAUD);
        digitalWrite (WINKEY, LOW);
        digitalWrite (AFSK, HIGH);
        break;
    }
  }  // endswitch
}
//-------------------------------------------------------------------------------------------------------
void OpenInterfaceMODE(){
  // MODE
  // Debugging("ActualMode "+String(ActualMode));
  switch (ActualMode) { // MODE
    case 0:{ // CW Keyer + WinKey
      if (K3NG_KEYER == true){
        K3NG_key();
      }
    break;
    }
    case 1:{ // CW dtr/rts
      if(digitalRead(PTT232)==HIGH){    // PTT-232
        // ptt_high(PTTmodeCW);
        ptt_high(PTTbyMode[ActualMode]);
        if(Ptt232Active == LOW){
          Ptt232Active = HIGH;
        }
      }else if(digitalRead(PTT232)==LOW && Ptt232Active == HIGH){       // only if activate from PTT232
        // ptt_low(PTTmodeCW,8);
        ptt_low(PTTbyMode[ActualMode],8);
        Ptt232Active = LOW;
      }
      if (K3NG_KEYER == true){
        K3NG_key();
      }
    break;
    }
    case 2:{ // SSB
      if(digitalRead(FootSW)==LOW){   // FootSW / 232(usb audio-ssb pc memory) PTT
        // ptt_high(PTTmodeSSB);
        ptt_high(PTTbyMode[ActualMode]);
        if(FootSwChange == 0){          // if change
          FootSwChange = 1;
          Debugging("FootSW-L "+String(FootSwChange));
        }
      }else{
        if(FootSwChange == 1){
          // ptt_low(PTTmodeSSB,9);
          ptt_low(PTTbyMode[ActualMode],9);
          FootSwChange = 0;
          Debugging("FootSW-H "+String(FootSwChange));
        }
      }
      if(digitalRead(PTT232)==HIGH){    // PTT-232 (audio DVK)
        // ptt_high(PTTmodeDIGI);
        ptt_high(PTTbyMode[ActualMode]);
        if(Ptt232Active == LOW){
          Ptt232Active = HIGH;
        }
      }else if(digitalRead(PTT232)==LOW && Ptt232Active == HIGH){       // only if activate from PTT232
        Ptt232Active = LOW;
        // ptt_low(PTTmodeDIGI,11);
        ptt_low(PTTbyMode[ActualMode],11);
      }
      MenuEncoder();
    break;
    }
    case 3:{ // FSK PC
      if (FSK_RX==1){
        fskDecoder();
      }
      if (FSK_TX==1){
        ButtonFSK();
      }
      if(digitalRead(PTT232)==HIGH){    // PTT-232
        // ptt_high(PTTmodeFSK);
        ptt_high(PTTbyMode[ActualMode]);
        if(Ptt232Active == LOW){
          Ptt232Active = HIGH;
        }
      }else if(digitalRead(PTT232)==LOW && Ptt232Active == HIGH){       // only if activate from PTT232
        Ptt232Active = LOW;
        // ptt_low(PTTmodeFSK,10);
        ptt_low(PTTbyMode[ActualMode],10);
      }
      MenuEncoder();
    break;
    }
    case 4:{ // FSK CLI
      if (FSK_TX==true){
        ButtonFSK();
        Serial2FSK();
      }
      MenuEncoder();
    break;
    }
    case 5:{ // DIGITAL (AFSK)
      if(digitalRead(PTT232)==HIGH){    // PTT-232
        // ptt_high(PTTmodeDIGI);
        ptt_high(PTTbyMode[ActualMode]);
        if(Ptt232Active == LOW){
          Ptt232Active = HIGH;
        }
      }else if(digitalRead(PTT232)==LOW && Ptt232Active == HIGH){       // only if activate from PTT232
        Ptt232Active = LOW;
        // ptt_low(PTTmodeDIGI,11);
        ptt_low(PTTbyMode[ActualMode],11);
      }
      MenuEncoder();
    break;
    }
  }  // endswitch
}
//-------------------------------------------------------------------------------------------------------
// TONE
int TON(int ToneType){
  if (BUTTON_BEEP == true){
    switch (ToneType) {
      case 0: tone(TONE, 200, 200); break;
      case 1: tone(TONE, 400, 50); break;
      case 2: tone(TONE, 300, 20); break;
    }
  }
}
//-------------------------------------------------------------------------------------------------------

// VOLT
float volt(int raw, float K, float DELTA) {
  float voltage = (raw * 5.0) / 1024.0 * K + DELTA;    // K - resistor coeficient
  return voltage;
}
//-------------------------------------------------------------------------------------------------------

void ButtonFSK(){
  tmp = analogRead(MEM);
  if(tmp < 5){
    FSKmemoryTX(1);
  }else if(tmp > 45 && tmp < 130){
    FSKmemoryTX(2);
  }else if(tmp > 130 && tmp < 210){
    FSKmemoryTX(3);
  }else if(digitalRead(PADDLER) == LOW){
    FSKmemoryTX(4);
  }else if(digitalRead(PADDLEL) == LOW){
    FSKmemoryTX(5);
  }
}

//-------------------------------------------------------------------------------------------------------

// MEMORY TO FSK TX
void FSKmemoryTX(int memory){
  fig1 = 1;                         // every shift to start message
  lcd.setCursor(positionCounter+1, 0);
  if (AFSK_ENABLE == true){
    tone(TONE, MARK);
  }
  // ptt_high(PTTmodeFSK);
  ptt_high(PTTbyMode[ActualMode]);
  tmp = FSKmemory[memory].length();
  for (i = 0; i < tmp; i++) {
    positionCounter++;
    if (positionCounter > 15){
        lcd.setCursor(0, 0);
        lcd.print(F("                "));
        lcd.setCursor(0, 0);
        positionCounter=0;
    }
    ch = toUpperCase(FSKmemory[memory].charAt(i));
    chTable();

    if(fig1 == 0 && fig2 == 1){
            d1 = 1; d2 = 1; d3 = 0; d4 = 1; d5 = 1; //FIGURES
            if (SHOW_HIDDEN_FSK_CHAR == true){
              lcd.write(byte(2));                     // UP LCD char
            }
            sendFsk();
    }else if(fig1 == 1 && fig2 == 0){
            d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 1; //LETTERS
            if (SHOW_HIDDEN_FSK_CHAR == true){
              lcd.write(byte(3));                     // DWN LCD char
            }
            sendFsk();
    }else if(space == 1 && fig2 == 1){
            d1 = 1; d2 = 1; d3 = 0; d4 = 1; d5 = 1; //FIGURES
            if (SHOW_HIDDEN_FSK_CHAR == true){
              lcd.write(byte(2));                     // UP LCD char
            }
            sendFsk();
    }

    if(fig2 == 0 || fig2 == 1){
            space = 0;
            fig1 = fig2;
    }

    if (ch == '\r'){              // CR LCD char
            if (SHOW_HIDDEN_FSK_CHAR == true){
              lcd.write(byte(0));
            }
    }else if(ch == '\n'){         // LF LCD char
            if (SHOW_HIDDEN_FSK_CHAR == true){
              lcd.write(byte(1));
            }
    }else{
              lcd.print(ch);
    }
    chTable();
    sendFsk();
    delay(5);
  }
  // ptt_low(PTTmodeFSK,12);
  ptt_low(PTTbyMode[ActualMode],12);
  if (SERIAL_FSK_TX_ECHO == true){
      Serial.println();
  }
  digitalWrite(FSK, LOW);
  if (AFSK_ENABLE == true){
    noTone(TONE);
  }
}

// SERIAL TO FSK TX
void Serial2FSK(){
    if (Serial.available()) {
      InterruptON(0,0,0); // keyb, enc, gps, Interlock
        fig1 = 1;                         // every shift to start message
        lcd.setCursor(positionCounter, 0);
        if (AFSK_ENABLE == true){
          tone(TONE, MARK);
        }
        // ptt_high(PTTmodeFSK);
        ptt_high(PTTbyMode[ActualMode]);
        // ch = ' '; Serial.print(ch); chTable(); sendFsk();   // Space before sending
        while (Serial.available()) {
            positionCounter++;
            if (positionCounter > 15){
                lcd.setCursor(0, 0);
                lcd.print(F("                "));
                lcd.setCursor(0, 0);
                positionCounter=0;
            }
            ch = toUpperCase(Serial.read());
            chTable();

            if(fig1 == 0 && fig2 == 1){
                    d1 = 1; d2 = 1; d3 = 0; d4 = 1; d5 = 1; //FIGURES
                    if (SHOW_HIDDEN_FSK_CHAR == true){
                      lcd.write(byte(2));                     // UP LCD char
                    }
                    sendFsk();
            }else if(fig1 == 1 && fig2 == 0){
                    d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 1; //LETTERS
                    if (SHOW_HIDDEN_FSK_CHAR == true){
                      lcd.write(byte(3));                     // DWN LCD char
                    }
                    sendFsk();
            }else if(space == 1 && fig2 == 1){
                    d1 = 1; d2 = 1; d3 = 0; d4 = 1; d5 = 1; //FIGURES
                    if (SHOW_HIDDEN_FSK_CHAR == true){
                      lcd.write(byte(2));                     // UP LCD char
                    }
                    sendFsk();
            }

            if(fig2 == 0 || fig2 == 1){
                    space = 0;
                    fig1 = fig2;
            }

            if (ch == '\r'){              // CR LCD char
              if (SHOW_HIDDEN_FSK_CHAR == true){
                lcd.write(byte(0));
              }
            }else if(ch == '\n'){         // LF LCD char
              if (SHOW_HIDDEN_FSK_CHAR == true){
                lcd.write(byte(1));
              }
            }else{
                      lcd.print(ch);
            }
            chTable();
            sendFsk();
            delay(5);
        }
        // ch = ' '; Serial.print(ch); chTable(); sendFsk();   // Space after sending
        // ptt_low(PTTmodeFSK,13);
        ptt_low(PTTbyMode[ActualMode],13);
        if (SERIAL_FSK_TX_ECHO == true){
            Serial.println();
        }
        digitalWrite(FSK, LOW);
        if (AFSK_ENABLE == true){
          noTone(TONE);
        }
      }
      InterruptON(1,1,1); // keyb, enc, gps, Interlock
}

void sendFsk(){
        if (SERIAL_FSK_TX_ECHO == true){
              Serial.print(d1);Serial.print(d2);Serial.print(d3);Serial.print(d4);Serial.print(d5);Serial.print(' '); // 5bit code serial echo
              //Serial.print(OneBit);Serial.print('|');Serial.print(OneBit*StopBit);Serial.print(' ');                  // ms
        }
        //--start bit
        digitalWrite(FSK, FSPACE);
          if (AFSK_ENABLE == true){
            tone(TONE, SPACE);
          }
        delay(OneBit);
        //--bit1
        if(d1 == 1){digitalWrite(FSK, FMARK);
          if (AFSK_ENABLE == true){
            tone(TONE, MARK);
          }
        }
        else       {digitalWrite(FSK, FSPACE);
          if (AFSK_ENABLE == true){
            tone(TONE, SPACE);
          }
        } delay(OneBit);
        //--bit2
        if(d2 == 1){digitalWrite(FSK, FMARK);
          if (AFSK_ENABLE == true){
            tone(TONE, MARK);
          }
        }
        else       {digitalWrite(FSK, FSPACE);
          if (AFSK_ENABLE == true){
            tone(TONE, SPACE);
          }
        } delay(OneBit);
        //--bit3
        if(d3 == 1){digitalWrite(FSK, FMARK);
          if (AFSK_ENABLE == true){
            tone(TONE, MARK);
          }
        }
        else       {digitalWrite(FSK, FSPACE);
          if (AFSK_ENABLE == true){
            tone(TONE, SPACE);
          }
        } delay(OneBit);
        //--bit4
        if(d4 == 1){digitalWrite(FSK, FMARK);
          if (AFSK_ENABLE == true){
            tone(TONE, MARK);
          }
        }
        else       {digitalWrite(FSK, FSPACE);
          if (AFSK_ENABLE == true){
            tone(TONE, SPACE);
          }
        } delay(OneBit);
        //--bit5
        if(d5 == 1){digitalWrite(FSK, FMARK);
          if (AFSK_ENABLE == true){
            tone(TONE, MARK);
          }
        }
        else       {digitalWrite(FSK, FSPACE);
          if (AFSK_ENABLE == true){
            tone(TONE, SPACE);
          }
        } delay(OneBit);
        //--stop bit
        digitalWrite(FSK, FMARK);
          if (AFSK_ENABLE == true){
            tone(TONE, MARK);
          }
        delay(OneBit*StopBit);
}

void chTable()
{
        fig2 = -1;
        if(ch == ' ')
        {
                d1 = 0; d2 = 0; d3 = 1; d4 = 0; d5 = 0;
                space = 1;
        }
        else if(ch == 'A'){d1 = 1; d2 = 1; d3 = 0; d4 = 0; d5 = 0; fig2 = 0;}
        else if(ch == 'B'){d1 = 1; d2 = 0; d3 = 0; d4 = 1; d5 = 1; fig2 = 0;}
        else if(ch == 'C'){d1 = 0; d2 = 1; d3 = 1; d4 = 1; d5 = 0; fig2 = 0;}
        else if(ch == 'D'){d1 = 1; d2 = 0; d3 = 0; d4 = 1; d5 = 0; fig2 = 0;}
        else if(ch == 'E'){d1 = 1; d2 = 0; d3 = 0; d4 = 0; d5 = 0; fig2 = 0;}
        else if(ch == 'F'){d1 = 1; d2 = 0; d3 = 1; d4 = 1; d5 = 0; fig2 = 0;}
        else if(ch == 'G'){d1 = 0; d2 = 1; d3 = 0; d4 = 1; d5 = 1; fig2 = 0;}
        else if(ch == 'H'){d1 = 0; d2 = 0; d3 = 1; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == 'I'){d1 = 0; d2 = 1; d3 = 1; d4 = 0; d5 = 0; fig2 = 0;}
        else if(ch == 'J'){d1 = 1; d2 = 1; d3 = 0; d4 = 1; d5 = 0; fig2 = 0;}
        else if(ch == 'K'){d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 0; fig2 = 0;}
        else if(ch == 'L'){d1 = 0; d2 = 1; d3 = 0; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == 'M'){d1 = 0; d2 = 0; d3 = 1; d4 = 1; d5 = 1; fig2 = 0;}
        else if(ch == 'N'){d1 = 0; d2 = 0; d3 = 1; d4 = 1; d5 = 0; fig2 = 0;}
        else if(ch == 'O'){d1 = 0; d2 = 0; d3 = 0; d4 = 1; d5 = 1; fig2 = 0;}
        else if(ch == 'P'){d1 = 0; d2 = 1; d3 = 1; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == 'Q'){d1 = 1; d2 = 1; d3 = 1; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == 'R'){d1 = 0; d2 = 1; d3 = 0; d4 = 1; d5 = 0; fig2 = 0;}
        else if(ch == 'S'){d1 = 1; d2 = 0; d3 = 1; d4 = 0; d5 = 0; fig2 = 0;}
        else if(ch == 'T'){d1 = 0; d2 = 0; d3 = 0; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == 'U'){d1 = 1; d2 = 1; d3 = 1; d4 = 0; d5 = 0; fig2 = 0;}
        else if(ch == 'V'){d1 = 0; d2 = 1; d3 = 1; d4 = 1; d5 = 1; fig2 = 0;}
        else if(ch == 'W'){d1 = 1; d2 = 1; d3 = 0; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == 'X'){d1 = 1; d2 = 0; d3 = 1; d4 = 1; d5 = 1; fig2 = 0;}
        else if(ch == 'Y'){d1 = 1; d2 = 0; d3 = 1; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == 'Z'){d1 = 1; d2 = 0; d3 = 0; d4 = 0; d5 = 1; fig2 = 0;}
        else if(ch == '0'){d1 = 0; d2 = 1; d3 = 1; d4 = 0; d5 = 1; fig2 = 1;}
        else if(ch == '1'){d1 = 1; d2 = 1; d3 = 1; d4 = 0; d5 = 1; fig2 = 1;}
        else if(ch == '2'){d1 = 1; d2 = 1; d3 = 0; d4 = 0; d5 = 1; fig2 = 1;}
        else if(ch == '3'){d1 = 1; d2 = 0; d3 = 0; d4 = 0; d5 = 0; fig2 = 1;}
        else if(ch == '4'){d1 = 0; d2 = 1; d3 = 0; d4 = 1; d5 = 0; fig2 = 1;}
        else if(ch == '5'){d1 = 0; d2 = 0; d3 = 0; d4 = 0; d5 = 1; fig2 = 1;}
        else if(ch == '6'){d1 = 1; d2 = 0; d3 = 1; d4 = 0; d5 = 1; fig2 = 1;}
        else if(ch == '7'){d1 = 1; d2 = 1; d3 = 1; d4 = 0; d5 = 0; fig2 = 1;}
        else if(ch == '8'){d1 = 0; d2 = 1; d3 = 1; d4 = 0; d5 = 0; fig2 = 1;}
        else if(ch == '9'){d1 = 0; d2 = 0; d3 = 0; d4 = 1; d5 = 1; fig2 = 1;}
        else if(ch == '-'){d1 = 1; d2 = 1; d3 = 0; d4 = 0; d5 = 0; fig2 = 1;}
        else if(ch == '?'){d1 = 1; d2 = 0; d3 = 0; d4 = 1; d5 = 1; fig2 = 1;}
        else if(ch == ':'){d1 = 0; d2 = 1; d3 = 1; d4 = 1; d5 = 0; fig2 = 1;}
        else if(ch == '('){d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 0; fig2 = 1;}
        else if(ch == ')'){d1 = 0; d2 = 1; d3 = 0; d4 = 0; d5 = 1; fig2 = 1;}
        else if(ch == '.'){d1 = 0; d2 = 0; d3 = 1; d4 = 1; d5 = 1; fig2 = 1;}
        else if(ch == ','){d1 = 0; d2 = 0; d3 = 1; d4 = 1; d5 = 0; fig2 = 1;}
        else if(ch == '/'){d1 = 1; d2 = 0; d3 = 1; d4 = 1; d5 = 1; fig2 = 1;}
        else if(ch == '+'){d1 = 1; d2 = 0; d3 = 0; d4 = 0; d5 = 1; fig2 = 1;} //ITA2
        else if(ch == '\n'){d1 = 0; d2 = 1; d3 = 0; d4 = 0; d5 = 0;} //LF
        else if(ch == '\r'){d1 = 0; d2 = 0; d3 = 0; d4 = 1; d5 = 0;} //CR
        else
        {
                ch = ' ';
                d1 = 0; d2 = 0; d3 = 1; d4 = 0; d5 = 0;
                space = 1;
        }
}

// FSK DECODER by JI3BNB
void timer_interrupt(void){
        static byte rSq;
        ti++;
        if(rSq == 0 && digitalRead(FSKDET) == 0){
                rSq = 1;
                ti = 0;
        }
        if(rSq == 1 && ti == 10){
                if(digitalRead(FSKDET) == 0){
                        rSq = 2;
                        ti = 0;
                }else{
                        rSq = 0;
                }
        }
        if(rSq == 2 && ti == 22){
                bitWrite(baudot, 0, digitalRead(FSKDET));
        }
        if(rSq == 2 && ti == 44){
                bitWrite(baudot, 1, digitalRead(FSKDET));
        }
        if(rSq == 2 && ti == 66){
                bitWrite(baudot, 2, digitalRead(FSKDET));
        }
        if(rSq == 2 && ti == 88){
                bitWrite(baudot, 3, digitalRead(FSKDET));
        }
        if(rSq == 2 && ti == 110){
                bitWrite(baudot, 4, digitalRead(FSKDET));
                dsp = 1;
        }
        if(rSq == 2 && ti == 135){
                rSq = 0;
        }
}

void fskDecoder(){
        if(dsp == 1){
                chIn = '\0';
                     if(baudot == B11111){fig = 0; } //LETTERS
                else if(baudot == B11011){fig = 1; } //FIGURES
                else if(baudot == B01000){         } //CR
                else if(baudot == B00010){chIn = ' ';} //LF
                else if(baudot == B00100){chIn = ' ';} //SPACE
                if(fig == 0){
                             if(baudot == B00011){chIn = 'a';}
                        else if(baudot == B11001){chIn = 'b';}
                        else if(baudot == B01110){chIn = 'c';}
                        else if(baudot == B01001){chIn = 'd';}
                        else if(baudot == B00001){chIn = 'e';}
                        else if(baudot == B01101){chIn = 'f';}
                        else if(baudot == B11010){chIn = 'g';}
                        else if(baudot == B10100){chIn = 'h';}
                        else if(baudot == B00110){chIn = 'i';}
                        else if(baudot == B01011){chIn = 'j';}
                        else if(baudot == B01111){chIn = 'k';}
                        else if(baudot == B10010){chIn = 'l';}
                        else if(baudot == B11100){chIn = 'm';}
                        else if(baudot == B01100){chIn = 'n';}
                        else if(baudot == B11000){chIn = 'o';}
                        else if(baudot == B10110){chIn = 'p';}
                        else if(baudot == B10111){chIn = 'q';}
                        else if(baudot == B01010){chIn = 'r';}
                        else if(baudot == B00101){chIn = 's';}
                        else if(baudot == B10000){chIn = 't';}
                        else if(baudot == B00111){chIn = 'u';}
                        else if(baudot == B11110){chIn = 'v';}
                        else if(baudot == B10011){chIn = 'w';}
                        else if(baudot == B11101){chIn = 'x';}
                        else if(baudot == B10101){chIn = 'y';}
                        else if(baudot == B10001){chIn = 'z';}
                }
                if(fig == 1){
                             if(baudot == B00011){chIn = '-';}
                        else if(baudot == B11001){chIn = '?';}
                        else if(baudot == B01110){chIn = ':';}
                        else if(baudot == B01001){         }
                        else if(baudot == B00001){chIn = '3';}
                        else if(baudot == B01101){         }
                        else if(baudot == B11010){         }
                        else if(baudot == B10100){         }
                        else if(baudot == B00110){chIn = '8';}
                        else if(baudot == B01011){         }
                        else if(baudot == B01111){chIn = '(';}
                        else if(baudot == B10010){chIn = ')';}
                        else if(baudot == B11100){chIn = '.';}
                        else if(baudot == B01100){chIn = ',';}
                        else if(baudot == B11000){chIn = '9';}
                        else if(baudot == B10110){chIn = '0';}
                        else if(baudot == B10111){chIn = '1';}
                        else if(baudot == B01010){chIn = '4';}
                        else if(baudot == B00101){         }
                        else if(baudot == B10000){chIn = '5';}
                        else if(baudot == B00111){chIn = '7';}
                        else if(baudot == B11110){         }
                        else if(baudot == B10011){chIn = '2';}
                        else if(baudot == B11101){chIn = '/';}
                        else if(baudot == B10101){chIn = '6';}
                        else if(baudot == B10001){         }
                }
                if(chIn != '\0'){
                          lcd.setCursor(positionCounter, 0);
                          positionCounter++;
                          if (positionCounter > 15){
                              lcd.setCursor(0, 0);
                              lcd.print(F("                "));
                              lcd.setCursor(0, 0);
                              positionCounter=0;
                          }
                          lcd.print(chIn);
                }
                dsp = 0;
        }
        delay(5);
}
//-------------------------------------------------------------------------------------------------------

void BandDecoder() {
  if (BAND_DECODER_IN > 0 && SequencerLevel == 0){
    // SERIAL IN
    if (BAND_DECODER_IN == 5){  // INPUT_SERIAL

        while (Serial.available() > 0) {
            BAND = Serial.parseInt();
            freq = Serial.parseInt();
            if (Serial.read() == '\n') {
                bandSET();
                #if defined(REMOTE_RELAY)
                    remoteRelay();
                    previous3 = millis();     // set time mark
                #endif
                #if defined(SERIAL_echo)
                    serialEcho();
                #endif
                if (BAND_DECODER_WATCHDOG > 0){
                    Timeout[3][0] = millis();                      // set time mark
                }
            }
        }
        if (BAND_DECODER_WATCHDOG > 0){
            watchDog();
        }
    }

    // ICOM ACC VOLTAGE IN
    if (BAND_DECODER_IN == 7){  // ICOM_ACC
        if (millis() - Timeout[2][0] > (Timeout[2][1])){
            VALUE = analogRead(ACC19);
            if (counter == 5) {
                VOLTAGE = float(VALUE) * 5.0 / 1023.0;

                //=====[ Icom ACC voltage range ]===========================================================

                if (VOLTAGE > 0.73 && VOLTAGE < 1.00 ) {BAND=10;}  //   6m   * * * * * * * * * * * * * * * *
                if (VOLTAGE > 1.00 && VOLTAGE < 1.09 ) {BAND=9;}   //  10m   *           Need              *
                if (VOLTAGE > 1.09 && VOLTAGE < 1.32 ) {BAND=8;}   //  12m   *    calibrated to your       *
                if (VOLTAGE > 1.32 && VOLTAGE < 1.55 ) {BAND=7;}   //  15m   *         own ICOM            *
                if (VOLTAGE > 1.55 && VOLTAGE < 1.77 ) {BAND=6;}   //  17m   *     ----------------        *
                if (VOLTAGE > 1.77 && VOLTAGE < 2.24 ) {BAND=5;}   //  20m   *    (These values have       *
                if (VOLTAGE > 0.10 && VOLTAGE < 0.50 ) {BAND=4;}   //  30m   *   been measured by any)     *
                if (VOLTAGE > 2.24 && VOLTAGE < 2.73 ) {BAND=3;}   //  40m   *          ic-746             *
                if (VOLTAGE > 2.73 && VOLTAGE < 2.99 ) {BAND=2;}   //  80m   *                             *
                if (VOLTAGE > 2.99 && VOLTAGE < 4.00 ) {BAND=1;}   // 160m   * * * * * * * * * * * * * * * *
                if (VOLTAGE > 0.00 && VOLTAGE < 0.10 ) {BAND=0;}   // parking

                //==========================================================================================

                bandSET();                                // set outputs
            }else{
                if (abs(prevVALUE-VALUE)>10) {            // average
                    //means change or spurious number
                    prevVALUE=VALUE;
                }else {
                    counter++;
                    prevVALUE=VALUE;
                }
            }
            #if defined(REMOTE_RELAY)
                remoteRelay();
                previous3 = millis();     // set time mark
            #endif
            #if defined(SERIAL_echo)
                serialEcho();
                Serial.print(VOLTAGE);
                Serial.println(F(" V"));
                Serial.flush();
            #endif
            Timeout[2][0] = millis();                      // set time mark
       }
    }

    // ICOM CI-V IN
    if (BAND_DECODER_IN == 1){  // ICOM_CIV
        if(BAND_DECODER_REQUEST > 0){
            if (millis() - Timeout[4][0] > (Timeout[4][1])){
                txCIV(3, 0, CIV_ADRESS);                    // ([command], [freq]) 3=read freq
                Timeout[4][0] = millis();              // set time mark
            }
        }

        if (BAND_DECODER_IN == 1){  // ICOM_CIV
            if (Serial2.available() > 0) {
              InterruptON(0,0,0); // keyb, enc, gps, Interlock
                incomingByte = Serial2.read();
                icomSM(incomingByte);
                rdS="";
                if(rdI[4]==0x03 && rdI[10]==0xFD){    // Freq - 03 command and state machine end
                    for (int i=9; i>=5; i-- ){
                        if (rdI[i] < 10) {            // leading zero
                            rdS = rdS + 0;
                        }
                        rdS = rdS + String(rdI[i], HEX); // append BCD digit from HEX variable to string
                    }
                    freq = rdS.toInt();
                    FreqToBandRules(freq);
                    bandSET();                             // set outputs relay
                    txCIV(4, 0, CIV_ADRESS);               // ([command], [freq]) 4=read MODE

                    #if defined(REMOTE_RELAY)
                        remoteRelay();
                        previous3 = millis();     // set time mark
                    #endif
                    #if defined(SERIAL_echo)
                        serialEcho();
                    #endif
                    if (BAND_DECODER_WATCHDOG > 0){
                        Timeout[3][0] = millis(); // set time mark
                    }
                }
                if(rdI[4]==0x04 && rdI[7]==0xFD && freq!=0){    // Mode - 04 command and state machine end
                  ActualMode=CIVModeSet[rdI[5]];        // set mode by CIVModeSet table
                  if(ActualMode!=ActualModePrev){
                    ActualModePrev=ActualMode;
                    { uint8_t _m = oi3ModeToCiv(ActualMode); net.publish("/mode", &_m, sizeof(_m)); }
                    SwitchHardware(ActualMode);
                  }
                }
                InterruptON(1,1,1); // keyb, enc, gps, Interlock
            }
        }

        if (BAND_DECODER_WATCHDOG > 0){
            watchDog();
        }
    }

    // YAESU BCD IN
    if (BAND_DECODER_IN == 6){  // YAESU_BCD
        if (millis() - Timeout[2][0] > (Timeout[2][1])){
            YBCD1 = digitalRead(BCD1);
            YBCD2 = digitalRead(BCD2);
            YBCD3 = digitalRead(BCD3);
            YBCD4 = digitalRead(BCD4);
            bool BCDmatrix[4][15] = { /*

            =======[ Input BCD ]====================================================================

                      BCD 1 --> */ { 0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0 }, /*
                      BCD 2 --> */ { 0,  0,  1,  1,  0,  0,  1,  1,  0,  0,  1,  1,  0,  0,  1 }, /*
                      BCD 3 --> */ { 0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  1,  1,  1 }, /*
                      BCD 4 --> */ { 0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1 }, /*
                                     |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
                                     V   V   V   V   V   V   V   V   V   V   V   V   V   V   V
            -------------------------------------------------------------------------------------
            Band # in matrix table   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
            Yaesu BCD                   160 80  40  30  20  17  15  12  10  6m  <--- free --->     FT-1000MP ?
            -------------------------------------------------------------------------------------

            ========================================================================================
            */};

            for (bandBCD=0; bandBCD<15; bandBCD++){
                  if (BCDmatrix[0][bandBCD]==BCD1 && BCDmatrix[1][bandBCD]==BCD2 && BCDmatrix[2][bandBCD]==BCD3 && BCDmatrix[3][bandBCD]==BCD4){
                        BAND=bandBCD;
                  }
            }
            bandSET();                         // set outputs
            #if defined(REMOTE_RELAY)
                remoteRelay();
                previous3 = millis();     // set time mark
            #endif
            #if defined(SERIAL_echo)
                serialEcho();
            #endif
            Timeout[2][0] = millis();                      // set time mark
        }
    }

    // KENWOOD CAT IN
    if (BAND_DECODER_IN == 2){  // KENWOOD_PC
        while (Serial2.available()) {
            rdS="";
            Serial2.readBytesUntil(lf, rdK, 38);       // fill array from serial
                if (rdK[0] == 73 && rdK[1] == 70){     // filter
                    for (int i=2; i<=12; i++){          // 3-13 position to freq
                        rdS = rdS + String(rdK[i]);   // append variable to string
                    }
                    freq = rdS.toInt();
                    FreqToBandRules(freq);
                    bandSET();                                              // set outputs relay

                    #if defined(REMOTE_RELAY)
                        remoteRelay();
                        previous3 = millis();     // set time mark
                    #endif
                    #if defined(SERIAL_echo)
                        serialEcho();
                    #endif
                    if (BAND_DECODER_WATCHDOG > 0){
                        Timeout[3][0] = millis();                      // set time mark
                    }
                    if(freq!=0){
                      ActualMode=KenwoodCatModeSet[String(rdK[29]).toInt()];        // get mode
                      if(ActualMode!=ActualModePrev){
                        ActualModePrev=ActualMode;
                        { uint8_t _m = oi3ModeToCiv(ActualMode); net.publish("/mode", &_m, sizeof(_m)); }
                        SwitchHardware(ActualMode);
                      }
                    }
                }
                memset(rdK, 0, sizeof(rdK));   // Clear contents of Buffer
        }
        if (BAND_DECODER_WATCHDOG > 0){
            watchDog();
        }

        if(BAND_DECODER_REQUEST > 0){
            if (millis() - Timeout[4][0] > (Timeout[4][1])){
                Serial2.print(F("IF;"));
                Serial2.flush();
                Timeout[4][0] = millis();              // set time mark
            }
        }
    }

    // YAESU CAT IN
    if (BAND_DECODER_IN == 3){  // YAESU_CAT
        while (Serial2.available()) {
            rdS="";
            Serial2.readBytesUntil(lf, rdY, 38);         // fill array from serial
                if (rdY[0] == 73 && rdY[1] == 70){      // filter
                    for (int i=5; i<=12; i++){          // 6-13 position to freq
                        rdS = rdS + String(rdY[i]);   // append variable to string
                    }
                    freq = rdS.toInt();
                    FreqToBandRules(freq);
                    bandSET();                                              // set outputs relay

                    #if defined(REMOTE_RELAY)
                        remoteRelay();
                        previous3 = millis();     // set time mark
                    #endif
                    #if defined(SERIAL_echo)
                        serialEcho();
                    #endif
                    if (BAND_DECODER_WATCHDOG > 0){
                        Timeout[3][0] = millis();                      // set time mark
                    }
                }
                memset(rdY, 0, sizeof(rdY));   // Clear contents of Buffer
        }
        if (BAND_DECODER_WATCHDOG > 0){
            watchDog();
        }

        if(BAND_DECODER_REQUEST > 0){
            if (millis() - Timeout[4][0] > (Timeout[4][1])){
                Serial2.print(F("IF;"));
                Serial2.flush();
                Timeout[4][0] = millis();              // set time mark
            }
        }
    }

    // YAESU CAT OLD IN
    if (BAND_DECODER_IN == 4){  // YAESU_CAT_OLD
        // tested on FT-817
        if(BAND_DECODER_REQUEST > 0){
            if (millis() - Timeout[4][0] > (Timeout[4][1])){
                Serial2.write(0);                                    // byte 1
                Serial2.write(0);                                    // byte 2
                Serial2.write(0);                                    // byte 3
                Serial2.write(0);                                    // byte 4
                Serial2.write(3);                                    // read freq
                Serial2.flush();
                Timeout[4][0] = millis();              // set time mark
            }
        }

        while (Serial2.available()) {
            rdS="";
            Serial2.readBytesUntil('240', rdYO, 5);                   // fill array from serial (240 = 0xF0)
            if (rdYO[0] != 0xF0 && rdYO[1] != 0xF0 && rdYO[2] != 0xF0 && rdYO[3] != 0xF0 && rdYO[4] != 0xF0 && rdYO[5] != 0xF0){     // filter
                for (int i=0; i<4; i++ ){
                    if (rdYO[i] < 10) {                              // leading zero
                        rdS = rdS + 0;
                    }
                    rdS = rdS + String(rdYO[i], HEX);            // append BCD digit from HEX variable to string
                }
                rdS = rdS + 0;                                   // append Hz
                freq = rdS.toInt();
                FreqToBandRules(freq);
                bandSET();                                                                // set outputs relay

                #if defined(REMOTE_RELAY)
                    remoteRelay();
                    previous3 = millis();     // set time mark
                #endif
                #if defined(SERIAL_echo)
                    serialEcho();
                #endif
                if (BAND_DECODER_WATCHDOG > 0){
                    Timeout[3][0] = millis();                      // set time mark
                }
                ActualMode=YaesuModeSet[rdYO[4]];        // set mode by YaesuModeSet table
                if(ActualMode!=ActualModePrev){
                  ActualModePrev=ActualMode;
                  { uint8_t _m = oi3ModeToCiv(ActualMode); net.publish("/mode", &_m, sizeof(_m)); }
                  SwitchHardware(ActualMode);
                }
            }
            memset(rdYO, 0, sizeof(rdYO));   // Clear contents of Buffer
        }
        if (BAND_DECODER_WATCHDOG > 0){
            watchDog();
        }
    }

    // Remote relay OUT (not use)
    #if defined(REMOTE_RELAY)
        if (millis() - Timeout[4][0] > (Timeout[4][1])){
            remoteRelay();
            Timeout[4][0] = millis();              // set time mark
        }
    #endif

    // ICOM CI-V OUT
    #if defined(ICOM_CIV_OUT)
        if(freq!= freqPrev1){                    // if change
            txCIVoutSub(0x07, 0xD2, 0x00, CIV_ADRESS);  // IC-7610: explicitly select MAIN band
            txCIVout(5, freq, CIV_ADRESS);          // 5 - set operating frequency using configured CI-V address
            freqPrev1 = freq;
        }
    #endif

    // KENWOOD CAT OUT
    #if defined(KENWOOD_PC_OUT)
        if(freq != freqPrev2){                     // if change
            String freqPCtx = String(freq);        // to string
            freqPCtx.reserve(11);
            while (freqPCtx.length() < 11) {       // leding zeros
                freqPCtx = 0 + freqPCtx;
            }
           Serial3.print("FA" + freqPCtx + ";");    // sets both VFO
           Serial3.print("FB" + freqPCtx + ";");
 //          Serial2.print("FA" + freqPCtx + ";");    // first packet not read every time
           Serial3.flush();
           freqPrev2 = freq;
        }
    #endif

    // YAESU CAT OUT
    #if defined(YAESU_CAT_OUT)
        if(freq != freqPrev2){                     // if change
            String freqPCtx = String(freq);        // to string
            freqPCtx.reserve(8);
            while (freqPCtx.length() < 8) {        // leding zeros
                freqPCtx = 0 + freqPCtx;
            }
           Serial3.print("FA" + freqPCtx + ";");    // sets both VFO
           Serial3.print("FB" + freqPCtx + ";");
           Serial3.flush();
           freqPrev2 = freq;
        }
    #endif

    // YAESU CAT OLD OUT
    #if defined(YAESU_CAT_OUT_OLD)
        if(freq != freqPrev2){                     // if change
            String freqPCtx = String(freq);        // to string
            freqPCtx.reserve(8);
            while (freqPCtx.length() < 8) {        // leding zeros
                freqPCtx = 0 + freqPCtx;
           }
           Serial3.write(1);                       // set freq
           Serial3.flush();
           freqPrev2 = freq;
        }
    #endif
  }
}

//-------------------------------------------------------------------------------------------------------

void FreqToBandRules(long freq){
         if (freq >=Freq2Band[0][0] && freq <=Freq2Band[0][1] )  {BAND=1;}  // 160m
    else if (freq >=Freq2Band[1][0] && freq <=Freq2Band[1][1] )  {BAND=2;}  //  80m
    else if (freq >=Freq2Band[2][0] && freq <=Freq2Band[2][1] )  {BAND=3;}  //  40m
    else if (freq >=Freq2Band[3][0] && freq <=Freq2Band[3][1] )  {BAND=4;}  //  30m
    else if (freq >=Freq2Band[4][0] && freq <=Freq2Band[4][1] )  {BAND=5;}  //  20m
    else if (freq >=Freq2Band[5][0] && freq <=Freq2Band[5][1] )  {BAND=6;}  //  17m
    else if (freq >=Freq2Band[6][0] && freq <=Freq2Band[6][1] )  {BAND=7;}  //  15m
    else if (freq >=Freq2Band[7][0] && freq <=Freq2Band[7][1] )  {BAND=8;}  //  12m
    else if (freq >=Freq2Band[8][0] && freq <=Freq2Band[8][1] )  {BAND=9;}  //  10m
    else if (freq >=Freq2Band[9][0] && freq <=Freq2Band[9][1] ) {BAND=10;}  //   6m
    else if (freq >=Freq2Band[10][0] && freq <=Freq2Band[10][1] ) {BAND=11;}  //   2m
    else {BAND=0;}                                                // out of range
}

// BAND DATA OUT
void bandSET() {
    Timeout[4][0] = millis();              // set time mark REQUESt time out
    #if defined(BCD_OUT)
        bcdOut();
    #endif
    if (EnableEthernet==1 && (freq!=prevfreq) && EthLinkStatus==1){
      // float freqPub = freq;
      // freqPub = freqPub/1000;
      { uint32_t _f = (uint32_t)freq; net.publish("/hz", (uint8_t*)&_f, sizeof(_f)); }
      { uint8_t _m = oi3ModeToCiv(ActualMode); net.publish("/mode", &_m, sizeof(_m)); }
      prevfreq=freq;
      lastFreqChangeAt = millis();          // adaptive polling: stay in FAST for ACTIVITY_HOLD ms
      Timeout[4][1] = BAND_DECODER_REQUEST_FAST;
    }
}

// REMOTE RELAY OUT (not use)
void remoteRelay() {
    Serial.print(1);
    Serial.print(',');
    Serial.print(BAND, DEC);
    Serial.print('\n');
    Serial.flush();
}

// SERIAL OUT
void serialEcho() {
    Serial.print(F("<"));
    Serial.print(BAND);
    Serial.print(F(","));
    Serial.print(freq);
    Serial.println(F(">"));
    Serial.flush();
}

// BCD OUT
#if defined(BCD_OUT)
    void bcdOut(){
        if (BCDmatrixOUT[0][BAND] == 1){ digitalWrite(BCD1, HIGH); }else{ digitalWrite(BCD1, LOW);;}
        if (BCDmatrixOUT[1][BAND] == 1){ digitalWrite(BCD2, HIGH); }else{ digitalWrite(BCD2, LOW);;}
        if (BCDmatrixOUT[2][BAND] == 1){ digitalWrite(BCD3, HIGH); }else{ digitalWrite(BCD3, LOW);;}
        if (BCDmatrixOUT[3][BAND] == 1){ digitalWrite(BCD4, HIGH); }else{ digitalWrite(BCD4, LOW);;}
    }
#endif

// BAND DECODER WATCHDOG
void watchDog() {
    if (millis() - Timeout[3][0] > (Timeout[3][1])){
        BAND=0;
        freq=0;
        Timeout[3][0] = millis();                      // set time mark
    }
}

// ICOM STATE MACHINE!
int icomSM(byte b){      // state machine
  // fefe560e03fd fefe0e56038079022800fd fefe560e04fd fefe0e56040301fd    request
  // fefe0056009079022800fd fefe0056000080022800fd    CIV-TX-ON

    rdI[10] = 0;
    // This filter solves read from 0x00 0x05 0x03 commands and 00 E0 F1 address used by software
    switch (stateMachine) {
        case 1: if( b == 0xFE ){ stateMachine = 2; rdI[0]=b; }; break;
        case 2: if( b == 0xFE ){ stateMachine = 3; rdI[1]=b; }else{ stateMachine = 1;}; break;
        // addresses that use different software 00-trx, e0-pc-ale, winlinkRMS, f1-winlink trimode
        case 3: if( b == 0x00 || b == 0xE0 || b == 0x0E || b == 0xF1 ){ stateMachine = 4; rdI[2]=b;                       // choose command $03
          }else if( b == CIV_ADRESS ){ stateMachine = 6; rdI[2]=b;}else{ stateMachine = 1;}; break;                       // or $05

        case 4: if( b == CIV_ADRESS ){ stateMachine = 5; rdI[3]=b; }else{ stateMachine = 1;}; break;                      // select command $03
        case 5: if( b == 0x00 || b == 0x03 ){stateMachine = 8; rdI[4]=b;  // freq
                }else if( b == 0x04 ){stateMachine = 14; rdI[4]=b;        // mode
                }else{ stateMachine = 1;}; break;

        case 6: if( b == 0x00 || b == 0xE0 || b == 0xF1 ){ stateMachine = 7; rdI[3]=b; }else{ stateMachine = 1;}; break;  // select command $05
        case 7: if( b == 0x00 || b == 0x05 ){ stateMachine = 8; rdI[4]=b; }else{ stateMachine = 1;}; break;

        case 8: if( b <= 0x99 ){stateMachine = 9; rdI[5]=b; }else{stateMachine = 1;}; break;
        case 9: if( b <= 0x99 ){stateMachine = 10; rdI[6]=b; }else{stateMachine = 1;}; break;
       case 10: if( b <= 0x99 ){stateMachine = 11; rdI[7]=b; }else{stateMachine = 1;}; break;
       case 11: if( b <= 0x99 ){stateMachine = 12; rdI[8]=b; }else{stateMachine = 1;}; break;
       case 12: if( b <= 0x99 ){stateMachine = 13; rdI[9]=b; }else{stateMachine = 1;}; break;
       case 13: if( b == 0xFD ){stateMachine = 1; rdI[10]=b; }else{stateMachine = 1; rdI[10] = 0;}; break;

       case 14: if( b <= 0x12 ){stateMachine = 15; rdI[5]=b; }else{stateMachine = 1;}; break;   // Mode
       case 15: if( b <= 0x03 ){stateMachine = 16; rdI[6]=b; }else{stateMachine = 1;}; break;   // Filter
       case 16: if( b == 0xFD ){stateMachine = 1; rdI[7]=b; }else{stateMachine = 1; rdI[7] = 0;}; break;
    }
}

int txCIV(int commandCIV, long dataCIVtx, int toAddress) {
    //Serial2.flush();
    Serial2.write(254);                                    // FE
    Serial2.write(254);                                    // FE
    Serial2.write(toAddress);                              // to adress
    Serial2.write(fromAdress);                             // from OE
    Serial2.write(commandCIV);                             // data
    if (dataCIVtx != 0){
        String freqCIVtx = String(dataCIVtx);             // to string
        freqCIVtx.reserve(10);
        String freqCIVtxPart;
        freqCIVtxPart.reserve(10);
        while (freqCIVtx.length() < 10) {                 // leding zeros
            freqCIVtx = 0 + freqCIVtx;
        }
        for (int x=8; x>=0; x=x-2){                       // loop for 5x2 char [xx xx xx xx xx]
            freqCIVtxPart = freqCIVtx.substring(x,x+2);   // cut freq to five part
                Serial2.write(hexToDec(freqCIVtxPart));    // HEX to DEC, because write as DEC format from HEX variable
        }
    }
    Serial2.write(253);                                    // FD
    Serial2.flush();
}

int txCIVout(int commandCIV, long dataCIVtx, int toAddress) {
    Serial2.write(254);                                    // FE
    Serial2.write(254);                                    // FE
    Serial2.write(toAddress);                              // to address
    Serial2.write(fromAdress);                             // from OE
    Serial2.write(commandCIV);                             // data
    if (dataCIVtx != 0){
        String freqCIVtx = String(dataCIVtx);             // to string
        freqCIVtx.reserve(10);
        String freqCIVtxPart;
        freqCIVtxPart.reserve(10);
        while (freqCIVtx.length() < 10) {                 // leding zeros
            freqCIVtx = 0 + freqCIVtx;
        }
        for (int x=8; x>=0; x=x-2){                       // loop for 5x2 char [xx xx xx xx xx]
            freqCIVtxPart = freqCIVtx.substring(x,x+2);   // cut freq to five part
                Serial2.write(hexToDec(freqCIVtxPart));    // HEX to DEC, because write as DEC format from HEX variable
        }
    }
    Serial2.write(253);                                    // FD
    Serial2.flush();
}

int txCIVoutSub(int commandCIV, int subCommandCIV, int dataCIVtx, int toAddress) {
    Serial2.write(254);                                    // FE
    Serial2.write(254);                                    // FE
    Serial2.write(toAddress);                              // to address
    Serial2.write(fromAdress);                             // from OE
    Serial2.write(commandCIV);                             // command
    Serial2.write(subCommandCIV);                          // sub-command
    Serial2.write(dataCIVtx);                              // data
    Serial2.write(253);                                    // FD
    Serial2.flush();
}
// #OI3 END -------------------------------------------------------------------------------

void K3NG_key()                                                      // changed from loop() #OI3

{
  // this is where the magic happens




  if (keyer_machine_mode == KEYER_NORMAL) {
    #ifdef FEATURE_COMMAND_BUTTONS
      check_command_buttons();
    #endif //FEATURE_COMMAND_BUTTONS
    check_paddles();
    service_dit_dah_buffers();


    service_send_buffer(PRINTCHAR);
    check_ptt_tail();


    #ifdef FEATURE_ROTARY_ENCODER
      if(ModeMenuStatus > 0){                         // if Menu
        MenuEncoder();                                // activate Menu encoder
      }else if(ActualMenu!=20){                       // else (main screen)
        WpmEncoder();                                 // OI3 edge-detect WPM encoder (replaces k3ng quadrature)
      }
    #endif //FEATURE_ROTARY_ENCODER



    check_for_dirty_configuration();



    #ifdef FEATURE_DISPLAY
      check_paddles();
      service_dit_dah_buffers();
      service_send_buffer(PRINTCHAR);
      service_display();
    #endif //FEATURE_DISPLAY




    #ifdef FEATURE_PTT_INTERLOCK
      //service_ptt_interlock();          // disable for #OI3
    #endif //FEATURE_PTT_INTERLOCK

    #ifdef FEATURE_PADDLE_ECHO
      service_paddle_echo();
    #endif





  }
}

// Subroutines --------------------------------------------------------------------------------------------


// Are you a radio artisan ?



//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------

#ifdef ARDUINO_SAM_DUE

/*

This code from http://forum.arduino.cc/index.php?topic=136500.0

*/


// timers TC0 TC1 TC2   channels 0-2 ids 0-2  3-5  6-8     AB 0 1
// use TC1 channel 0

#define TONE_TIMER TC1
#define TONE_CHNL 0
#define TONE_IRQ TC3_IRQn

// TIMER_CLOCK4   84MHz/128 with 16 bit counter give 10 Hz to 656KHz

static uint8_t pinEnabled[PINS_COUNT];
static uint8_t TCChanEnabled = 0;
static bool pin_state = false ;
static Tc *chTC = TONE_TIMER;
static uint32_t chNo = TONE_CHNL;

volatile static int32_t toggle_count;
static uint32_t tone_pin;

void toneDUE(uint32_t ulPin, uint32_t frequency, int32_t duration = 0){

  // frequency (in hertz) and duration (in milliseconds)

  const uint32_t rc = VARIANT_MCK / 256 / frequency;
  tone_pin = ulPin;
  toggle_count = 0;  // strange  wipe out previous duration
  if (duration > 0 ){
    toggle_count = 2 * frequency * duration / 1000;
  } else {
    toggle_count = -1;
  }
  if (!TCChanEnabled) {
    pmc_set_writeprotect(false);
    pmc_enable_periph_clk((uint32_t)TONE_IRQ);
    TC_Configure(chTC, chNo, TC_CMR_TCCLKS_TIMER_CLOCK4 |
      TC_CMR_WAVE |         // Waveform mode
      TC_CMR_WAVSEL_UP_RC ); // Counter running up and reset when equals to RC
    chTC->TC_CHANNEL[chNo].TC_IER=TC_IER_CPCS;  // RC compare interrupt
    chTC->TC_CHANNEL[chNo].TC_IDR=~TC_IER_CPCS;
    NVIC_EnableIRQ(TONE_IRQ);
    TCChanEnabled = 1;
  }
  if (!pinEnabled[ulPin]) {
    pinMode(ulPin, OUTPUT);
    pinEnabled[ulPin] = 1;
  }
  TC_Stop(chTC, chNo);
  TC_SetRC(chTC, chNo, rc);    // set frequency
  TC_Start(chTC, chNo);
}

void noToneDUE(uint32_t ulPin){

  TC_Stop(chTC, chNo);  // stop timer
  digitalWrite(ulPin,LOW);  // no signal on pin

}

// timer ISR  TC1 ch 0
void TC3_Handler ( void ) {

  TC_GetStatus(TC1, 0);
  if (toggle_count != 0){
    // toggle pin  TODO  better
    digitalWrite(tone_pin,pin_state= !pin_state);
    if (toggle_count > 0) toggle_count--;
  } else {
    noTone(tone_pin);
  }

}


#elif defined(ARDUINO_MAPLE_MINI)  //HARDWARE_ARDUINO_DUE

/*

This code from http://www.stm32duino.com/viewtopic.php?t=496

*/

///////////////////////////////////////////////////////////////////////
//
// tone(pin,frequency[,duration]) generate a tone on a given pin
//
// noTone(pin)                    switch of the tone on the pin
//
///////////////////////////////////////////////////////////////////////

//#include "Arduino.h"
//#include <HardwareTimer.h>

#ifndef TONE_TIMER
  #define TONE_TIMER 2
#endif

HardwareTimer tone_timer(TONE_TIMER);

bool tone_state = true;             // last pin state for toggling
short tone_pin = -1;                // pin for outputting sound
short tone_freq = 444;              // tone frequency (0=pause)
unsigned tone_micros = 500000/444;  // tone have wave time in usec
int tone_counts = 0;                // tone duration in units of half waves

// timer hander for tone with no duration specified,
// will keep going until noTone() is called
void tone_handler_1(void) {
  tone_state = !tone_state;
  digitalWrite(tone_pin,tone_state);
}

// timer hander for tone with a specified duration,
// will stop automatically when duration time is up.
void tone_handler_2(void) {   // check duration
  if(tone_freq>0){
   tone_state = !tone_state;
   digitalWrite(tone_pin,tone_state);
  }
  if(!--tone_counts){
   tone_timer.pause();
   pinMode(tone_pin, INPUT);
  }
}

//  play a tone on given pin with given frequency and optional duration in msec
void tone(uint8_t pin, unsigned short freq, unsigned duration = 0) {
  tone_pin = pin;
  tone_freq = freq;
  tone_micros = 500000/(freq>0?freq:1000);
  tone_counts = 0;

  tone_timer.pause();

  if(freq >= 0){
    if(duration > 0)tone_counts = ((long)duration)*1000/tone_micros;
    pinMode(tone_pin, OUTPUT);

    // set timer to half period in microseconds
    tone_timer.setPeriod(tone_micros);

    // Set up an interrupt on channel 1
    tone_timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    tone_timer.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
    tone_timer.attachCompare1Interrupt(tone_counts?tone_handler_2:tone_handler_1);

    // Refresh the tone timer
    tone_timer.refresh();

    // Start the timer counting
    tone_timer.resume();
  } else {
    pinMode(tone_pin, INPUT);
  }
}

// disable tone on specified pin, if any
void noTone(uint8_t pin){
  tone(pin,-1);
}


#endif //ARDUINO_MAPLE_MINI / ARDUINO_SAM_DUE


//-------------------------------------------------------------------------------------------------------

/*   Sleep code prior to 2016-01-18
#ifdef FEATURE_SLEEP
void wakeup() {
  detachInterrupt(0);
}
#endif //FEATURE_SLEEP
*/


//-------------------------------------------------------------------------------------------------------
/*  Sleep code prior to 2016-01-18
#ifdef FEATURE_SLEEP
void check_sleep(){

  if ((millis() - last_activity_time) > (go_to_sleep_inactivity_time*60000)){

    if (config_dirty) {  // force a configuration write to EEPROM if the config is dirty
      last_config_write = 0;
      check_for_dirty_configuration();
    }

    attachInterrupt(0, wakeup, LOW);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    #ifdef DEBUG_SLEEP
    debug_serial_port->println(F("check_sleep: entering sleep"));
    delay(1000);
    #endif //DEBUG_SLEEP

    sleep_mode();

    // shhhhh! we are asleep here !!

    sleep_disable();
    last_activity_time = millis();

    #ifdef DEBUG_SLEEP
    debug_serial_port->println(F("check_sleep: I'm awake!"));
    #endif //DEBUG_SLEEP
  }


}
#endif //FEATURE_SLEEP
*/



//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_DISPLAY
void service_display() {

  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering service_display"));
  #endif

  byte x = 0;

  if (lcd_status == LCD_REVERT) {
    lcd_status = lcd_previous_status;
    switch (lcd_status) {
      case LCD_CLEAR: lcd_clear(); break;
      case LCD_SCROLL_MSG:
         lcd.clear();
         for (x = 0;x < LCD_ROWS;x++){
           //clear_display_row(x);
           lcd.setCursor(0,x);
           lcd.print(lcd_scroll_buffer[x]);
         }
         lcd_scroll_flag = 0;
         lcd_scroll_buffer_dirty = 0;
         break;
    }
  } else {
    switch (lcd_status) {
      case LCD_CLEAR : break;
      case LCD_TIMED_MESSAGE:
        if (millis() > lcd_timed_message_clear_time) {
          lcd_status = LCD_REVERT;
        }
      case LCD_SCROLL_MSG:
        if (lcd_scroll_buffer_dirty) {
          if (lcd_scroll_flag) {
            lcd.clear();
            lcd_scroll_flag = 0;
          }
          for (x = 0;x < LCD_ROWS;x++){
            //clear_display_row(x);
            lcd.setCursor(0,x);
            lcd.print(lcd_scroll_buffer[x]);
          }
          lcd_scroll_buffer_dirty = 0;
        }
      break;
    }
  }

}
#endif



//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_DISPLAY
void display_scroll_print_char(char charin){

  static byte column_pointer = 0;
  static byte row_pointer = 0;
  static byte holding_space = 0;
  byte x = 0;

  #ifdef DEBUG_DISPLAY_SCROLL_PRINT_CHAR
  debug_serial_port->print(F("display_scroll_print_char: "));
  debug_serial_port->write(charin);
  debug_serial_port->print(F(" "));
  debug_serial_port->println(charin);
  #endif //DEBUG_DISPLAY_SCROLL_PRINT_CHAR


  if (lcd_status != LCD_SCROLL_MSG) {
    lcd_status = LCD_SCROLL_MSG;
    lcd.clear();
  }

  if (charin == ' '){
    holding_space = 1;
    return;
  }

  if (holding_space){   // ok, I admit this is a hack.  Hold on to spaces and don't scroll until the next char comes in...
    if (column_pointer > (LCD_COLUMNS-1)) {
      row_pointer++;
      column_pointer = 0;
      if (row_pointer > (LCD_ROWS-1)) {
        for (x = 0; x < (LCD_ROWS-1); x++) {
          lcd_scroll_buffer[x] = lcd_scroll_buffer[x+1];
        }
        lcd_scroll_buffer[x] = "";
        row_pointer--;
        lcd_scroll_flag = 1;
      }
    }
    if (column_pointer > 0){ // don't put a space in the first column
      lcd_scroll_buffer[row_pointer].concat(' ');
      column_pointer++;
    }
    holding_space = 0;
  }



  if (column_pointer > (LCD_COLUMNS-1)) {
    row_pointer++;
    column_pointer = 0;
    if (row_pointer > (LCD_ROWS-1)) {
      for (x = 0; x < (LCD_ROWS-1); x++) {
        lcd_scroll_buffer[x] = lcd_scroll_buffer[x+1];
      }
      lcd_scroll_buffer[x] = "";
      row_pointer--;
      lcd_scroll_flag = 1;
    }
  }
  lcd_scroll_buffer[row_pointer].concat(charin);
  column_pointer++;


  lcd_scroll_buffer_dirty = 1;
}

#endif //FEATURE_DISPLAY


//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
void lcd_clear() {

  lcd.clear();
  lcd_status = LCD_CLEAR;

}
#endif
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
void lcd_center_print_timed(String lcd_print_string, byte row_number, unsigned int duration)
{
  if (lcd_status != LCD_TIMED_MESSAGE) {
    lcd_previous_status = lcd_status;
    lcd_status = LCD_TIMED_MESSAGE;
    lcd.clear();
  } else {
    clear_display_row(row_number);
  }
  lcd.setCursor(((LCD_COLUMNS - lcd_print_string.length())/2),row_number);
  lcd.print(lcd_print_string);
  lcd_timed_message_clear_time = millis() + duration;
}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_DISPLAY
void clear_display_row(byte row_number)
{
  for (byte x = 0; x < LCD_COLUMNS; x++) {
    lcd.setCursor(x,row_number);
    lcd.print(F(" "));
  }
}
#endif

//-------------------------------------------------------------------------------------------------------

void check_for_dirty_configuration()
{
  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_for_dirty_configuration"));
  #endif

  if ((config_dirty) && ((millis()-last_config_write)>30000)) {
    write_settings_to_eeprom(0);
    last_config_write = millis();
    #ifdef DEBUG_EEPROM
    debug_serial_port->println(F("check_for_dirty_configuration: wrote config\n"));
    #endif
  }

}

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

#ifdef DEBUG_CAPTURE_COM_PORT
void debug_capture ()
{

  byte serial_byte_in;
  int x = 1022;

  while (primary_serial_port->available() == 0) {}  // wait for first byte
  serial_byte_in = primary_serial_port->read();
  primary_serial_port->write(serial_byte_in);
  //if ((serial_byte_in > 47) or (serial_byte_in = 20)) { primary_serial_port->write(serial_byte_in); }  // echo back
  if (serial_byte_in == '~') {
    debug_capture_dump();    // go into dump mode if we get a tilde
  } else {
    EEPROM.write(x,serial_byte_in);
    x--;
    while ( x > 400) {
      if (primary_serial_port->available() > 0) {
        serial_byte_in = primary_serial_port->read();
        EEPROM.write(x,serial_byte_in);
        EEPROM.write(x-1,255);
        send_dit();
        x--;
        primary_serial_port->write(serial_byte_in);
        //if ((serial_byte_in > 47) or (serial_byte_in = 20)) { primary_serial_port->write(serial_byte_in); }  // echo back
      }
    }
  }

  while (1) {}

}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef DEBUG_CAPTURE_COM_PORT
void debug_capture_dump()
{
  byte eeprom_byte_in;

  for ( int x = 1022; x > (1022-100); x-- ) {
    eeprom_byte_in = EEPROM.read(x);
    if (eeprom_byte_in < 255) {
      primary_serial_port->print(eeprom_byte_in,BYTE);
    } else {
      x = 0;
    }
  }
  primary_serial_port->println(F("\n"));
  for ( int x = 1022; x > (1022-100); x-- ) {
    eeprom_byte_in = EEPROM.read(x);
    if (eeprom_byte_in < 255) {
      primary_serial_port->print(eeprom_byte_in,HEX);
      primary_serial_port->write("   :");
      primary_serial_port->println(eeprom_byte_in,BYTE);
    } else {
      x = 0;
    }
  }

  while (1) {}

}
#endif

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_ROTARY_ENCODER
void check_rotary_encoder(){

  static unsigned long timestamp[5];

  unsigned char pinstate = (digitalRead(rotary_pin2) << 1) | digitalRead(rotary_pin1);
  state = ttable[state & 0xf][pinstate];
  unsigned char result = (state & 0x30);

  if (result) {                                    // If rotary encoder modified
    timestamp[0] = timestamp[1];                    // Encoder step timer
    timestamp[1] = timestamp[2];
    timestamp[2] = timestamp[3];
    timestamp[3] = timestamp[4];
    timestamp[4] = millis();

    unsigned long elapsed_time = (timestamp[4] - timestamp[0]); // Encoder step time difference for 10's step

    if (result == DIR_CW) {
      if (elapsed_time < 250) {speed_change(2);} else {speed_change(1);};
    }
    if (result == DIR_CCW) {
      if (elapsed_time < 250) {speed_change(-2);} else {speed_change(-1);};
    }

  } // if (result)



}
#endif //FEATURE_ROTARY_ENCODER
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------

void check_paddles()
{

  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering check_paddles"));
  #endif

  #define NO_CLOSURE 0
  #define DIT_CLOSURE_DAH_OFF 1
  #define DAH_CLOSURE_DIT_OFF 2
  #define DIT_CLOSURE_DAH_ON 3
  #define DAH_CLOSURE_DIT_ON 4

  static byte last_closure = NO_CLOSURE;

  check_dit_paddle();
  check_dah_paddle();


  if (configuration.keyer_mode == ULTIMATIC) {
    if (ultimatic_mode == ULTIMATIC_NORMAL) {

      switch (last_closure) {
        case DIT_CLOSURE_DAH_OFF:
          if (dah_buffer) {
            if (dit_buffer) {
              last_closure = DAH_CLOSURE_DIT_ON;
              dit_buffer = 0;
            } else {
              last_closure = DAH_CLOSURE_DIT_OFF;
            }
          } else {
            if (!dit_buffer) {
              last_closure = NO_CLOSURE;
            }
          }
          break;
        case DIT_CLOSURE_DAH_ON:
          if (dit_buffer) {
            if (dah_buffer) {
              dah_buffer = 0;
            } else {
              last_closure = DIT_CLOSURE_DAH_OFF;
            }
          } else {
            if (dah_buffer) {
              last_closure = DAH_CLOSURE_DIT_OFF;
            } else {
              last_closure = NO_CLOSURE;
            }
          }
          break;

        case DAH_CLOSURE_DIT_OFF:
          if (dit_buffer) {
            if (dah_buffer) {
              last_closure = DIT_CLOSURE_DAH_ON;
              dah_buffer = 0;
            } else {
              last_closure = DIT_CLOSURE_DAH_OFF;
            }
          } else {
            if (!dah_buffer) {
              last_closure = NO_CLOSURE;
            }
          }
          break;

        case DAH_CLOSURE_DIT_ON:
          if (dah_buffer) {
            if (dit_buffer) {
              dit_buffer = 0;
            } else {
              last_closure = DAH_CLOSURE_DIT_OFF;
            }
          } else {
            if (dit_buffer) {
              last_closure = DIT_CLOSURE_DAH_OFF;
            } else {
              last_closure = NO_CLOSURE;
            }
          }
          break;

        case NO_CLOSURE:
          if ((dit_buffer) && (!dah_buffer)) {
            last_closure = DIT_CLOSURE_DAH_OFF;
          } else {
            if ((dah_buffer) && (!dit_buffer)) {
              last_closure = DAH_CLOSURE_DIT_OFF;
            } else {
              if ((dit_buffer) && (dah_buffer)) {
                // need to handle dit/dah priority here
                last_closure = DIT_CLOSURE_DAH_ON;
                dah_buffer = 0;
              }
            }
          }
          break;
      }
    } else {  // if (ultimatic_mode == ULTIMATIC_NORMAL)
     if ((dit_buffer) && (dah_buffer)) {   // dit or dah priority mode
       if (ultimatic_mode == ULTIMATIC_DIT_PRIORITY) {
         dah_buffer = 0;
       } else {
         dit_buffer = 0;
       }
     }
    } // if (ultimatic_mode == ULTIMATIC_NORMAL)
  } // if (configuration.keyer_mode == ULTIMATIC)

  if (configuration.keyer_mode == SINGLE_PADDLE){
    switch (last_closure) {
      case DIT_CLOSURE_DAH_OFF:
        if (dit_buffer) {
          if (dah_buffer) {
            dah_buffer = 0;
          } else {
            last_closure = DIT_CLOSURE_DAH_OFF;
          }
        } else {
          if (dah_buffer) {
            last_closure = DAH_CLOSURE_DIT_OFF;
          } else {
            last_closure = NO_CLOSURE;
          }
        }
        break;

      case DIT_CLOSURE_DAH_ON:

        if (dah_buffer) {
          if (dit_buffer) {
            last_closure = DAH_CLOSURE_DIT_ON;
            dit_buffer = 0;
          } else {
            last_closure = DAH_CLOSURE_DIT_OFF;
          }
        } else {
          if (!dit_buffer) {
            last_closure = NO_CLOSURE;
          }
        }
        break;



      case DAH_CLOSURE_DIT_OFF:
        if (dah_buffer) {
          if (dit_buffer) {
            dit_buffer = 0;
          } else {
            last_closure = DAH_CLOSURE_DIT_OFF;
          }
        } else {
          if (dit_buffer) {
            last_closure = DIT_CLOSURE_DAH_OFF;
          } else {
            last_closure = NO_CLOSURE;
          }
        }
        break;

      case DAH_CLOSURE_DIT_ON:
        if (dit_buffer) {
          if (dah_buffer) {
            last_closure = DIT_CLOSURE_DAH_ON;
            dah_buffer = 0;
          } else {
            last_closure = DIT_CLOSURE_DAH_OFF;
          }
        } else {
          if (!dah_buffer) {
            last_closure = NO_CLOSURE;
          }
        }
        break;

      case NO_CLOSURE:
        if ((dit_buffer) && (!dah_buffer)) {
          last_closure = DIT_CLOSURE_DAH_OFF;
        } else {
          if ((dah_buffer) && (!dit_buffer)) {
            last_closure = DAH_CLOSURE_DIT_OFF;
          } else {
            if ((dit_buffer) && (dah_buffer)) {
              // need to handle dit/dah priority here
              last_closure = DIT_CLOSURE_DAH_ON;
              dah_buffer = 0;
            }
          }
        }
        break;
    }
  } //if (configuration.keyer_mode == SINGLE_PADDLE)


}

//-------------------------------------------------------------------------------------------------------

void ptt_key()
{
  if (ptt_line_activated == 0) {   // if PTT is currently deactivated, bring it up and insert PTT lead time delay
    if (configuration.current_ptt_line) {
      // ptt_high(PTTmodeCW);                                              //  add #OI3
      ptt_high(PTTbyMode[ActualMode]);                                              //  add #OI3
      // digitalWrite (configuration.current_ptt_line, HIGH);   //  disable #OI3
      delay(ptt_lead_time[configuration.current_tx-1]);
    }
    ptt_line_activated = 1;
  }
  ptt_time = millis();
}

//-------------------------------------------------------------------------------------------------------
void ptt_unkey()
{
  if (ptt_line_activated) {
    if (configuration.current_ptt_line) {
      // ptt_low(PTTmodeCW,14);                                              //  add #OI3
      ptt_low(PTTbyMode[ActualMode],14);                                              //  add #OI3
      // digitalWrite (configuration.current_ptt_line, LOW);  //  disable #OI3
    }
    ptt_line_activated = 0;
  }
}

//-------------------------------------------------------------------------------------------------------
void check_ptt_tail()
{
  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_ptt_tail"));
  #endif

  if (key_state) {
    ptt_time = millis();
  } else {
    if ((ptt_line_activated) && (manual_ptt_invoke == 0)) {
      //if ((millis() - ptt_time) > ptt_tail_time) {
      if (last_sending_mode == MANUAL_SENDING) {
        #ifndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING

          // PTT Tail Time: N     PTT Hang Time: Y

          if ((millis() - ptt_time) >= ((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm)) ) {
            ptt_unkey();
          }
        #else //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
          #ifndef OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING

            // PTT Tail Time: Y     PTT Hang Time: Y

            if ((millis() - ptt_time) >= (((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm))+ptt_tail_time[configuration.current_tx-1])) {
              ptt_unkey();
            }
          #else //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
          if ((millis() - ptt_time) >= ptt_tail_time[configuration.current_tx-1]) {


            // PTT Tail Time: Y    PTT Hang Time: N

            ptt_unkey();
          }
          #endif //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
        #endif //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
      } else {
        if ((millis() - ptt_time) > ptt_tail_time[configuration.current_tx-1]) {
            ptt_unkey();
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------------------------------
void write_settings_to_eeprom(int initialize_eeprom) {

  #if !defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))

  if (initialize_eeprom) {
    //configuration.magic_number = eeprom_magic_number;
    EEPROM.write(0,eeprom_magic_number);
  }

  const byte* p = (const byte*)(const void*)&configuration;
  unsigned int i;
  int ee = 1;  // starting point of configuration struct
  for (i = 0; i < sizeof(configuration); i++){
    EEPROM.write(ee++, *p++);
  }

  #endif //!defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))

  config_dirty = 0;


}

//-------------------------------------------------------------------------------------------------------

int read_settings_from_eeprom() {

  // returns 0 if eeprom had valid settings, returns 1 if eeprom needs initialized

  #if defined(DEBUG_FORCE_RESET)
    return 1;
  #endif

  #if !defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))

    if (EEPROM.read(0) == eeprom_magic_number){

      byte* p = (byte*)(void*)&configuration;
      unsigned int i;
      int ee = 1; // starting point of configuration struct
      for (i = 0; i < sizeof(configuration); i++){
        *p++ = EEPROM.read(ee++);
      }

    //if (configuration.magic_number == eeprom_magic_number) {
      switch_to_tx_silent(configuration.current_tx);
      config_dirty = 0;

      configuration.dit_buffer_off = 0;
      configuration.dah_buffer_off = 0;

      return 0;
    } else {
      return 1;
    }

  #endif //!defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))



  return 1;

}

//-------------------------------------------------------------------------------------------------------

void check_dit_paddle()
{



  byte pin_value = 0;
  byte dit_paddle = 0;

  if (configuration.paddle_mode == PADDLE_NORMAL) {
    dit_paddle = paddle_left;
  } else {
    dit_paddle = paddle_right;
  }

  pin_value = paddle_pin_read(dit_paddle);




    if (pin_value == 0) {
    dit_buffer = 1;



    manual_ptt_invoke = 0;
  }



}

//-------------------------------------------------------------------------------------------------------

void check_dah_paddle()
{



  byte pin_value = 0;
  byte dah_paddle;

  if (configuration.paddle_mode == PADDLE_NORMAL) {
    dah_paddle = paddle_right;
  } else {
    dah_paddle = paddle_left;
  }

  pin_value = paddle_pin_read(dah_paddle);


  if (pin_value == 0) {
    dah_buffer = 1;



    manual_ptt_invoke = 0;
  }



}

//-------------------------------------------------------------------------------------------------------

void send_dit(){

  // notes: key_compensation is a straight x mS lengthening or shortening of the key down time
  //        weighting is

  unsigned int character_wpm = configuration.wpm;

  being_sent = SENDING_DIT;
  tx_and_sidetone_key(1);
   // ptt_low(PTTmodeCW);                                //  add #OI3 - PTT alive
   #ifdef DEBUG_VARIABLE_DUMP
    dit_start_time = millis();
  #endif
  if ((tx_key_dit) && (key_tx)) {digitalWrite(tx_key_dit,tx_key_dit_and_dah_pins_active_state);}


    loop_element_lengths((1.0*(float(configuration.weighting)/50)),keying_compensation,character_wpm);



  if ((tx_key_dit) && (key_tx)) {digitalWrite(tx_key_dit,tx_key_dit_and_dah_pins_inactive_state);}
  #ifdef DEBUG_VARIABLE_DUMP
    dit_end_time = millis();
  #endif
  tx_and_sidetone_key(0);


  loop_element_lengths((2.0-(float(configuration.weighting)/50)),(-1.0*keying_compensation),character_wpm);




  #ifdef FEATURE_PADDLE_ECHO
    if (sending_mode == MANUAL_SENDING) {
      paddle_echo_buffer = (paddle_echo_buffer * 10) + 1;
      paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*1200.0)/configuration.wpm)*length_letterspace);

    }
  #endif //FEATURE_PADDLE_ECHO


  being_sent = SENDING_NOTHING;
  last_sending_mode = sending_mode;

  check_paddles();

}

//-------------------------------------------------------------------------------------------------------

void send_dah(){

  unsigned int character_wpm = configuration.wpm;


  being_sent = SENDING_DAH;
  tx_and_sidetone_key(1);
  // ptt_low(PTTmodeCW);                                //  add #OI3 - PTT alive
  #ifdef DEBUG_VARIABLE_DUMP
    dah_start_time = millis();
  #endif
  if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_active_state);}

    loop_element_lengths((float(configuration.dah_to_dit_ratio/100.0)*(float(configuration.weighting)/50)),keying_compensation,character_wpm);

  if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_inactive_state);}

  #ifdef DEBUG_VARIABLE_DUMP
    dah_end_time = millis();
  #endif

  tx_and_sidetone_key(0);

  loop_element_lengths((4.0-(3.0*(float(configuration.weighting)/50))),(-1.0*keying_compensation),character_wpm);



  #ifdef FEATURE_PADDLE_ECHO
    if (sending_mode == MANUAL_SENDING) {
      paddle_echo_buffer = (paddle_echo_buffer * 10) + 2;
      paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*1200.0)/configuration.wpm)*length_letterspace);

    }
  #endif //FEATURE_PADDLE_ECHO


  check_paddles();

  being_sent = SENDING_NOTHING;
  last_sending_mode = sending_mode;

}

//-------------------------------------------------------------------------------------------------------

void tx_and_sidetone_key (int state)
{



  #if !defined(FEATURE_PTT_INTERLOCK)
    if ((state) && (key_state == 0)) {
      if (key_tx) {
        byte previous_ptt_line_activated = ptt_line_activated;
        ptt_key();
        if (current_tx_key_line) {digitalWrite (current_tx_key_line, HIGH);}
        if ((first_extension_time) && (previous_ptt_line_activated == 0)) {
          delay(first_extension_time);
        }
      }
      if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
        tone(sidetone_line, configuration.hz_sidetone);
      }
      key_state = 1;
    } else {
      if ((state == 0) && (key_state)) {
        if (key_tx) {
          if (current_tx_key_line) {digitalWrite (current_tx_key_line, LOW);}
          ptt_key();
        }
        if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
          noTone(sidetone_line);
        }
        key_state = 0;
      }
    }
  #else  //FEATURE_PTT_INTERLOCK
    if ((state) && (key_state == 0)) {
      if (key_tx) {
        byte previous_ptt_line_activated = ptt_line_activated;
        if (!ptt_interlock_active) {
          ptt_key();
        }
        if (current_tx_key_line) {digitalWrite (current_tx_key_line, HIGH);}
        if ((first_extension_time) && (previous_ptt_line_activated == 0)) {
          delay(first_extension_time);
        }
      }
      if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
        tone(sidetone_line, configuration.hz_sidetone);
      }
      key_state = 1;
    } else {
      if ((state == 0) && (key_state)) {
        if (key_tx) {
          if (current_tx_key_line) {digitalWrite (current_tx_key_line, LOW);}
          if (!ptt_interlock_active) {
            ptt_key();
          }
        }
        if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
          noTone(sidetone_line);
        }
        key_state = 0;
      }
    }

  #endif //FEATURE_PTT_INTERLOCK


  check_ptt_tail();


}

//-------------------------------------------------------------------------------------------------------


// #ifndef FEATURE_HI_PRECISION_LOOP_TIMING

//   void loop_element_lengths(float lengths, float additional_time_ms, int speed_wpm_in)
//   {



//     if ((lengths == 0) or (lengths < 0)) {
//       return;
//     }


//     float element_length;

//     if (speed_mode == SPEED_NORMAL) {
//       element_length = 1200/speed_wpm_in;
//     } else {
//       element_length = qrss_dit_length * 1000;
//     }



//     #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
//       unsigned long starttime = millis();
//     #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

//     unsigned long ticks = long(element_length*lengths) + long(additional_time_ms); // improvement from Paul, K1XM
//     unsigned long start = millis();
//     while ((millis() - start) < ticks) {

//       check_ptt_tail();

//       #if defined(FEATURE_INTERNET_LINK) /*&& !defined(OPTION_INTERNET_LINK_NO_UDP_SVC_DURING_KEY_DOWN)*/
//         if ((millis() > 1000)  && ((millis()-start) > FEATURE_INTERNET_LINK_SVC_DURING_LOOP_TIME_MS)){
//           service_udp_send_buffer();
//           service_udp_receive();
//           service_internet_link_udp_receive_buffer();
//         }
//       #endif //FEATURE_INTERNET_LINK

//       #ifdef OPTION_WATCHDOG_TIMER
//         wdt_reset();
//       #endif  //OPTION_WATCHDOG_TIMER

//       #ifdef FEATURE_ROTARY_ENCODER
//         check_rotary_encoder();
//       #endif //FEATURE_ROTARY_ENCODER

//       #if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
//         service_usb();
//       #endif //FEATURE_USB_KEYBOARD || FEATURE_USB_MOUSE

//       #ifdef FEATURE_PTT_INTERLOCK
//         service_ptt_interlock();
//       #endif //FEATURE_PTT_INTERLOCK

//       if ((configuration.keyer_mode != ULTIMATIC) && (configuration.keyer_mode != SINGLE_PADDLE)) {
//         if ((configuration.keyer_mode == IAMBIC_A) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
//             iambic_flag = 1;
//         }

//         #ifndef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
//           if (being_sent == SENDING_DIT) {
//             check_dah_paddle();
//           } else {
//             if (being_sent == SENDING_DAH) {
//               check_dit_paddle();
//             } else {
//               check_dah_paddle();
//               check_dit_paddle();
//             }
//           }
//         #else ////FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
//           if (configuration.cmos_super_keyer_iambic_b_timing_on){
//             if ((float(float(millis()-starttime)/float(starttime-ticks))*100) >= configuration.cmos_super_keyer_iambic_b_timing_percent) {
//               if (being_sent == SENDING_DIT) {
//                 check_dah_paddle();
//               } else {
//                 if (being_sent == SENDING_DAH) {
//                   check_dit_paddle();
//                 }
//               }
//             } else {
//               if (((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
//                 dah_buffer = 0;
//                 dit_buffer = 0;
//               }
//             }
//           } else {
//             if (being_sent == SENDING_DIT) {
//               check_dah_paddle();
//             } else {
//               if (being_sent == SENDING_DAH) {
//                 check_dit_paddle();
//               } else {
//                 check_dah_paddle();
//                 check_dit_paddle();
//               }
//             }
//           }
//         #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

//       } else { //(configuration.keyer_mode != ULTIMATIC)


//           if (being_sent == SENDING_DIT) {
//             check_dah_paddle();
//           } else {
//             if (being_sent == SENDING_DAH) {
//               check_dit_paddle();
//             } else {
//               check_dah_paddle();
//               check_dit_paddle();
//             }
//           }

//       }

//       #if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_BUTTONS)
//         check_the_memory_buttons();
//       #endif

//       // blow out prematurely if we're automatic sending and a paddle gets hit
//       #ifdef FEATURE_COMMAND_BUTTONS
//         if (sending_mode == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) || dit_buffer || dah_buffer)) {
//           if (keyer_machine_mode == KEYER_NORMAL) {
//             sending_mode == AUTOMATIC_SENDING_INTERRUPTED;
//             automatic_sending_interruption_time = millis();
//             return;
//           }
//         }
//       #else
//         if (sending_mode == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || dit_buffer || dah_buffer)) {
//           if (keyer_machine_mode == KEYER_NORMAL) {
//             sending_mode == AUTOMATIC_SENDING_INTERRUPTED;
//             automatic_sending_interruption_time = millis();
//             return;
//           }
//         }
//       #endif

//       #ifdef FEATURE_STRAIGHT_KEY
//         service_straight_key();
//       #endif //FEATURE_STRAIGHT_KEY


        // #if defined(FEATURE_WEB_SERVER)
        //   if (speed_mode == SPEED_QRSS){
        //     service_web_server();
        //   }
        // #endif //FEATURE_WEB_SERVER

//     }  //while ((millis() < endtime) && (millis() > 200))

//     if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left) == HIGH ) && (paddle_pin_read(paddle_right) == HIGH )) {
//         iambic_flag = 0;
//         dit_buffer = 0;
//         dah_buffer = 0;
//     }

//     if ((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)){
//       if (configuration.dit_buffer_off) {dit_buffer = 0;}
//       if (configuration.dah_buffer_off) {dah_buffer = 0;}
//     }



//   } //void loop_element_lengths


// #else //FEATURE_HI_PRECISION_LOOP_TIMING------------------------------------------------------------------

  void loop_element_lengths(float lengths, float additional_time_ms, int speed_wpm_in) {



    if ((lengths == 0) or (lengths < 0)) {
      return;
    }



    float element_length;

    if (speed_mode == SPEED_NORMAL) {
      element_length = 1200/speed_wpm_in;
    } else {
      element_length = qrss_dit_length * 1000;
    }

    #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
      unsigned long starttime = micros();
    #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING


    unsigned long ticks = long(element_length*lengths*1000) + long(additional_time_ms*1000); // improvement from Paul, K1XM
    unsigned long start = micros();
    unsigned long endtime = micros() + long(element_length*lengths*1000) + long(additional_time_ms*1000);

    while ((micros() - start) < ticks){


    //while ((micros() < endtime) && (micros() > 200000)) {  // the second condition is to account for millis() rollover


      // encoder reading disabled here — OI3 WpmEncoder handles WPM via edge-detect

      if ((configuration.keyer_mode != ULTIMATIC) && (configuration.keyer_mode != SINGLE_PADDLE))  {
        if ((configuration.keyer_mode == IAMBIC_A) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
            iambic_flag = 1;
        }

        #ifndef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

          if (being_sent == SENDING_DIT) {
            check_dah_paddle();
          } else {
            if (being_sent == SENDING_DAH) {
              check_dit_paddle();
            } else {
              check_dah_paddle();
              check_dit_paddle();
            }
          }

        #else ////FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
          if (configuration.cmos_super_keyer_iambic_b_timing_on){
            if ((float(float(micros()-starttime)/float(endtime-starttime))*100) >= configuration.cmos_super_keyer_iambic_b_timing_percent) {
              if (being_sent == SENDING_DIT) {
                check_dah_paddle();
              } else {
                if (being_sent == SENDING_DAH) {
                  check_dit_paddle();
                }
              }
            } else {
              if (((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
                dah_buffer = 0;
                dit_buffer = 0;
              }
            }
          } else {
            if (being_sent == SENDING_DIT) {
              check_dah_paddle();
            } else {
              if (being_sent == SENDING_DAH) {
                check_dit_paddle();
              } else {
                check_dah_paddle();
                check_dit_paddle();
              }
            }
          }
        #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

        } else { //(configuration.keyer_mode != ULTIMATIC)
          if (being_sent == SENDING_DIT) {
            check_dah_paddle();
          } else {
            if (being_sent == SENDING_DAH) {
              check_dit_paddle();
            } else {
              check_dah_paddle();
              check_dit_paddle();
            }
          }
        }



        if (EnableEthernet==1 && EthLinkStatus==1) net.loop();
        if (trxCwAbort) break;

    } //while ((millis() < endtime) && (millis() > 200))


    // blow out prematurely if we're automatic sending and a paddle gets hit
    #ifdef FEATURE_COMMAND_BUTTONS
      if (sending_mode == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) || dit_buffer || dah_buffer)) {
        if (keyer_machine_mode == KEYER_NORMAL) {
          sending_mode == AUTOMATIC_SENDING_INTERRUPTED;
          automatic_sending_interruption_time = millis();
          return;
        }
      }
    #else
      if (sending_mode == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || dit_buffer || dah_buffer)) {
        if (keyer_machine_mode == KEYER_NORMAL) {
          sending_mode == AUTOMATIC_SENDING_INTERRUPTED;
          automatic_sending_interruption_time = millis();
          return;
        }
      }
    #endif


    if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left) == HIGH ) && (paddle_pin_read(paddle_right) == HIGH )) {
        iambic_flag = 0;
        dit_buffer = 0;
        dah_buffer = 0;
    }

    if ((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)){
      if (configuration.dit_buffer_off) {dit_buffer = 0;}
      if (configuration.dah_buffer_off) {dah_buffer = 0;}
    }


  } //void loop_element_lengths

// #endif //FEATURE_HI_PRECISION_LOOP_TIMING

//-------------------------------------------------------------------------------------------------------

void speed_change(int change)
{
  if (((configuration.wpm + change) > wpm_limit_low) && ((configuration.wpm + change) < wpm_limit_high)) {
    speed_set(configuration.wpm + change);
  }

  #ifdef FEATURE_DISPLAY
    lcd_center_print_timed_wpm();
  #endif
}

//-------------------------------------------------------------------------------------------------------

void speed_set(int wpm_set){

  configuration.wpm = wpm_set;
  config_dirty = 1;





  #ifdef FEATURE_DISPLAY
    lcd_center_print_timed_wpm();
  #endif
}
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
  void lcd_center_print_timed_wpm(){


      lcd_center_print_timed(String(configuration.wpm) + " wpm", 0, default_display_msg_delay);

  }
#endif
//-------------------------------------------------------------------------------------------------------

long get_cw_input_from_user(unsigned int exit_time_milliseconds) {

  byte looping = 1;
  byte paddle_hit = 0;
  long cw_char = 0;
  unsigned long last_element_time = 0;
  byte button_hit = 0;
  unsigned long entry_time = millis();

  while (looping) {



    // encoder reading disabled here — OI3 WpmEncoder handles WPM via edge-detect

    check_paddles();

    if (dit_buffer) {
      sending_mode = MANUAL_SENDING;
      send_dit();
      dit_buffer = 0;
      paddle_hit = 1;
      cw_char = (cw_char * 10) + 1;
      last_element_time = millis();
    }
    if (dah_buffer) {
      sending_mode = MANUAL_SENDING;
      send_dah();
      dah_buffer = 0;
      paddle_hit = 1;
      cw_char = (cw_char * 10) + 2;
      last_element_time = millis();
    }
    if ((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) {
      #ifdef DEBUG_GET_CW_INPUT_FROM_USER
      debug_serial_port->println(F("get_cw_input_from_user: hit length_letterspace"));
      #endif
      looping = 0;
    }

    if ((!paddle_hit) && (exit_time_milliseconds) && ((millis() - entry_time) > exit_time_milliseconds)) { // if we were passed an exit time and no paddle was hit, blow out of here
      return 0;
    }

    #ifdef FEATURE_COMMAND_BUTTONS
      while (analogbuttonread(0)) {    // hit the button to get out of command mode if no paddle was hit
        looping = 0;
        button_hit = 1;
      }
    #endif


  } //while (looping)




  if (button_hit) {
    #ifdef DEBUG_GET_CW_INPUT_FROM_USER
      debug_serial_port->println(F("get_cw_input_from_user: button_hit exit 9"));
    #endif
    return 9;
  } else {
    #ifdef DEBUG_GET_CW_INPUT_FROM_USER
      debug_serial_port->print(F("get_cw_input_from_user: exiting cw_char:"));
      debug_serial_port->println(cw_char);
    #endif
    return cw_char;
  }
}

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_mode()
{

  keyer_machine_mode = KEYER_COMMAND_MODE;

  #ifdef DEBUG_COMMAND_MODE
    debug_serial_port->println(F("command_mode: entering"));
  #endif



  byte looping;
  byte button_that_was_pressed = 0;
  byte paddle_hit = 0;
  unsigned long last_element_time = 0;
  unsigned long cw_char;
  byte stay_in_command_mode = 1;
  byte speed_mode_before = speed_mode;
  speed_mode = SPEED_NORMAL;                 // put us in normal speed mode (life is too short to do command mode in QRSS)
  byte keyer_mode_before = configuration.keyer_mode;
  char c[4];
  if ((configuration.keyer_mode != IAMBIC_A) && (configuration.keyer_mode != IAMBIC_B)) {
    configuration.keyer_mode = IAMBIC_B;                   // we got to be in iambic mode (life is too short to make this work in bug mode)
  }

  command_mode_disable_tx = 0;

  boop_beep();
  #ifdef command_mode_active_led
    if (command_mode_active_led) {digitalWrite(command_mode_active_led,HIGH);}
  #endif //command_mode_active_led

  #ifdef FEATURE_DISPLAY
    lcd.clear();
    lcd_center_print_timed("Command Mode", 0, default_display_msg_delay);
  #endif


  while (stay_in_command_mode) {
    cw_char = 0;
 //   cw_char = get_cw_input_from_user(0);


    // #ifdef OPTION_WATCHDOG_TIMER
    //   wdt_reset();
    // #endif  //OPTION_WATCHDOG_TIMER

    looping = 1;
    while (looping) {

      // encoder reading disabled here — OI3 WpmEncoder handles WPM via edge-detect

      check_paddles();

      if (dit_buffer) {
        sending_mode = MANUAL_SENDING;
        send_dit();
        dit_buffer = 0;
        paddle_hit = 1;
        cw_char = (cw_char * 10) + 1;
        last_element_time = millis();
      }
      if (dah_buffer) {
        sending_mode = MANUAL_SENDING;
        send_dah();
        dah_buffer = 0;
        paddle_hit = 1;
        cw_char = (cw_char * 10) + 2;
        last_element_time = millis();
      }
      if ((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) {
        #ifdef DEBUG_GET_CW_INPUT_FROM_USER
          debug_serial_port->println(F("get_cw_input_from_user: hit length_letterspace"));
        #endif
        looping = 0;
      }

      if (analogbuttonpressed() < analog_buttons_number_of_buttons){  // check for a button press
        looping = 0;
        cw_char = 9;
        delay(50);
        button_that_was_pressed = analogbuttonpressed();
        while (analogbuttonpressed() < analog_buttons_number_of_buttons) {}
      }


    } //while (looping)



// end new code

    #ifdef DEBUG_COMMAND_MODE
      debug_serial_port->print(F("command_mode: cwchar: "));
      debug_serial_port->println(cw_char);
    #endif
    if (cw_char > 0) {              // do the command
      switch (cw_char) {
        case 12: // A - Iambic mode
          configuration.keyer_mode = IAMBIC_A;
          keyer_mode_before = IAMBIC_A;
          configuration.dit_buffer_off = 0;
          configuration.dah_buffer_off = 0;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Iambic A", 0, default_display_msg_delay);
          #endif
          send_dit();
          break;
        case 2111: // B - Iambic mode
          configuration.keyer_mode = IAMBIC_B;
          keyer_mode_before = IAMBIC_B;
          configuration.dit_buffer_off = 0;
          configuration.dah_buffer_off = 0;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Iambic B", 0, default_display_msg_delay);
          #endif
          send_dit();
          break;
        case 2121: // C - Single paddle mode
          configuration.keyer_mode = SINGLE_PADDLE;
          keyer_mode_before = SINGLE_PADDLE;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Single Paddle", 0, default_display_msg_delay);
          #endif
          send_dit();
          break;
        case 1: // E - announce spEed
          delay(250);
          sprintf(c, "%d", configuration.wpm);
          send_char(c[0],KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          break;
        case 211: // D - Ultimatic mode
          configuration.keyer_mode = ULTIMATIC;
          keyer_mode_before = ULTIMATIC;
          configuration.dit_buffer_off = 1;
          configuration.dah_buffer_off = 1;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
          #endif
          send_dit();
          break;
        case 1121: command_sidetone_freq_adj(); break;                    // F - adjust sidetone frequency
        case 221: // G - switch to buG mode
          configuration.keyer_mode = BUG;
          keyer_mode_before = BUG;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Bug", 0, default_display_msg_delay);
          #endif
          send_dit();
          break;
        case 1111:   // H - set weighting and dah to dit ratio to defaults
          configuration.weighting = default_weighting;
          configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Dflt Wght & Ratio", 0, default_display_msg_delay);
          #endif
          send_dit();
          break;
        case 11:                                                     // I - toggle TX enable / disable
          if (command_mode_disable_tx) {
            command_mode_disable_tx = 0;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX On", 0, default_display_msg_delay);
            #endif
          } else {
            command_mode_disable_tx = 1;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX Off", 0, default_display_msg_delay);
            #endif
          }
          send_dit();
          break;
        case 1222: command_dah_to_dit_ratio_adjust(); break;                        // J - dah to dit ratio adjust
        case 212:                                                                   // K - turn dit and dah buffers on and off in Ulitmatic mode
          if (configuration.keyer_mode == ULTIMATIC){
            send_char('O',KEYER_NORMAL);
            if (configuration.dit_buffer_off){
              configuration.dit_buffer_off = 0;
              configuration.dah_buffer_off = 0;
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("Dit Dah Buffers On", 0, default_display_msg_delay);
              #endif
              send_char('N',KEYER_NORMAL);
            } else {
              configuration.dit_buffer_off = 1;
              configuration.dah_buffer_off = 1;
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("Dit Dah Buffers Off", 0, default_display_msg_delay);
              #endif
              send_char('F',KEYER_NORMAL);
              send_char('F',KEYER_NORMAL);
            }
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Error", 0, default_display_msg_delay);
            #endif
            send_char('E',KEYER_NORMAL);
            send_char('R',KEYER_NORMAL);
            send_char('R',KEYER_NORMAL);
          }
          break;
        case 1211: command_weighting_adjust();break; // L - weight adjust
        case 21: // N - paddle mode toggle
          if (configuration.paddle_mode == PADDLE_NORMAL) {
            configuration.paddle_mode = PADDLE_REVERSE;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
            #endif //FEATURE_DISPLAY
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
            #endif //FEATURE_DISPLAY
            configuration.paddle_mode = PADDLE_NORMAL;
          }
          config_dirty = 1;
          send_dit();
          break;
        case 222: // O - toggle sidetone on and off
          if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)) {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
            #endif
            #ifdef DEBUG_COMMAND_MODE
              debug_serial_port->println(F("command_mode: SIDETONE_OFF"));
            #endif
            configuration.sidetone_mode = SIDETONE_OFF;
            //boop();
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
            #endif
            #ifdef DEBUG_COMMAND_MODE
              debug_serial_port->println(F("command_mode: SIDETONE_ON"));
            #endif
            configuration.sidetone_mode = SIDETONE_ON;
            //beep();
          }
          config_dirty = 1;
          send_dit();
          break;
        case 2: command_tuning_mode(); break;                             // T - tuning mode
        case 122: command_speed_mode(); break;                            // W - change wpm
        case 2112: stay_in_command_mode = 0; break;     // X - exit command mode
        case 121212:send_char(75,KEYER_NORMAL);send_char(51,KEYER_NORMAL);send_char(78,KEYER_NORMAL);send_char(71,KEYER_NORMAL);send_char(32,KEYER_NORMAL);
                    send_char(55,KEYER_NORMAL);send_char(51,KEYER_NORMAL);send_char(32,KEYER_NORMAL);send_char(69,KEYER_NORMAL);send_char(69,KEYER_NORMAL);
                    break;

        case 112211: // ? - status

          delay(250);
          sprintf(c, "%d", configuration.wpm);
          send_char(c[0],KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);

          switch(keyer_mode_before){
            case IAMBIC_A:
              send_char('A',KEYER_NORMAL);
              break;
            case IAMBIC_B:
              send_char('B',KEYER_NORMAL);
              break;
            case SINGLE_PADDLE:
              send_char('S',KEYER_NORMAL);
              break;
            case ULTIMATIC:
              send_char('U',KEYER_NORMAL);
              break;
            case BUG:
              send_char('G',KEYER_NORMAL);
              break;
          }
          send_char(' ',KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);


          sprintf(c, "%d", configuration.weighting);
          send_char(c[0],KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);

          sprintf(c, "%d", configuration.dah_to_dit_ratio);
          send_char(c[0],KEYER_NORMAL);
          send_char('.',KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          send_char(c[2],KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);

          break;



        case 9: // button was hit
            stay_in_command_mode = 0;
          break;
        default: // unknown command, send a ?
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Unknown command", 0, default_display_msg_delay);
          #endif
          send_char('?',KEYER_NORMAL);
          break;
      }
    }
  }
  beep_boop();

  #ifdef command_mode_active_led
    if (command_mode_active_led) {digitalWrite(command_mode_active_led,LOW);}
  #endif //command_mode_active_led

  keyer_machine_mode = KEYER_NORMAL;

  speed_mode = speed_mode_before;   // go back to whatever speed mode we were in before
  configuration.keyer_mode = keyer_mode_before;

  #ifdef DEBUG_COMMAND_MODE
    if (command_mode_disable_tx) {
      debug_serial_port->print(F("command_mode: command_mode_disable_tx set"));
    }
  #endif //DEBUG_COMMAND_MODE



}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------

void adjust_dah_to_dit_ratio(int adjustment) {

 if ((configuration.dah_to_dit_ratio + adjustment) > 150 && (configuration.dah_to_dit_ratio + adjustment) < 810) {
   configuration.dah_to_dit_ratio = configuration.dah_to_dit_ratio + adjustment;
   #ifdef FEATURE_DISPLAY
   #endif
 }

 config_dirty = 1;
}

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_dah_to_dit_ratio_adjust() {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
    lcd_center_print_timed("Adj dah to dit", 0, default_display_msg_delay);
  #endif

  while (looping) {
    send_dit();
    send_dah();
    if (paddle_pin_read(paddle_left) == LOW) {
      adjust_dah_to_dit_ratio(10);
    }
    if (paddle_pin_read(paddle_right) == LOW) {
      adjust_dah_to_dit_ratio(-10);
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
      looping = 0;
    }



  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  dit_buffer = 0;
  dah_buffer = 0;
}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_weighting_adjust() {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
    lcd_center_print_timed("Adj weighting", 0, default_display_msg_delay);
  #endif

  while (looping) {
    send_dit();
    send_dah();
    if (paddle_pin_read(paddle_left) == LOW) {
      configuration.weighting = configuration.weighting + 1;
      if (configuration.weighting > 90){configuration.weighting = 90;}
    }
    if (paddle_pin_read(paddle_right) == LOW) {
      configuration.weighting = configuration.weighting - 1;
      if (configuration.weighting < 10){configuration.weighting = 10;}
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
      looping = 0;
    }


  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  dit_buffer = 0;
  dah_buffer = 0;
}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_tuning_mode() {

  byte looping = 1;
  byte latched = 0;


  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Tune Mode", 0, default_display_msg_delay);
  #endif

  send_dit();
  key_tx = 1;
  while (looping) {


    if (paddle_pin_read(paddle_left) == LOW) {
      sending_mode = MANUAL_SENDING;
      tx_and_sidetone_key(1);
      ptt_key();
      latched = 0;
    } else {
       if (paddle_pin_read(paddle_left) == HIGH && latched == 0) {
         sending_mode = MANUAL_SENDING;
         tx_and_sidetone_key(0);
         ptt_unkey();
       }
    }

    if (paddle_pin_read(paddle_right) == LOW && latched == 0) {
      latched = 1;
      sending_mode = MANUAL_SENDING;
      tx_and_sidetone_key(1);
      ptt_key();
      while ((paddle_pin_read(paddle_right) == LOW) && (paddle_pin_read(paddle_left) == HIGH)) {
        delay(10);
      }
    } else {
      if ((paddle_pin_read(paddle_right) == LOW) && (latched)) {
        latched = 0;
        sending_mode = MANUAL_SENDING;
        tx_and_sidetone_key(0);
        ptt_unkey();
        while ((paddle_pin_read(paddle_right) == LOW) && (paddle_pin_read(paddle_left) == HIGH)) {
          delay(10);
        }
      }
    }
   if ((analogbuttonread(0)) || ((paddle_pin_read(paddle_left) == LOW) && (paddle_pin_read(paddle_right) == LOW))) { // if paddles are squeezed or button0 pressed - exit
     looping = 0;
   }

  }
  sending_mode = MANUAL_SENDING;
  tx_and_sidetone_key(0);
  ptt_unkey();
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  key_tx = 0;
  send_dit();
  dit_buffer = 0;
  dah_buffer = 0;
}
#endif //FEATURE_COMMAND_BUTTONS
//-------------------------------------------------------------------------------------------------------

void sidetone_adj(int hz) {

  if ((configuration.hz_sidetone + hz) > SIDETONE_HZ_LOW_LIMIT && (configuration.hz_sidetone + hz) < SIDETONE_HZ_HIGH_LIMIT) {
    configuration.hz_sidetone = configuration.hz_sidetone + hz;
    config_dirty = 1;
  }

}

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
void command_sidetone_freq_adj() {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
  #endif

  while (looping) {
    tone(sidetone_line, configuration.hz_sidetone);
    if (paddle_pin_read(paddle_left) == LOW) {
      #ifdef FEATURE_DISPLAY
      sidetone_adj(5);
      lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
      #else
      sidetone_adj(1);
      #endif
      delay(10);
    }
    if (paddle_pin_read(paddle_right) == LOW) {
      #ifdef FEATURE_DISPLAY
      sidetone_adj(-5);
      lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
      #else
      sidetone_adj(-1);
      #endif
      delay(10);
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
      looping = 0;
    }


  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  noTone(sidetone_line);

}
#endif //FEATURE_COMMAND_BUTTONS
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
void command_speed_mode()
{

  byte looping = 1;
  String wpm_string;

  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Adjust Speed", 0, default_display_msg_delay);
  #endif


  while (looping) {
    send_dit();
    if ((paddle_pin_read(paddle_left) == LOW)) {
      speed_change(1);
    }
    if ((paddle_pin_read(paddle_right) == LOW)) {
      speed_change(-1);
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0) ))  // if paddles are squeezed or button0 pressed - exit
    {
      looping = 0;
    }


  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  #ifndef FEATURE_DISPLAY
    // announce speed in CW
    wpm_string = String(configuration.wpm, DEC);
    send_char(wpm_string[0],KEYER_NORMAL);
    send_char(wpm_string[1],KEYER_NORMAL);
  #endif

  dit_buffer = 0;
  dah_buffer = 0;

}
#endif //FEATURE_COMMAND_BUTTONS
//------------------------------------------------------------------
#ifndef FEATURE_DISPLAY
void send_tx() {

  send_char('T',KEYER_NORMAL);
  send_char('X',KEYER_NORMAL);
}
#endif

//------------------------------------------------------------------

void switch_to_tx_silent(byte tx) {

  switch (tx) {
   case 1: if ((ptt_tx_1) || (tx_key_line_1)) { configuration.current_ptt_line = ptt_tx_1; current_tx_key_line = tx_key_line_1; configuration.current_tx = 1; config_dirty = 1; } break;
   case 2: if ((ptt_tx_2) || (tx_key_line_2)) { configuration.current_ptt_line = ptt_tx_2; current_tx_key_line = tx_key_line_2; configuration.current_tx = 2; config_dirty = 1; } break;
   case 3: if ((ptt_tx_3) || (tx_key_line_3)) { configuration.current_ptt_line = ptt_tx_3; current_tx_key_line = tx_key_line_3; configuration.current_tx = 3; config_dirty = 1; } break;
   case 4: if ((ptt_tx_4) || (tx_key_line_4)) { configuration.current_ptt_line = ptt_tx_4; current_tx_key_line = tx_key_line_4; configuration.current_tx = 4; config_dirty = 1; } break;
   case 5: if ((ptt_tx_5) || (tx_key_line_5)) { configuration.current_ptt_line = ptt_tx_5; current_tx_key_line = tx_key_line_5; configuration.current_tx = 5; config_dirty = 1; } break;
   case 6: if ((ptt_tx_6) || (tx_key_line_6)) { configuration.current_ptt_line = ptt_tx_6; current_tx_key_line = tx_key_line_6; configuration.current_tx = 6; config_dirty = 1; } break;
  }

}

//------------------------------------------------------------------
void switch_to_tx(byte tx)
{


  #ifdef FEATURE_DISPLAY
  switch (tx) {
   case 1: if ((ptt_tx_1) || (tx_key_line_1)) { switch_to_tx_silent(1); lcd_center_print_timed("TX 1", 0, default_display_msg_delay); } break;
   case 2: if ((ptt_tx_2) || (tx_key_line_2)) { switch_to_tx_silent(2); lcd_center_print_timed("TX 2", 0, default_display_msg_delay); } break;
   case 3: if ((ptt_tx_3) || (tx_key_line_3)) { switch_to_tx_silent(3); lcd_center_print_timed("TX 3", 0, default_display_msg_delay); } break;
   case 4: if ((ptt_tx_4) || (tx_key_line_4)) { switch_to_tx_silent(4); lcd_center_print_timed("TX 4", 0, default_display_msg_delay); } break;
   case 5: if ((ptt_tx_5) || (tx_key_line_5)) { switch_to_tx_silent(5); lcd_center_print_timed("TX 5", 0, default_display_msg_delay); } break;
   case 6: if ((ptt_tx_6) || (tx_key_line_6)) { switch_to_tx_silent(6); lcd_center_print_timed("TX 6", 0, default_display_msg_delay); } break;
  }
  #else
  switch (tx) {
   case 1: if ((ptt_tx_1) || (tx_key_line_1)) { switch_to_tx_silent(1); send_tx(); send_char('1',KEYER_NORMAL); } break;
   case 2: if ((ptt_tx_2) || (tx_key_line_2)) { switch_to_tx_silent(2); send_tx(); send_char('2',KEYER_NORMAL); } break;
   case 3: if ((ptt_tx_3) || (tx_key_line_3)) { switch_to_tx_silent(3); send_tx(); send_char('3',KEYER_NORMAL); } break;
   case 4: if ((ptt_tx_4) || (tx_key_line_4)) { switch_to_tx_silent(4); send_tx(); send_char('4',KEYER_NORMAL); } break;
   case 5: if ((ptt_tx_5) || (tx_key_line_5)) { switch_to_tx_silent(5); send_tx(); send_char('5',KEYER_NORMAL); } break;
   case 6: if ((ptt_tx_6) || (tx_key_line_6)) { switch_to_tx_silent(6); send_tx(); send_char('6',KEYER_NORMAL); } break;
  }
  #endif
}

//------------------------------------------------------------------


//------------------------------------------------------------------


//------------------------------------------------------------------

void initialize_analog_button_array() {
#ifdef FEATURE_COMMAND_BUTTONS




  /*

  typical button values:

    0: -56 - 46
    1: 47 - 131
    2: 132 - 203
    3: 203 - 264

  */




    int button_value;
    int lower_button_value;
    int higher_button_value;


    for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
      button_value = int(1023 * (float(x * analog_buttons_r2)/float((x * analog_buttons_r2) + analog_buttons_r1)));
      lower_button_value = int(1023 * (float((x-1) * analog_buttons_r2)/float(((x-1) * analog_buttons_r2) + analog_buttons_r1)));
      higher_button_value = int(1023 * (float((x+1) * analog_buttons_r2)/float(((x+1) * analog_buttons_r2) + analog_buttons_r1)));
        button_array_low_limit[x] = (button_value - ((button_value - lower_button_value)/2));
        button_array_high_limit[x] = (button_value + ((higher_button_value - button_value)/2));

      #ifdef DEBUG_BUTTON_ARRAY
        debug_serial_port->print(F("initialize_analog_button_array: "));
        debug_serial_port->print(x);
        debug_serial_port->print(F(": "));
        debug_serial_port->print(button_array_low_limit[x]);
        debug_serial_port->print(F(" - "));
        debug_serial_port->println(button_array_high_limit[x]);
      #endif //DEBUG_BUTTON_ARRAY


    }

#endif //FEATURE_COMMAND_BUTTONS
}


//------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
byte analogbuttonpressed() {

  int analog_line_read_average = 0;
  int analog_read_temp = 0;

    if (analogRead(analog_buttons_pin) <= button_array_high_limit[analog_buttons_number_of_buttons-1]) {

      for (byte x = 0;x < 19;x++){
        analog_read_temp = analogRead(analog_buttons_pin);
        if (analog_read_temp <= button_array_high_limit[analog_buttons_number_of_buttons-1]){
          analog_line_read_average = (analog_line_read_average + analog_read_temp) / 2;
        }
      }

      for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
        if ((analog_line_read_average > button_array_low_limit[x]) && (analog_line_read_average <=  button_array_high_limit[x])) {
          #ifdef DEBUG_BUTTONS
          //if (!debug_flag) {
            debug_serial_port->print(F(" analogbuttonpressed: returning: "));
            debug_serial_port->println(x);
          //  debug_flag = 1;
          //}
          #endif
          return x;
        }
      }

    }



  /*

  int analog_line_read = analogRead(analog_buttons_pin);

  static byte samplecounts = 0;
  static int running_analog_line_read_average = 0;

  #ifdef DEBUG_BUTTONS
  static byte debug_flag = 0;
  #endif

  if (analog_line_read < 1000) {

    running_analog_line_read_average = running_analog_line_read_average + analog_line_read;
    samplecounts++;
    if (samplecounts > 19) {
      analog_line_read = running_analog_line_read_average / samplecounts;

      #ifdef DEBUG_BUTTONS
      if (!debug_flag) {
        primary_serial_port->print(F("\nanalogbuttonpressed: analog_line_read: "));
        primary_serial_port->print(analog_line_read);
        primary_serial_port->print(F(" samplecounts: "));
        primary_serial_port->print(samplecounts);
      }
      #endif

      for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
        if ((analog_line_read > button_array_low_limit[x]) && (analog_line_read <=  button_array_high_limit[x])) {
          #ifdef DEBUG_BUTTONS
          if (!debug_flag) {
            primary_serial_port->print(F(" analogbuttonpressed: returning: "));
            primary_serial_port->println(x);
            debug_flag = 1;
          }
          #endif
          samplecounts = 0;
          running_analog_line_read_average = 0;
          return x;
        }
      }
    }  //(samplecounts > 9)
  } else {  //(analog_line_read < 1000)
    samplecounts = 0;
    running_analog_line_read_average = 0;
  }

  #ifdef DEBUG_BUTTONS
  debug_flag = 0;
  #endif


  */

  return 255;
}

#endif

//------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
byte analogbuttonread(byte button_number) {

  // button numbers start with 0

  int analog_line_read = analogRead(analog_buttons_pin);

  #ifdef DEBUG_BUTTONS
  static byte debug_flag = 0;
  #endif

  if (analog_line_read < 1000) {
    if ((analog_line_read > button_array_low_limit[button_number])&& (analog_line_read <  button_array_high_limit[button_number])) {
      #ifdef DEBUG_BUTTONS
      if (!debug_flag) {
        debug_serial_port->print(F("\nanalogbuttonread: analog_line_read: "));
        debug_serial_port->print(analog_line_read);
        debug_serial_port->print(F("  button pressed: "));
        debug_serial_port->println(button_number);
        debug_flag = 1;
      }
      #endif
      return 1;
    }
  }
  #ifdef DEBUG_BUTTONS
  debug_flag = 0;
  #endif
  return 0;
}
#endif

//------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void check_command_buttons()
{

  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering check_buttons"));
  #endif

  // OI3: MEM1 / MEM2 change WPM by ±1 in CW modes (ActualMode 0 or 1)
  if (ActualMode == 0 || ActualMode == 1) {
    static unsigned long last_mem_wpm_ms = 0;
    byte mem_btn = analogbuttonpressed();
    if ((mem_btn == 1 || mem_btn == 2) && (millis() - last_mem_wpm_ms) > 200) {
      speed_change(mem_btn == 1 ? -1 : 1);
      last_mem_wpm_ms = millis();
      while (analogbuttonpressed() == mem_btn) {}   // wait for release
      return;                                       // skip the rest (no switch_to_tx, no command mode)
    }
  }

  static long last_button_action = 0;
  byte analogbuttontemp = analogbuttonpressed();
  long button_depress_time;
  byte paddle_was_hit = 0;
  byte store_key_tx = key_tx;
  byte previous_sidetone_mode = 0;
  if ((analogbuttontemp < analog_buttons_number_of_buttons) && ((millis() - last_button_action) > 200)) {
    button_depress_time = millis();
    while ((analogbuttontemp == analogbuttonpressed()) && ((millis() - button_depress_time) < 1000)) {
      if ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW)) {
        button_depress_time = 1001;  // if button 0 is held and a paddle gets hit, assume we have a hold and shortcut out
      }
    }
    if ((millis() - button_depress_time) < 500) {
      if (analogbuttontemp == 0) {
        key_tx = 0;
        command_mode();
        if (command_mode_disable_tx) {
          key_tx = !store_key_tx;
        } else {
          key_tx = 1;
        }
      }
    } else {
//      if ((millis() - button_depress_time) < 1000) {
//        if ((analogbuttontemp > 0) && (analogbuttontemp < 7)) {
//          key_tx = 0;
//          switch_to_tx(analogbuttontemp);
//          key_tx = 1;
//        }
//      } else {  // we got a button hold
        if (analogbuttontemp == 0) {
          key_tx = 0;
          // do stuff if this is a command button hold down
          while (analogbuttonpressed() == 0) {
            if (paddle_pin_read(paddle_left) == LOW) {                     // left paddle increase speed
              speed_change(1);
              previous_sidetone_mode = configuration.sidetone_mode;
              configuration.sidetone_mode = SIDETONE_ON;
              sending_mode = MANUAL_SENDING;
              send_dit();
              configuration.sidetone_mode = previous_sidetone_mode;
              //speed_button_cmd_executed = 1;
              dit_buffer = 0;

              #ifdef DEBUG_BUTTONS
                debug_serial_port->println(F("\ncheck_buttons: speed_change(1)"));
              #endif //DEBUG_BUTTONS


            }
            if (paddle_pin_read(paddle_right) == LOW) {                    // right paddle decreases speed
              speed_change(-1);
              previous_sidetone_mode = configuration.sidetone_mode;
              configuration.sidetone_mode = SIDETONE_ON;
              sending_mode = MANUAL_SENDING;
              send_dah();
              configuration.sidetone_mode = previous_sidetone_mode;
              //speed_button_cmd_executed = 1;
              dah_buffer = 0;

              #ifdef DEBUG_BUTTONS
                debug_serial_port->println(F("\ncheck_buttons: speed_change(-1)"));
              #endif //DEBUG_BUTTONS

            }
         }
         key_tx = 1;
       }  //(analogbuttontemp == 0)
       if ((analogbuttontemp > 0) && (analogbuttontemp < analog_buttons_number_of_buttons)) {
         while (analogbuttonpressed() == analogbuttontemp) {
            if (((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW)) && (analogbuttontemp < (number_of_memories + 1))){
              paddle_was_hit = 1;
            }
         }
         if (!paddle_was_hit) {  // if no paddle was hit, this was a button hold to change transmitters
             key_tx = 0;
             previous_sidetone_mode = configuration.sidetone_mode;
             configuration.sidetone_mode = SIDETONE_ON;
             switch_to_tx(analogbuttontemp);
             key_tx = 1;
             configuration.sidetone_mode = previous_sidetone_mode;
         }
       }
     //} // button hold
    }
    last_button_action = millis();
  }
}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------

void service_dit_dah_buffers()
{
  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering service_dit_dah_buffers"));
  #endif

  if (automatic_sending_interruption_time != 0){
    if ((millis() - automatic_sending_interruption_time) > (configuration.paddle_interruption_quiet_time_element_lengths*(1200/configuration.wpm))){
      automatic_sending_interruption_time = 0;
      sending_mode = MANUAL_SENDING;
    } else {
      dit_buffer = 0;
      dah_buffer = 0;
      return;
    }
  }

  static byte bug_dah_flag = 0;

  #ifdef FEATURE_PADDLE_ECHO
    static unsigned long bug_dah_key_down_time = 0;
  #endif //FEATURE_PADDLE_ECHO


  if ((configuration.keyer_mode == IAMBIC_A) || (configuration.keyer_mode == IAMBIC_B) || (configuration.keyer_mode == ULTIMATIC) || (configuration.keyer_mode == SINGLE_PADDLE)) {
    if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left)) && (paddle_pin_read(paddle_right))) {
      iambic_flag = 0;
      dit_buffer = 0;
      dah_buffer = 0;
    } else {
      if (dit_buffer) {
        dit_buffer = 0;
        sending_mode = MANUAL_SENDING;
        send_dit();
      }
      if (dah_buffer) {
        dah_buffer = 0;
        sending_mode = MANUAL_SENDING;
        send_dah();
      }
    }
  } else {
    if (configuration.keyer_mode == BUG) {
      if (dit_buffer) {
        dit_buffer = 0;
        sending_mode = MANUAL_SENDING;
        send_dit();
      }

      if (dah_buffer) {
        dah_buffer = 0;
        if (!bug_dah_flag) {
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(1);
          bug_dah_flag = 1;
          #ifdef FEATURE_PADDLE_ECHO
            bug_dah_key_down_time = millis();
          #endif //FEATURE_PADDLE_ECHO
        }

        #ifdef FEATURE_PADDLE_ECHO
          paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*3000.0)/configuration.wpm)*length_letterspace);
        #endif //FEATURE_PADDLE_ECHO

      } else {
        if (bug_dah_flag){
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(0);
          #ifdef FEATURE_PADDLE_ECHO
            if ((millis() - bug_dah_key_down_time) > (0.5 * (1200.0/configuration.wpm))){
              if ((millis() - bug_dah_key_down_time) > (2 * (1200.0/configuration.wpm))){
                paddle_echo_buffer = (paddle_echo_buffer * 10) + 2;
              } else {
                paddle_echo_buffer = (paddle_echo_buffer * 10) + 1;
              }
              paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*3000.0)/configuration.wpm)*length_letterspace);
            }
          #endif //FEATURE_PADDLE_ECHO
          bug_dah_flag = 0;
        }
      }
    } else {
      if (configuration.keyer_mode == STRAIGHT) {
        if (dit_buffer) {
          dit_buffer = 0;
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(1);
        } else {
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(0);
        }
      }
    }
  }

}

//-------------------------------------------------------------------------------------------------------

void beep()
{
 tone(sidetone_line, hz_high_beep, 200);
}

//-------------------------------------------------------------------------------------------------------

void boop()
{
  tone(sidetone_line, hz_low_beep);
  delay(100);
  noTone(sidetone_line);
}

//-------------------------------------------------------------------------------------------------------

void beep_boop()
{
  tone(sidetone_line, hz_high_beep);
  delay(100);
  tone(sidetone_line, hz_low_beep);
  delay(100);
  noTone(sidetone_line);
}

//-------------------------------------------------------------------------------------------------------

void boop_beep()
{
  tone(sidetone_line, hz_low_beep);
  delay(100);
  tone(sidetone_line, hz_high_beep);
  delay(100);
  noTone(sidetone_line);
}



//-------------------------------------------------------------------------------------------------------
void send_the_dits_and_dahs(char const * cw_to_send){


  /* American Morse - Special Symbols

    ~  long dah (4 units)

    =  very long dah (5 units)

    &  an extra space (1 unit)

  */

  sending_mode = AUTOMATIC_SENDING;

  for (int x = 0;x < 12;x++){
    if (trxCwAbort) return;
    switch(cw_to_send[x]){
      case '.': send_dit(); break;
      case '-': send_dah(); break;
      default: return; break;
    }
    if (dit_buffer || dah_buffer || sending_mode == AUTOMATIC_SENDING_INTERRUPTED){
      dit_buffer = 0;
      dah_buffer = 0;
      return;
    }


  }

}

//-------------------------------------------------------------------------------------------------------

void send_char(byte cw_char, byte omit_letterspace)
{
  #ifdef DEBUG_SEND_CHAR
    debug_serial_port->print(F("send_char: called with cw_char:"));
    debug_serial_port->print((byte)cw_char);
    if (omit_letterspace) {
      debug_serial_port->print(F(" OMIT_LETTERSPACE"));
    }
    debug_serial_port->println();
  #endif



  if ((cw_char == 10) || (cw_char == 13)) { return; }  // don't attempt to send carriage return or line feed

  sending_mode = AUTOMATIC_SENDING;

  if (char_send_mode == CW) {
    switch (cw_char) {
      case 'A': send_the_dits_and_dahs(".-");break;
      case 'B': send_the_dits_and_dahs("-...");break;
      case 'C': send_the_dits_and_dahs("-.-.");break;
      case 'D': send_the_dits_and_dahs("-..");break;
      case 'E': send_the_dits_and_dahs(".");break;
      case 'F': send_the_dits_and_dahs("..-.");break;
      case 'G': send_the_dits_and_dahs("--.");break;
      case 'H': send_the_dits_and_dahs("....");break;
      case 'I': send_the_dits_and_dahs("..");break;
      case 'J': send_the_dits_and_dahs(".---");break;
      case 'K': send_the_dits_and_dahs("-.-");break;
      case 'L': send_the_dits_and_dahs(".-..");break;
      case 'M': send_the_dits_and_dahs("--");break;
      case 'N': send_the_dits_and_dahs("-.");break;
      case 'O': send_the_dits_and_dahs("---");break;
      case 'P': send_the_dits_and_dahs(".--.");break;
      case 'Q': send_the_dits_and_dahs("--.-");break;
      case 'R': send_the_dits_and_dahs(".-.");break;
      case 'S': send_the_dits_and_dahs("...");break;
      case 'T': send_the_dits_and_dahs("-");break;
      case 'U': send_the_dits_and_dahs("..-");break;
      case 'V': send_the_dits_and_dahs("...-");break;
      case 'W': send_the_dits_and_dahs(".--");break;
      case 'X': send_the_dits_and_dahs("-..-");break;
      case 'Y': send_the_dits_and_dahs("-.--");break;
      case 'Z': send_the_dits_and_dahs("--..");break;

      case '0': send_the_dits_and_dahs("-----");break;
      case '1': send_the_dits_and_dahs(".----");break;
      case '2': send_the_dits_and_dahs("..---");break;
      case '3': send_the_dits_and_dahs("...--");break;
      case '4': send_the_dits_and_dahs("....-");break;
      case '5': send_the_dits_and_dahs(".....");break;
      case '6': send_the_dits_and_dahs("-....");break;
      case '7': send_the_dits_and_dahs("--...");break;
      case '8': send_the_dits_and_dahs("---..");break;
      case '9': send_the_dits_and_dahs("----.");break;

      case '=': send_the_dits_and_dahs("-...-");break;
      case '/': send_the_dits_and_dahs("-..-.");break;
      case ' ': loop_element_lengths((configuration.length_wordspace-length_letterspace-2),0,configuration.wpm); break;
      case '*': send_the_dits_and_dahs("-...-.-");break;
      //case '&': send_dit(); loop_element_lengths(3); send_dits(3); break;
      case '.': send_the_dits_and_dahs(".-.-.-");break;
      case ',': send_the_dits_and_dahs("--..--");break;
      case '\'': send_the_dits_and_dahs(".----.");break;// apostrophe
      case '!': send_the_dits_and_dahs("-.-.--");break;
      case '(': send_the_dits_and_dahs("-.--.");break;
      case ')': send_the_dits_and_dahs("-.--.-");break;
      case '&': send_the_dits_and_dahs(".-...");break;
      case ':': send_the_dits_and_dahs("---...");break;
      case ';': send_the_dits_and_dahs("-.-.-.");break;
      case '+': send_the_dits_and_dahs(".-.-.");break;
      case '-': send_the_dits_and_dahs("-....-");break;
      case '_': send_the_dits_and_dahs("..--.-");break;
      case '"': send_the_dits_and_dahs(".-..-.");break;
      case '$': send_the_dits_and_dahs("...-..-");break;
      case '@': send_the_dits_and_dahs(".--.-.");break;
      case '<': send_the_dits_and_dahs(".-.-.");break; // AR
      case '>': send_the_dits_and_dahs("...-.-");break; // SK


      case '\n': break;
      case '\r': break;



      case '|':
          loop_element_lengths(0.5,0,configuration.wpm);
        return;
        break;

      #if defined(OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION)
        case '?': send_the_dits_and_dahs("..--..");break;
      #endif

      default:
        #if !defined(OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION)
          send_the_dits_and_dahs("..--..");
        #endif
        break;

    }
    if (omit_letterspace != OMIT_LETTERSPACE) {

      loop_element_lengths((length_letterspace-1),0,configuration.wpm); //this is minus one because send_dit and send_dah have a trailing element space

    }
  } else {
    if (char_send_mode == HELL){
    } else {
      if (char_send_mode == AMERICAN_MORSE){
      }
    }
  }

}

//-------------------------------------------------------------------------------------------------------

int uppercase (int charbytein)
{
  if (((charbytein > 96) && (charbytein < 123)) || ((charbytein > 223) && (charbytein < 255))) {
    charbytein = charbytein - 32;
  }
  if (charbytein == 158) { charbytein = 142; }  // ž -> Ž
  if (charbytein == 154) { charbytein = 138; }  // š -> Š

  return charbytein;
}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------

void service_send_buffer(byte no_print)
{
  // send one character out of the send buffer


  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering service_send_buffer"));
  #endif


  static unsigned long timed_command_end_time;
  static byte timed_command_in_progress = 0;

  if (send_buffer_status == SERIAL_SEND_BUFFER_NORMAL) {
    if ((send_buffer_bytes > 0) && (pause_sending_buffer == 0)) {

      if ((send_buffer_array[0] > SERIAL_SEND_BUFFER_SPECIAL_START) && (send_buffer_array[0] < SERIAL_SEND_BUFFER_SPECIAL_END)) {
        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_HOLD_SEND) {
          send_buffer_status = SERIAL_SEND_BUFFER_HOLD;
          remove_from_send_buffer();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE) {
          remove_from_send_buffer();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_MEMORY_NUMBER) {
          #ifdef DEBUG_SEND_BUFFER
            debug_serial_port->println(F("service_send_buffer: SERIAL_SEND_BUFFER_MEMORY_NUMBER"));
          #endif
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            if (send_buffer_array[0] < number_of_memories) {
            }
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_WPM_CHANGE) {  // two bytes for wpm
          remove_from_send_buffer();
          if (send_buffer_bytes > 1) {
            configuration.wpm = send_buffer_array[0] * 256;
            remove_from_send_buffer();
            configuration.wpm = configuration.wpm + send_buffer_array[0];
            remove_from_send_buffer();


          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TX_CHANGE) {  // one byte for transmitter #
          remove_from_send_buffer();
          if (send_buffer_bytes > 1) {
            if ((send_buffer_array[0] > 0) && (send_buffer_array[0] < 7)){
              switch_to_tx_silent(send_buffer_array[0]);
            }
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_NULL) {
          remove_from_send_buffer();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_PROSIGN) {
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            send_char(send_buffer_array[0],OMIT_LETTERSPACE);
            remove_from_send_buffer();
          }
          if (send_buffer_bytes > 0) {
            send_char(send_buffer_array[0],KEYER_NORMAL);
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TIMED_KEY_DOWN) {
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            send_buffer_status = SERIAL_SEND_BUFFER_TIMED_COMMAND;
            sending_mode = AUTOMATIC_SENDING;
            tx_and_sidetone_key(1);
            timed_command_end_time = millis() + (send_buffer_array[0] * 1000);
            timed_command_in_progress = SERIAL_SEND_BUFFER_TIMED_KEY_DOWN;
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TIMED_WAIT) {
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            send_buffer_status = SERIAL_SEND_BUFFER_TIMED_COMMAND;
            timed_command_end_time = millis() + (send_buffer_array[0] * 1000);
            timed_command_in_progress = SERIAL_SEND_BUFFER_TIMED_WAIT;
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_PTT_ON) {
          remove_from_send_buffer();
          manual_ptt_invoke = 1;
          ptt_key();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_PTT_OFF) {
          remove_from_send_buffer();
          manual_ptt_invoke = 0;

          ptt_unkey();
        }



      } else {







        #ifdef FEATURE_DISPLAY
          if (lcd_send_echo) {
            display_scroll_print_char(send_buffer_array[0]);
            service_display();
          }
        #endif //FEATURE_DISPLAY
        send_char(send_buffer_array[0],KEYER_NORMAL);
        remove_from_send_buffer();
      }
    }

  } else {

    if (send_buffer_status == SERIAL_SEND_BUFFER_TIMED_COMMAND) {    // we're in a timed command

      if ((timed_command_in_progress == SERIAL_SEND_BUFFER_TIMED_KEY_DOWN) && (millis() > timed_command_end_time)) {
        sending_mode = AUTOMATIC_SENDING;
        tx_and_sidetone_key(0);
        timed_command_in_progress = 0;
        send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
      }

      if ((timed_command_in_progress == SERIAL_SEND_BUFFER_TIMED_WAIT) && (millis() > timed_command_end_time)) {
        timed_command_in_progress = 0;
        send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
      }

    }

    if (send_buffer_status == SERIAL_SEND_BUFFER_HOLD) {  // we're in a send hold ; see if there's a SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE in the buffer
      if (send_buffer_bytes == 0) {
        send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;  // this should never happen, but what the hell, we'll catch it here if it ever does happen
      } else {
        for (int z = 0; z < send_buffer_bytes; z++) {
          if (send_buffer_array[z] ==  SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE) {
            send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
            z = send_buffer_bytes;
          }
        }
      }
    }

  }

  //if the paddles are hit, dump the buffer
  check_paddles();
  if ((dit_buffer || dah_buffer) && (send_buffer_bytes  > 0)) {
    clear_send_buffer();
    send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
    dit_buffer = 0;
    dah_buffer = 0;
  }

}

//-------------------------------------------------------------------------------------------------------
void clear_send_buffer()
{
  send_buffer_bytes = 0;
}

//-------------------------------------------------------------------------------------------------------
void remove_from_send_buffer()
{


  if (send_buffer_bytes > 0) {
    send_buffer_bytes--;
  }
  if (send_buffer_bytes > 0) {
    for (int x = 0;x < send_buffer_bytes;x++) {
      send_buffer_array[x] = send_buffer_array[x+1];
    }
  }
}

//-------------------------------------------------------------------------------------------------------

void add_to_send_buffer(byte incoming_serial_byte)
{
//  if ((incoming_serial_byte == SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE) && (send_buffer_status == SERIAL_SEND_BUFFER_HOLD)) {
//    send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
//  } else {
    if (send_buffer_bytes < send_buffer_size) {
      if (incoming_serial_byte != 127) {
        send_buffer_bytes++;
        send_buffer_array[send_buffer_bytes - 1] = incoming_serial_byte;


      } else {  // we got a backspace
        send_buffer_bytes--;
      }
    }
//  }
}

//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------



/*

Chapter One

It was late on a rainy Sunday evening.  Static crashes on the direct conversion receiver signaled a distant thunderstorm, due to arrive in an hour or so.  Colin knew he would have to disconnect the little microcontroller circuit from the receiver and all the station antennas soon, but it was getting late and he had to get his sleep for work the next day.

The contraption was a tangled mess on his desk, something only a radio amateur or mad scientist could appreciate.  Alligator clips connected the I and Q audio from the simple receiver to the microcontroller.  Colin had been learning about fast Fourier analysis.  This was his first attempt at actually running the code in an effort to decode RTTY signals.   The microcontroller probably lacked the horsepower to do it, and Colin knew expecting any sort of performance from his creation was a long shot.

Colin tuned to some RTTY signals but couldn't copy anything, despite carefully and slowly tuning the receiver in hopes of hitting that sweet spot where perhaps the microcontroller would blurt out some intelligence, some discernable word or text.  Just one recognizable snippet would give him the feeling of accomplishment or even victory, even if his design never proved to be usable in his nightly hobby.

The static crashes grew stronger and more frequent.  Colin had resigned himself to the fact that success would not be achieved this evening.  The approaching storm along with his growing fatigue convinced him to shut things down and head upstairs to bed.  Just then a burst of noise, different from the thunderstorm static crashes, but a type that you normally hear on 80 meters each night blurted out.  The microcontroller sent out its serial port a string of random characters, in a vain attempt to decode the sounds:

GEHZCVFNOVTZBEBA

Colin went about the process of disconnecting the power to everything and disconnecting antennas and went to bed.

The next evening after supper with his family, Colin went to his basement radio room again, determined to work again on his project but perhaps less eager than before due to the increasing futility of his efforts.  The microcontroller sat connected to the receiver, and the controller to the computer.  He listened to the receiver in the background while responding to emails.  There was a QSO in progress, an old man talking about his dog itching a lot.  The two old men in the conversation droned on forever, with Colin chuckling to himself, but too caught up in his email to reach over and tune the rig to another frequency in hopes of finding a more interesting conversation.

A burst of noise came through the rig again, much like the night before, though much stronger.  The simple receiver lacked automatic gain control and the strong signal produced a rather loud, annoying noise emanating from the rig, prompting Colin to reach over and turn the volume down.  Colin noticed on his serial terminal program another random string of characters which the microcontroller dutifully decoded:

GEHZCVFNOVTZBEBA

The string looked familiar to Colin.  He copied and pasted the string into search on his computer.  The search produced one hit, the terminal program log from the previous evening.  Colin opened the file and saw the matching string, 16 characters.  "What are the chances of that happening?", he thought.  He looked through his code again, looking for some sort of mistake, pattern in the code algorithm, or some plausible explanation. The receiver belched again:

GEHZCVFNOVTZBEBA

At this point Colin had no plausible explanation why the same random string of characters would be decoded last night and this evening, from mere noise bursts.  Frustrated, he decided to post a message on an Internet group describing the strange behavior and the random characters, and then walked away from his radios to watch TV with the family.  After almost an hour of watching mindless sitcoms, it was time for the kids to go to bed.  After they were tucked into bed, Colin came back to his desk to catch up on email.

The receiver, still powered up with the random noise of the universe coming out of the speaker at a low level, and the connected microcontroller circuit sat idle, waiting for some signal to decode.  An AM roundtable comes up on frequency and he listens awhile, while he continues to web surf, looking for something to occupy his mind.  A static crash comes through the speaks and the microcontroller terminal comes alive again, spewing characters:

COLINMEETME@40-10-45.5&75-10-52.6@SAT1200Z

"Wow" Colin exclaims, almost involuntarily.  He pauses for a moment, hoping his wife in the next room hasn't heard him.  She doesn't respond, continuing to watch TV.  "That's my name....coordinates, and a day and time.  That can't be a coincidence.  What in the world have I stumbled upon?" he thinks.  Nervously he brings up Google Earth and enters  the coordinates.  It's a coffee shop, about an hour and twenty minutes south. " Whoever sent this wants to meet me?"

Chapter Two

Colin barely slept the rest of the nights that week thinking about the message.  He stays out of his radio room which is very unlike him.  His wife is out of town this weekend, and Colin rationalizes that there's no excuse to not go to the coffee shop.  Early Saturday morning he quickly gets up, and nervously gets dressed.  He worries if he's given himself enough time to get there.  It's near the city and the surrounding suburban area where the coffee shop is located is notorious for bad traffic.  He decides to take a toll road and exit where he can take back roads to avoid the main thoroughfares.

He arrived at the coffee with a few minutes to spare, takes an out of the way parking spot towards the rear of the restaurant, backing in so he can see anyone pulling in or out, and the side entrance of the coffee shop.  He sits in the vehicle and surveys the parking lot.   Opening the glove compartment he pulls out a pistol in a holster.  Although licensed for carrying a sidearm, Colin rarely, if ever actual wore it in public.  He strapped it on to his belt and double-checked that his jacket concealed it.  His hands shook nervously, but he reassured himself he was somewhat prepared in case the proverbial "men in black" attempted to swoop down and throw him into a black van and drive off.

Looking up, Colin sees an old man in the parking lot looking his way.  They make eye contact.  Colin looks away but it's clear the old man is has somehow identified him.  Colin sighs.  "Perhaps he saw all the antennas on my vehicle, or my callsign plate."  He gets out of the vehicle, locks it, and walks over to the old man.

"Hello" he says in a somewhat frail voice.  "You Colin?"

"Yes" replies Colin, nervously.

The old man nods and his face lightens up.  "Come inside, let's talk."

They go inside and get in line.  The old man orders a coffee, and Colin, never acquiring a taste for coffee, get a hot chocolate.  They grab a table towards the back, away from everyone else.  The old man looks around to make sure they're out of earshot of others.

The old man leans inward, "So you copied my transmission the other day?"

"Yes."  Colin tells him the story of how he came upon the transmission.

"Well, congratulations.  You've stumbled upon something I think you're going to be very happy about.  You're in amateur radio?"  Colin nods.  "You've come upon a secret society.  We've been around a long time, since World War II.  Some of us are hams, others aren't.  We're everywhere.  You've heard us anytime you've turned on a radio, you just didn't know it.  We're the people you don't normally find on the air....the academics, scientists, progressives, politicians, famous people...activists...introverts...geniuses...people close to world leaders.  We communicate via encrypted messaging.  Those noise bursts you heard were transmissions from me.  Some of our communications are noise bursts.  Sometime we communicate with pure noise, indistinguishable from the normal noise you hear on your receiver everyday.  We hide out in the open."

"But how do you do this?"  Colin's technical curiosity emerges.  "How do you communicate with noise?"

The old man takes a sip from his coffee.  "We use a pseudo-random bit stream and quadrature modulate a digital signal taken from a special alphabet, somewhat like ASCII.  It's amazingly simple but nearly impossible to break without the bit stream.  You were just lucky to receive it.  Apparently the buggy code in your microcontroller digital signal processing generates part of the pseudo random stream under the right conditions.  Everyone thinks 80 meters is noisy.  It's really not, there's just a lot of us talking on it.  You ever turn on your radio and it's S9 noise everywhere?"

"Yes" replies Colin.

"Sometimes that's us.  We sometimes modulate wideband noise when we have a particularly large message to send out, something important.  The technology is really interesting.  It pushes the limits of Shannon's Equation." he pauses.  "You ever hear of long delay echos?"

"I've never experienced one, but I've read about them and heard they're somewhat common." Colin says.

He smiles.  "That's us.  Sometime we communicate by receiving someone's signal on the air, we delay it, modulate the noise on it, and re-transmit it.  We do that for fun.  People seem to get a kick out of it."

"Why does this society exist?"  asks Colin.

"We serve a higher purpose." pointing above, he says.  "It came out of the Resistance in World War II and was originally intended to prevent atrocities like the Holocaust from happening again, but since then it's grown to encompass other things.  Many of us started off as radio amateurs and got bored with it.  We dropped out.  We're the radio guys you don't see at hamfests or on the Internet.  Those of us who are licensed amateurs usually lay low and don't get on the air, at least in a way you can hear us.  Amateur radio is to us as CB is to amateur radio.  Few of us fit in with them. Members communicate about important stuff, like scientific discoveries or secret information from governments that could save lives or change the world.  We've provided information that has ended wars, and started some.  Some say we provided the information that started the fall of the USSR.  We operate without borders or recognition of nationality.   I'm not sure how many of us there are, but it's perhaps in the thousands, worldwide."

Colin asks "Are you spies?"

"We're not spies, we're communicators." he replies.

"Does the government know of this network?"

"Perhaps, but not at a high level or in any official capacity that we know of.  We definitely have members close to people high up, advisers of sorts.  Undoubtedly there are members in intelligence agencies in various governments.  But they don't dare divulge knowledge of the network.  It's too valuable.  To them it's a tool, and they know they would be denied that tool, purged from the network, should they let others know of it.  But they are free to use the information they receive, as they see fit.  But they know they have a responsibility to use it for the greater good."

The old man clears his throat and takes another gulp of coffee.  "Communications is a weapon, more powerful than any weapon you can carry.  That phone," he said, pointing to my iPhone lying on the table, " is just as powerful as the weapon you have on your belt, just in a different way."

Colin tries to hide a puzzled look, wondering how the old man knew of his weapon.  Changing the subject, he asks "How do people get into this?"

"Membership is by invitation only.  We have 16 character identity strings.  You received mine.  An identity string is what you would call a callsign in amateur radio.  You're the first person I've ever heard of receiving the signal without knowledge of the code.  There's no process for someone like you to join.  But I'm getting old and I need to hand off my encryption stream to someone before I die, to keep it going.  You seem to be a nice enough guy, qualified to join, from what I have seen and heard about you."

"But.... this sounds like a network of rather smart and powerful people.  I'm just an ordinary guy who likes to play with radios and occasionally build something.  I'm not a scientist or someone powerful.  Is there some role I will have, something I need to do?" Colin asks.

"Some members just have fun with this, somewhat like a hobby.  They don't have roles, for now.  You will have a role, you just don't know what it is yet.  Do not seek out a role.  Do not try to make yourself important or identify some great thing to do.  Those who invent things to do, create crises, or give themselves power get purged from the network.  Your role will become known in due time and you will know it when you encounter it.  Trust me." 

He goes on, "You're going to receive more information.  It will explain the encryption algorithm.  You know how to program, so with a little bit of work you should be able to write the software for a transceiver that will work reliably.  I'll also give you an identity string.  It's derived from mine and you'll eventually be able to trace it back mathematically to previous identity strings and others in the hierarchy.  The more you communicate, your identity string will establish a trust relationship with other identity strings, other operators.  The more operators you gain trust with, you will get more of the algorithm and more of the bit stream.  With more of the algorithm and bit stream, the more signals you will be able to receive and you will be able to communicate with more people in the network hierarchy.  With perseverance and patience you'll get to know some high level members, perhaps even people you see on the news."

"I said before that there are thousands of operators.  The truth is I don't know how many operators there are.  No one does.  As more of the bit stream is revealed, more members appear.  For all we know there could be millions of members.  There could be extra-terrestrials in the network."  He chuckles.  "Some have theorized that some of the noise we receive from outer space could be actually intelligence encrypted in the noise, like we do.  We just don't have the information or computing power yet to decode it."

The smile leaves old man's face.  "You have to keep this a secret.  If you reveal this to the wrong people, the results would be disastrous.  Those who reveal the code of the noise are purged from the network, sometimes not seen again."
Before Colin could ask his next question, the old man got up, handed him a card with characters written in bold black marker:

8^fGwq9(:lLDPu6$

"Congratulations.  This is your identity string.  Memorize it.  Guard it with your life."  He offers his right hand and they shake hands.

Colin follows the old man out the door, wanting to ask more questions. "Where will I would get the information on the algorithm, how do I build a transceiver?"  he frantically asks.

"You have to listen to the noise."  he said as he walked to his car, got in, and drove off.

Colin drove home in somewhat of a daze, not sure what to make of all this.  Was the old man crazy, or was all this real?  Colin went about my business for a few days, thinking about the old man and wondering what would be next.  "Would I get something in the mail?  Perhaps an email?  Would he contact me again?"

A few days later while watching the local news, a story came on about the death of a prominent researcher.  Colin was shocked to see a grainy photo of the old man he had met at the coffee shop, the photo perhaps from the 60s as he looked younger, more Colin's age today.  Walter was his name.  He had worked at Bell Labs in New Jersey as a physicist and had made many discoveries in communications which were patented in the 60s and 70s.  Walter was a quiet man but was known for his community work.  He fled Germany with his family as a young boy prior to World War II breaking out.  His father was a poor potato farmer who later helped the allies in cryptography after he devised a code based on the patterns of eyes on potatoes.  His wife had passed before him several years earlier.  Walter died alone at his home, of unknown causes and his death was under investigation.  Investigators doubted there was foul play, but there was a rather odd paper he was writing with codes on it found next to him.  He was survived by two children and some grandchildren residing in Florida.  Colin thought perhaps he could contact his family, but he knew he couldn't risk revealing what he had heard from the man if what he said was true.  Colin sat dumbfounded, wondering if he had lost his one connection to the secret network.

Later that night Colin once again turned on his receiver to 80 meters.  The little circuit sat idle with alligator clips connecting the rig audio to it.  His original goal of copying a RTTY signal now seemed pointless and insignificant in the grand scheme of things with the new knowledge he had.  He wanted to write more code and figure out the algorithm, all of it.  But Colin had no idea what next step to take, no clue what the algorithm was that would grant him access to a whole new world.  He pulled the card out of his wallet with his identity string and stared at the seemingly random 16 characters.  It contained uppercase, lowercase, numbers, symbols, just about everything.  Perhaps it was a base 64 character set?  What secrets were in it?  His thoughts were a disorganized jumble, and feeling a headache coming on he stopped himself from thinking further about it.

He was no longer interested in listening to Morse code signals or voice conversations.  That was merely just meaningless noise, a distraction from what he was really looking for.  Every little pop and crackle on the receiver caught his attention.  Was it just random atmospheric noise leftover from the Big Bang or some noisy electrical appliance, or was there intelligence in each seemingly random sounds?  For hours he scanned through the band, hoping to catch the right signal in hopes that his little contraption might pick up some clue that would lead him to the next step, perhaps someone else in the network since his contact had passed away.  BZZZZZT bursts from the receiver and the microcontroller terminal screen came alive:

 8^fGwq9(:lLDPu6$ : KEEP LISTENING TO THE NOISE AND AWAIT FURTHER INFO.

*/


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------

//---------------------------------------------------------------------



//---------------------------------------------------------------------

#ifdef FEATURE_PADDLE_ECHO
void service_paddle_echo()
{
  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering service_paddle_echo"));
  #endif

  static byte paddle_echo_space_sent = 1;
  byte character_to_send = 0;
  static byte no_space = 0;






  if ((paddle_echo_buffer) && (millis() > paddle_echo_buffer_decode_time)) {




    #ifdef FEATURE_DISPLAY
      if (lcd_paddle_echo){

            display_scroll_print_char(byte(convert_cw_number_to_ascii(paddle_echo_buffer)));




      }
    #endif //FEATURE_DISPLAY


    paddle_echo_buffer = 0;
    paddle_echo_buffer_decode_time = millis() + (float(600/configuration.wpm)*length_letterspace);
    paddle_echo_space_sent = 0;
  }

  if ((paddle_echo_buffer == 0) && (millis() > (paddle_echo_buffer_decode_time + (float(1200/configuration.wpm)*(configuration.length_wordspace-length_letterspace)))) && (!paddle_echo_space_sent)) {


    #ifdef FEATURE_DISPLAY
      if (lcd_paddle_echo){
        display_scroll_print_char(' ');
      }
    #endif //FEATURE_DISPLAY



    paddle_echo_space_sent = 1;
  }

}
#endif //FEATURE_PADDLE_ECHO

//---------------------------------------------------------------------
//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------

//---------------------------------------------------------------------

//---------------------------------------------------------------------

//---------------------------------------------------------------------

//---------------------------------------------------------------------

//---------------------------------------------------------------------

//---------------------------------------------------------------------

//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------

//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------




//---------------------------------------------------------------------

int convert_cw_number_to_ascii (long number_in)
{

  // number_in:  1 = dit, 2 = dah, 9 = a space

  switch (number_in) {
    case 12: return 65; break;         // A
    case 2111: return 66; break;
    case 2121: return 67; break;
    case 211: return 68; break;
    case 1: return 69; break;
    case 1121: return 70; break;
    case 221: return 71; break;
    case 1111: return 72; break;
    case 11: return 73; break;
    case 1222: return 74; break;
    case 212: return 75; break;
    case 1211: return 76; break;
    case 22: return 77; break;
    case 21: return 78; break;
    case 222: return 79; break;
    case 1221: return 80; break;
    case 2212: return 81; break;
    case 121: return 82; break;
    case 111: return 83; break;
    case 2: return 84; break;
    case 112: return 85; break;
    case 1112: return 86; break;
    case 122: return 87; break;
    case 2112: return 88; break;
    case 2122: return 89; break;
    case 2211: return 90; break;    // Z

    case 22222: return 48; break;    // 0
    case 12222: return 49; break;
    case 11222: return 50; break;
    case 11122: return 51; break;
    case 11112: return 52; break;
    case 11111: return 53; break;
    case 21111: return 54; break;
    case 22111: return 55; break;
    case 22211: return 56; break;
    case 22221: return 57; break;
    case 112211: return '?'; break;  // ?
    case 21121: return 47; break;   // /
      case 2111212: return '*'; break; // BK
    case 221122: return 44; break;  // ,
    case 121212: return '.'; break;
    case 122121: return '@'; break;
    case 222222: return 92; break;  // special hack; six dahs = \ (backslash)
    case 21112: return '='; break;  // BT
    //case 2222222: return '+'; break;
    case 9: return 32; break;       // special 9 = space

      case 12121: return '+'; break;


      case 21221: return 40; break; // (KN store as ascii ( ) //sp5iou //aaaaaaa



    default:
      return unknown_cw_character;
      break;

  }

}

//---------------------------------------------------------------------
#ifdef DEBUG_MEMORYCHECK
void memorycheck()
{
  void* HP = malloc(4);
  if (HP)
    free (HP);

  unsigned long free = (unsigned long)SP - (unsigned long)HP;

//  port_to_use->print(F("Heap="));
//  port_to_use->println((unsigned long)HP,HEX);
//  port_to_use->print(F("Stack="));
//  port_to_use->println((unsigned long)SP,HEX);
//  port_to_use->print(F("Free Memory = "));
//  port_to_use->print((unsigned long)free,HEX);
//  port_to_use->print(F("  "));
  if (free > 2048) {
    free = 0;
  }
  if (primary_serial_port_mode == SERIAL_CLI) {
    port_to_use->print((unsigned long)free,DEC);
    port_to_use->println(F(" bytes free"));
  }
}
#endif

//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------



//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------
void check_button0()
{
  #ifdef FEATURE_COMMAND_BUTTONS
    if (analogbuttonread(0)) {button0_buffer = 1;}
  #endif
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------

//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------


//---------------------------------------------------------------------

void initialize_pins() {


  pinMode (paddle_left, INPUT);
  digitalWrite (paddle_left, HIGH);
  pinMode (paddle_right, INPUT);
  digitalWrite (paddle_right, HIGH);


  if (tx_key_line_1) {
    pinMode (tx_key_line_1, OUTPUT);
    digitalWrite (tx_key_line_1, LOW);
  }
  if (tx_key_line_2) {
    pinMode (tx_key_line_2, OUTPUT);
    digitalWrite (tx_key_line_2, LOW);
  }
  if (tx_key_line_3) {
    pinMode (tx_key_line_3, OUTPUT);
    digitalWrite (tx_key_line_3, LOW);
  }
  if (tx_key_line_4) {
    pinMode (tx_key_line_4, OUTPUT);
    digitalWrite (tx_key_line_4, LOW);
  }
  if (tx_key_line_5) {
    pinMode (tx_key_line_5, OUTPUT);
    digitalWrite (tx_key_line_5, LOW);
  }
  if (tx_key_line_6) {
    pinMode (tx_key_line_6, OUTPUT);
    digitalWrite (tx_key_line_6, LOW);
  }


  if (ptt_tx_1) {
    pinMode (ptt_tx_1, OUTPUT);
    digitalWrite (ptt_tx_1, LOW);
  }
  if (ptt_tx_2) {
    pinMode (ptt_tx_2, OUTPUT);
    digitalWrite (ptt_tx_2, LOW);
  }
  if (ptt_tx_3) {
    pinMode (ptt_tx_3, OUTPUT);
    digitalWrite (ptt_tx_3, LOW);
  }
  if (ptt_tx_4) {
    pinMode (ptt_tx_4, OUTPUT);
    digitalWrite (ptt_tx_4, LOW);
  }
  if (ptt_tx_5) {
    pinMode (ptt_tx_5, OUTPUT);
    digitalWrite (ptt_tx_5, LOW);
  }
  if (ptt_tx_6) {
    pinMode (ptt_tx_6, OUTPUT);
    digitalWrite (ptt_tx_6, LOW);
  }
  pinMode (sidetone_line, OUTPUT);
  digitalWrite (sidetone_line, LOW);

  if (tx_key_dit) {
    pinMode (tx_key_dit, OUTPUT);
    digitalWrite (tx_key_dit, tx_key_dit_and_dah_pins_inactive_state);
  }
  if (tx_key_dah) {
    pinMode (tx_key_dah, OUTPUT);
    digitalWrite (tx_key_dah, tx_key_dit_and_dah_pins_inactive_state);
  }


  #if defined(FEATURE_COMMAND_BUTTONS) && defined(command_mode_active_led)
    if(command_mode_active_led) {
      pinMode (command_mode_active_led, OUTPUT);
      digitalWrite (command_mode_active_led,LOW);
    }
  #endif //FEATURE_COMMAND_BUTTONS && command_mode_active_led




  #ifdef FEATURE_PTT_INTERLOCK
    pinMode(ptt_interlock,INPUT);
    if (ptt_interlock_active_state == HIGH){
      digitalWrite(ptt_interlock,LOW);
    } else {
      digitalWrite(ptt_interlock,HIGH);
    }
  #endif //FEATURE_PTT_INTERLOCK





}

//---------------------------------------------------------------------

void initialize_debug_startup(){
#ifdef DEBUG_STARTUP

  serial_status(debug_serial_port);
  #ifndef OPTION_DO_NOT_SAY_HI
  debug_serial_port->println(F("OPTION_DO_NOT_SAY_HI"));
  #endif
  #ifdef FEATURE_COMMAND_BUTTONS
  debug_serial_port->println(F("FEATURE_COMMAND_BUTTONS"));
  #endif
  #ifdef FEATURE_LCD_4BIT
  debug_serial_port->println(F("FEATURE_LCD_4BIT"));
  #endif
  debug_serial_port->println(F("setup: exiting, going into loop"));
#endif //DEBUG_STARTUP
}


//---------------------------------------------------------------------




//---------------------------------------------------------------------

void initialize_keyer_state(){

  key_state = 0;
  key_tx = 1;
  configuration.wpm = initial_speed_wpm;

  configuration.paddle_interruption_quiet_time_element_lengths = default_paddle_interruption_quiet_time_element_lengths;

  configuration.hz_sidetone = initial_sidetone_freq;
  configuration.memory_repeat_time = default_memory_repeat_time;
  configuration.cmos_super_keyer_iambic_b_timing_percent = default_cmos_super_keyer_iambic_b_timing_percent;

  configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
  configuration.length_wordspace = default_length_wordspace;
  configuration.weighting = default_weighting;


  switch_to_tx_silent(1);

}

//---------------------------------------------------------------------
void initialize_rotary_encoder(){

  #ifdef FEATURE_ROTARY_ENCODER
    pinMode(rotary_pin1, INPUT);
    pinMode(rotary_pin2, INPUT);
  #endif //FEATURE_ROTARY_ENCODER

}

//---------------------------------------------------------------------

void initialize_default_modes(){


  // setup default modes
  keyer_machine_mode = KEYER_NORMAL;
  configuration.paddle_mode = PADDLE_NORMAL;
  configuration.keyer_mode = IAMBIC_B;
  configuration.sidetone_mode = SIDETONE_ON;
  char_send_mode = CW;

  delay(250);  // wait a little bit for the caps to charge up on the paddle lines

}

//---------------------------------------------------------------------

void check_eeprom_for_initialization(){

  // do an eeprom reset to defaults if paddles are squeezed
  if (paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) {
    while (paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) {}
    write_settings_to_eeprom(1);
    beep_boop();
    beep_boop();
    beep_boop();
  }

  // read settings from eeprom and initialize eeprom if it has never been written to
  if (read_settings_from_eeprom()) {
    write_settings_to_eeprom(1);
    beep_boop();
    beep_boop();
    beep_boop();
  }
}

//---------------------------------------------------------------------

void check_for_debug_modes(){

  #ifdef DEBUG_CAPTURE_COM_PORT
    primary_serial_port->begin(primary_serial_port_baud_rate);
    debug_capture();
  #endif

  #ifdef DEBUG_HELL_TEST
    hell_test();
  #endif
}

//---------------------------------------------------------------------

void initialize_display(){

  #ifdef FEATURE_DISPLAY
      lcd.begin(LCD_COLUMNS, LCD_ROWS);





    lcd_center_print_timed("K3NG Keyer",0,4000);
  #endif //FEATURE_DISPLAY

  if (keyer_machine_mode != BEACON) {
    #ifndef OPTION_DO_NOT_SAY_HI
      // say HI
      // store current setting (compliments of DL2SBA - http://dl2sba.com/ )
      byte oldKey = key_tx;
      byte oldSideTone = configuration.sidetone_mode;
      key_tx = 0;
      configuration.sidetone_mode = SIDETONE_ON;

      //delay(201);
      #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("h",1,4000);
      #endif
      send_char('H',KEYER_NORMAL);
      #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("hi",1,4000);
      #endif
      send_char('I',KEYER_NORMAL);

      configuration.sidetone_mode = oldSideTone;
      key_tx = oldKey;
    #endif //OPTION_DO_NOT_SAY_HI

  }
}


//---------------------------------------------------------------------

int paddle_pin_read(int pin_to_read){


        return digitalRead(pin_to_read);

}
//---------------------------------------------------------------------


//---------------------------------------------------------------------
#ifdef FEATURE_PTT_INTERLOCK
void service_ptt_interlock(){

  static unsigned long last_ptt_interlock_check = 0;

  if ((millis() - last_ptt_interlock_check) > ptt_interlock_check_every_ms){
    if (digitalRead(ptt_interlock) == ptt_interlock_active_state){
      if (!ptt_interlock_active){
        ptt_interlock_active = 1;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("PTT Interlock",0,2000);
        #endif //FEATURE_DISPLAY
      }
    } else {
      if (ptt_interlock_active){
        ptt_interlock_active = 0;
      }
    }
    last_ptt_interlock_check = millis();
  }
}
#endif //FEATURE_PTT_INTERLOCK

//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------

