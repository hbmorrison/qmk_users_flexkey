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

// Tapping terms.

#define PERMISSIVE_HOLD
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 190
#define TAPPING_TERM_MODS 900
#define TAPPING_TERM_LAYER 150

// Capsword.

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 10000 // ten seconds

// Layout macros that allow preprocessor substitutions. Use these instead of the
// standard LAYOUT_ macros in keymap.c code. For example, the following will
// define the base layer for a Ferris Sweep keyboard:
//   [LAYER_BASE] = FK_LAYOUT_ferris_sweep( LAYOUT_BASE ),

#define FK_LAYOUT_ferris_sweep(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define FK_LAYOUT_zilpzalp(...) LAYOUT(__VA_ARGS__)

// Spacing keycodes for non-base layers so they match the base layer format, and
// Ferris Sweep test platform spacers that fill in the blanks to make up a 3x5+2
// layout.

#ifdef FK_TOP_OUTER
#define SPACER_TL KC_NO,
#define SPACER_TR ,KC_NO
#define FERRIS_TL
#define FERRIS_TR
#else
#define SPACER_TL
#define SPACER_TR
#define FERRIS_TL KC_NO,
#define FERRIS_TR ,KC_NO
#endif

#ifdef FK_MDL_OUTER
#define SPACER_ML KC_NO,
#define SPACER_MR ,KC_NO
#define FERRIS_ML
#define FERRIS_MR
#else
#define SPACER_ML
#define SPACER_MR
#define FERRIS_ML KC_NO,
#define FERRIS_MR ,KC_NO
#endif

#ifdef FK_BTM_OUTER
#define SPACER_BL KC_NO,
#define SPACER_BR ,KC_NO
#define FERRIS_BL
#define FERRIS_BR
#else
#define SPACER_BL
#define SPACER_BR
#define FERRIS_BL KC_NO,
#define FERRIS_BR ,KC_NO
#endif

#ifdef FK_TOP_INNER
#define SPACER_TI KC_NO, KC_NO,
#define FERRIS_TI
#else
#define SPACER_TI
#define FERRIS_TI KC_NO, KC_NO,
#endif

#ifdef FK_MDL_INNER
#define SPACER_MI KC_NO, KC_NO,
#define FERRIS_MI
#else
#define SPACER_MI
#define FERRIS_MI KC_NO, KC_NO,
#endif

#ifdef FK_BTM_INNER
#define SPACER_BI KC_NO, KC_NO,
#define FERRIS_BI
#else
#define SPACER_BI
#define FERRIS_BI KC_NO, KC_NO,
#endif

#ifdef FK_THUMB_OUTER
#define FERRIS_THL
#define FERRIS_THR
#else
#define FERRIS_THL KC_NO,
#define FERRIS_THR ,KC_NO
#endif
