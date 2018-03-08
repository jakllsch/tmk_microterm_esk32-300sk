#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3ebc
#define DEVICE_VER      0x0000

#define MANUFACTURER        "jakllsch"
#define USBSTR_MANUFACTURER
#define PRODUCT             "ESK32-300SK"
#define USBSTR_PRODUCT
#define DESCRIPTION         "tmk for Micro-Term via ESK32-300SK"

/* key matrix size */
#define MATRIX_ROWS 14
#define MATRIX_COLS 8

/* define if matrix has ghost */
#define MATRIX_HAS_GHOST

// features
//#define NKRO_ENABLE
//#define MOUSE_ENABLE

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
