/*
Copyright 2020 Holten Campbell

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
#include QMK_KEYBOARD_H

#define ______ KC_TRNS

static uint16_t key_trigger = 0; //1 = hold repeat NORELOAD 2 = VERTICAL FARM 3 = HORIZONTAL FARM
static uint16_t key_timer = 0;

enum custom_keycodes {
  //MAPLE
  NRL_BOB = SAFE_RANGE,
  NRL_WEAVE,
  NRL_BOB_S,
  NRL_WEAVE_S,
  SG_BOB,
  SG_WEAVE,
  SG_BOB_S,
  SG_WEAVE_S,
  NRLHAMMER,
  SKATE,
};
  // NLRHAMMER,
  // SG_BOB,
  // SG_WEAVE,
  // SKATE,

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NRL_BOB:
            if (record->event.pressed) {
                key_trigger = 1;
            } else {
                key_trigger = 0;
            }
            break;

        case NRL_WEAVE:
            if (record->event.pressed) {
                key_trigger = 2;
            } else {
                key_trigger = 0;
            }
            break;

        case NRL_BOB_S:
            if (record->event.pressed) {
                key_trigger = 3;
            } else {
                key_trigger = 0;
            }
            break;

        case NRL_WEAVE_S:
            if (record->event.pressed) {
                key_trigger = 4;
            } else {
                key_trigger = 0;
            }
            break;

        case SG_BOB:
          if (record->event.pressed) {
              key_trigger = 5;
            } else {
              key_trigger = 0;
          }
          break;

        case SG_WEAVE:
          if (record->event.pressed) {
              key_trigger = 6;
            } else {
              key_trigger = 0;
          }
          break;

        case SG_BOB_S:
          if (record->event.pressed) {
              key_trigger = 7;
            } else {
              key_trigger = 0;
          }
          break;

        case SG_WEAVE_S:
          if (record->event.pressed) {
              key_trigger = 8;
            } else {
              key_trigger = 0;
          }
          break;

        case NRLHAMMER:
          if (record->event.pressed) {
              SEND_STRING(
                SS_DOWN(X_R)
                SS_DOWN(X_A)
                SS_DELAY(60)
                SS_TAP(X_E)
                SS_DELAY(260)
                SS_UP(X_R)
                SS_DELAY(200)
                SS_TAP(X_D)
                SS_DELAY(350)
                SS_UP(X_A)
                SS_DELAY(5)
                SS_TAP(X_SPC)
                SS_DELAY(60)
              );
          }
          break;

        case SKATE:
          if (record->event.pressed) {
              SEND_STRING(
                SS_DOWN(X_A)
              );
            } else {
              SEND_STRING(
                SS_UP(X_A)
                SS_DELAY(240)
                SS_TAP(X_SPC)
                SS_TAP(X_V)
              );
          }
          break;
    }
    return true;
};

void matrix_scan_user(void) {
    switch (key_trigger) {
        // NRL_BOB
        case 1: {
            if (timer_elapsed(key_timer) > 60) {
                SEND_STRING(
                    SS_DOWN(X_A)
                    SS_TAP(X_D)
                    SS_DELAY(180)
                    SS_TAP(X_F)
                    SS_DELAY(250)
                    SS_UP(X_A)
                    SS_DELAY(5)
                    SS_TAP(X_SPC)
                    SS_DELAY(60)
                );
                key_timer = timer_read32();
            }
        } break;
        // NRL_WEAVE
        case 2: {
            if (timer_elapsed(key_timer) > 60) {
                SEND_STRING(
                    SS_DOWN(X_S)
                    SS_TAP(X_D)
                    SS_DELAY(180)
                    SS_TAP(X_F)
                    SS_DELAY(220)
                    SS_UP(X_S)
                    SS_DELAY(5)
                    SS_TAP(X_SPC)
                    SS_DELAY(60)
                );
                key_timer = timer_read32();
            }
        } break;
        // NRL_BOB_S
        case 3: {
            if (timer_elapsed(key_timer) > 10) {
                SEND_STRING(
                    SS_DOWN(X_A)
                    SS_TAP(X_D)
                    SS_DELAY(100)
                    SS_TAP(X_F)
                    SS_DELAY(220)
                    SS_UP(X_A)
                    SS_DELAY(200)
                    SS_TAP(X_SPC)
                    SS_DELAY(60)
                );
                key_timer = timer_read32();
            }
        } break;
        // NRL_WEAVE_S
        case 4: {
            if (timer_elapsed(key_timer) > 10) {
                SEND_STRING(
                    SS_DOWN(X_S)
                    SS_TAP(X_D)
                    SS_DELAY(100)
                    SS_TAP(X_F)
                    SS_DELAY(220)
                    SS_UP(X_S)
                    SS_DELAY(200)
                    SS_TAP(X_SPC)
                    SS_DELAY(60)
                );
                key_timer = timer_read32();
            }
        } break;
        // SG_BOB
        case 5: {
          if (timer_elapsed(key_timer) > 50) {
            SEND_STRING(
              SS_TAP(X_G)
              SS_DOWN(X_A)
              SS_DELAY(200)
              SS_UP(X_A)
              SS_DELAY(5)
              SS_TAP(X_SPC)
              SS_DELAY(140)
            );
            key_timer = timer_read32();
          }
        } break;
        // SG_WEAVE
        case 6: {
          if (timer_elapsed(key_timer) > 50) {
            SEND_STRING(
              SS_TAP(X_G)
              SS_DOWN(X_S)
              SS_DELAY(200)
              SS_UP(X_S)
              SS_DELAY(5)
              SS_TAP(X_SPC)
              SS_DELAY(140)
            );
            key_timer = timer_read32();
          }
        } break;
        // SG_BOB_S - shotgun punch small dash
        case 7: {
          if (timer_elapsed(key_timer) > 10) {
            SEND_STRING(
              SS_TAP(X_G)
              SS_DOWN(X_A)
              SS_DELAY(200)
              SS_UP(X_A)
              SS_DELAY(200)
              SS_TAP(X_SPC)
              SS_DELAY(90)
            );
            key_timer = timer_read32();
          }
        } break;
        // SG_WEAVE_S - shotgun punch small dash
        case 8: {
          if (timer_elapsed(key_timer) > 10) {
            SEND_STRING(
              SS_TAP(X_G)
              SS_DOWN(X_S)
              SS_DELAY(200)
              SS_UP(X_S)
              SS_DELAY(200)
              SS_TAP(X_SPC)
              SS_DELAY(90)
            );
            key_timer = timer_read32();
          }
        } break;

      default:
      break;	
    }
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_bs_rshift(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_UP, MO(1),
		KC_LCTL, KC_LGUI,                   KC_LALT, KC_SPC,   KC_SPC,  KC_RALT,                                     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_split_bs_rshift(
    	KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC,
    	_______, TO(0), KC_PGUP, TO(2), _______, _______, _______, _______, KC_UP,   _______, KC_MPRV, KC_MPLY, KC_MNXT,          _______,
    	_______, KC_HOME, KC_PGDN, KC_END,  _______, KC_VOLD, KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______,
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PSCR, _______,
    	_______, _______, _______,          _______,          _______,          _______,                   _______, _______, _______
  ),
  	[2] = LAYOUT_split_bs_rshift(
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    	_______, _______, _______, _______, _______, NRLHAMMER, _______, _______, _______, _______, _______, _______, _______,          _______,
    	MO(3), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    	_______, NRL_BOB, NRL_WEAVE, SG_BOB, SG_WEAVE, SKATE, _______, _______, _______, _______, _______, _______,          _______, _______,
    	_______, _______, _______,          _______,          _______,          _______,                   _______, _______, _______
  ),
	[3] = LAYOUT_split_bs_rshift(
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    	_______, NRL_BOB_S, NRL_WEAVE_S, SG_BOB_S, SG_WEAVE_S, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    	_______, _______, _______,          _______,          _______,          _______,                   _______, _______, _______
  )
};