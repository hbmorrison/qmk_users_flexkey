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

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Layers and layer aliases.

enum fk_layers {
  LAYER_BASE,
  LAYER_SYM_LEFT,
  LAYER_SYM_RIGHT,
  LAYER_EXT_LEFT,
  LAYER_EXT_RIGHT,
  LAYER_NAV,
  LAYER_NUM,
  LAYER_CTRLS,
  LAYER_FUNC,
  LAYER_SCUT
};

// Custom keycodes.

enum fk_keycodes {
  M_ALT_TAB = SAFE_RANGE,
  M_APP1,
  M_APP2,
  M_APP3,
  M_APP4,
  M_1PASS,
  M_NDESK,
  M_PDESK,
  M_EMOJI,
  M_4RAND,
  M_ISCROS,
  M_ISWIN,
};

// Alternative keys for UK ISO keyboard layouts.

#define KC_UK_DQUO LSFT(KC_2)
#define KC_UK_PND LSFT(KC_3)
#define KC_UK_PIPE LSFT(KC_NUBS)
#define KC_UK_BSLS KC_NUBS
#define KC_UK_AT LSFT(KC_QUOT)
#define KC_UK_TILDE LSFT(KC_BSLS)
#define KC_UK_HASH KC_BSLS

// Modified keys.

#define KC_SFT_TAB LSFT(KC_TAB)
#define KC_CTL_TAB LCTL(KC_TAB)

// Modifier keys in the style of homerow mods.

#define KC_W_ALT LALT_T(KC_W)
#define KC_R_CTL LCTL_T(KC_R)
#define KC_T_SFT LSFT_T(KC_T)
#define KC_P_GUI LGUI_T(KC_P)
#define KC_L_GUI LGUI_T(KC_L)
#define KC_N_SFT RSFT_T(KC_N)
#define KC_I_CTL LCTL_T(KC_I)
#define KC_Y_ALT LALT_T(KC_Y)

// Layer keys.

#define KC_X_SYM_LEFT LT(LAYER_SYM_LEFT, KC_X)
#define KC_S_EXT_LEFT LT(LAYER_EXT_LEFT, KC_S)
#define KC_F_CTRLS LT(LAYER_CTRLS, KC_F)
#define KC_U_FUNC LT(LAYER_FUNC, KC_U)
#define KC_E_EXT_RIGHT LT(LAYER_EXT_RIGHT, KC_E)
#define KC_DOT_SYM_RIGHT LT(LAYER_SYM_RIGHT, KC_DOT)
#define KC_SPC_NAV LT(LAYER_NAV, KC_SPC)
#define KC_ENT_NUM LT(LAYER_NUM, KC_ENT)
#define KC_SCUT OSL(LAYER_SCUT)

// Base layer for flexkey keyboards.

#define KM_BASE_1L KC_BASE_Q KC_W_ALT, KC_F_CTRLS, KC_P_GUI KC_BASE_B
#define KM_BASE_2L KC_BASE_A KC_R_CTL, KC_S_EXT_LEFT, KC_T_SFT KC_BASE_G
#define KM_BASE_3L KC_BASE_Z KC_X_SYM_LEFT, KC_C, KC_D KC_BASE_V

#define KM_BASE_1R KC_BASE_J KC_L_GUI, KC_U_FUNC, KC_Y_ALT KC_BASE_BSPC
#define KM_BASE_2R KC_BASE_M KC_N_SFT, KC_E_EXT_RIGHT, KC_I_CTL KC_BASE_O
#define KM_BASE_3R KC_BASE_K KC_H, KC_COMM, KC_DOT_SYM_RIGHT KC_BASE_SLSH

#define KM_BASE_1 KM_BASE_1L, KM_BASE_1R
#define KM_BASE_2 KM_BASE_2L, KM_BASE_2R
#define KM_BASE_3 KM_BASE_3L, KM_BASE_3R

#ifdef FK_TWO_THUMBKEYS
#define KM_BASE_THUMB_L OSM(MOD_LSFT), KC_SPC_NAV
#define KM_BASE_THUMB_R KC_ENT_NUM, KC_BSPC
#else
#define KM_BASE_THUMB_L KC_SPC_NAV
#define KM_BASE_THUMB_R KC_ENT_NUM
#endif

