#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "hal.h"
#include "timer.h"
#include "wait.h"
#include "print.h"
#include "matrix.h"

static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];
static bool debouncing = false;
static uint16_t debouncing_time = 0;

void matrix_init(void){
    palSetLineMode(LINE_LED2, PAL_MODE_OUTPUT_PUSHPULL);
    palSetLineMode(LINE_LED1, PAL_MODE_OUTPUT_PUSHPULL);
    /* COLS */
    palSetGroupMode(GPIO_B, 0x1, 9, PAL_MODE_INPUT_PULLDOWN);
    palSetGroupMode(GPIO_C, 0x7, 4, PAL_MODE_INPUT_PULLDOWN);
    palSetGroupMode(GPIO_D, 0x3f, 9, PAL_MODE_INPUT_PULLDOWN);
    /* ROWS */
    palSetGroupMode(GPIO_E, 0xff, 0, PAL_MODE_OUTPUT_PUSHPULL);
    palSetGroupMode(GPIO_B, 0x7, 6, PAL_MODE_OUTPUT_PUSHPULL);
    palSetGroupMode(GPIO_B, 0x3, 10, PAL_MODE_OUTPUT_PUSHPULL);
    palSetGroupMode(GPIO_D, 0x1, 15, PAL_MODE_OUTPUT_PUSHPULL);
    memset(matrix, 0, MATRIX_ROWS);
}

uint8_t matrix_scan(void) {
    for (int row = 0; row < MATRIX_ROWS; row++) {
        matrix_row_t data = 0;

        switch (row) {
                                                 // interconnect wire color,
                                                 // pin on keyboard connector
            case 0: palSetPad(GPIO_E, 0); break; // purple 3
            case 1: palSetPad(GPIO_E, 1); break; // gray 5
            case 2: palSetPad(GPIO_E, 2); break; // white 7
            case 3: palSetPad(GPIO_E, 3); break; // black 9
            case 4: palSetPad(GPIO_E, 4); break; // brown 11
            case 5: palSetPad(GPIO_E, 5); break; // red 13
            case 6: palSetPad(GPIO_E, 6); break; // orange 15
            case 7: palSetPad(GPIO_E, 7); break; // yellow 17
            case 8: palSetPad(GPIO_B, 6); break; // green 19
            case 9: palSetPad(GPIO_B, 7); break; // blue 21
            case 10: palSetPad(GPIO_B, 8); break; // violet 23
            case 11: palSetPad(GPIO_B, 10); break; // white 25
            case 12: palSetPad(GPIO_B, 11); break; // black 26
            case 13: palSetPad(GPIO_D, 15); break; // black 16
        }
        wait_us(20);
        if (row == 13)
            // D.14 is pin 18 (white)
            // B.9 is pin 24 (gray)
            data = (palReadPad(GPIO_B, 9)<<1)|palReadPad(GPIO_D, 14);
        else
            data = ((matrix_row_t)palReadGroup(GPIO_D, 0x1f, 9) << 3) | palReadGroup(GPIO_C, 0x7, 4);
        switch (row) {
            case 0: palClearPad(GPIO_E, 0); break; // purple 3
            case 1: palClearPad(GPIO_E, 1); break; // gray 5
            case 2: palClearPad(GPIO_E, 2); break; // white 7
            case 3: palClearPad(GPIO_E, 3); break; // black 9
            case 4: palClearPad(GPIO_E, 4); break; // brown 11
            case 5: palClearPad(GPIO_E, 5); break; // red 13
            case 6: palClearPad(GPIO_E, 6); break; // orange 15
            case 7: palClearPad(GPIO_E, 7); break; // yellow 17
            case 8: palClearPad(GPIO_B, 6); break; // green 19
            case 9: palClearPad(GPIO_B, 7); break; // blue 21
            case 10: palClearPad(GPIO_B, 8); break; // violet 23
            case 11: palClearPad(GPIO_B, 10); break; // white 25
            case 12: palClearPad(GPIO_B, 11); break; // black 26
            case 13: palClearPad(GPIO_D, 15); break; // black 16
        }
        if (matrix_debouncing[row] != data) {
                matrix_debouncing[row] = data;
                debouncing = true;
                debouncing_time = timer_read();
        }
    }
    if (debouncing && timer_elapsed(debouncing_time) > DEBOUNCE) {
        for (int row = 0; row < MATRIX_ROWS; row++) {
            matrix[row] = matrix_debouncing[row];
        }
        debouncing = false;
    }
    return 1;
}

bool matrix_is_on(uint8_t row, uint8_t col){
    return (matrix[row] & (1<<col));
}

matrix_row_t matrix_get_row(uint8_t row){
    return matrix[row];
}

void matrix_print(void)
{
    xprintf("\nr/c 01234567\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        xprintf("%02X: ");
        matrix_row_t data = matrix_get_row(row);
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (data & (1<<col))
                xprintf("1");
            else
                xprintf("0");
        }
        xprintf("\n");
    }
}

void __early_init(void)
{
        ht32_clock_init();
}
