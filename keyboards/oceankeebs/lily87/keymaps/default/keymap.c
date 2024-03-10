#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
    * ,---------------------------.   ,-----------------------------------------.                    ,-----------------------------------------.   ,---------------------------.
    * | ESC  |   /  |   *  |BackSp|   | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |   |      | Ins  | Home | PgUp |
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   7  |   8  |   9  |  -   |   | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|   |      | Del  | End  |PgDown|
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   4  |   5  |   6  |  +   |   |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |   |      |      |      |      |
    * |------+------+------+------|   |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|   |------+------+------+------|
    * |   1  |   2  |   3  |Enter |   |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|   |      |      |  Up  |      |
    * |------+------+------+------|   `-----------------------------------------/       /     \      \-----------------------------------------'   |------+------+------+------|
    * |  Fn  |   0  |   .  |Enter |                     | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI |                    |      | Left | Down |Right |
    * `---------------------------'                     |      |      |      |/       /         \      \ |      |      |      |                    `---------------------------'
    *                                                   `----------------------------'           '------''--------------------'
    */
  [_QWERTY] = LAYOUT(
      KC_ESC,  KC_PSLS, KC_PAST, KC_BSPC,      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,       XXXXXXX, KC_INS,  KC_HOME, KC_PGUP,  
      KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,      XXXXXXX, KC_DEL,  KC_END,  KC_PGDN,  
      KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
      KC_P1,   KC_P2,   KC_P3,   KC_PENT,      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, 
      MO(_LOWER), KC_P0, KC_PDOT, KC_PENT,                          KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,  KC_ENT, MO(_RAISE), KC_RALT, KC_RGUI,                                XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  
    ),
    

    /* LOWER
    * ,---------------------------.   ,-----------------------------------------.                    ,-----------------------------------------.   ,---------------------------.
    * | ESC  |   /  |   *  |BackSp|   | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   |      | Ins  | Home | PgUp |
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   7  |   8  |   9  |  -   |   | Tab  | Play | Prev |VolUp |VolDwn| Next |                    |      |      |      |      |      | Del  |   |      | Del  | End  |PgDown|
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   4  |   5  |   6  |  +   |   |LCTRL |      | Left |  Up  | Down |Right |-------.    ,-------|      |      |      |      |      |      |   |      |      |      |      |
    * |------+------+------+------|   |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|   |------+------+------+------|
    * |   1  |   2  |   3  |Enter |   |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|   |      |      |  Up  |      |
    * |------+------+------+------|   `-----------------------------------------/       /     \      \-----------------------------------------'   |------+------+------+------|
    * |  Fn  |   0  |   .  |Enter |                     | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI |                    |      | Left | Down |Right |
    * `---------------------------'                     |      |      |      |/       /         \      \ |      |      |      |                    `---------------------------'
    *                                                   `----------------------------'           '------''--------------------'
    */
  [_LOWER] = LAYOUT(
      KC_ESC,  KC_PSLS, KC_PAST, KC_BSPC,      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       XXXXXXX, KC_INS,  KC_HOME, KC_PGUP,  
      KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      _______, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,       XXXXXXX, KC_DEL,  KC_END,  KC_PGDN,  
      KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      _______, XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
      KC_P1,   KC_P2,   KC_P3,   KC_PENT,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, 
      _______, KC_P0,   KC_PDOT, KC_PENT,                                 _______, _______, _______, _______, _______, _______, _______, _______,                                 XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  
    ),


    /* Raise
    * ,---------------------------.   ,-----------------------------------------.                    ,-----------------------------------------.   ,---------------------------.
    * | ESC  |   /  |   *  |BackSp|   | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |   |      | Ins  | Home | PgUp |
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   7  |   8  |   9  |  -   |   | Tab  |      |      |      |      |      |                    |      |      |      |      |      | Del  |   |      | Del  | End  |PgDown|
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   4  |   5  |   6  |  +   |   |LCTRL |      |      |      |      |      |-------.    ,-------|   -  |   \  |   `  |      |      |      |   |      |      |      |      |
    * |------+------+------+------|   |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|   |------+------+------+------|
    * |   1  |   2  |   3  |Enter |   |LShift|      |      |      |      |      |-------|    |-------|   _  |   |  |   ~  |      |      |RShift|   |      |      |  Up  |      |
    * |------+------+------+------|   `-----------------------------------------/       /     \      \-----------------------------------------'   |------+------+------+------|
    * |  Fn  |   0  |   .  |Enter |                     | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI |                    |      | Left | Down |Right |
    * `---------------------------'                     |      |      |      |/       /         \      \ |      |      |      |                    `---------------------------'
    *                                                   `----------------------------'           '------''--------------------'
    */
  [_RAISE] = LAYOUT(
      KC_ESC,  KC_PSLS, KC_PAST, KC_BSPC,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_INS,  KC_HOME, KC_PGUP,  
      KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,       XXXXXXX, KC_DEL,  KC_END,  KC_PGDN,  
      KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_BSLS, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
      KC_P1,   KC_P2,   KC_P3,   KC_PENT,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PIPE, KC_TILD, XXXXXXX, XXXXXXX, _______,      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, 
      _______, KC_P0,   KC_PDOT, KC_PENT,                                 _______, _______, _______, _______, _______, _______, _______, _______,                                 XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  
    ),


    /* Adjust
    * ,---------------------------.   ,-----------------------------------------.                    ,-----------------------------------------.   ,---------------------------.
    * | ESC  |   /  |   *  |BackSp|   | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |   |      | Ins  | Home | PgUp |
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   7  |   8  |   9  |  -   |   | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|   |      | Del  | End  |PgDown|
    * |------+------+------+------|   |------+------+------+------+------+------|                    |------+------+------+------+------+------|   |------+------+------+------|
    * |   4  |   5  |   6  |  +   |   |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |   |      |      |      |      |
    * |------+------+------+------|   |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|   |------+------+------+------|
    * |   1  |   2  |   3  |Enter |   |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|   |      |      |  Up  |      |
    * |------+------+------+------|   `-----------------------------------------/       /     \      \-----------------------------------------'   |------+------+------+------|
    * |  Fn  |   0  |   .  |Enter |                     | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI |                    |      | Left | Down |Right |
    * `---------------------------'                     |      |      |      |/       /         \      \ |      |      |      |                    `---------------------------'
    *                                                   `----------------------------'           '------''--------------------'
    */
  [_ADJUST] = LAYOUT(
      KC_ESC,  KC_PSLS, KC_PAST, KC_BSPC,      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,       XXXXXXX, KC_INS,  KC_HOME, KC_PGUP,  
      KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,      XXXXXXX, KC_DEL,  KC_END,  KC_PGDN,  
      KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
      KC_P1,   KC_P2,   KC_P3,   KC_PENT,      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, 
      MO(_LOWER), KC_P0, KC_PDOT, KC_PENT,                          KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,  KC_ENT, MO(_RAISE), KC_RALT, KC_RGUI,                                XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  
    )
};


