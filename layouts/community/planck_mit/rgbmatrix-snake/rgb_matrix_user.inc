RGB_MATRIX_EFFECT(SNAKE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "snake.h"

uint32_t timer = 0;

uint8_t counter = 0;

static bool SNAKE(effect_params_t* params) {
  if (timer > g_rgb_timer) {
    return false;
  }

  HSV hsv  = rgb_matrix_config.hsv;
  RGB rgb = hsv_to_rgb(hsv);
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (int q = led_min; q < led_max; q++) {
      if (q == counter) {
          rgb_matrix_set_color(q, rgb.r, rgb.g, rgb.b);
      } else {
          rgb_matrix_set_color(q, 0x00, 0x00, 0x00);
      }
  }

  if (led_max == DRIVER_LED_TOTAL) {
    timer = g_rgb_timer + 200;

    if (snake_status.direction == DIRECTION_RIGHT) {
      counter++;
    } else if (snake_status.direction == DIRECTION_LEFT) {
      counter--;
    }
    if (counter > 11) {
      counter = 0;
    }
    if (counter < 0) {
      counter = 11;
    }
  }

  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS