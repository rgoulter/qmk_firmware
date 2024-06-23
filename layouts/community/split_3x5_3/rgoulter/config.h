#pragma once

#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL

#define COMBO_COUNT USER_COMBO_EVENT_COUNT

#define SPLIT_MODS_ENABLE

#define SOLENOID_DEFAULT_DWELL 200
#define SOLENOID_MIN_DWELL 50
#define SOLENOID_MAX_DWELL 255

#define NO_HAPTIC_ALPHA
#define NO_HAPTIC_PUNCTUATION
#define NO_HAPTIC_NAV
#define NO_HAPTIC_NUMERIC

/* I use modifier keys frequently enough that this just becomes noise. */
#define NO_HAPTIC_MOD

// #define OLED_DISABLE_TIMEOUT
#define OLED_TIMEOUT 90000
