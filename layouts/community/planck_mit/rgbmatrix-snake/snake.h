#pragma once

#define DIRECTION_RIGHT 0
#define DIRECTION_UP 1
#define DIRECTION_LEFT 2
#define DIRECTION_DOWN 3

typedef struct _snake_status_t {
    char direction;
} snake_status_t;

extern snake_status_t snake_status;
