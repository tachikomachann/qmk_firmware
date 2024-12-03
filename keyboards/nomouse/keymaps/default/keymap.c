// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

enum macro_keycodes {
    M_CP_LINE = SAFE_RANGE,
	M_NEW_LINE,
	M_DEL_LINE,
	M_DELTO_START,
	M_DELTO_END,
	M_SEL_LINE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT( 
    /** 
    RP2040 mouse keys are not working when using vendor driver ps/2 trackpoint.
    Replace mouse key MS_BTN1 ~ MS_BTN3 to KC_PSLS, KC_PAST and KC_PMNS, 
    then use software(ahk) remap these keys to left/middle/right button
    **/
        KC_ESC,				KC_1,			KC_2,			KC_3,			KC_4,			KC_5,							KC_6,			KC_7,			KC_8,			KC_9,			KC_0,			KC_BSPC,	KC_DEL,			
        KC_TAB,				KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,							KC_Y,			KC_U,			KC_I,			KC_O,			KC_P,			KC_BSLS,	KC_HOME,
        KC_LCTL,			KC_A,			KC_S,			KC_D,			KC_F,			KC_G,							KC_H,			KC_J,			KC_K,			KC_L,			KC_SCLN,		KC_QUOT,	KC_END,	
        KC_LSFT,			KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,							KC_N,			KC_M,			KC_COMM,		KC_DOT,			KC_SLSH,		KC_RSFT,			
        KC_CAPS,			KC_LGUI,		KC_LALT,		LT(2,KC_SPC),	KC_PSLS,														KC_PAST,		KC_ENT,			KC_RALT,		KC_RGUI,		KC_RCTL

    ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    // [2] = { ENCODER_CCW_CW(C(KC_EQL), C(KC_MINS))  },
    // [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    // [3] = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV)  },
// };
// #endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    print("encorder press\n");
    uprintf("clockwise:%d \n", clockwise);
    uprintf("index:%d \n", index);
    if (index == 0) { 
        if (get_mods() == MOD_BIT(KC_LALT)) {
			if (clockwise) {
				tap_code(KC_TAB);
			} else {
				register_code(KC_LSFT);
				tap_code(KC_TAB);
				unregister_code(KC_LSFT);
			}
		} else {
			if (clockwise) {
				tap_code(MS_WHLU);
			} else {
				tap_code(MS_WHLD);
			}
        }

            return false;
	}
    return true;
}