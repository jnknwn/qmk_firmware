#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_all( /* Base */
/*
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┐
* │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │010│011│012│013│014│  │015│016│017│
* ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤  ├───┼───┼───┤
* │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │110│111│112│113  │  │115│116│117│
* ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤  └───┴───┴───┘
* │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │210│211│213     │
* ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤      ┌───┐
* │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │310│311│313   │314│      │316│
* ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬┴──┬───┼───┤  ┌───┼───┼───┐
* │40  │41  │42  │44      │46  │48        │410│411│412│413│414│  │415│416│417│
* └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘  └───┴───┴───┘
*/
//0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,   KC_INS,   KC_HOME,  KC_PGUP,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,             KC_DEL,   KC_END,   KC_PGDN,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  MO(1),              KC_UP,
  KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_SPC,             KC_SPC,             KC_RALT,  KC_RALT,  KC_RGUI,  KC_RGUI,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT   ),

[1] = LAYOUT_all( /* FN */
//0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,   KC_INS,   KC_HOME,  KC_PGUP,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_DEL,   KC_END,   KC_PGDN,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  MO(1),              KC_UP,
  KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_SPC,             KC_SPC,             KC_RALT,  KC_RALT,  KC_RGUI,  KC_RGUI,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT   ),

[2] = LAYOUT_all( 
//0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,   KC_INS,   KC_HOME,  KC_PGUP,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_DEL,   KC_END,   KC_PGDN,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  MO(1),              KC_UP,
  KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_SPC,             KC_SPC,             KC_RALT,  KC_RALT,  KC_RGUI,  KC_RGUI,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT   ),

[3] = LAYOUT_all( 
//0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,   KC_INS,   KC_HOME,  KC_PGUP,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_DEL,   KC_END,   KC_PGDN,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  MO(1),              KC_UP,
  KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_SPC,             KC_SPC,             KC_RALT,  KC_RALT,  KC_RGUI,  KC_RGUI,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif
  return true;
}
