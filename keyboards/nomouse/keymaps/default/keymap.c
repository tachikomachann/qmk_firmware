// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
        KC_TAB,				KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,			KC_PSLS,		KC_Y,			KC_U,			KC_I,			KC_O,			KC_P,			KC_BSPC,			
        KC_LCTL,			KC_A,			KC_S,			KC_D,			KC_F,			KC_G,							KC_H,			KC_J,			KC_K,			KC_L,			KC_SCLN,		KC_QUOT,			
        KC_LSFT,			KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,			KC_PMNS,		KC_N,			KC_M,			KC_COMM,		KC_DOT,			KC_SLSH,		KC_RSFT,			
        LT(4,KC_LCAP),		MO(1),			KC_LALT,		LT(2,KC_SPC),					KC_PAST,						KC_ENT,							MO(3),			KC_RGUI,		KC_RCTL,		KC_MENU
    ),

    [1] = LAYOUT( 
        G(KC_TAB),			C(G(KC_LEFT)),	C(G(KC_RIGHT)),		G(KC_E),		G(KC_R),		KC_TRNS,		KC_TRNS,		M_CP_LINE,		KC_TRNS,		KC_HOME,		M_NEW_LINE,		S(KC_INS),		KC_DEL,			
        KC_TRNS,			M_DEL_LINE,		G(KC_D),		KC_TRNS,		KC_TRNS,		KC_TRNS,						KC_LEFT,		KC_DOWN,		KC_UP,			KC_RIGHT,		KC_TRNS,		KC_TRNS,			
        KC_TRNS,			KC_TRNS,		M_DELTO_START,	M_DELTO_END,	M_SEL_LINE,		KC_TRNS,		KC_TRNS,		KC_PGUP,		KC_PGDN,		KC_TRNS,		G(KC_DOT),		KC_TRNS,		KC_TRNS,			
        KC_TRNS,			KC_TRNS,		KC_TRNS,		KC_TRNS,						KC_TRNS,						G(KC_SPC),						KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS
    ),

    [2] = LAYOUT( 
        KC_ESC,				KC_1,			KC_2,			KC_3,			KC_4,			KC_5,			KC_TRNS,		KC_6,			KC_7,			KC_8,			KC_9,			KC_0,			KC_TRNS,		
        KC_TRNS,			C(G(KC_1)), 	C(G(KC_2)),	   	C(G(KC_3)),	   	C(G(KC_4)),	   	C(G(KC_5)),  		           	KC_TRNS, 		KC_BSLS, 		KC_MINS, 		KC_EQL, 		KC_TRNS, 		KC_TRNS, 
        KC_TRNS,			C(G(KC_6)), 	C(G(KC_7)),	   	C(G(KC_8)),	   	C(G(KC_9)),	   	C(G(KC_0)),		KC_TRNS,		KC_TRNS, 		KC_TRNS, 		KC_LBRC, 		KC_RBRC, 		KC_TRNS, 		KC_TRNS, 
        KC_TRNS,			KC_TRNS, 		KC_TRNS, 		KC_TRNS,     	         		KC_TRNS,  		           		KC_TRNS,						KC_TRNS,		KC_TRNS, 		KC_TRNS, 		KC_TRNS
    ),

    [3] = LAYOUT( 
        KC_GRV,				KC_F1,			KC_F2,			KC_F3,			KC_F4,			KC_F5,			KC_TRNS,		KC_F6,			KC_F7,			KC_F8,			KC_F9,			KC_F10,			KC_DEL,		
        KC_TRNS,	   		KC_F11, 		KC_F12, 		KC_TRNS,     	KC_TRNS, 		KC_TRNS,  		           		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 
        KC_TRNS,	   		KC_VOLD, 		KC_VOLU, 		KC_MPRV,     	KC_MNXT, 		KC_MPLY,  		KC_TRNS,   		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS,
        KC_TRNS,	   		KC_TRNS, 		KC_TRNS, 		KC_TRNS,     	         		KC_TRNS,  		           		KC_TRNS,						KC_TRNS,		KC_TRNS, 		KC_TRNS, 		KC_TRNS
    ),

    [4] = LAYOUT( 
        G(KC_GRV),			KC_TRNS,		KC_UP,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,
        KC_TRNS,	   		KC_LEFT, 		KC_DOWN, 		KC_RIGHT,     	KC_TRNS, 		KC_TRNS,  		           		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 
        KC_TRNS,	   		KC_TRNS, 		KC_TRNS, 		KC_TRNS,     	KC_TRNS, 		KC_TRNS,  		KC_TRNS,   		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS, 		KC_TRNS,
        KC_TRNS,	   		KC_TRNS, 		KC_TRNS, 		KC_TRNS,     	         		KC_MPLY,  		           		KC_TRNS,						KC_TRNS,		KC_TRNS, 		KC_TRNS, 		QK_BOOT

    ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    [2] = { ENCODER_CCW_CW(C(KC_EQL), C(KC_MINS))  },
    [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [3] = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV)  },
};
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        if (get_mods() == MOD_BIT(KC_LALT)) {
			if (clockwise) {
				tap_code(KC_TAB);
			} else {
				register_code(KC_LSFT);
				tap_code(KC_TAB);
				unregister_code(KC_LSFT);
			}
		}
	}
    return true;
}
