#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
	    { KC_NO,   KC_NO,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   },
	    { KC_NO,   KC_NO,   KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   },
	    { KC_NO,   KC_NO,   KC_LNUM, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   },
	    { KC_NO,   KC_NO,   KC_LCAP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   },
	    { KC_NO,   KC_NO,   KC_LSCR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   },
	    { KC_SPC,  KC_RGHT, KC_X,    KC_R,    KC_BSLS, KC_MINS, KC_3,    KC_F    },
	    { KC_SCLN, KC_GRV,  KC_NO,   KC_W,    KC_V,    KC_P,    KC_1,    KC_S    },
	    { KC_TAB,  KC_APP,  KC_NO,   KC_T,    KC_N,    KC_RBRC, KC_4,    KC_G    },
	    { KC_BSLS, KC_LEFT, KC_NO,   KC_I,    KC_DOT,  KC_0,    KC_7,    KC_K    },
	    { KC_QUOT, KC_BSPC, KC_NO,   KC_E,    KC_B,    KC_LBRC, KC_2,    KC_D    },
	    { KC_L,    KC_EQL,  KC_NO,   KC_Q,    KC_C,    KC_O,    KC_ESC,  KC_A    },
	    { KC_FN0,  KC_UP,   KC_NO,   KC_Y,    KC_M,    KC_8,    KC_5,    KC_H    },
	    { KC_ENT,  KC_DOWN, KC_Z,    KC_U,    KC_COMM, KC_9,    KC_6,    KC_J    },
	    { KC_CLR,  KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   }
    },
    [1] = { { 0, }, },
};

const action_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};

