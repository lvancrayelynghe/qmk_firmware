/*
 * qmk flash -kb kingly_keys/romac -km gbotin
 */

#include QMK_KEYBOARD_H
#include "keymap_french.h"

#define OPT_KP0 LT(_OPT, KC_P0)
#define TAPPING_TERM 50
#define FN_LAYER_TAP_COUNT 3

enum layers {
    _BASE = 0,
    _OPT,
    _FN,
};

enum tap_dances {
    TD_FN = 0,
    TD_BE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_KP_7, KC_KP_8, KC_KP_9,  \
        KC_KP_4, KC_KP_5, KC_KP_6,  \
        KC_KP_1, KC_KP_2, KC_KP_3,  \
        OPT_KP0, FR_DOT,  TD(TD_FN) \
    ),

    [_OPT] = LAYOUT(
        KC_PSLS, KC_PAST, TD(TD_BE),\
        FR_LPRN, FR_RPRN, KC_PPLS,  \
        _______, _______, KC_PMNS,  \
        _______, FR_COMM, KC_PEQL   \
    ),

    [_FN] = LAYOUT(
        KC_F7,   KC_F8,   KC_F9,    \
        KC_F4,   KC_F5,   KC_F6,    \
        KC_F1,   KC_F2,   KC_F3,    \
        KC_F10,  _______, TO(_BASE) \
    )
};

void dance_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == FN_LAYER_TAP_COUNT) {
        layer_move(_FN);
        return;
    }

    register_code(KC_ENT);
}

void dance_func_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == FN_LAYER_TAP_COUNT) {
        return;
    }

    unregister_code(KC_ENT);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BE] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_ESC),
    [TD_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_func_finished, dance_func_reset)
};
