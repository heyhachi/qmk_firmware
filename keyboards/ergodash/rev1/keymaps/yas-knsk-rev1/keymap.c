#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)
#define CTL_F1 (LCTL(KC_F1))
#define CTL_F2 (LCTL(KC_F2))
#define CTL_F3 (LCTL(KC_F3))
#define CTL_F4 (LCTL(KC_F4))
#define CTL_F5 (LCTL(KC_F5))
#define CTL_F6 (LCTL(KC_F6))
#define CTL_F7 (LCTL(KC_F7))
#define CTL_F8 (LCTL(KC_F8))
#define CTL_F9 (LCTL(KC_F9))
#define CTL_F10 (LCTL(KC_F10))
#define CTL_F11 (LCTL(KC_F11))
#define CTL_F12 (LCTL(KC_F12))
#define ALT_F1 (LALT(KC_F1))
#define ALT_F2 (LALT(KC_F2))
#define ALT_F3 (LALT(KC_F3))
#define ALT_F4 (LALT(KC_F4))
#define ALT_F5 (LALT(KC_F5))
#define ALT_F6 (LALT(KC_F6))
#define ALT_F7 (LALT(KC_F7))
#define ALT_F8 (LALT(KC_F8))
#define ALT_F9 (LALT(KC_F9))
#define ALT_F10 (LALT(KC_F10))
#define ALT_F11 (LALT(KC_F11))
#define ALT_F12 (LALT(KC_F12))

//ユーザーマクロ定義
enum user_macro {
    UM_EMHL,
    UM_KHKR
};
#define M_EMHL MACROTAP(UM_EMHL)      // 「Lower」キー用のキーコード
#define M_KHKR MACROTAP(UM_KHKR)      // 「Raise」キー用のキーコード

//タップダンスの定義
enum {
  TD_CTL_GUI = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTL_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   +  |   6  |   7  |   8  |   9  |   0  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   \  |                    |   /  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Alt  |   Z  |   X  |   C  |   V  |   B  | GUI  |                    |Space |   N  |   M  |   ,  |   .  |   /  | Alt  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |CT+AT |CT+ST | Shift|  Alt |||||||| Lower| Space|CTL/GUI|||||||| Bksp| Enter| Raise|||||||| GUI  | Shift|Insert|CTL+Sp|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC       , KC_1         ,    KC_2,    KC_3    , KC_4, KC_5  , KC_MINS,                                           KC_EQL , KC_6  , KC_7   , KC_8   , KC_9   , KC_0,    KC_GRV , \
    KC_TAB       , KC_Q         ,    KC_W,    KC_E    , KC_R, KC_T  , KC_LBRC,                                           KC_RBRC, KC_Y  , KC_U   , KC_I   , KC_O   , KC_P,    KC_BSLS, \
    KC_LCTL      , KC_A         ,    KC_S,    KC_D    , KC_F, KC_G  , KC_BSLS,                                           KC_SLSH, KC_H  , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
    KC_LALT      , KC_Z         ,    KC_X,    KC_C    , KC_V, KC_B  , KC_LGUI,                                           KC_SPC , KC_N  , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT, \
    LCTL(KC_LALT), LCTL(KC_LSFT), _______, MO(_ADJUST),       M_EMHL, SFT_T(KC_SPC),TD(TD_CTL_GUI),       KC_BSPC,SFT_T(KC_ENT) , M_KHKR,          KC_RGUI, KC_RSFT, KC_INS , LCTL(KC_SPC)  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | Alt  |||||||| Lower| Space|CTL/GUI|||||||| Bksp | Enter| Raise|||||||| Shift| Space|Insert|CTL+Sp|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______ , _______,  \
    _______, _______, _______, _______, KC_LPRN, _______, _______,                       _______, KC_RPRN, KC_7   , KC_8   , KC_9   , KC_0    , _______,  \
    _______, _______, _______, _______, KC_COMM, _______, _______,                       _______, KC_DOT , KC_4   , KC_5   , KC_6   , KC_ASTR , _______, \
    _______, _______, _______, _______, _______, _______, _______,                       _______, KC_COMM, KC_1   , KC_2   , KC_3   , _______ , _______, \
    _______, _______, _______, _______,          _______, _______,_______,       _______,_______, _______,          _______, _______, _______ , _______  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |   +  |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    | Bksp |      | Left | Down |  Up  | Right|      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|      | Home |PageDn|PageUp| End  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | Alt  |||||||| Lower| Space|CTL/GUI|||||||| Bksp | Enter| Raise|||||||| Shift| Space|Insert|CTL+Sp|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                       KC_RCBR, KC_F6  ,   KC_F7,   KC_F8,   KC_F9, KC_F10  ,  KC_F12,  \
    _______, _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______ , _______, \
    _______, _______, _______, _______, _______, _______, _______,                       _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, \
    _______, _______, _______, _______, _______, _______, _______,                       _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  , _______, \
    _______, _______, _______, _______,          _______, _______,_______,       _______,_______, _______,          _______, _______, _______ , _______  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                      _______, _______, KC_F10 , KC_F11 , KC_F12 , _______, _______,  \
    _______, _______, _______, _______, _______, _______, _______,                      _______, _______, KC_F7  , KC_F8  , KC_F9  , _______, _______,  \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_F4  , KC_F5  , KC_F6  , _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_F1  , KC_F2  , KC_F3  , _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       KC_DEL ,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case UM_EMHL: // タップで「英数」と「無変換」、ホールドで「Lower」
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(LALT), T(LANG2), END), _LOWER );
        case UM_KHKR: // タップで「かな」と「変換」、ホールドで「Raise」
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(RALT), T(LANG1), END), _RAISE );
    };
    return MACRO_NONE;
}
