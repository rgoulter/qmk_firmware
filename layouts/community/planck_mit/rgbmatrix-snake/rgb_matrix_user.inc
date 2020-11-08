RGB_MATRIX_EFFECT(SNAKE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define SNAKE_FPS 12

#include "snake.h"

uint32_t timer = 0;
uint32_t last_updated = 0;

static void render(uint8_t led_min, uint8_t led_max) {
  HSV hsv  = rgb_matrix_config.hsv;
  RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t q = led_min; q < led_max; q++) {
      if (q == 11) {
          rgb_matrix_set_color(q, rgb.r, rgb.g, rgb.b);
      } else {
          rgb_matrix_set_color(q, 0x00, 0x00, 0x00);
      }
  }
}

static bool SNAKE(effect_params_t* params) {
  if (timer > g_rgb_timer) {
    return false;
  }

  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  render(led_min, led_max);

  if (led_max == DRIVER_LED_TOTAL) {
    uint32_t delta_time = timer_elapsed32(last_updated);
    snake_update(delta_time);
    last_updated = timer_read32();

    timer = g_rgb_timer + (1000 / SNAKE_FPS);
  }

  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS