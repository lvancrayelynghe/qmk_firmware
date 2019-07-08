#include QMK_KEYBOARD_H

// #include "keymap_french.h"
#include "keymap_french_osx.h"

enum layers {
  _AZERTY = 0,
  _LOWER,
  _RAISE,
  _FN1,
  _FN2,
  _FN3,
};

enum custom_macros {
  _WD_SLC = 0,
  _LN_SLC,
  _LN_DEL,
  _LN_DUP,
};

enum tap_dances {
  TD_SHIFT_CAPS = 0,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FN1    MO(_FN1)
#define FN2    MO(_FN2)
#define FN3    MO(_FN3)

/* Custom Macros */
#define WD_SLC M(_WD_SLC)
#define LN_SLC M(_LN_SLC)
#define LN_DEL M(_LN_DEL)
#define LN_DUP M(_LN_DUP)

/* Custom FR_OSX Overrides */
#define MY_EURO LALT(FR_DLR)
#define MY_HASH LALT(LSFT(FR_GRV))
#define MY_AT   LALT(FR_GRV)
#define MY_DEG  LSFT(FR_RPRN)
#define MY_LABK FR_AT
#define MY_RABK LSFT(FR_AT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   ;  |   :  |  Up  | FN3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN1 | Ctrl | Alt  | GUI  | Lower|    Space    | Raise| FN2  | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_planck_mit( \
  KC_ESC,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    FR_M,    KC_ENT,  \
  TD(TD_SHIFT_CAPS), FR_W,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    FR_COMM, FR_SCLN, FR_COLN, KC_UP,   FN3,     \
  FN1,     KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   FN2,     KC_LEFT, KC_DOWN, KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   à  |      |   è  |      |      |      |   ù  |   (  |   )  |   _  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   €  |      |      |   #  |   |  |   {  |   }  |   ^  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   '  |   "  |   `  |      |      |   ~  |   !  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | HOLD |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit( \
  _______, FR_AGRV, _______, FR_EGRV, _______, _______, _______, FR_UGRV, FR_LPRN, FR_RPRN, FR_UNDS, _______, \
  _______, _______, _______, MY_EURO, _______, _______, MY_HASH, FR_PIPE, FR_LCBR, FR_RCBR, FR_CIRC, _______, \
  _______, FR_APOS, FR_QUOT, FR_GRV,  _______, _______, FR_TILD, FR_EXLM, FR_LBRC, FR_RBRC, _______, _______, \
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   @  |      |   é  |      |      |      |      |   *  |   +  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   $  |      |      |      |      |   /  |   %  |   =  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |   °  |   &  |   <  |   >  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | HOLD |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit( \
  _______, MY_AT,   _______, FR_EACU, _______, _______, _______, _______, FR_ASTR, FR_PLUS, FR_MINS, _______, \
  _______, _______, _______, FR_DLR,  _______, _______, _______, _______, FR_SLSH, FR_PERC, FR_EQL,  _______, \
  _______, _______, _______, FR_CCED, _______, _______, MY_DEG,  FR_AMP,  MY_LABK, MY_RABK, _______, _______, \
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______  \
),

/* Fn1
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  lC  |  mU  |  rC  |  sU  |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  mL  |  mD  |  mR  |  sD  |      |      |   1  |   2  |   3  |  pUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | HOLD |      |      |      |      |             |   0  |   .  | Home |  pDn |  End |
 * `-----------------------------------------------------------------------------------'
 *
 * TODO : Mouse acceleration / constant
 */

[_FN1] = LAYOUT_planck_mit( \
  _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    KC_DEL,  \
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_D, _______, _______, FR_4,    FR_5,    FR_6,    _______, _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, _______, FR_1,    FR_2,    FR_3,    KC_PGUP, _______, \
  _______, _______, _______, _______, _______,      _______,     FR_0,    FR_DOT,  KC_HOME, KC_PGDN, KC_END   \
),

/* Fn2
 * ,-----------------------------------------------------------------------------------.
 * | Lock |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  Tp  |  Tn  |  Tp  | Sleep|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |  v-  |  v+  |  vM  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  b-  |  b+  |  bT  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | HOLD |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_FN2] = LAYOUT_planck_mit( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_MRWD, KC_MFFD, KC_MPLY, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,  BL_TOGG, _______, \
  _______, _______, _______, _______, _______,      _______,     _______, _______, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Fn3
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 * TODO
 */

[_FN3] = LAYOUT_planck_mit( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, LN_DEL,  _______, _______, _______, _______, _______, LN_SLC,  _______, _______, \
  _______, WD_SLC,  _______, LN_DUP,  _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______  \
),

};

void matrix_init_user() {
    backlight_level(4);
    rgblight_disable();
}

// Loop
void matrix_scan_user(void) {
  // Empty
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t keycode, uint8_t opt) {
    if (record->event.pressed) {
      switch(keycode) {

        case _WD_SLC:
          SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LALT));
          return false;

        case _LN_SLC:
          SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSHIFT));
          return false;

        case _LN_DEL:
          SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSHIFT));
          SEND_STRING(SS_TAP(X_BSPACE));
          return false;

        case _LN_DUP:
          SEND_STRING(SS_LGUI("c") SS_TAP(X_RIGHT) SS_LGUI("v"));
          return false;
      }
    }

    return MACRO_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_sethsv(HSV_BLUE);
        layer_on(_LOWER);
      } else {
        rgblight_disable();
        layer_off(_LOWER);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_sethsv(HSV_GREEN);
        layer_on(_RAISE);
      } else {
        rgblight_disable();
        layer_off(_RAISE);
      }
      break;
    case FN1:
    case FN3:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_sethsv(HSV_RED);
        layer_on(_FN1);
      } else {
        rgblight_disable();
        layer_off(_FN1);
      }
      break;
    case FN2:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_sethsv(HSV_MAGENTA);
        layer_on(_FN2);
      } else {
        rgblight_disable();
        layer_off(_FN2);
      }
      break;
    default:
      return true;
  }

  return false;
}
