#include QMK_KEYBOARD_H

// #include "keymap_french_osx.h"

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
unsigned int cmd_tab_delay = 500;

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   &  |   é  |   "  |   '  |   (  |                    |   §  |   è  |   !  |   ç  |   à  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   Q  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   M  |  '   |
 * |------+------+------+------+------+------|   [   |    |       |------+------+------+------+------+------|
 * |LCTRL |   W  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   ,  |   ;  |   :  |   =  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LSFT,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, _______, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   à  |      |  è   |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   [   |    |       |------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
  _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      | pUp  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      | pDn  |
 * |------+------+------+------+------+------|   [   |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_WH_D, \
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_WH_U, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, XXXXXXX,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
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
    // { 18,  5, HSV_WHITE }
    // { 35, 35, HSV_WHITE }
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 41,  5, HSV_WHITE },
    { 47,  5, HSV_WHITE }
    // { 53,  5, HSV_WHITE }
    // {  0, 35, HSV_WHITE }
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {  6,  5, HSV_WHITE },
    { 13,  5, HSV_WHITE },
    // { 18,  5, HSV_WHITE },
    { 41,  5, HSV_WHITE },
    { 47,  5, HSV_WHITE }
    // { 53,  5, HSV_WHITE }
);

const rgblight_segment_t PROGMEM shift_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    // { 31, 1, HSV_CORAL },
    // { 66, 1, HSV_CORAL }
    { 65, 1, HSV_CORAL }
);

const rgblight_segment_t PROGMEM control_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    // { 31, 1, HSV_CHARTREUSE },
    // { 66, 1, HSV_CHARTREUSE }
    { 65, 1, HSV_CHARTREUSE }
);

const rgblight_segment_t PROGMEM alt_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    // { 31, 1, HSV_CYAN },
    // { 66, 1, HSV_CYAN }
    { 65, 1, HSV_CYAN }
);

const rgblight_segment_t PROGMEM gui_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    // { 31, 1, HSV_GOLD },
    // { 66, 1, HSV_GOLD }
    { 65, 1, HSV_GOLD }
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer,
    raise_layer,
    adjust_layer,

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
    if (layer_state_cmp(state, _QWERTY)) {
        restore_rgb_config();
    }

    rgblight_set_layer_state(0, !layer_state_cmp(state, _ADJUST) && layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, !layer_state_cmp(state, _ADJUST) && layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _RAISE));

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
    rgblight_set_layer_state(3, mods & MOD_MASK_SHIFT);
    rgblight_set_layer_state(4, mods & MOD_MASK_CTRL);
    rgblight_set_layer_state(5, mods & MOD_MASK_ALT);
    rgblight_set_layer_state(6, mods & MOD_MASK_GUI);
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
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }

            return false;
            break;
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
    if (IS_LAYER_ON(_QWERTY)) {
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