#define KM_BASE_THUMB KM_BASE_THUMB_L, KM_BASE_THUMB_R

#define LAYOUT_BASE KM_BASE_1, KM_BASE_2, KM_BASE_3, KM_BASE_THUMB

// Left extended layer for flexkey keyboards.

#define KM_EXT_LEFT_1L SPACER_TL KC_LALT, KC_NO, KC_LGUI
#define KM_EXT_LEFT_2L SPACER_ML KC_LCTL, KC_TRNS, KC_LSFT
#define KM_EXT_LEFT_3L SPACER_BL KC_NO, KC_NO, KC_NO

#define KM_EXT_LEFT_1R SPACER_TI KC_J, KC_DEL, KC_BSPC SPACER_TR
#define KM_EXT_LEFT_2R SPACER_MI KC_M, KC_NO, KC_O SPACER_MR
#define KM_EXT_LEFT_3R SPACER_BI KC_K, KC_H, KC_SLSH SPACER_BR

#define KM_EXT_LEFT_1 KM_EXT_LEFT_1L, KM_EXT_LEFT_1R
#define KM_EXT_LEFT_2 KM_EXT_LEFT_2L, KM_EXT_LEFT_2R
#define KM_EXT_LEFT_3 KM_EXT_LEFT_3L, KM_EXT_LEFT_3R

#define LAYOUT_EXT_LEFT KM_EXT_LEFT_1, KM_EXT_LEFT_2, KM_EXT_LEFT_3, KM_THUMB_TRNS

// Right extended layer for flexkey keyboards.

#define KM_EXT_RIGHT_1L SPACER_TL KC_Q, KC_GRV, KC_B
#define KM_EXT_RIGHT_2L SPACER_ML KC_A, KC_TRNS, KC_G
#define KM_EXT_RIGHT_3L SPACER_BL KC_Z, KC_D, KC_V

#define KM_EXT_RIGHT_1R SPACER_TI KC_LGUI, KC_NO, KC_LALT SPACER_TR
#define KM_EXT_RIGHT_2R SPACER_MI KC_RSFT, KC_TRNS, KC_LCTL SPACER_MR
#define KM_EXT_RIGHT_3R SPACER_BI KC_NO, KC_NO, KC_NO SPACER_BR

#define KM_EXT_RIGHT_1 KM_EXT_RIGHT_1L, KM_EXT_RIGHT_1R
#define KM_EXT_RIGHT_2 KM_EXT_RIGHT_2L, KM_EXT_RIGHT_2R
#define KM_EXT_RIGHT_3 KM_EXT_RIGHT_3L, KM_EXT_RIGHT_3R

#define LAYOUT_EXT_RIGHT KM_EXT_RIGHT_1, KM_EXT_RIGHT_2, KM_EXT_RIGHT_3, KM_THUMB_TRNS

// Left symbol layer for flexkey keyboards.

#define KM_SYM_LEFT_1L SPACER_TL KC_GRV, KC_EXLM, KC_CIRC
#define KM_SYM_LEFT_2L SPACER_ML KC_NO, KC_PLUS, KC_COLN
#define KM_SYM_LEFT_3L SPACER_BL KC_X, KC_EQL, KC_SCLN

#define KM_SYM_LEFT_1R SPACER_TI KC_AMPR, KC_ASTR, KC_UNDS SPACER_TR
#define KM_SYM_LEFT_2R SPACER_MI KC_UK_AT, KC_UK_TILDE, KC_MINS SPACER_MR
#define KM_SYM_LEFT_3R SPACER_BI KC_QUOT, KC_UK_HASH, KC_NO SPACER_BR

#define KM_SYM_LEFT_1 KM_SYM_LEFT_1L, KM_SYM_LEFT_1R
#define KM_SYM_LEFT_2 KM_SYM_LEFT_2L, KM_SYM_LEFT_2R
#define KM_SYM_LEFT_3 KM_SYM_LEFT_3L, KM_SYM_LEFT_3R

#define LAYOUT_SYM_LEFT KM_SYM_LEFT_1, KM_SYM_LEFT_2, KM_SYM_LEFT_3, KM_THUMB_TRNS

// Right symbol layer for flexkey keyboards.

