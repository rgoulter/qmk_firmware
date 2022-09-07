#pragma once

/* Uses 'held' key in sequence like "TH-DOWN, X-DOWN, TH-UP, X-UP".
 * (Default behaviour would be 'tap').
 */
// #define PERMISSIVE_HOLD

/* Necessary for home-row mods */
#define IGNORE_MOD_TAP_INTERRUPT

/*
 * Per: https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
 * When the user holds a key after tapping it, the tapping function is repeated
 * by default, rather than activating the hold function. This allows keeping
 * the ability to auto-repeat the tapping function of a dual-role key.
 * TAPPING_FORCE_HOLD removes that ability to let the user activate the hold
 * function instead, in the case of holding the dual-role key after having
 * tapped it.
 */
#define TAPPING_FORCE_HOLD_PER_KEY

#define TAPPING_TERM 200

#define COMBO_COUNT 3

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
