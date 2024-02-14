#include QMK_KEYBOARD_H

// @see https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_french_mac_iso.h
#include "keymap_french_mac_iso.h"

enum layer_names {
    _AZERTY = 0,
    _SHIFTED,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNC,
    _SUPER,
};

enum custom_keycodes {
    FT_LABK = SAFE_RANGE,
    FT_RABK,
    FT_DQUO,
    FT_COLN,
    FT_LEAC,
    FT_LCCE,
    FT_LAGR,
    FT_LEGR,
    FT_LUGR,
};

#define FT_LOWE MO(_LOWER)
#define FT_RAIS MO(_RAISE)
#define FT_FUNC MO(_FUNC)

#define FT_LSFT LM(_SHIFTED, MOD_LSFT)
#define FT_SUPE LM(_SUPER, MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* AZERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   -   |  =  | BkSp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   a  |   z  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   q  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   m  |   '  |
 * |------+------+------+------+------+------|   (   |    |   )   |------+------+------+------+------+------|
 * |LCTRL |   w  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   ;  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | GUI  |LOWER | /Space  /       \Enter \  |RAISE | CAPS | FUNC |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_AZERTY] = LAYOUT(                                                                                                               \
    QK_GESC, FR_EXLM, FR_AT,   FR_HASH, FR_DLR,  FR_PERC,                   FR_CIRC, FR_AMPR, FR_ASTR, FR_MINS, FR_EQL,  KC_BSPC, \
    KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,                      FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    KC_DEL,  \
    FT_LSFT, FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,                      FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_QUOT, \
    KC_LCTL, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_LPRN, FR_RPRN, FR_N,    FR_SCLN, FR_COMM, FR_DOT,  FR_SLSH, FR_BSLS, \
                               KC_LALT, FT_SUPE, FT_LOWE, KC_SPC,  KC_ENT,  FT_RAIS, KC_CAPS, FT_FUNC                             \
),

