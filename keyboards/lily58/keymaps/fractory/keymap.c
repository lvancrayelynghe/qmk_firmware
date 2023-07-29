#include QMK_KEYBOARD_H

#include "keymap_french_osx.h"

#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif

#ifdef SSD1306OLED
    #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
    extern rgblight_config_t rgblight_config;
    rgblight_config_t        RGB_current_config;
#endif

extern uint8_t is_master;
extern bool is_keyboard_left(void);

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;
unsigned int cmd_tab_delay = 2000;

enum layer_names {
    _AZERTY,
    _LOWER,
    _RAISE,
    _SHIFTED,
    _SUPER,
    _FUNC,
    _ADJUST
};

enum custom_keycodes {
    AZERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

#define FT_LSFT LM(_SHIFTED, MOD_LSFT)
#define FT_SUPE LM(_SUPER, MOD_LGUI)
#define FT_FUNC MO(_FUNC)

// // À É È MAJ

// FT_LWRD // move left word
// FT_RWRD // move right word

// FT_DFWD // del fw
// FT_DBWD // del bw

#define FT_CHRM HYPR(FR_C)
#define FT_CODE HYPR(FR_V)
#define FT_SLCK HYPR(FR_S)
#define FT_TERM HYPR(FR_T)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* AZERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   (  |                    |   )  |   &  |   *  |   -   |  =  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   a  |   z  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   q  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   ,  |   '  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |   w  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   m  |   ,  |   .  |   /  |  Fn |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_AZERTY] = LAYOUT( \
  KC_ESC,  FR_EXLM, FR_AT,   FR_HASH,  FR_DLR, FR_LPRN,                   FR_RPRN, FR_AMPR, FR_ASTR, FR_MINS, FR_EQL,  KC_BSPC, \
  KC_TAB,  FR_A,    FR_Z,    FR_E,     FR_R,   FR_T,                      FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    KC_DEL,  \
  FT_LSFT, FR_Q,    FR_S,    FR_D,     FR_F,   FR_G,                      FR_H,    FR_J,    FR_K,    FR_L,    FR_SCLN, FR_QUOT, \
  KC_LCTL, FR_W,    FR_X,    FR_C,     FR_V,   FR_B,    XXXXXXX, XXXXXXX, FR_N,    FR_M,    FR_COMM, FR_DOT,  FR_SLSH, FT_FUNC, \
                             KC_LALT,  FT_SUPE, LOWER,  KC_SPC,  KC_ENT,  RAISE,   _______, _______  \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   ^  |      |      |   €  |   [  |                    |   ]  |      |   °  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   é  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  FR_GRV,  FR_CIRC, _______, _______, FR_EURO, FR_LBRC,                   FR_RBRC, _______, FR_DEG,  _______, _______, _______,  \
  _______, _______, _______, FR_LEAC, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, FR_LCCE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ~  |   ¨  |      |      |   £  |   {  |                    |   }  |      |   %  |   _  |   +  |Del Bw|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   à  |      |   è  |      |      |                    |      |   ù  |      |      |      |Del Fw|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |   :  |   "  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  FR_TILD, FR_DIAE, _______, _______, FR_PND,  FR_LCBR,                   FR_RCBR, _______, FR_PERC, FR_UNDS, FR_PLUS, _______,  \
  _______, FR_LAGR, _______, FR_LEGR, _______, _______,                   _______, FR_LUGR, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, FR_COLN, FR_DQUO, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, FR_LABK, FR_RABK, FR_QUES, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* SHIFTED
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SHIFTED] = LAYOUT( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______  \
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
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SUPER] = LAYOUT( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  lBn |  mUp |  rBn |      |  whD |                    |      | Vol- | Vol+ | MUTE | Pl/Pa|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  mLt |  mDn | mRt  |      |  whU |-------.    ,-------|      | RGB  | HUE+ | SAT+ | VAL+ |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MODE | HUE- | SAT- | VAL- |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______, _______, _______, _______, _______,                   _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, \
                             _______, _______, _______, _______, _______, _______, _______, RESET    \
),

