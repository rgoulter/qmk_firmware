#include QMK_KEYBOARD_H
#include "action_layer.h"

#include "raw_hid.h"

#include "rgoulter.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _LOWER2,
  _RAISE,
  _RAISE2,
  _CHILDPROOF,
  _NUMPAD,
  _ADJUST,
};

enum custom_keycodes {
  QUARTER = SAFE_RANGE,
  OSLINUX,
  OSMACOS,
  OSWIN,
};

enum host_os {
  _LINUX,
  _MACOS,
  _WINDOWS,
};

char quarter_count = 0;

#define QWERTY     DF(_QWERTY)
#define DVORAK     DF(_DVORAK)
#define CHILDPROOF DF(_CHILDPROOF)
#define LOWER   MO(_LOWER)
#define LOWER2   MO(_LOWER2)
#define RAISE   MO(_RAISE)
#define RAISE2   MO(_RAISE2)
#define NUMPAD  MO(_NUMPAD)
#define ADJUST  MO(_ADJUST)


#define LAYOUT_wrapper(...)            LAYOUT_planck_mit(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// XXX: find place for the PrtScr, ScrlLck, Pause keys;
// XXX: aim for one-handed numpad?
// XXX: aim for one-handed cursor keys?

[_DVORAK] = LAYOUT_wrapper( \
  ___SEG5_DVORAK_LHS_1___, KC_TAB,     KC_BSPC, ___SEG5_DVORAK_RHS_1___,    \
  ___SEG5_DVORAK_LHS_2___, LCTLESC,    RCTLENT, ___SEG5_DVORAK_RHS_2___, \
  ___SEG5_DVORAK_LHS_3___, _______,    _______, ___SEG5_DVORAK_RHS_3___,      \
                                           ___BASE_BOTTOM_ROW___ \
),

[_QWERTY] = LAYOUT_wrapper( \
  ___SEG5_QWERTY_LHS_1___, KC_TAB,     KC_BSPC, ___SEG5_QWERTY_RHS_1___,    \
  ___SEG5_QWERTY_LHS_2___, LCTLESC,    RCTLENT, ___SEG5_QWERTY_RHS_2___, \
  ___SEG5_QWERTY_LHS_3___, _______,    _______, ___SEG5_QWERTY_RHS_3___,      \
                                           ___BASE_BOTTOM_ROW___ \
),

// XXX: Let's ... move the function keys elsewhere?
// XXX: Let's ... move the cursor keys so they're on a navigation layer with Home/PgUp/PgDown/End, arrow keys etc.
[_LOWER] = LAYOUT_planck_mit( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_GRV,  KC_PIPE, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_INS,  KC_QUES, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_LOWER2] = LAYOUT_planck_mit( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______ \
),

[_RAISE] = LAYOUT_planck_mit( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TILD, KC_BSLS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  _______, _______, _______, _______, _______, KC_DEL,  KC_SLSH, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  _______, KC_CUT,  KC_COPY, KC_PSTE, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,    _______,       _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_RAISE2] = LAYOUT_planck_mit( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______ \
),

[_CHILDPROOF] = LAYOUT_planck_mit( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  LOWER,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RAISE \
),

[_NUMPAD] = LAYOUT_planck_mit( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_0,    KC_0,    KC_DOT,  _______  \
),

[_ADJUST] =  LAYOUT_planck_mit( \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______,
  _______, _______, _______, _______, _______, _______, _______, QWERTY,  XXXXXXX, DVORAK,  CHILDPROOF, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_WH_D, KC_WH_U, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
  }
  return true;
}


// RAW_EPSIZE is 32
void raw_hid_receive(uint8_t *data, uint8_t length) {
    raw_hid_send(data, length);
}

enum combo_events {
  DESKTOP_GO_LEFT,
  DESKTOP_GO_RIGHT,
  LEAD,
};

// can't be keys which have tap-hold
const uint16_t PROGMEM dsk_lower_left_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM dsk_lower_left_combo[] = {LCTLT_E, LSFTT_U, COMBO_END};
const uint16_t PROGMEM dsk_lower_right_combo[] = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM dsk_lower_lead_combo[] = {KC_SCLN, KC_Q, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DESKTOP_GO_LEFT] = COMBO_ACTION(dsk_lower_left_combo),
  [DESKTOP_GO_RIGHT] = COMBO_ACTION(dsk_lower_right_combo),
  [LEAD] = COMBO_ACTION(dsk_lower_lead_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case DESKTOP_GO_LEFT:
      if (pressed) {
        tap_code16(CODE16_LINUX_DESKTOP_LEFT);
      }
      break;
    case DESKTOP_GO_RIGHT:
      if (pressed) {
        tap_code16(CODE16_LINUX_DESKTOP_RIGHT);
      }
      break;
    case LEAD:
      if (pressed) {
        qk_leader_start();
      }
      break;
  }
}
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("kubectl");
    }

    SEQ_ONE_KEY(KC_G) {
      SEND_STRING("kubectl get pods --namespace production");
    }

    SEQ_ONE_KEY(KC_N) {
      SEND_STRING("--namespace production");
    }
  }
}