#define KM_SYM_RIGHT_1L SPACER_TL KC_UK_DQUO, KC_UK_PND, KC_DLR
#define KM_SYM_RIGHT_2L SPACER_ML KC_UK_PIPE, KC_LBRC, KC_LCBR
#define KM_SYM_RIGHT_3L SPACER_BL KC_UK_BSLS, KC_RBRC, KC_RCBR

#define KM_SYM_RIGHT_1R SPACER_TI KC_PERC, KC_GRV, KC_NO SPACER_TR
#define KM_SYM_RIGHT_2R SPACER_MI KC_LPRN, KC_LT, KC_NO SPACER_MR
#define KM_SYM_RIGHT_3R SPACER_BI KC_RPRN, KC_GT, KC_DOT SPACER_BR

#define KM_SYM_RIGHT_1 KM_SYM_RIGHT_1L, KM_SYM_RIGHT_1R
#define KM_SYM_RIGHT_2 KM_SYM_RIGHT_2L, KM_SYM_RIGHT_2R
#define KM_SYM_RIGHT_3 KM_SYM_RIGHT_3L, KM_SYM_RIGHT_3R

#define LAYOUT_SYM_RIGHT KM_SYM_RIGHT_1, KM_SYM_RIGHT_2, KM_SYM_RIGHT_3, KM_THUMB_TRNS

// Navigation layer for flexkey keyboards.

#define KM_NAV_1L SPACER_TL KC_ESC, KC_PSCR, M_ALT_TAB
#define KM_NAV_2L SPACER_ML KC_TAB, KC_SFT_TAB, KC_CTL_TAB
#define KM_NAV_3L SPACER_BL KC_CAPS, KC_PGDN, KC_TRNS

#define KM_NAV_1R SPACER_TI M_PDESK, KC_UP, M_NDESK SPACER_TR
#define KM_NAV_2R SPACER_MI KC_LEFT, KC_DOWN, KC_RGHT SPACER_MR
#define KM_NAV_3R SPACER_BI KC_HOME, KC_PGUP, KC_END SPACER_BR

#define KM_NAV_1 KM_NAV_1L, KM_NAV_1R
#define KM_NAV_2 KM_NAV_2L, KM_NAV_2R
#define KM_NAV_3 KM_NAV_3L, KM_NAV_3R

#ifdef FK_TWO_THUMBKEYS
#define KM_NAV_THUMB_L KC_NO, KC_TRNS
#define KM_NAV_THUMB_R KC_SCUT, KC_NO
#else
#define KM_NAV_THUMB_L KC_TRNS
#define KM_NAV_THUMB_R KC_SCUT
#endif

#define KM_NAV_THUMB KM_NAV_THUMB_L, KM_NAV_THUMB_R

#define LAYOUT_NAV KM_NAV_1, KM_NAV_2, KM_NAV_3, KM_NAV_THUMB

// Number layer for flexkey keyboards.

#define KM_NUM_1L SPACER_TL KC_1, KC_2, KC_3
#define KM_NUM_2L SPACER_ML KC_4, KC_5, KC_6
#define KM_NUM_3L SPACER_BL KC_7, KC_8, KC_9

#define KM_NUM_1R SPACER_TI KC_NO, KC_DEL, KC_BSPC SPACER_TR
#define KM_NUM_2R SPACER_MI KC_NO, KC_0, KC_NO SPACER_MR
#define KM_NUM_3R SPACER_BI KC_TRNS, KC_DOT, KC_SLSH SPACER_BR

#define KM_NUM_1 KM_NUM_1L, KM_NUM_1R
#define KM_NUM_2 KM_NUM_2L, KM_NUM_2R
#define KM_NUM_3 KM_NUM_3L, KM_NUM_3R

#ifdef FK_TWO_THUMBKEYS
#define KM_NUM_THUMB_L KC_NO, KC_SCUT
#define KM_NUM_THUMB_R KC_TRNS, KC_NO
#else
#define KM_NUM_THUMB_L KC_SCUT
#define KM_NUM_THUMB_R KC_TRNS
#endif

#define KM_NUM_THUMB KM_NUM_THUMB_L, KM_NUM_THUMB_R

