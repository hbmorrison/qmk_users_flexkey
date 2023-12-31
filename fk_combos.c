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

const uint16_t PROGMEM cw_combo[] = {KC_T_SFT, KC_N_SFT, COMBO_END};

// Combos for missing keys.

#if defined FK_COMBOS_ON || ! defined FK_TOP_OUTER
const uint16_t PROGMEM q_combo[] = {KC_W_ALT, KC_F_CTRLS, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_U_FUNC, KC_Y_ALT, COMBO_END};
#endif

#if defined FK_COMBOS_ON || ! defined FK_MDL_OUTER
const uint16_t PROGMEM a_combo[] = {KC_R_CTL, KC_S_EXT_LEFT, COMBO_END};
const uint16_t PROGMEM o_combo[] = {KC_E_EXT_RIGHT, KC_I_CTL, COMBO_END};
#endif

#if defined FK_COMBOS_ON || ! defined FK_BTM_OUTER
const uint16_t PROGMEM z_combo[] = {KC_X_SYM_LEFT, KC_C, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_COMM, KC_DOT_SYM_RIGHT, COMBO_END};
#endif

#if defined FK_COMBOS_ON || ! defined FK_TOP_INNER
const uint16_t PROGMEM b_combo[] = {KC_F_CTRLS, KC_P_GUI, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_L_GUI, KC_U_FUNC, COMBO_END};
#endif

#if defined FK_COMBOS_ON || ! defined FK_MDL_INNER
const uint16_t PROGMEM m_combo[] = {KC_N_SFT, KC_E_EXT_RIGHT, COMBO_END};
const uint16_t PROGMEM g_combo[] = {KC_S_EXT_LEFT, KC_T_SFT, COMBO_END};
#endif

#if defined FK_COMBOS_ON || ! defined FK_BTM_INNER
const uint16_t PROGMEM v_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM k_combo[] = {KC_H, KC_COMM, COMBO_END};
#endif

// Combo definitions.

combo_t key_combos[] = {
  COMBO(cw_combo, CW_TOGG),
#if defined FK_COMBOS_ON || ! defined FK_TOP_OUTER
  COMBO(q_combo, KC_Q),
  COMBO(bspc_combo, KC_BSPC),
#endif
#if defined FK_COMBOS_ON || ! defined FK_MDL_OUTER
  COMBO(a_combo, KC_A),
  COMBO(o_combo, KC_O),
#endif
#if defined FK_COMBOS_ON || ! defined FK_BTM_OUTER
  COMBO(z_combo, KC_Z),
  COMBO(slsh_combo, KC_SLSH),
#endif
#if defined FK_COMBOS_ON || ! defined FK_TOP_INNER
  COMBO(b_combo, KC_B),
  COMBO(j_combo, KC_J),
#endif
#if defined FK_COMBOS_ON || ! defined FK_MDL_INNER
  COMBO(g_combo, KC_G),
  COMBO(m_combo, KC_M),
#endif
#if defined FK_COMBOS_ON || ! defined FK_BTM_INNER
  COMBO(v_combo, KC_V),
  COMBO(k_combo, KC_K),
#endif
};
