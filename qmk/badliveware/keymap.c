#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_PSCR,                                        US_MINS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           US_EQL,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_QUOTE,                                       KC_BSLS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           US_ARNG,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           US_COMM,                                        KC_SLASH,       KC_H,           KC_J,           KC_K,           KC_L,           US_ODIA,        US_ADIA,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           US_COMM,        US_DOT,         US_SCLN,        KC_RSFT,
    KC_LCTL,        KC_LGUI,        KC_LALT,        KC_LEFT,        KC_RIGHT,                KC_APPLICATION,                                        LSFT(KC_APPLICATION),           KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        MO(1),
                                                                    KC_SPACE,       KC_DELETE,      KC_LGUI,                                        KC_LALT,        KC_BSPC,        KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RM_NEXT,                                                                                                        RM_TOGG,        KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
    RM_VALD,        RM_VALU,        KC_TRANSPARENT,                 RGB_SLD,        RM_HUED,        RM_HUEU
  ),
  [2] = LAYOUT_moonlander(
    AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    MU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, MS_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, MS_LEFT,        MS_DOWN,        MS_RGHT,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MS_BTN1,        MS_BTN2,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv(0, 255, 255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv(86, 255, 128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv(172, 255, 255);
      }
      return false;
  }
  return true;
}
