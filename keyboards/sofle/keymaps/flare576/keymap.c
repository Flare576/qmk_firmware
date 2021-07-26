#include QMK_KEYBOARD_H
#include "print.h"
#include "enums.c"

#ifdef OLED_DRIVER_ENABLE
#include "graphics.c"
#endif

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};

#define KC_TPLY TD(TD_PLAY)
#define KC_THME TD(TD_HOME)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |~/MDIA|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Alt/Tb|   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |+/SHFT|
 * `-----------------------------------------/       /     \Enter \-----------------------------------------'
 *            |Gaming| LGUI | LAlt | ESC/ | /Space  /       \ or   \  | Bspc | Alt +|Delete|NUMPAD|
 *            |      |      |      |Number|/       /         \Mouse \ |      |Shift |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
  LT(_MDIA,KC_GRV), KC_1,      KC_2,    KC_3,              KC_4,    KC_5,                   KC_6,               KC_7,    KC_8,          KC_9,   KC_0,     KC_MINS,
  LALT_T(KC_TAB),   KC_Q,      KC_W,    KC_E,              KC_R,    KC_T,                   KC_Y,               KC_U,    KC_I,          KC_O,   KC_P,     KC_BSLS,
  KC_LSFT,          KC_A,      KC_S,    KC_D,              KC_F,    KC_G,                   KC_H,               KC_J,    KC_K,          KC_L,   KC_SCLN,  KC_QUOT,
  KC_LCTRL,         KC_Z,      KC_X,    KC_C,              KC_V,    KC_B, KC_TPLY, KC_THME, KC_N,               KC_M,    KC_COMM,       KC_DOT, KC_SLSH,  RSFT_T(KC_PLUS),
                    TG(_GAME), KC_LALT, LT(_SYMS,KC_ESC),  KC_LGUI, KC_SPC,                 LT(_MOUS, KC_ENT),  KC_BSPC, LALT(KC_LSFT), KC_DEL, TG(_NPAD)
),
/*
 * MOUS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |PRNTSC|      | M UP | HOME | PGUP |                    |M Wl U|M Wl D|M Wl L|M Wl R|      |COMP1 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |SC LCK|M LFT |M DWN |M RGHT|      |-------.    ,-------|  UP  | DOWN | LEFT |RIGHT |      |COMP2 |
 * |------+------+------+------+------+------| TRNS  |    | TRNS  |------+------+------+------+------+------|
 * | TRNS |PAUSE |      |      | END  | PGDN |-------|    |-------|MOUS1 |MOUS2 |  [   |   ]  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS |TRNS  | / TRNS  /       \ TRNS \  |MOUS3 |MOUS4 |MOUS5 |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MOUS] = LAYOUT(
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                        KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,
  _______,  KC_PSCR,  XXXXXXX,  KC_MS_U,  KC_HOME,  KC_PGUP,                      KC_WH_U,  KC_WH_D,  KC_WH_L,  KC_WH_R,   XXXXXXX,  _COMP1,
  _______,  KC_SLCK,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  XXXXXXX,  _COMP2,
  _______,  KC_PAUS,  XXXXXXX,  XXXXXXX,  KC_END,   KC_PGDN,  _______,  _______,  KC_BTN1,  KC_BTN2,  KC_LBRC,  KC_RBRC,   XXXXXXX,  XXXXXXX,
            _______,  _______,  _______,  _______,  _______,                      _______,  KC_BTN3,  KC_BTN4,  KC_BTN5,   XXXXXXX
),
/* SYMS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |CTRL+W|ALT+A |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |      |      |      |
 * |------+------+------+------+------+------| TRNS  |    | TRNS  |------+------+------+------+------+------|
   | TRNS | V_FS | T_FS |      |      |      |-------|    |-------|      |      |   (  |   )  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | / TRNS  /       \ TRNS \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMS] = LAYOUT(
  LCTL(KC_W), LALT(KC_A), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  _______,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  _______,    KC_EXLM,    KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                          KC_CIRC,  KC_AMPR,  KC_ASTR,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  _______,    V_FS,       T_FS,     XXXXXXX,  XXXXXXX,  XXXXXXX,   _______,    _______,   XXXXXXX,  XXXXXXX,  KC_LPRN,  KC_RPRN,  XXXXXXX,  XXXXXXX,
              _______,    _______,  _______,  _______,  _______,                          _______, _______,   _______,  _______,  _______
),

/* MDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | TRNS |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |VOLUP |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|MUTE  | PREV | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|VOLDN |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |Reset |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_MDIA] = LAYOUT(
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     KC_VOLU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______, KC_VOLD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET
),

/* NPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | HOME |N Lck |  /   |  *   |  -   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | End  |  7   |  8   |  9   |  +   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShft |Pg Up |  4   |  5   |  6   |  ,   |-------.    ,-------|  UP  | DOWN | LEFT |RIGHT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCtrl |Pg Dn |  1   |  2   |  3   |  =   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS |  0   |  .   |ENTER | / TRNS  /       \      \  |      |      |      | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_NPAD] = LAYOUT(
  KC_ESC,   KC_HOME,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
  KC_TAB,   KC_END,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
  KC_LSFT,  KC_PGUP,  KC_P4,    KC_P5,    KC_P6,    KC_PCMM,                      KC_DOWN,  KC_UP,    KC_LEFT,  KC_RIGHT,  XXXXXXX,  XXXXXXX,
  KC_LCTL,  KC_PGDN,  KC_P1,    KC_P2,    KC_P3,    KC_PEQL,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
            _______,  KC_P0,    KC_PDOT,  KC_PENT,  _______,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   _______
),

/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | MEDIA|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   T  |Alt/Tb|   Q  |   W  |   E  |   R  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------|------+------+------+------+------+                    |------+------+------+------+------+------|
 * |   G  |LShift|   A  |   S  |   D  |   F  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------|------+------+------+------+------+       |    |       |------+------+------+------+------+------|
 * |   B  |LCtrl |   Z  |   X  |   C  |   V  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \Enter \-----------------------------------------'
 *            | TRNS |      |      | LAlt | /Space  /       \      \  |PrnScr|      |      | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_GAME] = LAYOUT(
  KC_ESC,  KC_1,            KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,       KC_7,       KC_8,          KC_9,          KC_0,          KC_BSPC,
  KC_T,    KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,                        RCTL(KC_Y), RCTL(KC_U), RCTL(KC_I),    RCTL(KC_O),    RCTL(KC_P),    KC_PGUP,
  KC_G,    KC_LSFT,         KC_A,    KC_S,    KC_D,    KC_F,                        RCTL(KC_H), RCTL(KC_J), RCTL(KC_K),    RCTL(KC_L),    RCTL(KC_SCLN), KC_PGDN,
  KC_B,    KC_LCTRL,        KC_Z,    KC_X,    KC_C,    KC_V,  _______,    _______,  RCTL(KC_N), RCTL(KC_M), RCTL(KC_COMM), RCTL(KC_DOT),  RCTL(KC_SLSH), KC_RIGHT,
           _______,         XXXXXXX, XXXXXXX, KC_LALT, _______,                     _______,    _______,    KC_PSCR,       _______,       _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _COMP1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LCTRL) SS_DELAY(100) SS_TAP(X_LCTRL) SS_DELAY(100) "1");
            }
            return false;
        case _COMP2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LCTRL) SS_DELAY(100) SS_TAP(X_LCTRL) SS_DELAY(100) "2");
            }
            return false;
        case V_FS:
            if (record->event.pressed) {
                SEND_STRING(",\n");
            }
            return false;
        case T_FS:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("a") "\n");
            }
            return false;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_THME:
        case KC_TPLY:
            return TAPPING_TERM + 250;
        default:
            return TAPPING_TERM;
    }
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
