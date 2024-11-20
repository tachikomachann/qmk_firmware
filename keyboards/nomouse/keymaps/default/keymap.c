// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT( 
    /** 
    RP2040 mouse keys are not working when using vendor driver ps/2 trackpoint.
    Replace mouse key MS_BTN1 ~ MS_BTN3 to KC_PSLS, KC_PAST and KC_PMNS, 
    then use software(ahk) remap these keys to left/middle/right button
    **/
        KC_TAB,		   KC_Q,    KC_W,    KC_E,        KC_R,    KC_T,    KC_PSLS,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL,	   KC_A,    KC_S,    KC_D,        KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
        KC_LSFT,	   KC_Z,    KC_X,    KC_C,        KC_V,    KC_B,    KC_PMNS,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        LT(4,KC_LCAP), MO(1),   KC_LALT, LT(2,KC_SPC),         KC_PAST,             KC_ENT,           MO(3),   KC_RGUI, KC_RCTL, KC_MENU
    ),

    [1] = LAYOUT( 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,             KC_TRNS,		  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT( 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,             KC_TRNS,		  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT( 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,             KC_TRNS,		  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [4] = LAYOUT( 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,	   KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,             KC_TRNS,		  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    [1] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    [2] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    [3] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
};
#endif
