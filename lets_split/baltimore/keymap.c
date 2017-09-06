#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _COLEMAK 2
#define _LOWER 3
#define _RAISE 4
#define _NAVIGATION 5
#define _NUMPAD 6
#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  LOWER,
  RAISE,
  NAV, EXT_NAV,
  NUMPAD, EXT_NUMPAD, 
  ADJUST,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h" //yes this must go here after the keycodes

#define DM_P_1 DYN_MACRO_PLAY1
#define DM_RS_1 DYN_REC_START1
#define DM_P_2 DYN_MACRO_PLAY2
#define DM_RS_2 DYN_REC_START2
#define DM_RS  DYN_REC_STOP

// Fillers to make layering more clear
//#define _______ KC_TRNS
//#define _______ KC_TRANSPARENT
//#define XXXXXXX KC_NO

/*
DVORAK
    LOWER
    RAISE
    ADJUST (lower+rise)
        QWERTY
        COLEMAK
        KEYPAD
    NAV
*/

/*
DYN_REC_START1 — start recording the macro 1,
DYN_REC_START2 — start recording the macro 2,
DYN_MACRO_PLAY1 — replay the macro 1,
DYN_MACRO_PLAY2 — replay the macro 2,
DYN_REC_STOP — finish the macro that is currently being recorded.
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LS ( |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | RS ) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |Adjust| Alt  | GUI  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = KEYMAP( \
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,    KC_MINS, \
    KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,    KC_RSPC, \
    KC_ESC,  NAV,     KC_LALT, KC_LGUI, LOWER, KC_ENT, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | NAV  | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
    KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A, KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSPO, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC , \
    KC_ESC,  NAV,  KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = KEYMAP( \
    KC_TAB,  KC_Q, KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
    KC_LCTL, KC_A, KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT, \
    KC_LSPO, KC_Z, KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
    KC_ESC,  NAV,  KC_LALT, KC_LGUI, LOWER, KC_ENT, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   0  |   )  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  M1  | M1(R)| MSTP |      |      |      |      |   /  |   =  |  \   |KP Ent|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Help |   [  | Hyper|  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |      |      | Home |  PG↓ |  PG↑ | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,    KC_DEL, \
    _______, DM_P_1,  DM_RS_1, DM_RS,   _______, _______, _______, _______, KC_SLSH, KC_EQL,    KC_BSLS, KC_RETURN, \
    _______, _______, _______, _______, _______, _______, _______, KC_HELP, KC_LBRC, KC_HYPR,   KC_RBRC, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ?   |  +   |  |   |      |      |      |      | MSTP | M2(R)|  M2  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  {   | MEH  |  }   | ISO# | ISO/ |      | Mute |      |      | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Return|      |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_DEL,
    _______, KC_QUES, KC_PLUS, KC_PIPE, _______, _______,  _______, _______, DM_RS,   DM_RS_2, DM_P_2,  _______,
    _______, KC_LCBR, KC_MEH,  KC_RCBR, KC_NUHS, KC_NUBS,  _______, KC_MUTE, _______, _______, KC_MPLY, _______,
    _______, _______, _______, _______, _______, KC_KP_ENTER, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      | MB1  | MB2  | MB3  | MB4  | MB5  |      |      |      |      |      |ExtNav|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  m← |  m↓  |  m↑  |  m→  |      |      |  w← |  w↓  |  w↑  |  w→  |  ,   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | MA0  | MA1  | MA2  |      |      |      |      |      |      |  ↑   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |      |      |      |      | Enter| Space|      |      |  ←  |  ↓   |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATION] = KEYMAP( \
    _______, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN4,  KC_MS_BTN5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, \
    _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,   KC_MS_RIGHT, XXXXXXX,    XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, \
    _______, KC_ACL0,    KC_ACL1,    KC_ACL2,    XXXXXXX,     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   _______, \
    KC_ESC , EXT_NAV,    _______,    _______,    _______,     KC_ENT,     KC_SPC,  _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Number Pad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  0   |  1   |  4   |  7   |NumLck|ExtNav|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  0   |  2   |  5   |  8   |  =   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  .   |  3   |  6   |  9   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      | Entr | Entr |  +   |  -   |  *   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = KEYMAP( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_0,     KC_KP_1,     KC_KP_4,    KC_KP_7,     KC_NUMLOCK,     EXT_NUMPAD, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_0,     KC_KP_2,     KC_KP_5,    KC_KP_8,     KC_KP_EQUAL,    KC_KP_COMMA, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_DOT,   KC_KP_3,     KC_KP_6,    KC_KP_9,     KC_KP_SLASH,    XXXXXXX, \
    KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_ENTER, KC_KP_ENTER, KC_KP_PLUS, KC_KP_MINUS, KC_KP_ASTERISK, XXXXXXX \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Nav  | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  |Dvorak|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |NumPad| F11  | F12  | F13  | F14  | F15  | F16  | F17  | F18  | F19  | F20  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Aud on|Audoff|AGnorm|AGswap| EJCT |Power |Dvorak|Qwerty|Colemk| Nav  |NumPad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |      |      |      |      | Reset|Reset |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
    NAV,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  DVORAK, \
    NUMPAD,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX, \
    XXXXXXX, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_EJCT, KC_POWER, DVORAK,  QWERTY,  COLEMAK, NAV,     NUMPAD, \
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, _______, RESET,   RESET,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_nav[][2]        = SONG(PLOVER_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
    if (!process_record_dynamic_macro(keycode, record)) {return false;}
  
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAVIGATION);
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_NOTE_ARRAY(tone_nav, false, 0);
                #endif
      }
      return false;
      break;
    case EXT_NAV:
      if (record->event.pressed) { layer_off(_NAVIGATION);}
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_NOTE_ARRAY(tone_nav, false, 0);
                #endif
      }
      return false;
      break;
    case EXT_NUMPAD:
      if (record->event.pressed) { layer_off(_NUMPAD);}
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

extern keyrecord_t macro_buffer;
extern keyrecord_t *macro_end;
//extern keyrecord_t *r_macro_buffer;
//extern keyrecord_t *r_macro_end;

LEADER_EXTERNS();

void matrix_scan_user(void)
{
    LEADER_DICTIONARY()
    {
        leading = false;
        leader_end();
        
        /*SEQ_ONE_KEY(KC_O)
        {
            dynamic_macro_play(macro_buffer, macro_end, 1);
        }*/
        
        SEQ_ONE_KEY(KC_A)
        {
            keypos_t key = {.col = 1, .row = 1};
            keyevent_t event = {.key = key , .pressed = true, .time = 1};
            keyrecord_t record = { .event = event };
            process_record_dynamic_macro(DYN_MACRO_PLAY1, &record);
            
            //register_code(KC_S);
            //unregister_code(KC_S);
        }
        
        //play macro 1
        SEQ_TWO_KEYS(KC_M, KC_A)
        {
            keypos_t key = {.col = 1, .row = 1};
            keyevent_t event = {.key = key , .pressed = true, .time = 1};
            keyrecord_t record = { .event = event };
            process_record_dynamic_macro(DYN_MACRO_PLAY1, &record);
            //dynamic_macro_play(macro_buffer, macro_end, +1);
            //register_code(DYN_MACRO_PLAY1);
            //unregister_code(KC_DYN_MACRO_PLAY1);
        }
        //record macro 1
        /*SEQ_THREE_KEYS(KC_M, KC_A, KC_A)
        {
            register_code(DYN_REC_START1);
            unregister_code(DYN_REC_START1);
        }*/
        //end macro record
        /*SEQ_TWO_KEYS(KC_M, KC_ESC)
        {
            register_code(DYN_REC_STOP);
            unregister_code(DYN_REC_STOP);
        }*/
    }
}