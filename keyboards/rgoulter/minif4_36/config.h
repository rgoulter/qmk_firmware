/* Copyright 2020 Thys de Wet
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
#pragma once

// #include "config_common.h"


/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x7813
#define DEVICE_VER 0x0001
#define MANUFACTURER Richard Goulter
#define PRODUCT MiniF4 36-key


#define MATRIX_IO_DELAY 5
#define TAP_CODE_DELAY 10

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5


/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* key matrix size */
#ifdef SPLIT_KEYBOARD
#define MATRIX_ROWS 8
#else
#define MATRIX_ROWS 4
#endif
#define MATRIX_COLS 5

/*
 #define DIRECT_PINS {            \
   { B15, A8, A9, A10, A2 },       \
   { B5, A15, B3, B4, B10 },       \
   { A1, B1, B0, A7, A6 },         \
   { NO_PIN, B14, A5, A4, A3 }     \
}
// */
// SW25 was at B2; but .... this is where NRST is.
// let's use B11 for SW25
// A0 didn't work if we used A0 as RGB pin...
//   { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },
#define DIRECT_PINS { \
   { B15, A8, A9, A10, A3 },       \
   { B5, A15, B3, B4, A0 },       \
   { A2, B10, B1, B0, A7 },             \
   { NO_PIN, B14, A6, A5, A4 }         \
}

// Split Transport
#ifdef SPLIT_KEYBOARD
#define SOFT_SERIAL_PIN B6
#define SPLIT_TRANSPORT_MIRROR
#endif

// Rotary Encoders
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
// RE switch is B14
#endif

// RGB Matrix
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN A1

#ifdef SPLIT_KEYBOARD
// 18 + 4 on each side
#define DRIVER_LED_TOTAL 44
#define RGBLED_NUM 44
#define RGB_MATRIX_SPLIT { 22,22 }
#else
#define DRIVER_LED_TOTAL 22
#define RGBLED_NUM 22
#endif

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_KEYPRESSES

// cf. Table 9. Alternate function mapping
// of STM32F401xE datasheet
// PA0's AF_02 is TIM5_CH1
#define WS2812_PWM_DRIVER PWMD5
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 2
// cf. Table 28. DMA1 request mapping
// in 9.3.3 of RM0368
#define WS2812_DMA_STREAM STM32_DMA1_STREAM0
#define WS2812_DMA_CHANNEL 6
#endif

// OLED
#ifdef OLED_DRIVER_ENABLE
/* B8, B9 instead of B6, B7 */
#define I2C1_SCL 8
#define I2C1_SDA 9
#endif
