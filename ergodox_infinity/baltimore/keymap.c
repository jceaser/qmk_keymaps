/**
Baltimore key map for QMK/ergodox
**/

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define DVORAK 0 // default layer
#define QWERTY 1 // second layer
#define SYMBOL 2 // symbols
#define MOUSE  3 // mouse keys
#define NUMBER 4 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
    , DYNAMIC_MACRO_RANGE
};

void _delay_ms(int i){}

#include "dynamic_macro.h"

#define DM_P1 DYN_MACRO_PLAY1
#define DM_R1 DYN_REC_START1
#define DM_P2 DYN_MACRO_PLAY2
#define DM_R2 DYN_REC_START2
#define DM_SP DYN_REC_STOP

/*#define DM_P1 KC_NO
#define DM_R1 KC_NO
#define DM_P2 KC_NO
#define DM_R2 KC_NO
#define DM_SP KC_NO*/


/*

DVORAK
* QWERTY
* Number
* Mouse
* Symbol

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |Number|           | Mouse|   6  |   7  |   8  |   9  |   0  |   /    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |SYMBOL|           |QWERTY|   F  |   G  |   C  |   R  |   L  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CONTROL|   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------| OSL  |           | LEAD |------+------+------+------+------+--------|
 * |  LSPO  |   ;  |   Q  |   J  |   K  |   X  |SYMBOL|           |      |   B  |   M  |   W  |   V  |   Z  |  RSPC  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ESC  |  `   | ISO# | Left | Right|                                       |  Up  | Down |   [  |   ]  | CAPS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGUI | Opt  |       |  OPT | Hyper|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | DEL  | Back |------|       |------| Enter|Space |
 *                                 |      |Space | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[DVORAK] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_EQL,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   TG(NUMBER),
    KC_TAB,     KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y,   TG(SYMBOL),
    KC_LCTL,    KC_A,   KC_O,   KC_E,   KC_U,   KC_I,
    KC_LSPO,    KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   OSL(SYMBOL),
    KC_ESC,     KC_GRV, KC_NUHS,KC_LEFT,KC_RGHT,
                                                KC_LGUI,KC_LALT,
                                                        KC_HOME,
                                        KC_BSPC,KC_DELT,KC_END,
    // right hand
    TG(MOUSE),  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_SLSH,
    TG(QWERTY), KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_BSLS,
                KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_MINS,
    KC_LEAD,    KC_B,   KC_M,   KC_W,   KC_V,   KC_Z, KC_RSPC,
                                KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,KC_CAPS,
    KC_RALT,    KC_HYPR,
    KC_PGUP,
    KC_PGDN,    KC_ENT, KC_SPC
),
/* Keymap 1: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWERTY] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(NUMBER),
    KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMBOL),
    KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
    KC_LSPO,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   OSL(SYMBOL),
    LT(SYMBOL,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                          ALT_T(KC_APP),  KC_LGUI,
                                                          KC_HOME,
                                           KC_SPC,KC_BSPC,KC_END,
    // right hand
    KC_RGHT,        KC_6,   KC_7,  KC_8,    KC_9,   KC_0,           KC_MINS,
    TG(SYMBOL),     KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,           KC_BSLS,
                    KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN,        GUI_T(KC_QUOT),
    MEH_T(KC_NO),   KC_N,   KC_M,  KC_COMM, KC_DOT, CTL_T(KC_SLSH), KC_RSPC,
                            KC_UP, KC_DOWN, KC_LBRC,KC_RBRC,        KC_FN1,
    KC_LALT,        CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,        KC_TAB, KC_ENT
),

/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 | DVORAK |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  F11 |  f12 |  f13 |  f14 |  f15 |      |           |      |  F16 |  F17 |  F18 |  F19 |  F20 | QWERTY |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  M1  | M1(R)| MSTOP|      |      |------|           |------|      |      | MSTOP| M2(R)|  M2  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      | Mute |      |      | Play |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      | Pre  | Next |                                       |  V-  |  V+  |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |L CMD |L OPT |       |R OPT |R CMD |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |Solid |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |Animat|       |Toggle|      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMBOL] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  DF(DVORAK),
       KC_TRNS,KC_F11,  KC_F12, KC_F13, KC_F14, KC_F15, /*DF(QWERTY)*/KC_TRNS,
       KC_TRNS,DM_P1,   DM_R1,  DM_SP,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          EPRM,KC_TRNS, KC_TRNS,KC_MPRV,KC_MNXT,
                                        KC_LGUI ,KC_LALT,
                                                KC_TRNS,
                                RGB_VAD,RGB_VAI,RGB_MOD,
       // right hand
       KC_TRNS, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
       KC_TRNS, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS,
                KC_TRNS,KC_TRNS,DM_SP,  DM_R2,  DM_P2,  KC_TRNS,
       KC_TRNS, KC_TRNS,KC_MUTE,KC_TRNS,KC_TRNS,KC_MPLY,KC_TRNS,
                        KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_RALT,    KC_RGUI,
       RGB_TOG,
       RGB_SLD, RGB_HUD, RGB_HUI
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  B1  |  B2  |  B3  |  B4  | B5   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft| MsUp |MsDown|MsRght|      |------|           |------|      |  w← |  w↓  |  w↑  |  w→  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MA0  | MA1  | MA2  |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MOUSE] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |NumLck|  =   |  /   |  *   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ←   |  ↓  |  ↑   |  →   |      |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |   .  | Enter|  ,   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[NUMBER] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_NUMLOCK,   KC_KP_EQUAL,KC_KP_SLASH,KC_KP_ASTERISK, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_KP_7,      KC_KP_8,    KC_KP_9,    KC_KP_MINUS,    KC_TRNS,
                 KC_TRNS, KC_KP_4,      KC_KP_5,    KC_KP_6,    KC_KP_PLUS,     KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_KP_1,      KC_KP_2,    KC_KP_3,    KC_KP_ENTER,    KC_TRNS,
                          KC_KP_0,      KC_KP_0,    KC_KP_DOT,  KC_KP_ENTER,    KC_KP_COMMA,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [2] = ACTION_LAYER_TAP_TOGGLE(SYMBOL),                // FN1 - Momentary Layer 1 (Symbols)
    [3] = ACTION_LAYER_TAP_TOGGLE(MOUSE),                // FN1 - Momentary Layer 1 (Symbols)
    [4] = ACTION_LAYER_TAP_TOGGLE(NUMBER)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    //if (!process_record_dynamic_macro(keycode, record)) {return false;}
    
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
