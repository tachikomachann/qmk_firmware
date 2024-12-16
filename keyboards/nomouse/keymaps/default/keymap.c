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
	M_SEL_WORD,
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
        KC_CAPS,			MO(1),		    KC_LALT,		LT(2,KC_SPC),	KC_PSLS,														KC_PAST,		KC_ENT,			MO(3),		    KC_RGUI,		KC_RCTL

    ),

    [1] = LAYOUT( 
        G(KC_GRV),		    C(G(KC_LEFT)),	C(G(KC_RIGHT)),	KC_TRNS,		KC_TRNS,		KC_TRNS,						KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,	KC_TRNS,			
        G(KC_TAB),			C(KC_INS),		M_SEL_WORD,		G(KC_E),		G(KC_R),		M_CP_LINE,						KC_TRNS,		KC_TRNS,		KC_HOME,		M_NEW_LINE,		S(KC_INS),		KC_TRNS,	KC_TRNS,
        KC_TRNS,			G(KC_A),		M_DEL_LINE,		G(KC_D),		KC_TRNS,		KC_TRNS,						KC_LEFT,		KC_DOWN,		KC_UP,		    KC_RIGHT,		KC_TRNS,		KC_TRNS,	KC_TRNS,	
        KC_TRNS,			KC_TRNS,	    M_DELTO_START,	M_DELTO_START,	M_SEL_LINE,		KC_TRNS,						KC_PGDN,		KC_PGUP,		G(KC_COMM),		G(KC_DOT),		KC_TRNS,		KC_TRNS,			
        KC_TRNS,			KC_TRNS,		KC_TRNS,		G(KC_SPC),		KC_TRNS,														KC_TRNS,		G(KC_SPC),		KC_TRNS,		KC_TRNS,		QK_BOOT

    ),

    [2] = LAYOUT( 
        KC_GRV,		        KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,						KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,	KC_TRNS,			
        C(G(KC_6)),			C(G(KC_7)),	    C(G(KC_8)),	    C(G(KC_9)),	    C(G(KC_0)),		KC_TRNS,						KC_TRNS,		KC_TRNS,		KC_BSLS,		KC_TRNS,		KC_TRNS,		KC_TRNS,	KC_TRNS,
        C(G(KC_1)),			C(G(KC_2)),		C(G(KC_3)),		C(G(KC_4)),		C(G(KC_5)),		KC_TRNS,						KC_TRNS,		KC_TRNS,		KC_MINS,		KC_EQL,		    KC_TRNS,		KC_TRNS,	KC_TRNS,	
        S(G(KC_1)),			S(G(KC_2)),		S(G(KC_3)),		S(G(KC_4)),		S(G(KC_5)),		KC_TRNS,						KC_TRNS,		KC_TRNS,		KC_LBRC,		KC_RBRC,		KC_TRNS,		KC_TRNS,			
        KC_TRNS,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_PMNS,														KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS

    ),
    [3] = LAYOUT( 
        KC_GRV,		        KC_F1,  		KC_F2,		    KC_F3,		    KC_F4,		    KC_F5,						    KC_F6,		    KC_F7,		    KC_F8,		    KC_F9,		    KC_F10,		    KC_TRNS,	KC_TRNS,			
        KC_TRNS,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,						KC_TRNS,		KC_TRNS,		KC_UP,		    KC_TRNS,		KC_TRNS,	    KC_TRNS,    KC_TRNS,
        KC_TRNS,			KC_F11,		    KC_F12,		    KC_TRNS,		KC_TRNS,		KC_TRNS,						KC_TRNS,		KC_LEFT,		KC_DOWN,		KC_RIGHT,		KC_TRNS,	    KC_TRNS,	KC_TRNS,
        KC_TRNS,			KC_VOLD,	    KC_VOLU,	    KC_MPRV,	    KC_MNXT,		KC_MPLY,						KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,			
        KC_TRNS,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_PAST,														KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS

    ),



};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
    switch (keycode) {
        case M_CP_LINE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_LCTL(SS_TAP(X_INS)));
        }
        break;
        case M_NEW_LINE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENT));
        }
        break;
        case M_DEL_LINE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DEL));
        }
        break;
        case M_DELTO_START:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_DEL));
        }
        break;
        case M_DELTO_END:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DEL));
        }
        break;
        case M_SEL_LINE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
        }
        break;
        case M_SEL_WORD:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_LSFT(SS_LCTL(SS_TAP(X_RIGHT))));
        }
        break;
    } 
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
#ifdef CONSOLE_ENABLE
    uprintf("encorder data change, index:%d, clockwise:%d", index, clockwise);
#endif 
    if (get_mods() == MOD_BIT(KC_LALT)) {
        if (clockwise) {
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT);
        } else {
            tap_code(KC_TAB);
        }
        return false;
    } 
    if(IS_LAYER_ON(0)){
        if (clockwise) {
            tap_code(MS_WHLD);
        } else {
            tap_code(MS_WHLU);
        }
    }
    if(IS_LAYER_ON(1)){
        // if (clockwise) {
        //     register_code(KC_LCTL);
        //     tap_code(KC_TAB);
        //     unregister_code(KC_LCTL);
        // } else {
        //     tap_code(KC_TAB);
        // }
    }
    if(IS_LAYER_ON(2)){
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    if(IS_LAYER_ON(3)){
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }

    }

    return false;
}