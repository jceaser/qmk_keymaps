/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand

enum xd75_layers
{
    _DVORAK
    , _QWERTY
    , _LOWER
    , _RAISE
    , _ADJUST
};

#define LOWER M(_LOWER)
#define RAISE M(_RAISE)

enum xd75_keycodes
{
    DVORAK = SAFE_RANGE
    , QUERTY
    //, LOWER
    //, UPPER
    //, BOTH
    , MACRO_CREDIT
    , DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define DM_R1 DYN_REC_START1
#define DM_R2 DYN_REC_START2
#define DM_P1 DYN_MACRO_PLAY1
#define DM_P2 DYN_MACRO_PLAY2
#define DM_SP DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

/* Dvorak
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | '      | 1      | 2      | 3      | 4      | 5      | INSERT | 6      | 7      | 8      | 9      | 0      | =      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | HOME   | TAB    | '      | ,      | .      | P      | Y      | M1     | F      | G      | C      | R      | L      | /      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | PG UP  | CTRL   | A      | O      | E      | U      | I      | M2     | D      | H      | T      | N      | S      | -      | [      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | P DOWN | LSHIFT | ;      | Q      | J      | K      | X      | DEL    | B      | M      | W      | V      | Z      | RSHIFT | ]      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | END    | LEAD   | HYPER  | OPT    | CMD    | L DOWN | ENTER  | LOCK   | SPACE  | LAY UP | CMD    | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_DVORAK] = { /* Dvorak */
  { KC_ESC,   KC_GRV,    KC_1,    KC_2,    KC_3,  KC_4,  KC_5,    KC_NO,     KC_6,  KC_7,   KC_8,   KC_9,     KC_0,  KC_EQL, KC_BSPC },
  { KC_HOME,  KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,  KC_P,  KC_Y,    DM_P1,     KC_F,  KC_G,   KC_C,   KC_R,     KC_L, KC_SLSH, KC_BSLS },
  { KC_PGUP, KC_LCTL,    KC_A,    KC_O,    KC_E,  KC_U,  KC_I,    DM_P2,     KC_D,  KC_H,   KC_T,   KC_N,     KC_S, KC_MINS, KC_LBRC },
  { KC_PGDN, KC_LSPO, KC_SCLN,    KC_Q,    KC_J,  KC_K,  KC_X,   KC_DEL,     KC_B,  KC_M,   KC_W,   KC_V,     KC_Z, KC_RSPC, KC_RBRC },
  { KC_END,  KC_LEAD, KC_HYPR, KC_LALT, KC_LGUI, LOWER, KC_ENT, KC_LOCK, KC_SPACE, RAISE, KC_RGUI, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT},
 },

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_MINS, KC_GRV,  KC_EQL,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_QUOT },
  { KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_HOME, KC_DEL,  KC_PGUP, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT  },
  { KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_END,  KC_UP,   KC_PGDN, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC },
  { KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, RAISE, KC_RALT, KC_RGUI, KC_RCTL },
 },

/* *****************************************************************************
 * FUNCTION DOWN - LEFT HAND HOLDING
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  |        | F1     | F2     | F3     | F4     | F5     |        | F6     | F7     | F8     | F9     | F10    |        | Delete |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | F11    | F12    | F13    |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | MUTE   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        |        |        |TRANS(X)| PLAY   | PLAY   | PLAY   | TRANS  | PENT   | PRE    | VOL-   | VOL+   | NEXT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_LOWER] = { /* FUNCTION - lower (left hand holding) */
  { RESET, KC_NO,  KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO,  KC_DEL },
  { KC_NO, KC_NO, KC_F11, KC_F12, KC_F13,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO },
  { KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO },
  { KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO },
  { RESET, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_TRNS, KC_MPLY, KC_MPLY, KC_MPLY, KC_TRNS, KC_TRNS, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD },
 },

