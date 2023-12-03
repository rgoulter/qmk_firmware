#include QMK_KEYBOARD_H
#include "action_layer.h"

#include "raw_hid.h"

#include "users/rgoulter/rgoulter.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _DVORAK,
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _CHILDPROOF,
    _CHECK,
    _ADJUST,
    _FN,
};

#define QWERTY DF(_QWERTY)
#define GAMING DF(_GAMING)
#define DVORAK DF(_DVORAK)
#define CHILDPROOF DF(_CHILDPROOF)
#define CHECK DF(_CHECK)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FN MO(_FN)

#define LAYOUT_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)

#ifdef CORNER_RESET_ENABLE
keypos_t boot_keypositions[4] = {
    {.col = 1, .row = 0},
    {.col = 1, .row = MATRIX_ROWS - 2},
    {.col = MATRIX_COLS - 2, .row = 0},
    {.col = MATRIX_COLS - 2, .row = MATRIX_ROWS - 2},
};
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Dvorak, with Home-Row Mods
//
// - LHS thumb keys: Tab, Esc, Spc
//     I don't use Tab frequently;
//     for code, I rely on editorconfig & auto-formatting.
// - RHS thumb keys: Bspc, Enter
//
// Pinky-outer-column
[_DVORAK] = LAYOUT_wrapper(
    KC_TAB,    ___SEG5_DVORAK_LHS_1___,                       ___SEG5_DVORAK_RHS_1___,                        KC_BSPC,
    _______,   ___SEG5_DVORAK_LHS_2___,                       ___SEG5_DVORAK_RHS_2___,                        _______,
    _______,   ___SEG5_DVORAK_LHS_3___,                       ___SEG5_DVORAK_RHS_3___,                        KC_ENT,
    FN,        XXXXXXX, XXXXXXX, KC_TAB, LWR_ESC,   KC_SPC,    RSE_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

// Same QWERTY as default of X-2
//
// Pinky-outer-column
[_QWERTY] = LAYOUT_wrapper(
    KC_TAB,    ___SEG5_QWERTY_LHS_SIMPLE_1___,              ___SEG5_QWERTY_RHS_SIMPLE_1___,              KC_BSPC,
    KC_ESC,    ___SEG5_QWERTY_LHS_SIMPLE_2___,              ___SEG5_QWERTY_RHS_SIMPLE_2___,              KC_QUOT,
    KC_LSFT,   ___SEG5_QWERTY_LHS_SIMPLE_3___,              ___SEG5_QWERTY_RHS_SIMPLE_3___,              KC_ENT,
    FN,        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,    RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

// GAMING: No home row mods, but QWERTY.
//
// (copied from ortho_5x15 layout.)
//
// Obviously won't work for games which need number row.
//
// Bottom row half for gaming,
//  half for typing (e.g. console commands in games).
//
// Pinky-outer-column
[_GAMING] = LAYOUT_wrapper( \
    KC_TAB,    ___SEG5_QWERTY_LHS_SIMPLE_1___,               ___SEG5_QWERTY_RHS_SIMPLE_1___,   KC_BSPC,
    KC_CAPS,   ___SEG5_QWERTY_LHS_SIMPLE_2___,               ___SEG5_QWERTY_RHS_SIMPLE_2___,   KC_QUOT,
    KC_LSFT,   ___SEG5_QWERTY_LHS_SIMPLE_3___,               ___SEG5_QWERTY_RHS_SIMPLE_3___,   KC_ENT,
    KC_LCTL,   KC_LGUI, KC_LALT, KC_TAB, KC_ESC,   KC_SPC,    KC_ENT, ___SEG4_NAV_LDUR___
),

// CHILDPROOF
//
// Because mashing the keys of a mechanical keyboard can be fun,
// especially for key-reactive RGB matrix effects.
//
// Pinky-outer-column
[_CHILDPROOF] = LAYOUT_wrapper(
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
    LOWER,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RAISE
),

// CHECK
//
// Because mashing the keys of a mechanical keyboard can be fun,
// especially for key-reactive RGB matrix effects.
//
// Pinky-outer-column
[_CHECK] = LAYOUT_wrapper(
    KC_1, ___SEG5_QWERTY_LHS_SIMPLE_1___,              ___SEG5_QWERTY_RHS_SIMPLE_1___, KC_X,
    KC_2, ___SEG5_QWERTY_LHS_SIMPLE_2___,              ___SEG5_QWERTY_RHS_SIMPLE_2___, KC_Y,
    KC_3, ___SEG5_QWERTY_LHS_SIMPLE_3___,              ___SEG5_QWERTY_RHS_SIMPLE_3___, KC_Z,
    KC_4, KC_1, KC_2, KC_3, KC_4,            KC_5,     KC_7, KC_8, KC_9, KC_0, KC_W
),

// LOWER
//
// - Number row
// - Tild ('~'), LHS, upper, outer pinky column
// - Ins, LHS, home row, outer pinky column
// - Symbols:
//   - PAIR: '_' '+'
//   - PAIR: '{' '}'
//   - PAIR (outer pinky col): '|'
//          (outer pinky col): '?'
// - Navigation keys (cursor keys, Home/etc.)
// - Function keys, across home row and lower row
//
// Pinky-outer-column
[_LOWER] = LAYOUT_wrapper( \
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   KC_PIPE,
    KC_INS,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,   KC_QUES,
    _______,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  _______, KC_HOME, KC_PGUP, KC_PGDN,   KC_END,
    _______,   _______, _______, _______, XXXXXXX,      _______,    _______, KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT
),

// RAISE
//
// - Number row
// - Grv ('`'), LHS, upper, outer pinky column
// - DEL, LHS, home row, outer pinky column
// - Symbols:
//   - PAIR: '-' '='
//   - PAIR: '[' ']'
//   - PAIR (outer pinky col): '\'
//          (outer pinky col): '/'
// - Media Keys
// - Clipboard keys
//
// Pinky-outer-column
[_RAISE] = LAYOUT_wrapper(
    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSLS,
    KC_DEL,    _______, _______, _______, _______, _______,    _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,   KC_SLSH,
    _______,   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,   _______,
    _______,   _______, _______, _______, _______,       _______,       XXXXXXX, KC_MNXT, KC_VOLD, KC_VOLU,   KC_MPLY
),

// ADJUST
//
// - RESET, under LHS, upper, pinky
// - CAPS, LHS, middle, outer pinky column.
// - Runtime OS selection
//     For OS-specific shortcuts, like "go desktop left"
// - PrintScr/Scroll lock/Pause
// - Default Layer Selection (QWERTY, Gaming, Dvorak, Childproof)
// - Mouse (movement, buttons, scrolling).
//
// Pinky-outer-column
[_ADJUST] = LAYOUT_wrapper(
    _______,   QK_BOOT, _______, _______, _______, _______,    _______, ___SEG3_SYS___,            _______,   _______,
    KC_CAPS,   DM_REC2, DM_REC1, DM_PLY2, DM_PLY1, DM_RSTP,    _______, QWERTY,  GAMING,  DVORAK,  CHILDPROOF, CHECK,
    _______,   _______, OSWIN,   OSMACOS, OSLINUX, _______,    _______, _______, KC_BTN1, KC_BTN2, KC_WH_D,   KC_WH_U,
    _______,   _______, _______, _______, XXXXXXX,       _______,       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U,   KC_MS_R
),

// FN
//
// - Numpad, actual numpad keys, LHO accessible.
// - RGB control
//
// Same as default layer
[_FN] = LAYOUT_wrapper(
    KC_NUM,    KC_P7,   KC_P8,   KC_P9,   _______, _______,    _______, _______, _______, RGB_VAD, RGB_VAI,   _______,
    _______,   KC_P4,   KC_P5,   KC_P6,   _______, _______,    _______, _______, _______, RGB_SAD, RGB_SAI,   _______,
    _______,   KC_P1,   KC_P2,   KC_P3,   _______, _______,    _______, _______, RGB_TOG, RGB_HUD, RGB_HUI,   RGB_MOD,
    XXXXXXX,   _______, _______, _______, _______,       _______,       _______, _______, _______, _______,   _______
)

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
