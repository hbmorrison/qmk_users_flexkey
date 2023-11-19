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

#include "stdio.h"
#include "flexkey.h"

// Issues HYPR-keypress for Windows and ALT-keypress for ChromeOS.

void hypr_or_alt(char *ss, bool pressed);

// Defines whether to issue Windows or ChromeOS keypresses from macros - Windows
// by default.

static bool fk_is_chromebook = false;

// State for managing shift-backspace behaviour.

static bool fk_del_registered = false;
static uint8_t fk_mod_state = 0;

// State of the M_ALT_TAB macro - true if we are currently tabbing between
// windows.

static bool fk_alt_tab_pressed = false;

// True if rand() has already been seeded using srand().

static bool fk_srand_seeded = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Stop pressing the KC_LALT key once M_ALT_TAB is no longer being pressed.

  if (keycode != M_ALT_TAB && fk_alt_tab_pressed) {
    unregister_code(KC_LALT);
    fk_alt_tab_pressed = false;
  }

  // Make sure that we return directly to the base layer when the function layer
  // key is released. This avoids getting stuck in the left symbol layer which
  // precedes the function layer keypress.

  if (keycode == KC_FUNC_LAYER && ! record->event.pressed) {
    layer_move(LAYER_BASE);
  }

  // Ensure that shift is not pressed when additional layers are active, aside
  // from a few exceptions. This ensures that symbol keypresses will always
  // produce the unshifted symbol, unless explicitly shifted with LSFT() in
  // code.

  uint8_t current_layer = get_highest_layer(layer_state);

  if (record->event.pressed && current_layer > LAYER_BASE) {
    switch (keycode) {
      // Allow keys in the extended layers to be shifted.
      case KC_A ... KC_Z:
      case KC_DOT:
      case KC_BSPC:
      // Allow tabs to be shifted.
      case KC_TAB:
        break;
      default:
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
    }
  }

  // Store the current state of modifiers for shift-backspace behaviour.

  fk_mod_state = get_mods();

  switch (keycode) {

    // Shift-backspace issues delete.

    case KC_BSPC:
      if (record->event.pressed) {
        if (fk_mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_DEL);
          fk_del_registered = true;
          set_mods(fk_mod_state);
          return false;
        }
      } else {
        if (fk_del_registered) {
          unregister_code(KC_DEL);
          fk_del_registered = false;
          return false;
        }
      }
      break;

    // Hold down KC_LALT persistantly to allow tabbing through windows.

    case M_ALT_TAB:
      if (record->event.pressed) {
        if (!fk_alt_tab_pressed) {
          register_code(KC_LALT);
          fk_alt_tab_pressed = true;
        }
        tap_code(KC_TAB);
      }
      break;

    // Application switching macros.

    case M_APP1:
      hypr_or_alt(SS_TAP(X_1), record->event.pressed);
      break;
    case M_APP2:
      hypr_or_alt(SS_TAP(X_2), record->event.pressed);
      break;
    case M_APP3:
      hypr_or_alt(SS_TAP(X_3), record->event.pressed);
      break;
    case M_APP4:
      hypr_or_alt(SS_TAP(X_4), record->event.pressed);
      break;

    // Launch 1Password - in ChromeOS, switch to the browser before issuing
    // shortcut keypress.

    case M_1PASS:
      if (record->event.pressed) {
        if (fk_is_chromebook) {
          SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_1)SS_UP(X_LALT));
          SEND_STRING(SS_DELAY(100));
          SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL));
          SEND_STRING(SS_TAP(X_X));
          SEND_STRING(SS_UP(X_LCTL)SS_UP(X_LSFT));
        } else {
          SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL));
          SEND_STRING(SS_TAP(X_SPC));
          SEND_STRING(SS_UP(X_LCTL)SS_UP(X_LSFT));
        }
      }
      break;

    // Switch between virtual desktops.

    case M_NDESK:
      if (record->event.pressed) {
        if (fk_is_chromebook) {
          SEND_STRING(SS_DOWN(X_LGUI));
          SEND_STRING(SS_TAP(X_RBRC));
          SEND_STRING(SS_UP(X_LGUI));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
          SEND_STRING(SS_TAP(X_RGHT));
          SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
        }
      }
      break;
    case M_PDESK:
      if (record->event.pressed) {
        if (fk_is_chromebook) {
          SEND_STRING(SS_DOWN(X_LGUI));
          SEND_STRING(SS_TAP(X_LBRC));
          SEND_STRING(SS_UP(X_LGUI));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
          SEND_STRING(SS_TAP(X_LEFT));
          SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
        }
      }
      break;

    // Open the emoji window.

    case M_EMOJI:
      if (record->event.pressed) {
        if (fk_is_chromebook) {
          SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LGUI));
          SEND_STRING(SS_TAP(X_SPC));
          SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LSFT));
        } else {
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_SCLN)SS_UP(X_LGUI));
        }
      }
      break;

    // Types out a four-digit pseudo-random number.

    case M_4RAND:
      if (record->event.pressed) {
        if (fk_srand_seeded == false) {
#if defined(__AVR_ATmega32U4__)
          srand(TCNT0 + TCNT1 + TCNT3 + TCNT4);
#else
          srand(timer_read32());
#endif
          fk_srand_seeded = true;
        }
        char rand_string[6];
        sprintf(rand_string, "%d", rand() % 10000 + 1000);
        SEND_STRING(rand_string);
      }
      break;

    // Swap between Windows and ChromeOS macro keypresses.

    case M_ISCROS:
      if (record->event.pressed) {
        fk_is_chromebook = true;
      }
      break;
    case M_ISWIN:
      if (record->event.pressed) {
        fk_is_chromebook = false;
      }
      break;

  }

  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Set the tapping term for the homerow mods.
    case KC_W_ALT:
    case KC_R_CTL:
    case KC_T_SFT:
    case KC_P_GUI:
    case KC_L_GUI:
    case KC_N_SFT:
    case KC_I_CTL:
    case KC_Y_ALT:
      return TAPPING_TERM_MODS;
    // Set the tapping term for layer keys.
    case KC_ENT_NUM_LAYER:
    case KC_SPC_NAV_LAYER:
    case KC_S_EXT_LEFT:
    case KC_E_EXT_RIGHT:
    case KC_A_SYM_LEFT:
    case KC_X_SYM_LEFT:
    case KC_Z_SYM_LEFT:
    case KC_O_SYM_RIGHT:
    case KC_DOT_SYM_RIGHT:
    case KC_SLSH_SYM_RIGHT:
      return TAPPING_TERM_LAYER;
    default:
      return TAPPING_TERM;
  }
}

