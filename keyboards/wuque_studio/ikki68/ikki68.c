#include "ikki68.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.


void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  setPinOutput(C6);
  
  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(C6);
  } else {
    writePinHigh(C6);
  }
  led_set_user(usb_led);
}

