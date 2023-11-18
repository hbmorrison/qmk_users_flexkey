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

// Define combos.

const uint16_t PROGMEM tn_combo[] = {KC_T_SFT, KC_N_SFT, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xsymc_combo[] = {KC_X_SYM_LEFT, KC_C, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM commdotsym_combo[] = {KC_COMM, KC_DOT_SYM_RIGHT, COMBO_END};

combo_t key_combos[] = {
  COMBO(tn_combo, CW_TOGG),
  COMBO(xc_combo, KC_D),
  COMBO(xsymc_combo, KC_D),
  COMBO(commdot_combo, KC_H),
  COMBO(commdotsym_combo, KC_H),
};
