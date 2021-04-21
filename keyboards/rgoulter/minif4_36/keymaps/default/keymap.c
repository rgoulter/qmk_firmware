/* Copyright 2021 Richard Goulter
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

#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    // [_BASE] = LAYOUT(
    //                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //                                    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX                    
    // )
    [_BASE] = LAYOUT(
                     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
                     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
                     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                                       KC_1,    KC_2,    KC_3
    )
};

void board_init(void) {
  // B9 is configured as I2C1_SDA in the board file; that function must be
  // disabled before using B7 as I2C1_SDA.
  // setPinInputHigh(A9);

  // This still doesn't 'solve' A9 not handling properly. :/
  palSetPadMode(GPIOA, 9, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(0));
}

void keyboard_post_init_user(void) {
  // Call the post init code.
#ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); // sets mode to Fast breathing without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD); // sets mode to Fast breathing without saving
#endif
}

void print_info_about_gpioa_pin(uint32_t pin) {
#ifdef CONSOLE_ENABLE
  uint32_t moder = GPIOA->MODER; // mode
  uint32_t otyper = GPIOA->OTYPER; // output type
  uint32_t ospeedr = GPIOA->OSPEEDR; // output speed type
  uint32_t pupdr = GPIOA->PUPDR; // pull-up/pull-down
  uint32_t afrl = GPIOA->AFRL; // alternate function (low)
  uint32_t afrh = GPIOA->AFRH; // alternate function (high)

  uprintf("A%d:: ", pin);
  // PIN_MODE_INPUT(n)
  // PIN_MODE_OUTPUT(n)
  // PIN_MODE_ALTERNATE(n)
  // PIN_MODE_ANALOG(n)
  if ((moder & PIN_MODE_INPUT(pin)) > 0) {
    uprintf("m: I, ");
  }
  if ((moder & PIN_MODE_OUTPUT(pin)) > 0) {
    uprintf("m: O, ");
  }
  if ((moder & PIN_MODE_ALTERNATE(pin)) > 0) {
    uprintf("m: AL, ");
  }
  if ((moder & PIN_MODE_ANALOG(pin)) > 0) {
    uprintf("m: AN, ");
  }

  // PIN_OTYPE_PUSHPULL(n)
  // PIN_OTYPE_OPENDRAIN(n)
  if ((otyper & PIN_OTYPE_PUSHPULL(pin)) > 0) {
    uprintf("t: PP, ");
  }
  if ((otyper & PIN_OTYPE_OPENDRAIN(pin)) > 0) {
    uprintf("t: OD, ");
  }

  // output data register
  // PIN_ODR_LOW(n)
  // PIN_ODR_HIGH(n)

  // PIN_OSPEED_VERYLOW(n)
  // PIN_OSPEED_LOW(n)
  // PIN_OSPEED_MEDIUM(n)
  // PIN_OSPEED_HIGH(n)
  if ((ospeedr & PIN_OSPEED_VERYLOW(pin)) > 0) {
    uprintf("os: VL, ");
  }
  if ((ospeedr & PIN_OSPEED_LOW(pin)) > 0) {
    uprintf("os: L, ");
  }
  if ((ospeedr & PIN_OSPEED_MEDIUM(pin)) > 0) {
    uprintf("os: M, ");
  }
  if ((ospeedr & PIN_OSPEED_HIGH(pin)) > 0) {
    uprintf("os: H, ");
  }

  // PIN_PUPDR_FLOATING(n)
  // PIN_PUPDR_PULLUP(n)
  // PIN_PUPDR_PULLDOWN(n)
  if ((pupdr & PIN_PUPDR_FLOATING(pin)) > 0) {
    uprintf("PU/PD: F, ");
  }
  if ((pupdr & PIN_PUPDR_PULLUP(pin)) > 0) {
    uprintf("PU/PD: PU, ");
  }
  if ((pupdr & PIN_PUPDR_PULLDOWN(pin)) > 0) {
    uprintf("PU/PD: PD, ");
  }

  // PIN_AFIO_AF(n, v)
  if (pin < 8) {
    for (int af = 0; af < 16; af++) {
      if ((afrl & PIN_AFIO_AF(pin, af)) > 0) {
        uprintf("AF: %d", af);
      }
    }
  } else {
    for (int af = 0; af < 16; af++) {
      if ((afrh & PIN_AFIO_AF(pin, af)) > 0) {
        uprintf("AF: %d", af);
      }
    }
  }
  uprintf("\n");
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE

    print_info_about_gpioa_pin(7);
    print_info_about_gpioa_pin(8);
    print_info_about_gpioa_pin(9);
    print_info_about_gpioa_pin(10);
    uprintf("A9 is %d\n", readPin(A9));

#endif 
  return true;
}