#define LAYOUT_NUM KM_NUM_1, KM_NUM_2, KM_NUM_3, KM_NUM_THUMB

// Function layer for flexkey layouts.

#define KM_FUNC_1L SPACER_TL KC_F1, KC_F2, KC_F3
#define KM_FUNC_2L SPACER_ML KC_F4, KC_F5, KC_F6
#define KM_FUNC_3L SPACER_BL KC_F7, KC_F8, KC_F9

#define KM_FUNC_1R SPACER_TI KC_F10, KC_NO, KC_NO SPACER_TR
#define KM_FUNC_2R SPACER_MI KC_F11, KC_NO, KC_NO SPACER_MR
#define KM_FUNC_3R SPACER_BI KC_F12, KC_TRNS, KC_NO SPACER_BR

#define KM_FUNC_1 KM_FUNC_1L, KM_FUNC_1R
#define KM_FUNC_2 KM_FUNC_2L, KM_FUNC_2R
#define KM_FUNC_3 KM_FUNC_3L, KM_FUNC_3R

#define LAYOUT_FUNC KM_FUNC_1, KM_FUNC_2, KM_FUNC_3, KM_THUMB_TRNS

// Controls layer for flexkey layouts.

#define KM_CTRLS_1L SPACER_TL KC_NO, KC_NO, KC_NO
#define KM_CTRLS_2L SPACER_ML KC_NO, KC_NO, KC_NO
#define KM_CTRLS_3L SPACER_BL KC_NO, KC_TRNS, KC_NO

#define KM_CTRLS_1R SPACER_TI KC_BRIU, KC_VOLU, KC_MPLY SPACER_TR
#define KM_CTRLS_2R SPACER_MI KC_BRID, KC_VOLD, KC_MNXT SPACER_MR
#define KM_CTRLS_3R SPACER_BI KC_NO, KC_MUTE, KC_MPRV SPACER_BR

#define KM_CTRLS_1 KM_CTRLS_1L, KM_CTRLS_1R
#define KM_CTRLS_2 KM_CTRLS_2L, KM_CTRLS_2R
#define KM_CTRLS_3 KM_CTRLS_3L, KM_CTRLS_3R

#define LAYOUT_CTRLS KM_CTRLS_1, KM_CTRLS_2, KM_CTRLS_3, KM_THUMB_TRNS

// Shortcut layer for flexkey layouts.

#define KM_SCUT_1L SPACER_TL M_ISWIN, M_ISCROS, KC_NO
#define KM_SCUT_2L SPACER_ML M_APP1, M_APP2, M_1PASS
#define KM_SCUT_3L SPACER_BL LSFT(LCTL(KC_C)), LCTL(KC_C), LCTL(KC_V)

#define KM_SCUT_1R SPACER_TI KC_NO, M_EMOJI, M_4RAND SPACER_TR
#define KM_SCUT_2R SPACER_MI KC_NO, M_APP3, M_APP4 SPACER_MR
#define KM_SCUT_3R SPACER_BI KC_TRNS, KC_NO, KC_NO SPACER_BR

#define KM_SCUT_1 KM_SCUT_1L, KM_SCUT_1R
#define KM_SCUT_2 KM_SCUT_2L, KM_SCUT_2R
#define KM_SCUT_3 KM_SCUT_3L, KM_SCUT_3R

#define LAYOUT_SCUT KM_SCUT_1, KM_SCUT_2, KM_SCUT_3, KM_THUMB_TRNS

// Ferris sweep test platform - base layer.

#define KM_FERRIS_BASE_1 TEST_TL KM_BASE_1L, TEST_TI KM_BASE_1R TEST_TR
#define KM_FERRIS_BASE_2 TEST_ML KM_BASE_2L, TEST_MI KM_BASE_2R TEST_MR
#define KM_FERRIS_BASE_3 TEST_BL KM_BASE_3L, TEST_BI KM_BASE_3R TEST_BR

#define KM_FERRIS_BASE_THUMB TEST_THL KM_BASE_THUMB_L, KM_BASE_THUMB_R TEST_THR

#define FERRIS_LAYOUT_BASE KM_FERRIS_BASE_1, KM_FERRIS_BASE_2, KM_FERRIS_BASE_3, KM_FERRIS_BASE_THUMB