/* *****************************************************************************
 * FUNCTION UP - RIGHT HAND HOLDING DOWN
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        | MA0    | MA 1   | MA 2   | (4)    | (5)    |        | (6)    | NumLock| /      | *      | -      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        | MB1    | MB2    | MB3    | MB4    | MB5    |        |        | 7      | 8      | 9      | +      |        | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        | M <-   | M-Down | M-Up   | M ->   |        |        |        | 4      | 5      | 6      | +      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        | MS <-  | M-Down | M-Up   | MS ->  |        |        |        | 1      | 2      | 3      | Enter  |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | L-Down |        |        |        |L-Up (X)| 0      | .      | Enter  |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_RAISE] = { /* FUNCTION - upper (right hand holding) */
  /*                           1              2            3               4           5             6        7        8        9        0             */
  { KC_NO, KC_NO,       KC_ACL0,       KC_ACL1,     KC_ACL2,          KC_NO,      KC_NO, KC_NO, KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_NO },
  { KC_NO, KC_NO,    KC_MS_BTN1,    KC_MS_BTN2,  KC_MS_BTN3,     KC_MS_BTN4, KC_MS_BTN5, KC_NO, KC_NO,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_NO, KC_NO },
  { KC_NO, KC_NO,       KC_MS_L,       KC_MS_D,     KC_MS_U,        KC_MS_R,      KC_NO, KC_NO, KC_NO,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_NO, KC_NO },
  { KC_NO, KC_NO, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT,      KC_NO, KC_NO, KC_NO,   KC_P1,   KC_P2,   KC_P3, KC_PENT, KC_NO, KC_NO },
  { KC_NO, KC_NO,         KC_NO,         KC_NO,       KC_NO,        KC_TRNS,      KC_NO, KC_NO, KC_NO, KC_TRNS,   KC_P0, KC_PDOT, KC_PENT, KC_NO, KC_NO },
 },

/* *****************************************************************************
 * Function Both - both down
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  |        | F1     | F2     | F3     | F4     | F5     |        | F6     | F7     | F8     | F9     | F10    |        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | F11    | F12    | F13    |        | MRec 1 |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | MRec 2 |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | M-Stop |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        |        |        | TRANS  |        |        |        | TRANS  |        |        |        |        | RESET  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_ADJUST] = { /* FUNCTION - both (two keys holding) */
  { RESET, KC_NO,  KC_F1,  KC_F2,  KC_F3,   KC_F4, KC_F5, KC_NO, KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, RESET },
  { KC_NO, KC_NO, KC_F11, KC_F12, KC_F13,   KC_NO, KC_NO, DM_R1, KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO },
  { KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO, KC_NO, DM_R2, KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, MACRO_CREDIT },
  { KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO, KC_NO, DM_SP, KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO },
  { RESET, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO, RESET },
 }

/* ************************************************************************** */
};

const uint16_t PROGMEM fn_actions[] = {

};

LEADER_EXTERNS();

void matrix_scan_user(void)
{
    LEADER_DICTIONARY()
    {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_F)
        {
            register_code(KC_S);
            unregister_code(KC_S);
        }

        SEQ_TWO_KEYS(KC_J, KC_C){SEND_STRING("jceaser@mac.com");}
        SEQ_TWO_KEYS(KC_T, KC_C){SEND_STRING("thomas.cherry@gmail.com");}
        SEQ_THREE_KEYS(KC_T, KC_A, KC_C){SEND_STRING("thomas.a.cherry@nasa.gov");}

        SEQ_THREE_KEYS(KC_A, KC_S, KC_D)
        {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!process_record_dynamic_macro(keycode, record)) {return false;}

    if (record->event.pressed)
    {
        switch(keycode)
        {
            case MACRO_CREDIT:
                SEND_STRING("XD75 - Baltimore layout by thomas.cherry@gmail.com");
                return false;
                break;
        }
    }

    return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        /*case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;*/

        case _LOWER:
            //backlight_toggle();
            if (record->event.pressed)
            {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            else
            {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            break;
        case _RAISE:
            //backlight_toggle();
            if (record->event.pressed)
            {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            else
            {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            break;
      }
    return MACRO_NONE;
};
