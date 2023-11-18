/*
Copyright 2023 Hannah Blythe Morrison

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

#include "flexkey.h"

// Capsword combo spans both shift keys.

const uint16_t PROGMEM tn_combo[] = {KC_T_SFT, KC_N_SFT, COMBO_END};

// Top and middle left combos.

const uint16_t PROGMEM wf_combo[] = {KC_W_ALT, KC_F, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P_GUI, COMBO_END};
const uint16_t PROGMEM rs_combo[] = {KC_R_CTL, KC_S_EXT_LEFT, COMBO_END};
const uint16_t PROGMEM st_combo[] = {KC_S_EXT_LEFT, KC_T_SFT, COMBO_END};

// Bottom left combos.

const uint16_t PROGMEM xsymc_combo[] = {KC_X_SYM_LEFT, KC_C, COMBO_END};
const uint16_t PROGMEM cspcnav_combo[] = {KC_C, KC_SPC_NAV_LAYER, COMBO_END};

// Vertical left combos.

const uint16_t PROGMEM tspcnav_combo[] = {KC_T_SFT, KC_SPC_NAV_LAYER, COMBO_END};

// Top and middle right combos.

const uint16_t PROGMEM lu_combo[] = {KC_L_GUI, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y_ALT, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N_SFT, KC_E_EXT_RIGHT, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E_EXT_RIGHT, KC_I_CTL, COMBO_END};

// Bottom right combos.

const uint16_t PROGMEM entnumcomm_combo[] = {KC_ENT_NUM_LAYER, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdotsym_combo[] = {KC_COMM, KC_DOT_SYM_RIGHT, COMBO_END};

// Vertical right combos.

const uint16_t PROGMEM nentnum_combo[] = {KC_N_SFT, KC_ENT_NUM_LAYER, COMBO_END};

// Combo definitions.

combo_t key_combos[] = {
  COMBO(tn_combo, CW_TOGG),
  COMBO(wf_combo, KC_Q),
  COMBO(fp_combo, KC_B),
  COMBO(rs_combo, KC_A),
  COMBO(st_combo, KC_G),
  COMBO(xsymc_combo, KC_Z),
  COMBO(cspcnav_combo, KC_V),
  COMBO(tspcnav_combo, KC_D),
  COMBO(lu_combo, KC_J),
  COMBO(uy_combo, KC_BSPC),
  COMBO(ne_combo, KC_M),
  COMBO(ei_combo, KC_O),
  COMBO(entnumcomm_combo, KC_K),
  COMBO(commdotsym_combo, KC_SLSH),
  COMBO(nentnum_combo, KC_H),
};