// Ferris sweep test platform - left extended layer.

#define KM_FERRIS_LEFT_1 TEST_TL KM_EXT_LEFT_1L, TEST_TI KM_EXT_LEFT_1R TEST_TR
#define KM_FERRIS_LEFT_2 TEST_ML KM_EXT_LEFT_2L, TEST_MI KM_EXT_LEFT_2R TEST_MR
#define KM_FERRIS_LEFT_3 TEST_BL KM_EXT_LEFT_3L, TEST_BI KM_EXT_LEFT_3R TEST_BR
#define KM_FERRIS_THUMB_EXT_LEFT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define FERRIS_LAYOUT_EXT_LEFT KM_FERRIS_LEFT_1, KM_FERRIS_LEFT_2, KM_FERRIS_LEFT_3, KM_FERRIS_THUMB_EXT_LEFT

// Ferris sweep test platform - right extended layer.

#define KM_FERRIS_RIGHT_1 TEST_TL KM_EXT_RIGHT_1L, TEST_TI KM_EXT_RIGHT_1R TEST_TR
#define KM_FERRIS_RIGHT_2 TEST_ML KM_EXT_RIGHT_2L, TEST_MI KM_EXT_RIGHT_2R TEST_MR
#define KM_FERRIS_RIGHT_3 TEST_BL KM_EXT_RIGHT_3L, TEST_BI KM_EXT_RIGHT_3R TEST_BR
#define KM_FERRIS_THUMB_EXT_RIGHT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define FERRIS_LAYOUT_EXT_RIGHT KM_FERRIS_RIGHT_1, KM_FERRIS_RIGHT_2, KM_FERRIS_RIGHT_3, KM_FERRIS_THUMB_EXT_RIGHT

// Ferris sweep test platform - left symbol layer.

#define KM_FERRIS_SYM_LEFT_1 TEST_TL KM_SYM_LEFT_1L, TEST_TI KM_SYM_LEFT_1R TEST_TR
#define KM_FERRIS_SYM_LEFT_2 TEST_ML KM_SYM_LEFT_2L, TEST_MI KM_SYM_LEFT_2R TEST_MR
#define KM_FERRIS_SYM_LEFT_3 TEST_BL KM_SYM_LEFT_3L, TEST_BI KM_SYM_LEFT_3R TEST_BR
#define KM_FERRIS_THUMB_SYM_LEFT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define FERRIS_LAYOUT_SYM_LEFT KM_FERRIS_SYM_LEFT_1, KM_FERRIS_SYM_LEFT_2, KM_FERRIS_SYM_LEFT_3, KM_FERRIS_THUMB_SYM_LEFT

// Ferris sweep test platform - right symbol layer.

#define KM_FERRIS_SYM_RIGHT_1 TEST_TL KM_SYM_RIGHT_1L, TEST_TI KM_SYM_RIGHT_1R TEST_TR
#define KM_FERRIS_SYM_RIGHT_2 TEST_ML KM_SYM_RIGHT_2L, TEST_MI KM_SYM_RIGHT_2R TEST_MR
#define KM_FERRIS_SYM_RIGHT_3 TEST_BL KM_SYM_RIGHT_3L, TEST_BI KM_SYM_RIGHT_3R TEST_BR
#define KM_FERRIS_THUMB_SYM_RIGHT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define FERRIS_LAYOUT_SYM_RIGHT KM_FERRIS_SYM_RIGHT_1, KM_FERRIS_SYM_RIGHT_2, KM_FERRIS_SYM_RIGHT_3, KM_FERRIS_THUMB_SYM_RIGHT

// Ferris sweep test platform - navigation layer.

#define KM_FERRIS_NAV_1 TEST_TL KM_NAV_1L, TEST_TI KM_NAV_1R TEST_TR
#define KM_FERRIS_NAV_2 TEST_ML KM_NAV_2L, TEST_MI KM_NAV_2R TEST_MR
#define KM_FERRIS_NAV_3 TEST_BL KM_NAV_3L, TEST_BI KM_NAV_3R TEST_BR
#define KM_FERRIS_NAV_THUMB TEST_THL KM_NAV_THUMB_L, KM_NAV_THUMB_R TEST_THR

