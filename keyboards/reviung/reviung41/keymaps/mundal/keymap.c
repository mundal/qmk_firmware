/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum unicode_names {
  NO_ae,
  NO_oe,
  NO_aa,
  NO_AE,
  NO_OE,
  NO_AA
};

const uint32_t PROGMEM unicode_map[] = {
  [NO_ae] = 0xE6,
  [NO_oe] = 0xF8,
  [NO_aa] = 0xE5,
  [NO_AE] = 0xC6,
  [NO_OE] = 0xD8,
  [NO_AA] = 0xC5
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_PIPE,
    KC_ESCAPE,KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_MINS,
                                KC_RGUI, MT(MOD_LALT, KC_BSPC), LCTL_T(KC_SPC), LT(RAISE, KC_ENTER), LOWER
  ),
  
  [_LOWER] = LAYOUT_reviung41(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  _______,  KC_BSLS,
    KC_DEL,   KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,   KC_GRV,             KC_PLUS,  KC_MINS,  KC_SLSH,  KC_ASTR,  KC_PERC,  KC_QUOTE,
    _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,   KC_SCLN,            KC_AMPR,  KC_EQL,   _______,  _______,  KC_PGUP,  KC_PGDN,
                                      _______,   _______,  UNICODE_MODE_FORWARD,   _______,  _______
  ),
  
  [_RAISE] = LAYOUT_reviung41(
    KC_GRAVE, KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XP(NO_aa, NO_AA),
    KC_DELETE,_______,  KC_MPRV,  KC_MPLY,  KC_MNXT,   KC_VOLU,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT, XP(NO_oe, NO_OE),XP(NO_ae, NO_AE),
    _______,  _______,  KC_LGUI,  KC_RALT,  KC_MUTE,   KC_VOLD,            _______,  _______,  _______,  _______,  KC_HOME,  KC_END,
                                            _______,   _______,  KC_TAB,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    KC_F1,     KC_F2,   KC_F3,    KC_F4,    KC_F5,     KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, _______,   _______,            _______,  _______,  _______,  _______,  _______,  RESET,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, _______,   RGB_TOG,            RESET,    _______,  _______,  _______,  _______,  _______,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

