// Copyright 2024 Flare576 <flare576@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
 * Key-test layout for Sofle rev1 (60 keys)
 * Every key sends a unique, distinct character.
 * No layers, no modifiers, no special logic — pure matrix test.
 *
 * Row order (left to right, top to bottom, left half then right half):
 *   Row 0: ` 1 2 3 4 5 | 6 7 8 9 0 -
 *   Row 1: a b c d e f | g h i j k l
 *   Row 2: m n o p q r | s t u v w x
 *   Row 3: y z [ ] ; ' | , . / = ~ !
 *   Thumb: @ # $ % ^   |   & * ( ) {  (encoder push = ^ and &)
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,                      KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_M,    KC_N,    KC_O,    KC_P,    KC_Q,    KC_R,                      KC_S,    KC_T,    KC_U,    KC_V,    KC_W,    KC_X,
        KC_Y,    KC_Z,    KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, KC_EQL,  KC_BSLS, KC_COMM, KC_DOT,  KC_SLSH, KC_TILD, KC_EXLM, KC_AT,
                          KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,          KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR
    )
};
