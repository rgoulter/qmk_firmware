#include "snake.h"

snake_status_t snake_status = {
  .direction = DIRECTION_RIGHT,
  .snake = { 16, 15, 14, 13 },
  .snake_start = 3,
  .snake_length = 4,
  .food = 20,
  .snake_anim_counter = 750,
  .snake_ms_per_move = 750,
};

void snake_init() {

}

// wraps around automatically
uint8_t next_cell_wraparound(uint8_t idx, char direction) {
  uint8_t row = idx / SNAKE_GRID_WIDTH;
  uint8_t col = idx % SNAKE_GRID_WIDTH;
  uint8_t next_row = row;
  uint8_t next_col = col;
  switch (direction) {
  case DIRECTION_RIGHT:
    next_col = (col == SNAKE_GRID_WIDTH - 1) ? 0 : col + 1;
    break;
  case DIRECTION_UP:
    next_row = (row == 0) ? SNAKE_GRID_HEIGHT - 1 : row - 1;
    break;
  case DIRECTION_LEFT:
    next_col = (col == 0) ? SNAKE_GRID_WIDTH - 1 : col - 1;
    break;
  case DIRECTION_DOWN:
    next_row = (row == SNAKE_GRID_HEIGHT - 1) ? 0 : row + 1;
    break;
  }
  return (next_row * SNAKE_GRID_WIDTH) + next_col;
}

void snake_update(uint32_t delta_time) {
  switch (snake_status.direction) {
  case DIRECTION_RIGHT:
    break;
  case DIRECTION_UP:
    break;
  case DIRECTION_LEFT:
    break;
  case DIRECTION_DOWN:
    break;
  }
}
