/**
 * matrix.c
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <hal.h>
#include "quantum.h"
#include "timer.h"
#include "wait.h"
#include "print.h"
#include "matrix.h"

/**
 *
 * Row pins are input with internal pull-down.
 * Column pins are output and strobe with high.
 * Key is high or 1 when it turns on.
 *
 */
/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS]; // equiv. to quantum/matrix.c's matrix
static matrix_row_t matrix_debouncing[MATRIX_ROWS]; // equiv. to quantum/matrix.c's raw_matrix
static bool debouncing = false;
static uint16_t debouncing_time = 0;

#define LINE_SW_11                  PAL_LINE(GPIOB, 15U)
#define LINE_SW_12                  PAL_LINE(GPIOA, 8U)
#define LINE_SW_13                  PAL_LINE(GPIOA, 9U)
#define LINE_SW_14                  PAL_LINE(GPIOA, 10U)
#define LINE_SW_15                  PAL_LINE(GPIOA, 2U)

#define LINE_SW_21                  PAL_LINE(GPIOB, 5U)
#define LINE_SW_22                  PAL_LINE(GPIOA, 15U)
#define LINE_SW_23                  PAL_LINE(GPIOB, 3U)
#define LINE_SW_24                  PAL_LINE(GPIOB, 4U)
#define LINE_SW_25                  PAL_LINE(GPIOB, 10U)

#define LINE_SW_31                  PAL_LINE(GPIOA, 1U)
#define LINE_SW_32                  PAL_LINE(GPIOB, 1U)
#define LINE_SW_33                  PAL_LINE(GPIOB, 0U)
#define LINE_SW_34                  PAL_LINE(GPIOA, 7U)
#define LINE_SW_35                  PAL_LINE(GPIOA, 6U)

#define LINE_SW_41                  PAL_LINE(GPIOA, 5U)
#define LINE_SW_42                  PAL_LINE(GPIOA, 4U)
#define LINE_SW_43                  PAL_LINE(GPIOA, 3U)

/*
    // quantum/matrix.c impl:
    void matrix_init(void) {
        // initialize key pins
        init_pins();
    
        // initialize matrix state: all keys off
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            raw_matrix[i] = 0;
            matrix[i]     = 0;
        }
    
        debounce_init(MATRIX_ROWS);
    
        matrix_init_quantum();
    }
*/
void matrix_init(void)
{
    //debug_enable = true;

    // RICHARD: this is inlined, unrolled init_pins()
    palSetLineMode(LINE_SW_11, PAL_MODE_INPUT_PULLUP);
    palSetLineMode(LINE_SW_12, PAL_MODE_INPUT_PULLUP);
    palSetLineMode(LINE_SW_13, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_14, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_15, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_21, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_22, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_23, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_24, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_25, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_31, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_32, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_33, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_34, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_35, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_41, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_42, PAL_MODE_INPUT_PULLUP);
    // palSetLineMode(LINE_SW_43, PAL_MODE_INPUT_PULLUP);

    palClearLine(LINE_SW_11);
    palClearLine(LINE_SW_12);
    palClearLine(LINE_SW_13);
    // palClearLine(LINE_SW_14);
    // palClearLine(LINE_SW_15);
    // palClearLine(LINE_SW_21);
    // palClearLine(LINE_SW_22);
    // palClearLine(LINE_SW_23);
    // palClearLine(LINE_SW_24);
    // palClearLine(LINE_SW_25);
    // palClearLine(LINE_SW_31);
    // palClearLine(LINE_SW_32);
    // palClearLine(LINE_SW_33);
    // palClearLine(LINE_SW_34);
    // palClearLine(LINE_SW_35);
    // palClearLine(LINE_SW_41);
    // palClearLine(LINE_SW_42);
    // palClearLine(LINE_SW_43);

    memset(matrix, 0, MATRIX_ROWS * sizeof(matrix_row_t));
    memset(matrix_debouncing, 0, MATRIX_ROWS * sizeof(matrix_row_t));

    matrix_init_quantum();
}

/*
    // from quantum/matrix.c
    static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
        // Start with a clear matrix row
        matrix_row_t current_row_value = 0;
    
        for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
            pin_t pin = direct_pins[current_row][col_index];
            if (pin != NO_PIN) {
                current_row_value |= readPin(pin) ? 0 : (MATRIX_ROW_SHIFTER << col_index);
            }
        }
    
        // If the row has changed, store the row and return the changed flag.
        if (current_matrix[current_row] != current_row_value) {
            current_matrix[current_row] = current_row_value;
            return true;
        }
        return false;
    }

    uint8_t matrix_scan(void) {
        bool changed = false;
    
        // Set row, read cols
        for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
            changed |= read_cols_on_row(raw_matrix, current_row);
        }
    
        debounce(raw_matrix, matrix, MATRIX_ROWS, changed);
    
        matrix_scan_quantum();
        return (uint8_t)changed;
    }

    // from quantum/debounce/sym_defer_g.c
    static uint16_t debouncing_time;
    void            debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {
        if (changed) {
            debouncing      = true;
            debouncing_time = timer_read();
        }
    
        if (debouncing && timer_elapsed(debouncing_time) > DEBOUNCE) {
            for (int i = 0; i < num_rows; i++) {
                cooked[i] = raw[i];
            }
            debouncing = false;
        }
    }
*/
uint8_t matrix_scan(void)
{
    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        // RICHARD: this block inlines read_col_on_row(current_matrix = matrix, current_row)
        //          and per noah/matrix.c, `debouncing` is used directly, not a local `changed`.
        matrix_row_t data = 0;

        switch(current_row) {
        case 0:
          data = (
              ((palReadLine(LINE_SW_11) ? 0 : 1) << 0 ) |
              ((palReadLine(LINE_SW_12) ? 0 : 1) << 1 ) |
              ((palReadLine(LINE_SW_13) ? 0 : 1) << 2 ) /* |
              (palReadLine(LINE_SW_14) << 3 ) |
              (palReadLine(LINE_SW_15) << 4 ) // */
          );
          break;
        // RICHARD: XXX: impl. other rows
        }

        if (matrix_debouncing[current_row] != data) {
            matrix_debouncing[current_row] = data;
            debouncing = true;
            debouncing_time = timer_read();
        }
    }

    // RICHARD: inline of quantum/debounce/sym_defer_g.c
    //          with debounce(raw = matrix_debouncing, cook = matrix, ...)
    if (debouncing && timer_elapsed(debouncing_time) > DEBOUNCE) {
        for (int row = 0; row < MATRIX_ROWS; row++) {
            // for (int col = 0; col < MATRIX_COLS; col++) {
            //     matrix[row] |= ((matrix_debouncing[col] & (1 << row) ? 1 : 0) << col);
            // }
            matrix[row] = matrix_debouncing[row];
        }
        debouncing = false;
    }

    matrix_scan_quantum();

    return 1;
}

// from matrix_common.c
bool matrix_is_on(uint8_t row, uint8_t col) { return (matrix[row] & (1<<col)); }

matrix_row_t matrix_get_row(uint8_t row) { return matrix[row]; }

void matrix_print(void)
{
    printf("\nr/c 01234567\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        printf("%X0: ", row);
        matrix_row_t data = matrix_get_row(row);
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (data & (1<<col))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}
void matrix_init_kb(void) { matrix_init_user(); }

void matrix_scan_kb(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_task();
#endif
    matrix_scan_user();
}


__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}