// Only capitalise alpha characters and remove the minus character so that
// typing '-' stops the caps word.

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue caps word with shift applied.
    case KC_A ... KC_Z:
      // Apply shift to next key only.
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;
    // Keycodes that continue caps word without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;
    // Do not deactivate if the layer keys are held down.
    case KC_S_EXT_LEFT:
    case KC_E_EXT_RIGHT:
    case KC_A_SYM_LEFT:
    case KC_X_SYM_LEFT:
    case KC_Z_SYM_LEFT:
    case KC_O_SYM_RIGHT:
    case KC_DOT_SYM_RIGHT:
    case KC_SLSH_SYM_RIGHT:
      return true;
    // Deactivate caps word by default.
    default:
      return false;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (combo->keycode) {
    case CW_TOGG:
    case KC_SCUT_LAYER:
      return COMBO_TERM_CROSS_SPLIT;
    default:
      return COMBO_TERM;
  }
}

// Issues HYPR-keycode for Windows, for AutoHotkey to interpret, and ALT-keycode
// for ChromeOS, which launches the n'th app on the task bar.

void hypr_or_alt(char *ss, bool pressed) {
  if (pressed) {
    if (fk_is_chromebook) {
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(ss);
      SEND_STRING(SS_UP(X_LALT));
    } else {
      SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
      SEND_STRING(ss);
      SEND_STRING(SS_UP(X_LALT));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
    }
  }
}

// Reduce the size of the compiled firmware.

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
