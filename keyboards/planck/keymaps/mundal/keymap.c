#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_br_abnt2.h"
#include "keymap_contributions.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NORWAY,
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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
      KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_PIPE,
      KC_ESCAPE,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,
      KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_MINS,
      KC_MUTE,KC_LCTRL,KC_LALT,KC_LGUI,LT(LOWER,KC_BSPACE),KC_SPACE,KC_NO,LT(RAISE,KC_ENTER),KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT
    ),

  [_LOWER] = LAYOUT_planck_grid(
      KC_TILD,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,_______,_______,_______,_______,_______,KC_BSLS,
      KC_DELETE,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRV,KC_PLUS,KC_MINS,KC_SLSH,KC_ASTR,KC_PERC,KC_QUOTE,
      _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_SCLN,KC_AMPR,KC_EQL,KC_HOME,KC_END,_______,_______,
      _______,_______,_______,_______,_______,_______,KC_NO,_______,_______,_______,_______,_______
    ),

  [_RAISE] = LAYOUT_planck_grid(
      KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,XP(NO_aa, NO_AA),
      KC_DELETE,_______,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLU,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,XP(NO_oe, NO_OE),XP(NO_ae, NO_AE),
      _______,_______,KC_BTN1,KC_BTN2,KC_MUTE,KC_VOLD,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_PGDOWN,KC_PGUP,
      _______,_______,_______,_______,_______,_______,KC_NO,_______,_______,_______,_______,_______
    ),

  [_ADJUST] = LAYOUT_planck_grid(
      _______,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,_______,
      KC_DELETE,_______,AU_ON,AU_OFF,AU_TOG,_______,_______,_______,_______,KC_F11,KC_F12,RESET,
      _______,_______,MU_ON,MU_OFF,MU_TOG,_______,_______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,KC_NO,_______,_______,_______,_______,_______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
}
return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

