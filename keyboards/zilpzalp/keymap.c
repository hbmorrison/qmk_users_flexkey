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

#include QMK_KEYBOARD_H
#include "flexkey.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = FK_LAYOUT_zilpzalp( LAYOUT_BASE ),
  [LAYER_EXT_LEFT] = FK_LAYOUT_zilpzalp( LAYOUT_EXT_LEFT ),
  [LAYER_EXT_RIGHT] = FK_LAYOUT_zilpzalp( LAYOUT_EXT_RIGHT ),
  [LAYER_SYM_LEFT] = FK_LAYOUT_zilpzalp( LAYOUT_SYM_LEFT ),
  [LAYER_SYM_RIGHT] = FK_LAYOUT_zilpzalp( LAYOUT_SYM_RIGHT ),
  [LAYER_NAV] = FK_LAYOUT_zilpzalp( LAYOUT_NAV ),
  [LAYER_NUM] = FK_LAYOUT_zilpzalp( LAYOUT_NUM ),
  [LAYER_CTRLS] = FK_LAYOUT_zilpzalp( LAYOUT_CTRLS ),
  [LAYER_FUNC] = FK_LAYOUT_zilpzalp( LAYOUT_FUNC ),
  [LAYER_SCUT] = FK_LAYOUT_zilpzalp( LAYOUT_SCUT )
};
