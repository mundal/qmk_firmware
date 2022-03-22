#include QMK_KEYBOARD_H

// #define FN1_SPC     LT(1, KC_SPC)
#define FN1_K     LT(1, KC_K)
// #define FN2_BSPC    LT(2, KC_BSPC)
#define FN2_V    LT(2, KC_V)
// #define FN3_C       LT(3, KC_C)
#define FN5_C       LT(5, KC_C)
// #define FN4_V       LT(4, KC_V)
#define FN4_D       LT(4, KC_D)
// #define FN5_B       LT(5, KC_B)
#define FN3_H       LT(3, KC_H)
#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
// #define ALT_N       ALGR_T(KC_N)
#define ALT_BSPC       ALGR_T(KC_BSPC)
// #define CTL_M       RCTL_T(KC_M)
#define CTL_SPC       RCTL_T(KC_SPC)
#define SFT_ENT     RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [0] = LAYOUT_ortho_3x10(
  //   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,
  //   CTL_Z,   ALT_X,   FN3_C,   FN4_V,   FN2_BSPC,FN1_SPC, FN5_B,   ALT_N,   CTL_M,   SFT_ENT
  // ),

  [0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_ESC,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    CTL_Z,   ALT_X,   FN5_C,   FN4_D,   FN2_V,   FN1_K,   FN3_H, ALT_BSPC,  CTL_SPC, SFT_ENT
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [3] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TAB,  _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [4] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TAB,  _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_COLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [5] = LAYOUT_ortho_3x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______
  )

};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