#define FERRIS_LAYOUT_NAV KM_FERRIS_NAV_1, KM_FERRIS_NAV_2, KM_FERRIS_NAV_3, KM_FERRIS_NAV_THUMB

// Ferris sweep test platform - number layer.

#define KM_FERRIS_NUM_1 TEST_TL KM_NUM_1L, TEST_TI KM_NUM_1R TEST_TR
#define KM_FERRIS_NUM_2 TEST_ML KM_NUM_2L, TEST_MI KM_NUM_2R TEST_MR
#define KM_FERRIS_NUM_3 TEST_BL KM_NUM_3L, TEST_BI KM_NUM_3R TEST_BR
#define KM_FERRIS_NUM_THUMB TEST_THL KM_NUM_THUMB_L, KM_NUM_THUMB_R TEST_THR

#define FERRIS_LAYOUT_NUM KM_FERRIS_NUM_1, KM_FERRIS_NUM_2, KM_FERRIS_NUM_3, KM_FERRIS_NUM_THUMB

// Ferris sweep test platform - function layer.

#define KM_FERRIS_FUNC_1 TEST_TL KM_FUNC_1L, TEST_TI KM_FUNC_1R TEST_TR
#define KM_FERRIS_FUNC_2 TEST_ML KM_FUNC_2L, TEST_MI KM_FUNC_2R TEST_MR
#define KM_FERRIS_FUNC_3 TEST_BL KM_FUNC_3L, TEST_BI KM_FUNC_3R TEST_BR
#define KM_FERRIS_THUMB_FUNC KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define FERRIS_LAYOUT_FUNC KM_FERRIS_FUNC_1, KM_FERRIS_FUNC_2, KM_FERRIS_FUNC_3, KM_FERRIS_THUMB_FUNC

// Ferris sweep test platform - controls layer.

#define KM_FERRIS_CTRLS_1 TEST_TL KM_CTRLS_1L, TEST_TI KM_CTRLS_1R TEST_TR
#define KM_FERRIS_CTRLS_2 TEST_ML KM_CTRLS_2L, TEST_MI KM_CTRLS_2R TEST_MR
#define KM_FERRIS_CTRLS_3 TEST_BL KM_CTRLS_3L, TEST_BI KM_CTRLS_3R TEST_BR
#define KM_FERRIS_THUMB_CTRLS KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define FERRIS_LAYOUT_CTRLS KM_FERRIS_CTRLS_1, KM_FERRIS_CTRLS_2, KM_FERRIS_CTRLS_3, KM_FERRIS_THUMB_CTRLS

// Ferris sweep test platform - shortcut layer.

#define KM_FERRIS_SCUT_1 TEST_TL KM_SCUT_1L, TEST_TI KM_SCUT_1R TEST_TR
#define KM_FERRIS_SCUT_2 TEST_ML KM_SCUT_2L, TEST_MI KM_SCUT_2R TEST_MR
#define KM_FERRIS_SCUT_3 TEST_BL KM_SCUT_3L, TEST_BI KM_SCUT_3R TEST_BR
#define KM_FERRIS_THUMB_SCUT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define FERRIS_LAYOUT_SCUT KM_FERRIS_SCUT_1, KM_FERRIS_SCUT_2, KM_FERRIS_SCUT_3, KM_FERRIS_THUMB_SCUT

// Planck test platform - base layer.

#define KM_PLANCK_BASE_1 KC_ESC, TEST_TL KM_BASE_1L, TEST_TI KM_BASE_1R TEST_TR, KC_BSPC
#define KM_PLANCK_BASE_2 KC_TAB, TEST_ML KM_BASE_2L, TEST_MI KM_BASE_2R TEST_MR, KC_COLN
#define KM_PLANCK_BASE_3 OSL(LAYER_SYM_LEFT), TEST_BL KM_BASE_3L, TEST_BI KM_BASE_3R TEST_BR, OSL(LAYER_SYM_RIGHT)

#define KM_PLANCK_BASE_THUMB KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, TEST_THL KM_BASE_THUMB_L, KM_BASE_THUMB_R TEST_THR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT

#define PLANCK_LAYOUT_BASE KM_PLANCK_BASE_1, KM_PLANCK_BASE_2, KM_PLANCK_BASE_3, KM_PLANCK_BASE_THUMB

