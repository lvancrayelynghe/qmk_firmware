/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#define UNUSED_PINS { F4 }

#ifdef OLED_DRIVER_ENABLE
    #undef OLED_FONT_H
    #define OLED_FONT_H "keymaps/fractory/lib/glcdfont_fractory.c"
#endif

#ifdef MOUSEKEY_ENABLE
    #define MOUSEKEY_WHEEL_DELAY 0
#endif

#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { D4 }
    #define ENCODERS_PAD_B { F5 }
    #define ENCODERS_PAD_A_RIGHT { F5 }
    #define ENCODERS_PAD_B_RIGHT { D4 }
//   #define ENCODER_RESOLUTION 2 // Tune encoder resolution
//   #define ENCODER_DIRECTION_FLIP // Switch encoder’s directions
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 70
    #define RGBLED_SPLIT { 35, 35 }
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_LIMIT_VAL 80
    #define RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_HUE_STEP 16 // number of steps to cycle through the hue by
    #define RGBLIGHT_SAT_STEP 16 // number of steps to increment the saturation by
    #define RGBLIGHT_VAL_STEP 8 // number of steps to increment the brightness by
    #define RGBLIGHT_SLEEP //  the RGB lighting will be switched off when the host goes to sleep
    #define RGBLIGHT_LAYERS
#endif

 /* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
