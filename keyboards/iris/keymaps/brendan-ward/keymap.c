#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

// custom combinations
#define SAVE LGUI(KC_S)  // Command-S ("save" on Mac)
#define HOME LGUI(KC_LEFT) // Go to start of line
#define END LGUI(KC_RIGHT) // Go to line end
#define PLUS LSFT(KC_EQL)
#define L_CURL LSFT(KC_LBRC)
#define R_CURL LSFT(KC_RBRC)
#define PIPE LSFT(KC_BSLASH)
#define L_PAR LSFT(9)
#define R_PAR LSFT(0)

// spectacle shortcuts
#define F_SCR LGUI(LALT(KC_F))
#define L_SCR LGUI(LALT(KC_LEFT))
#define R_SCR LGUI(LALT(KC_RIGHT))


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Atreus: https://github.com/brendan-ward/tmk_keyboard/blob/atreus/keyboard/atreus/keymap_qwerty_bcw.c
#define LAYER_0 KEYMAP( \
  KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,   KC_I,    KC_O,       KC_P, \
  KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,   KC_K,    KC_L,       KC_ENT, \
  KC_Z, KC_X,   KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,   KC_COMM, KC_DOT,     KC_QUOT, \
  KC_ESC, KC_TAB, KC_LALT, KC_LSFT, KC_SPC, KC_LGUI,    KC_LCTL, KC_BSPC, KC_FN0, KC_FN3,  GUI(KC_S),  KC_SCLN)
*/

    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,           KC_LCTL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_LALT, KC_LSFT, KC_SPC,                  KC_BSPC,  LOWER,  SAVE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

/*
#define LAYER_1 KEYMAP( \
  KC_1,           KC_2,           KC_3,     KC_4,      KC_5,                     KC_6,          KC_7,     KC_8,     KC_9,      KC_0, \
  SHIFT(KC_LBRC), SHIFT(KC_RBRC), KC_LBRC,  KC_RBRC,   KC_MINS,                  GUI(KC_LEFT),  KC_LEFT,  KC_UP,    KC_RIGHT,  GUI(KC_RIGHT),  \
  SHIFT(KC_9),    SHIFT(KC_0),    KC_SLASH, KC_BSLASH, KC_EQL,                   KC_NO,         KC_PGUP,  KC_DOWN,  KC_PGDN,   KC_GRAVE,  \
  KC_FN1,         KC_NO,          KC_NO,    KC_LSFT,   KC_SPC, KC_LGUI, KC_LCTL, KC_BSPC,       KC_FN0,   KC_FN1,   KC_NO,     KC_DEL)
*/



  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,   PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      L_CURL,  R_CURL, KC_LBRC, KC_RBRC,   KC_NO,  KC_MINS,                             KC_NO,  KC_PGUP,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      L_PAR,   R_PAR,   KC_NO,  KC_SLASH,KC_BSLASH, KC_EQL,                              HOME,  KC_LEFT,  KC_UP,  KC_RIGHT,  END,    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼───────,─┼────────┼────────┼────────┼────────┼────────┤
      F_SCR,   L_SCR,   R_SCR,    KC_NO,   KC_NO,   PIPE,  _______,          _______, KC_NO,   KC_PGDN, KC_DOWN,  KC_NO, KC_BSLASH, KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),



/*
#define LAYER_2 KEYMAP( \
  KC_F3,  KC_F4,      KC_F5,      KC_F6,      KC_F7,                     KC_F8,    KC_F9,    KC_F10,  KC_F11, KC_F12,   \
  KC_F1,  KC_F2,      KC_NO,      KC_NO,      KC_NO,                     KC_PGUP,  KC_LEFT,  KC_UP,   KC_RIGHT, KC_ENT,   \
  KC_NO,  GUI(KC_X), GUI(KC_C), GUI(KC_V), KC_FN4,                    KC_PGDN,  KC_HOME,  KC_DOWN, KC_END, KC_NO,   \
  KC_FN2, KC_TAB,     KC_NO,    KC_LSFT,    KC_SPC, KC_LGUI,  KC_LCTL,   KC_BSPC,  KC_FN2,   KC_NO,   KC_NO, KC_NO)
*/



//   [_RAISE] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     _______, _______, _______,                   _______, _______, _______
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
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
