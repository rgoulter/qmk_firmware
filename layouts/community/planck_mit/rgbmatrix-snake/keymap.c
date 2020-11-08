#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

#include "raw_hid.h"

#include "snake.h"

extern keymap_config_t keymap_config;

#define _SNAKE 0
#define _QWERTY 1

enum custom_keycodes {
  QUARTER = SAFE_RANGE,
  HALF,
  SNAKE,
  DIRRGHT,
  DIRUP,
  DIRLEFT,
  DIRDOWN
};

#define LCTLESC LCTL_T(KC_ESC)
#define RCTLENT RCTL_T(KC_ENT)

char quarter_count = 0;
char half_count = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_SNAKE] = LAYOUT_planck_mit( \
  QUARTER, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QUARTER, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HALF,    XXXXXXX, XXXXXXX, HALF,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DIRUP,   XXXXXXX, \
  QUARTER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, DIRLEFT, DIRDOWN, DIRRGHT \
),

[_QWERTY] = LAYOUT_planck_mit( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LCTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTLENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_RSFT, \
  RESET,   KC_LCTL, KC_LALT, KC_LGUI, SNAKE,        KC_SPC,      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DIRUP:
      snake_status.direction = DIRECTION_UP;
      return false;
      break;
    case DIRDOWN:
      snake_status.direction = DIRECTION_DOWN;
      return false;
      break;
    case DIRLEFT:
      snake_status.direction = DIRECTION_LEFT;
      return false;
      break;
    case DIRRGHT:
      snake_status.direction = DIRECTION_RIGHT;

      // corner
      if (record->event.pressed) {
        quarter_count += 1;
      } else {
        quarter_count -= 1;
      }
      if (quarter_count == 4) {
        register_code(KC_X);
        unregister_code(KC_X);
      }
      return false;
      break;
    case QUARTER:
      // corner
      if (record->event.pressed) {
        quarter_count += 1;
      } else {
        quarter_count -= 1;
      }
      if (quarter_count == 4) {
        reset_keyboard();
      }
      return false;
      break;
    case HALF:
      if (record->event.pressed) {
        half_count += 1;
      } else {
        half_count -= 1;
      }
      if (half_count == 2) {
        layer_move(_QWERTY);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      }
      return false;
      break;
    case SNAKE:
      if (record->event.pressed) {
        half_count += 1;
      } else {
        half_count -= 1;
      }
      if (half_count == 2) {
        layer_move(_SNAKE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_MULTISPLASH + 1);
      }
      return false;
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // rgb_matrix_mode_noeeprom(RGB_MATRIX_SNAKE);
  eeconfig_init();
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_MULTISPLASH + 1);

  snake_init();
}