// Planck test platform - left extended layer.

#define KM_PLANCK_EXT_LEFT_1 KC_TRNS, TEST_TL KM_EXT_LEFT_1L, TEST_TI KM_EXT_LEFT_1R TEST_TR, KC_TRNS
#define KM_PLANCK_EXT_LEFT_2 KC_TRNS, TEST_ML KM_EXT_LEFT_2L, TEST_MI KM_EXT_LEFT_2R TEST_MR, KC_TRNS
#define KM_PLANCK_EXT_LEFT_3 KC_TRNS, TEST_BL KM_EXT_LEFT_3L, TEST_BI KM_EXT_LEFT_3R TEST_BR, KC_TRNS
#define KM_PLANCK_THUMB_EXT_LEFT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_EXT_LEFT KM_PLANCK_EXT_LEFT_1, KM_PLANCK_EXT_LEFT_2, KM_PLANCK_EXT_LEFT_3, KM_PLANCK_THUMB_EXT_LEFT

// Planck test platform - right extended layer.

#define KM_PLANCK_EXT_RIGHT_1 KC_TRNS, TEST_TL KM_EXT_RIGHT_1L, TEST_TI KM_EXT_RIGHT_1R TEST_TR, KC_TRNS
#define KM_PLANCK_EXT_RIGHT_2 KC_TRNS, TEST_ML KM_EXT_RIGHT_2L, TEST_MI KM_EXT_RIGHT_2R TEST_MR, KC_TRNS
#define KM_PLANCK_EXT_RIGHT_3 KC_TRNS, TEST_BL KM_EXT_RIGHT_3L, TEST_BI KM_EXT_RIGHT_3R TEST_BR, KC_TRNS
#define KM_PLANCK_THUMB_EXT_RIGHT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_EXT_RIGHT KM_PLANCK_EXT_RIGHT_1, KM_PLANCK_EXT_RIGHT_2, KM_PLANCK_EXT_RIGHT_3, KM_PLANCK_THUMB_EXT_RIGHT

// Planck test platform - left symbol layer.

#define KM_PLANCK_SYM_LEFT_1 KC_TRNS, TEST_TL KM_SYM_LEFT_1L, TEST_TI KM_SYM_LEFT_1R TEST_TR, KC_TRNS
#define KM_PLANCK_SYM_LEFT_2 KC_TRNS, TEST_ML KM_SYM_LEFT_2L, TEST_MI KM_SYM_LEFT_2R TEST_MR, KC_TRNS
#define KM_PLANCK_SYM_LEFT_3 KC_TRNS, TEST_BL KM_SYM_LEFT_3L, TEST_BI KM_SYM_LEFT_3R TEST_BR, KC_TRNS
#define KM_PLANCK_THUMB_SYM_LEFT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_SYM_LEFT KM_PLANCK_SYM_LEFT_1, KM_PLANCK_SYM_LEFT_2, KM_PLANCK_SYM_LEFT_3, KM_PLANCK_THUMB_SYM_LEFT

// Planck test platform - right symbol layer.

#define KM_PLANCK_SYM_RIGHT_1 KC_TRNS, TEST_ML KM_SYM_RIGHT_1L, TEST_MI KM_SYM_RIGHT_1R TEST_MR, KC_TRNS
#define KM_PLANCK_SYM_RIGHT_2 KC_TRNS, TEST_ML KM_SYM_RIGHT_2L, TEST_MI KM_SYM_RIGHT_2R TEST_MR, KC_TRNS
#define KM_PLANCK_SYM_RIGHT_3 KC_TRNS, TEST_BL KM_SYM_RIGHT_3L, TEST_BI KM_SYM_RIGHT_3R TEST_BR, KC_TRNS
#define KM_PLANCK_THUMB_SYM_RIGHT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_SYM_RIGHT KM_PLANCK_SYM_RIGHT_1, KM_PLANCK_SYM_RIGHT_2, KM_PLANCK_SYM_RIGHT_3, KM_PLANCK_THUMB_SYM_RIGHT

// Planck test platform - navigation layer.

