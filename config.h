/*
Copyright KM_2023 Hannah Blythe Morrison

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Tapping config.

#define PERMISSIVE_HOLD
#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

// Tapping timings.

#define TAPPING_TERM 190
#define TAPPING_TERM_MODS 700
#define TAPPING_TERM_LAYER 150

// Combo timings.

#define COMBO_TERM 25
#define COMBO_TERM_CROSS_SPLIT 50

// Capsword.

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 10000 // ten seconds

// Enable better behaved scroll wheel emulation.

#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_INTERVAL 70
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80

// Layout macros that allow preprocessor substitutions. Use these instead of the
// standard LAYOUT_ macros in keymap.c code. For example, the following will
// define the base layer for a Ferris Sweep keyboard: [LAYER_BASE] =
// FK_LAYOUT_ferris_sweep( LAYOUT_BASE ),

#define FK_LAYOUT_ferris_sweep(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define FK_LAYOUT_planck(...) LAYOUT_planck_grid(__VA_ARGS__)
#define FK_LAYOUT_zilpzalp(...) LAYOUT(__VA_ARGS__)

// Logic for extra keys that will be defined in the base layer, and spacers that
// will be used in other layers to make them the same size. Spacers for the test
// platform are used to ensure that the test platform always has 34 / 48 keys
// defined.

#ifdef FK_TOP_OUTER
#define KC_BASE_Q KC_Q,
#define KC_BASE_BSPC ,KC_BSPC
#define KC_SYM_EXLM KC_EXLM,
#define SPACER_TL KC_NO,
// Top right spacer is transparent so that other layers can access expanded
// backspace key.
#define SPACER_TR ,KC_TRNS
#define TEST_TL
#define TEST_TR
#else
#define KC_BASE_Q
#define KC_BASE_BSPC
#define KC_SYM_EXLM
#define SPACER_TL
#define SPACER_TR
#define TEST_TL KC_NO,
#define TEST_TR ,KC_NO
#endif

#ifdef FK_MDL_OUTER
#define KC_BASE_A KC_A_SYM_LEFT,
#define KC_BASE_O ,KC_O_SYM_RIGHT
#define SPACER_ML KC_NO,
#define SPACER_MR ,KC_NO
// Middle left and right spacers on the sym layers are transparent to accomodate
// the expanded layer keys.
#define SYM_SPACER_ML KC_TRNS,
#define SYM_SPACER_MR ,KC_TRNS
#define TEST_ML
#define TEST_MR
#else
#define KC_BASE_A
#define KC_BASE_O
#define SPACER_ML
#define SPACER_MR
#define SYM_SPACER_ML
#define SYM_SPACER_MR
#define TEST_ML KC_NO,
#define TEST_MR ,KC_NO
#endif

#ifdef FK_BTM_OUTER
#define KC_BASE_Z KC_Z_SYM_LEFT,
#define KC_BASE_SLSH ,KC_SLSH_SYM_RIGHT
#define SPACER_BL KC_NO,
#define SPACER_BR ,KC_NO
// Bottom left and right spacers on the sym layers are transparent to accomodate
// the expanded layer keys.
#define SYM_SPACER_BL KC_TRNS,
#define SYM_SPACER_BR ,KC_TRNS
// Bottom right spacer on the num layer is transparent so that expanded slash
// key is available.
#define NUM_SPACER_BR ,KC_TRNS
#define TEST_BL
#define TEST_BR
#else
#define KC_BASE_Z
#define KC_BASE_SLSH
#define SPACER_BL
#define SPACER_BR
#define SYM_SPACER_BL
#define SYM_SPACER_BR
#define NUM_SPACER_BR
#define TEST_BL KC_NO,
#define TEST_BR ,KC_NO
#endif

#ifdef FK_TOP_INNER
#define KC_BASE_B ,KC_B
#define KC_BASE_J KC_J,
#define KC_SYM_PERC KC_PERC, KC_NO,
#define KC_SYM_CIRC KC_NO, KC_CIRC,
#define SPACER_TI KC_NO, KC_NO,
#define TEST_TI
#else
#define KC_BASE_B
#define KC_BASE_J
#define KC_SYM_PERC
#define KC_SYM_CIRC
#define SPACER_TI
#define TEST_TI KC_NO, KC_NO,
#endif

#ifdef FK_MDL_INNER
#define KC_BASE_G ,KC_G
#define KC_BASE_M KC_M,
#define SPACER_MI KC_NO, KC_NO,
#define TEST_MI
#else
#define KC_BASE_G
#define KC_BASE_M
#define SPACER_MI
#define TEST_MI KC_NO, KC_NO,
#endif

#ifdef FK_BTM_INNER
#define KC_BASE_V ,KC_V
#define KC_BASE_K KC_K,
#define SPACER_BI KC_NO, KC_NO,
#define TEST_BI
#else
#define KC_BASE_V
#define KC_BASE_K
#define SPACER_BI
#define TEST_BI KC_NO, KC_NO,
#endif

#ifdef FK_TWO_THUMBKEYS
#define KM_THUMB_TRNS_L KC_TRNS, KC_TRNS
#define KM_THUMB_TRNS_R KC_TRNS, KC_TRNS
#define TEST_THL
#define TEST_THR
#else
#define KM_THUMB_TRNS_L KC_TRNS
#define KM_THUMB_TRNS_R KC_TRNS
#define TEST_THL KC_NO,
#define TEST_THR ,KC_NO
#endif

#define KM_THUMB_TRNS KM_THUMB_TRNS_L, KM_THUMB_TRNS_R
