/* Pins - you must review these and configure ! */
#ifndef keyer_pin_settings_h
#define keyer_pin_settings_h

#define paddle_left 28  //5
#define paddle_right 26 //2
#define tx_key_line_1 34 //11       // (high = key down/tx on)
#define tx_key_line_2 35  //12
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
#define sidetone_line 4         // connect a speaker for sidetone
#define potentiometer 0        // Speed potentiometer (0 to 5 V) Use pot from 1k to 10k
#define ptt_tx_1 41 //41              // PTT ("push to talk") lines
#define ptt_tx_2 22 //22             //   Can be used for keying fox transmitter, T/R switch, or keying slow boatanchors
#define ptt_tx_3 0              //   These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define tx_key_dit 0            // if defined, goes active for dit (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state
#define tx_key_dah 0            // if defined, goes active for dah (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state

#ifdef FEATURE_COMMAND_BUTTONS
  #define analog_buttons_pin A1
  #define command_mode_active_led 0
#endif //FEATURE_COMMAND_BUTTONS

//lcd pins
#ifdef FEATURE_LCD_4BIT
//#define lcd_enable 3    //  PCB_REV_3_141
  #define lcd_enable 37   //  PCB_REV_3_1415
  #define lcd_rs A2
  #define lcd_d4 6
  #define lcd_d5 7
  #define lcd_d6 8
  #define lcd_d7 9
#endif //FEATURE_LCD_4BIT


//ps2 keyboard pins

// rotary encoder pins and options - rotary encoder code from Jim Balls M0CKE
#ifdef FEATURE_ROTARY_ENCODER
  #define OPTION_ENCODER_HALF_STEP_MODE     // Half-step mode?
  #define rotary_pin1 24                      // CW Encoder Pin
  #define rotary_pin2 18  //23                    // CCW Encoder Pin
  #define OPTION_ENCODER_ENABLE_PULLUPS     // define to enable weak pullups.
#endif //FEATURE_ROTARY_ENCODER



#ifdef FEATURE_PTT_INTERLOCK
  #define ptt_interlock 2 //21  // this pin disables PTT and TX KEY
#endif //FEATURE_PTT_INTERLOCK







#else

  #error "Multiple pin_settings.h files included somehow..."

#endif //keyer_pin_settings_h