/* FUNC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUNC] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, FT_TERM,                   _______, _______, _______, _______, _______, _______, \
  _______, FT_SLCK, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, FT_CHRM, FT_CODE, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

/* RGB IDs

        11 10 09 08 07 06         41 42 43 44 45 46
        12 13 14 15 16 17         52 51 50 49 48 47
        23 22 21 20 19 18         53 54 55 56 57 58
        24 25 26 27 28 29 30   65 64 63 62 61 60 59
              34 33 32 31         66 67 68 69

        03 04 05                           40 39 38
        02 01 00                           35 36 37
*/

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {  6,  5, HSV_WHITE },
    { 13,  5, HSV_WHITE }
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 41,  5, HSV_WHITE },
    { 47,  5, HSV_WHITE }
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {  6,  5, HSV_WHITE },
    { 13,  5, HSV_WHITE },
    { 41,  5, HSV_WHITE },
    { 47,  5, HSV_WHITE }
);

const rgblight_segment_t PROGMEM func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {  6,  5, HSV_RED },
    { 13,  5, HSV_RED },
    { 41,  5, HSV_RED },
    { 47,  5, HSV_RED }
);

const rgblight_segment_t PROGMEM shift_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    { 65, 1, HSV_CORAL }
);

const rgblight_segment_t PROGMEM control_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    { 65, 1, HSV_CHARTREUSE }
);

const rgblight_segment_t PROGMEM alt_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    { 65, 1, HSV_CYAN }
);

const rgblight_segment_t PROGMEM gui_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    { 65, 1, HSV_GOLD }
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer,
    raise_layer,
    adjust_layer,
    func_layer,

    shift_layers,
    control_layers,
    alt_layers,
    gui_layers
);

#ifdef RGBLIGHT_ENABLE
void save_rgb_config(void) {
    RGB_current_config.enable = rgblight_config.enable;
    RGB_current_config.mode   = rgblight_config.mode;
    RGB_current_config.speed  = rgblight_config.speed;
    RGB_current_config.hue    = rgblight_config.hue;
    RGB_current_config.sat    = rgblight_config.sat;
    RGB_current_config.val    = rgblight_config.val;
}

void restore_rgb_config(void) {
    rgblight_set_speed_noeeprom(RGB_current_config.speed);

    if (rgblight_config.mode != RGB_current_config.mode) {
        rgblight_mode_noeeprom(RGB_current_config.mode);
    }

    if ((RGB_current_config.hue != rgblight_config.hue) || (RGB_current_config.sat != rgblight_config.sat) || (RGB_current_config.val != rgblight_config.val)) {
        rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat, RGB_current_config.val);
    }

    if (rgblight_config.enable) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_disable_noeeprom();
    }
}
#endif

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;

    save_rgb_config();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, !layer_state_cmp(state, _ADJUST) && layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, !layer_state_cmp(state, _ADJUST) && layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FUNC));

    return state;
}

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (layer_state_is(layer1) && layer_state_is(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

void matrix_scan_user(void) {
    if (is_cmd_tab_active) {
        if (timer_elapsed(cmd_tab_timer) > cmd_tab_delay) {
            unregister_code(KC_LCMD);
            is_cmd_tab_active = false;
        }
    }

    uint8_t mods = mod_config(get_mods()|get_oneshot_mods());
    rgblight_set_layer_state(4, mods & MOD_MASK_SHIFT);
    rgblight_set_layer_state(5, mods & MOD_MASK_CTRL);
    rgblight_set_layer_state(6, mods & MOD_MASK_ALT);
    rgblight_set_layer_state(7, mods & MOD_MASK_GUI);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
void set_timelog(void);
const char *read_timelog(void);

void oled_task_user(void) {
    if (is_keyboard_left()) {
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        set_timelog();
    }

    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }

            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }

            return false;
            break;
        case RGB_MOD:
        case RGB_TOG:
        case RGB_HUI:
        case RGB_HUD:
        case RGB_SAI:
        case RGB_SAD:
        case RGB_VAI:
        case RGB_VAD:
        case RGB_SPI:
        case RGB_SPD:
            /* Override layer-based RGB and resume RGB effect to be able to preview changes */
            if (! record->event.pressed) {
                restore_rgb_config();
                // Split keyboards need to trigger on key-up for edge-case issue
                // See : quantum/process_keycode/process_rgb.c#L58
                process_rgb(keycode, record);
                save_rgb_config();
            }
            return false;
    }

    return true;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_AZERTY)) {
        register_code(KC_LCTRL);

        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }

        unregister_code(KC_LCTRL);
        return;
    }

    if (IS_LAYER_ON(_RAISE)) {
        if (!is_cmd_tab_active) {
            is_cmd_tab_active = true;
            register_code(KC_LCMD);
        }

        cmd_tab_timer = timer_read();

        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            register_code(KC_LSHIFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSHIFT);
        }
    }
}
#endif // ENCODER_ENABLE