#define KM_PLANCK_NAV_1 KC_TRNS, TEST_TL KM_NAV_1L, TEST_TI KM_NAV_1R TEST_TR, KC_TRNS
#define KM_PLANCK_NAV_2 KC_TRNS, TEST_ML KM_NAV_2L, TEST_MI KM_NAV_2R TEST_MR, KC_TRNS
#define KM_PLANCK_NAV_3 KC_TRNS, TEST_BL KM_NAV_3L, TEST_BI KM_NAV_3R TEST_BR, KC_TRNS
#define KM_PLANCK_NAV_THUMB KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TEST_THL KM_NAV_THUMB_L, KM_NAV_THUMB_R TEST_THR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_NAV KM_PLANCK_NAV_1, KM_PLANCK_NAV_2, KM_PLANCK_NAV_3, KM_PLANCK_NAV_THUMB

// Planck test platform - number layer.

#define KM_PLANCK_NUM_1 KC_TRNS, TEST_TL KM_NUM_1L, TEST_TI KM_NUM_1R TEST_TR, KC_TRNS
#define KM_PLANCK_NUM_2 KC_TRNS, TEST_ML KM_NUM_2L, TEST_MI KM_NUM_2R TEST_MR, KC_TRNS
#define KM_PLANCK_NUM_3 KC_TRNS, TEST_BL KM_NUM_3L, TEST_BI KM_NUM_3R TEST_BR, KC_TRNS
#define KM_PLANCK_NUM_THUMB KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TEST_THL KM_NUM_THUMB_L, KM_NUM_THUMB_R TEST_THR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_NUM KM_PLANCK_NUM_1, KM_PLANCK_NUM_2, KM_PLANCK_NUM_3, KM_PLANCK_NUM_THUMB

// Planck test platform - function layer.

#define KM_PLANCK_FUNC_1 KC_TRNS, TEST_TL KM_FUNC_1L, TEST_TI KM_FUNC_1R TEST_TR, KC_TRNS
#define KM_PLANCK_FUNC_2 KC_TRNS, TEST_ML KM_FUNC_2L, TEST_MI KM_FUNC_2R TEST_MR, KC_TRNS
#define KM_PLANCK_FUNC_3 KC_TRNS, TEST_BL KM_FUNC_3L, TEST_BI KM_FUNC_3R TEST_BR, KC_TRNS
#define KM_PLANCK_THUMB_FUNC KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_FUNC KM_PLANCK_FUNC_1, KM_PLANCK_FUNC_2, KM_PLANCK_FUNC_3, KM_PLANCK_THUMB_FUNC

// Planck test platform - controls layer.

#define KM_PLANCK_CTRLS_1 KC_TRNS, TEST_TL KM_CTRLS_1L, TEST_TI KM_CTRLS_1R TEST_TR, KC_TRNS
#define KM_PLANCK_CTRLS_2 KC_TRNS, TEST_ML KM_CTRLS_2L, TEST_MI KM_CTRLS_2R TEST_MR, KC_TRNS
#define KM_PLANCK_CTRLS_3 KC_TRNS, TEST_BL KM_CTRLS_3L, TEST_BI KM_CTRLS_3R TEST_BR, KC_TRNS
#define KM_PLANCK_THUMB_CTRLS KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_CTRLS KM_PLANCK_CTRLS_1, KM_PLANCK_CTRLS_2, KM_PLANCK_CTRLS_3, KM_PLANCK_THUMB_CTRLS

// Planck test platform - shortcut layer.

#define KM_PLANCK_SCUT_1 KC_TRNS, TEST_TL KM_SCUT_1L, TEST_TI KM_SCUT_1R TEST_TR, KC_TRNS
#define KM_PLANCK_SCUT_2 KC_TRNS, TEST_ML KM_SCUT_2L, TEST_MI KM_SCUT_2R TEST_MR, KC_TRNS
#define KM_PLANCK_SCUT_3 KC_TRNS, TEST_BL KM_SCUT_3L, TEST_BI KM_SCUT_3R TEST_BR, KC_TRNS
#define KM_PLANCK_THUMB_SCUT KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define PLANCK_LAYOUT_SCUT KM_PLANCK_SCUT_1, KM_PLANCK_SCUT_2, KM_PLANCK_SCUT_3, KM_PLANCK_THUMB_SCUT

#endif // USERSPACE