/* SHIFTED
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXX |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |   "  |
 * |------+------+------+------+------+------|   <   |    |   >   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   :  |   <  |   >  |   ?  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      | CAPS |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SHIFTED] = LAYOUT(                                                                                                              \
    _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_5,                      FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, FT_DQUO, \
    _______, _______, _______, _______, _______, _______, FT_LABK, FT_RABK, _______, FT_COLN, FT_LABK, FT_RABK, FR_QUES, FR_PIPE, \
                               _______, _______, _______, _______, _______, _______, _______, KC_CAPS                             \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |   £  |      |                    |  °   |      |      |   _  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   é  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |   `  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |-------|    |-------|      |      |      |      |      |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | XXXX |/       /         \      \ |      |      |      |
 *                   |      |      | XXXX | /       /       \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(                                                                                                                \
    FR_GRV,  _______, _______, _______, FR_PND,  _______,                   FR_DEG,  _______, _______, FR_UNDS, _______, _______,  \
    _______, _______, _______, FT_LEAC, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, FR_GRV,  \
    _______, _______, _______, FT_LCCE, _______, _______, FR_LBRC, FR_RBRC, _______, _______, _______, _______, _______, FR_PIPE, \
                               _______, _______, _______, _______, _______, _______, _______, _______                             \
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ~  |      |      |      |   €  |      |                    |  ¨   |      |      |  +   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   à  |  Up  |   è  |      |      |                    |      |   ù  |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |-------.    ,-------|      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |      |      |      |  Ç   |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  | XXXX |      |      |
 *                   |      |      |      |/       /         \      \ | XXXX  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(                                                                                                                \
    FR_TILD, _______, _______, _______, FR_EURO, _______,                   FR_DIAE, _______, _______, FR_PLUS, _______, _______, \
    _______, FT_LAGR, KC_UP,   FT_LEGR, _______, _______,                   _______, FT_LUGR, _______, _______, _______, _______, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______, _______, _______, _______, FT_COLN, FT_DQUO, \
    _______, _______, _______, FR_CCCE, _______, _______, FR_LCBR, FR_RCBR, _______, _______, FT_LABK, FT_RABK, FR_QUES, FR_PIPE, \
                               _______, _______, _______, _______, _______, _______, _______, _______                             \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Up  |  ê   |      |      |                    | Bri+ | Vol+ |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |-------.    ,-------| Bri- | Vol- | Pl/Pa|      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MUTE |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | XXXX | /       /       \      \  | XXXX |      | BOOT |
 *                   |      |      | XXXX |/       /         \      \ | XXXX |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(                                                                                                               \
    KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,   KC_F6,                           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, _______,    A(KC_UP),   FR_ECIR,    _______, _______,                         KC_BRMU, KC_VOLU, _______, _______, _______, _______, \
    _______, A(KC_LEFT), A(KC_DOWN), A(KC_RGHT), _______, _______,                         KC_BRMD, KC_VOLD, KC_MPLY, _______, _______, _______, \
    _______, _______,    _______,    _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, \
                                     _______, _______, _______, _______, _______, _______, _______, QK_BOOT                             \
),

/* FUNC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  H_& |  H_é |  H_" |  H_' |      |                    |      |      |      |      |      |!Rpeat|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  H_a |  H_z |  H_e |  H_r |  H_t |                    |  H_y |  H_u |  H_i |  H_o |  H_p | Rpeat|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPW |  H_q |  H_s |  H_d |  H_f |  H_g |-------.    ,-------|  H_h |  H_j |  H_k |  H_l |  H_m |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  H_w |  H_x |  H_c |  H_v |  H_b |-------|    |-------|  H_n |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUNC] = LAYOUT(                                                                                                                                               \
    _______, LCAG(KC_1), LCAG(KC_2), LCAG(KC_3), LCAG(KC_4), LCAG(KC_5),                      _______,    _______,    _______,    _______,    _______,    QK_AREP, \
    _______, LCAG(FR_A), LCAG(FR_Z), LCAG(FR_E), LCAG(FR_R), LCAG(FR_T),                   LCAG(FR_Y), LCAG(FR_U), LCAG(FR_I), LCAG(FR_O), LCAG(FR_P), QK_REP,  \
    CW_TOGG, LCAG(FR_Q), LCAG(FR_S), LCAG(FR_D), LCAG(FR_F), LCAG(FR_G),                   LCAG(FR_H), LCAG(FR_J), LCAG(FR_K), LCAG(FR_L), LCAG(FR_M), _______, \
    _______, LCAG(FR_W), LCAG(FR_X), LCAG(FR_C), LCAG(FR_V), LCAG(FR_B), _______, _______, LCAG(FR_N), _______,    _______,    _______,    _______,    _______, \
                                     _______,    _______,    _______,    _______, _______, _______,    _______,    _______                                      \
),

/* SUPER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SUPER] = LAYOUT(                                                                                                                \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, _______, _______, _______, _______, _______                             \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;

    return rotation;
}

const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
void set_timelog(void);
const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(" ", false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }

    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
        set_timelog();
#endif
    }

    switch (keycode) {
        case FT_LABK:
        {
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(FR_LABK);
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    register_code(FR_LABK);
                }
            } else {
                unregister_code(FR_LABK);
            }

            break;
        }

        case FT_RABK:
        {
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    register_code(FR_LABK);
                } else {
                    add_mods(MOD_BIT(KC_LSFT));
                    register_code(FR_LABK);
                    del_mods(MOD_MASK_SHIFT);
                }
            } else {
                unregister_code(FR_LABK);
            }

            break;
        }

        case FT_DQUO:
        {
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(FR_DQUO);
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    register_code(FR_DQUO);
                }
            } else {
                unregister_code(FR_DQUO);
            }

            break;
        }

        case FT_COLN:
        case FT_LEAC:
        case FT_LCCE:
        case FT_LAGR:
        case FT_LEGR:
        case FT_LUGR:
        {
            int modcode = keycode;

            switch(keycode) {
                case FT_COLN: modcode = FR_COLN; break;
                case FT_LEAC: modcode = FR_LEAC; break;
                case FT_LCCE: modcode = FR_LCCE; break;
                case FT_LAGR: modcode = FR_LAGR; break;
                case FT_LEGR: modcode = FR_LEGR; break;
                case FT_LUGR: modcode = FR_LUGR; break;
            }

            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_CAPS);
                    register_code(modcode);
                    wait_ms(TAP_HOLD_CAPS_DELAY);
                    tap_code(KC_CAPS);
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    register_code(modcode);
                }
            } else {
                unregister_code(modcode);
            }

            break;
        }
    }

    return true;
}
