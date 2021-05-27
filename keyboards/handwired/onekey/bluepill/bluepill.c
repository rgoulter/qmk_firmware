
#include QMK_KEYBOARD_H

void board_init(void) {
  // Use B8, B9 as I2C1.
  AFIO->MAPR |= AFIO_MAPR_I2C1_REMAP;
}
