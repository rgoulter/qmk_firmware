/* Copyright 2020 João Pedro Pio
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

enum layers {
  _COLEMAK_DMH,
  _SYMBOLS,
  _PROGRAMMING,
  _SYSTEM,
  _GAMER,
  _GAMER_NUMBERS,
  _RGB
};

enum custom_keycodes {
  TWITCHURL1 = SAFE_RANGE,
  TWITCHURL2,
  TWITCHURL3,
  TWITCHURL4,
  NEW_SAFE_RANGE
};

// Left-hand home row mods - Base Layer
#define GUI_A   LGUI_T(KC_A)
#define ALT_R   LALT_T(KC_R)
#define CTRL_S  LCTL_T(KC_S)
#define SHIFT_T LSFT_T(KC_T)

// Right-hand home row mods  - Base Layer
#define SHIFT_N RSFT_T(KC_N)
#define CTRL_E  RCTL_T(KC_E)
#define ALT_I   LALT_T(KC_I)
#define GUI_O   RGUI_T(KC_O)

// Left-hand home row mods - Layer 1
#define LGUI_1 LGUI_T(KC_1)
#define LALT_2 LALT_T(KC_2)
#define LCTL_3 LCTL_T(KC_3)
#define LSFT_4 LSFT_T(KC_4)

// Right-hand home row mods - Layer 1
#define LSFT_7 LSFT_T(KC_7)
#define LCTL_8 LCTL_T(KC_8)
#define LALT_9 LALT_T(KC_9)
#define LGUI_0 LGUI_T(KC_0)

// Left-hand home row mods - Layer 2
#define GUI_F5   LGUI_T(KC_F5)
#define ALT_F6   LALT_T(KC_F6)
#define CTRL_F7  LCTL_T(KC_F7)
#define SHIFT_F8 LSFT_T(KC_F8)

// Right-hand home row mods - Layer 2
#define S_LBRC RSFT_T(KC_LBRC)
#define C_RBRC RCTL_T(KC_RBRC)
#define A_GRV  LALT_T(KC_GRV)
#define G_QUOT RGUI_T(KC_QUOT)

// Layers
#define LT2_SPC LT(2,KC_SPC)
#define LT1_ENT LT(1,KC_ENT)
#define RGBLYR  MO(_RGB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak-DHm (Layers 1 and 2 has mod taps)
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃    Q    ┃    W    ┃    F    ┃    P    ┃    B    ┃         ┃         ┃    J    ┃    L    ┃    U    ┃    Y    ┃    ;    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃  GUI/A  ┃  ALT/R  ┃  CTL/S  ┃  SFT/T  ┃    G    ┃         ┃         ┃    M    ┃  SFT/N  ┃  CTL/E  ┃  ALT/I  ┃  GUI/O  ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃    Z    ┃    X    ┃    C    ┃    D    ┃    V    ┃         ┃         ┃    K    ┃    H    ┃    ,    ┃    .    ┃    /    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃RGB_LAYER┃         ┃   TAB   ┃   ESC   ┃LT2/SPACE┃                   ┃LT1/ENTER┃   BSCP  ┃   DEL   ┃         ┃  GAMER  ┃
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

	[_COLEMAK_DMH] = LAYOUT_ortho_4x12_1x2uC(
        KC_Q,    KC_W,    KC_F,   KC_P,    KC_B,    XXXXXXX,       XXXXXXX,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        GUI_A,   ALT_R,   CTRL_S, SHIFT_T, KC_G,    LCTL(KC_DOWN), LCTL(KC_UP),    KC_M,    SHIFT_N, CTRL_E,  ALT_I,   GUI_O,
        KC_Z,    KC_X,    KC_C,   KC_D,    KC_V,    LCTL(KC_LEFT), LCTL(KC_RIGHT), KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
        RGBLYR , XXXXXXX, KC_TAB, KC_ESC,  LT2_SPC,           XXXXXXX,             LT1_ENT, KC_BSPC, KC_DEL,  XXXXXXX, TO(_GAMER)
    ),

    /* Symbols (This layer has mode taps. This draw don't show it for clarity)
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃    !    ┃    @    ┃    #    ┃    $    ┃    %    ┃         ┃         ┃    ^    ┃    &    ┃    *    ┃    (    ┃    )    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃         ┃         ┃    6    ┃    7    ┃    8    ┃    9    ┃    0    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃    ←    ┃    ↓    ┃    ↑	  ┃    →    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃  MO(3)  ┃                   ┃         ┃         ┃         ┃         ┃         ┃
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

    [_SYMBOLS] = LAYOUT_ortho_4x12_1x2uC(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        LGUI_1,  LALT_2,  LCTL_3,  LSFT_4,  KC_5,    _______, _______, KC_6,    LSFT_7,  LCTL_8,  LALT_9,  LGUI_0,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        _______, _______, _______, _______, MO(_SYSTEM),  _______,     _______, _______, _______, _______, _______
    ),

    /* Programming (This layer has mode taps. This draw don't show it for clarity)
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃   F1    ┃   F2    ┃   F3    ┃   F4    ┃  PRTSCR ┃         ┃         ┃    "    ┃    {    ┃    }    ┃    \    ┃    |    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃   F5    ┃   F6    ┃   F7    ┃   F8    ┃         ┃         ┃         ┃    ~    ┃    [    ┃    ]    ┃    `    ┃    '    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃   F9    ┃   F10   ┃   F11   ┃   F12   ┃         ┃         ┃         ┃         ┃    -    ┃    _    ┃    =    ┃    +    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃                   ┃  MO(3)  ┃         ┃         ┃         ┃         ┃
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

    [_PROGRAMMING] = LAYOUT_ortho_4x12_1x2uC(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_PSCR, _______, _______, KC_DQUO, KC_LCBR, KC_RCBR, KC_BSLS, KC_PIPE,
        GUI_F5,  ALT_F6,  CTRL_F7, SHIFT_F8, _______, _______, _______, KC_TILD, S_LBRC,  C_RBRC,  A_GRV,   G_QUOT,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______, _______, _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS,
        _______, _______, _______, _______,  _______,      _______,     MO(_SYSTEM),   _______, _______, _______, _______
    ),

    /* System
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃TWITCHURL┃TWITCHURL┃TWITCHURL┃TWITCHURL┃         ┃         ┃         ┃  RESET  ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃                   ┃         ┃         ┃         ┃         ┃         ┃
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

	[_SYSTEM] = LAYOUT_ortho_4x12_1x2uC(
        TWITCHURL1, TWITCHURL2, TWITCHURL3, TWITCHURL4, _______, _______, _______, QK_BOOT, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
    ),


    /* Gamer
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃   TAB   ┃    Q    ┃    W    ┃    E    ┃    R    ┃    T    ┃    Y    ┃    U    ┃    I    ┃    O    ┃    P    ┃  BKSP   ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃   ESC   ┃    A    ┃    S    ┃    D    ┃    F    ┃    G    ┃    H    ┃    J    ┃    K    ┃    L    ┃    ;    ┃    '    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃  SHIFT  ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┃    N    ┃    M    ┃    ,    ┃    .    ┃    /    ┃  ENTER  ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃   CTRL  ┃         ┃         ┃  ALT    ┃   MO(5) ┃       SPACE       ┃         ┃         ┃         ┃         ┃ COLEMAK ┃
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

	[_GAMER] = LAYOUT_ortho_4x12_1x2uC(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,               KC_T, KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,               KC_G, KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,               KC_B, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, MO(_GAMER_NUMBERS),   KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_COLEMAK_DMH)
    ),

    /* Gamer Numbers
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃         ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃         ┃         ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃                   ┃         ┃         ┃         ┃         ┃         ┃
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

	[_GAMER_NUMBERS] = LAYOUT_ortho_4x12_1x2uC(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,       _______,    _______, _______, _______, _______, _______
    ),

    /* RGB
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃RGBTOGGLE┃RGBMODE- ┃RGBMODE+ ┃ COLOUR -┃ COLOUR +┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃RGBBRGHT-┃RGBBRGHT+┃ RGBSAT- ┃ RGBSAT+ ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃                   ┃         ┃         ┃         ┃         ┃         ┃
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

    [_RGB] = LAYOUT_ortho_4x12_1x2uC(
		_______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI,
		_______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD,  RGB_VAI, RGB_SAD, RGB_SAI,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
		_______, _______, _______, _______, _______,      _______,     _______, _______,  _______, _______, _______
    )
};

static bool is_w_pressed = false;
static uint8_t last_layer = _COLEMAK_DMH;
static bool crazy_layer_shift = false;
static uint32_t current_rgb_mode = 1;
static uint32_t gamer_rgb_mode = 22;
static bool current_rgb_enabled = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_2) {
        if (crazy_layer_shift && !record->event.pressed) {
            unregister_code(KC_W);
            crazy_layer_shift = false;
        }
        is_w_pressed = record->event.pressed;
    }
    if (record->event.pressed) {
        switch(keycode) {
            case TWITCHURL1: SEND_STRING("https://www.twitch.tv/sacyedade segue a live ai, seus lindos"); return false;
            case TWITCHURL2: SEND_STRING("https://www.twitch.tv/sacyedade sigam a live ai, vlw guys"); return false;
            case TWITCHURL3: SEND_STRING("https://www.twitch.tv/sacyedade quem puder ajudar aí, fico muito agradecido :D"); return false;
            case TWITCHURL4: SEND_STRING("https://www.twitch.tv/sacyedade pra quem puder seguir, muito obrigado :D"); return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    uint32_t current = rgblight_get_mode();
    if (current != gamer_rgb_mode) {
        current_rgb_mode = current;
        current_rgb_enabled = rgblight_is_enabled();
    }
    switch (layer) {
        case _GAMER:
        case _GAMER_NUMBERS:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(gamer_rgb_mode);
            if (is_w_pressed) {
                unregister_code(KC_2);
                register_code(KC_W);
                crazy_layer_shift = true;
            }
            break;
        default:
            rgblight_mode_noeeprom(current_rgb_mode);
            if (current_rgb_enabled) {
                rgblight_enable();
            } else {
                rgblight_disable();
            }
    }
    last_layer = layer;
    return state;
}
