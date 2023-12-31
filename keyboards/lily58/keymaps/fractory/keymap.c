#include QMK_KEYBOARD_H

#include "keymap_french_mac_iso.h"

enum layer_names {
    _AZERTY = 0,
    _SHIFTED,
    _LOWER,
    _RAISE,
    _SUPER,
    _ADJUST,
    _FUNC,
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

// @todo
// Super Layout
// FastApp
// open close parenthesis macro
// paste style

#define FT_LOWE MO(_LOWER)
#define FT_RAIS MO(_RAISE)
#define FT_LSFT LM(_SHIFTED, MOD_LSFT)
#define FT_SUPE LM(_SUPER, MOD_LGUI)
#define FT_FUNC MO(_FUNC)

#define FT_SCR1 C(G(S(KC_4)))   // "⌃ ⇧ ⌘ 4"
#define FT_SCR2 G(S(KC_4))      // "  ⇧ ⌘ 4"
#define FT_SCR3 C(G(S(KC_3)))   // "⌃ ⇧ ⌘ 3"
#define FT_SCR4 G(S(KC_3))      // "  ⇧ ⌘ 3"
#define FT_SCR0 G(S(KC_5))      // "  ⇧ ⌘ 5"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* AZERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   -   |  =  |Del Bw|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   a  |   z  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  |Del Fw|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   q  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------|   (   |    |   )   |------+------+------+------+------+------|
 * |LCTRL |   w  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   m  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | GUI  |LOWER | /Space  /       \Enter \  |RAISE | GUI  | FUNC |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_AZERTY] = LAYOUT(                                                                                                               \
    QK_GESC, FR_EXLM, FR_AT,   FR_HASH, FR_DLR,  FR_PERC,                   FR_CIRC, FR_AMPR, FR_ASTR, FR_MINS, FR_EQL,  KC_BSPC, \
    KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,                      FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    KC_DEL,  \
    FT_LSFT, FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,                      FR_H,    FR_J,    FR_K,    FR_L,    FR_SCLN, FR_QUOT, \
    KC_LCTL, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_LPRN, FR_RPRN, FR_N,    FR_M,    FR_COMM, FR_DOT,  FR_SLSH, FR_BSLS, \
                               KC_LALT, FT_SUPE, FT_LOWE, KC_SPC,  KC_ENT,  FT_RAIS, FT_SUPE, FT_FUNC                             \
),

/* SHIFTED
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|   <   |    |   >   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      | CAPS |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SHIFTED] = LAYOUT(                                                                                                              \
    _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_5,                      FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, FT_COLN, FT_DQUO, \
    _______, _______, _______, _______, _______, _______, FT_LABK, FT_RABK, _______, _______, FT_LABK, FT_RABK, FR_QUES, FR_PIPE, \
                               _______, _______, _______, _______, _______, _______, _______, KC_CAPS                             \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |   £  |      |                    |  °   |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   é  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |   `  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |-------|    |-------|      |      |      |      |      |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT(                                                                                                                \
    FR_GRV,  _______, _______, _______, FR_PND,  _______,                   FR_DEG,  _______, _______, _______, _______, _______,  \
    _______, _______, _______, FT_LEAC, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, FR_GRV,  \
    _______, _______, _______, FT_LCCE, _______, _______, FR_LBRC, FR_RBRC, _______, _______, _______, _______, _______, FR_PIPE, \
                               _______, _______, _______, _______, _______, _______, _______, _______                             \
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ~  |      |      |      |   €  |      |                    |  ¨   |      |      |   _  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   à  |      |   è  |      |      |                    |      |   ù  |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |   :  |   "  |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(                                                                                                                \
    FR_TILD, _______, _______, _______, FR_EURO, _______,                   FR_DIAE, _______, _______, FR_UNDS, FR_PLUS, _______, \
    _______, FT_LAGR, _______, FT_LEGR, _______, _______,                   _______, FT_LUGR, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, FT_COLN, FT_DQUO, \
    _______, _______, _______, _______, _______, _______, FR_LCBR, FR_RCBR, _______, _______, FT_LABK, FT_RABK, FR_QUES, FR_PIPE, \
                               _______, _______, _______, _______, _______, _______, _______, _______                             \
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
// @fractodo
[_SUPER] = LAYOUT(                                                                                                                \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, _______, _______, _______, _______, _______                             \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      | Pl/Pa|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Bri- | Vol- | Vol+ | Bri+ |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MUTE |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      | BOOT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_ADJUST] = LAYOUT(                                                                                                               \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_MPLY, _______, \
    _______, _______, _______, _______, _______, _______,                   KC_BRMD, KC_VOLD, KC_VOLU, KC_BRMU, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, \
                               _______, _______, _______, _______, _______, _______, _______, QK_BOOT                             \
),

/* FUNC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | SCR1 | SCR2 | SCR3 | SCR4 |      |                    |      |      |      |      | SCR0 |!Rpeat|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  H_a |  H_z |  H_e |  H_r |  H_t |                    |  H_y |  H_u |  H_i |  H_o |  H_p | Rpeat|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPW |  H_q |  H_s |  H_d |  H_f |  H_g |-------.    ,-------|  H_h |  H_j |  H_k |  H_l |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  H_w |  H_x |  H_c |  H_v |  H_b |-------|    |-------|  H_n |  H_m |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_FUNC] = LAYOUT(                                                                                                                                               \
    _______, FT_SCR1,    FT_SCR2,    FT_SCR3,    FT_SCR4,    _______,                      _______,    _______,    _______,    _______,    FT_SCR0,    QK_AREP, \
    _______, HYPR(FR_A), HYPR(FR_Z), HYPR(FR_E), HYPR(FR_R), HYPR(FR_T),                   HYPR(FR_Y), HYPR(FR_U), HYPR(FR_I), HYPR(FR_O), HYPR(FR_P), QK_REP,  \
    CW_TOGG, HYPR(FR_Q), HYPR(FR_S), HYPR(FR_D), HYPR(FR_F), HYPR(FR_G),                   HYPR(FR_H), HYPR(FR_J), HYPR(FR_K), HYPR(FR_L), _______,    _______, \
    _______, HYPR(FR_W), HYPR(FR_X), HYPR(FR_C), HYPR(FR_V), HYPR(FR_B), _______, _______, HYPR(FR_N), HYPR(FR_M), _______,    _______,    _______,    _______, \
                                     _______,    _______,    _______,    _______, _______, _______,    _______,    _______                                      \
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
