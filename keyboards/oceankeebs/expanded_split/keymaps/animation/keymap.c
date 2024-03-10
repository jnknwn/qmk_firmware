#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*   Base Layer
     *             ┌────┬────┬────┐                                      ┌────┬────┬────┐
     *   ┌────┬────┤ 2  │ 3  │ 4  ├────┐                            ┌────┤ 7  │ 8  │ 9  ├────┬────┐
     *   │Esc │ 1  ├────┼────┼────┤ 5  │                            │ 6  ├────┼────┼────┤ 0  │ =  │
     *   ├────┼────┤ W  │ E  │ R  ├────┤                            ├────┤ U  │ I  │ O  ├────┼────┤
     *   │Tab │ Q  ├────┼────┼────┤ T  │                            │ Y  ├────┼────┼────┤ P  │Bksp│
     *   ├────┼────┤ S  │ D  │ F  ├────┤                            ├────┤ J  │ K  │ L  ├────┼────┤
     *   │Ctrl│ A  ├────┼────┼────┤ G  ├────┐                  ┌────┤ H  ├────┼────┼────┤ ;  │ '  │
     *   ├────┼────┤ X  │ C  │ V  ├────┤ {  │ ┌────┬────┬────┐ │ }  ├────┤ M  │ ,  │ .  ├────┼────┤
     *   │Shft│ Z  ├──┬─┴──┬─┴──┬─┤ B  ├────┘ │    │ Up │    │ └────┤ N  ├─┬──┴─┬──┴─┬──┤ /  │Shft│
     *   └────┴────┘  │Win │Alt ├─┴──┬─┼────┐ ├────┼────┼────┤ ┌────┼─┬──┴─┤Alt │Win │  └────┴────┘
     *                └────┴────┤ Fn │ │Spce│ │Left│Down│Rght│ │Entr│ │ Fn ├────┴────┘
     *                          └────┘ │    │ └────┴────┴────┘ │    │ └────┘
     *                                 └────┘                  └────┘
     */
     
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_1,    KC_UP,   KC_1,     KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LGUI, KC_LALT, MO(1),       KC_SPC,   KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT,      MO(1),   KC_LALT, KC_LGUI
    ),

    /*   Fn Layer
     *             ┌────┬────┬────┐                                      ┌────┬────┬────┐
     *   ┌────┬────┤ F2 │ F3 │ F4 ├────┐                            ┌────┤ F7 │ F8 │ F9 ├────┬────┐
     *   │Esc │ F1 ├────┼────┼────┤ F5 │                            │ F6 ├────┼────┼────┤F10 │F11 │
     *   ├────┼────┤Prev│Vol-│Vol+├────┤                            ├────┤PgDn│PgUp│End ├────┼────┤
     *   │Tab │Play├────┼────┼────┤Next│                            │Home├────┼────┼────┤F12 │Del │
     *   ├────┼────┤Left│Down│ Up ├────┤                            ├────┤ \  │ `  │    ├────┼────┤
     *   │Ctrl│    ├────┼────┼────┤Rght├────┐                  ┌────┤ -  ├────┼────┼────┤    │    │
     *   ├────┼────┤    │    │    ├────┤ (  │ ┌────┬────┬────┐ │ )  ├────┤ |  │ ~  │    ├────┼────┤
     *   │Shft│    ├──┬─┴──┬─┴──┬─┤    ├────┘ │    │Vol+│    │ └────┤ _  ├─┬──┴─┬──┴─┬──┤    │Shft│
     *   └────┴────┘  │Win │Alt ├─┴──┬─┼────┐ ├────┼────┼────┤ ┌────┼─┬──┴─┤Alt │Win │  └────┴────┘
     *                └────┴────┤ Fn │ │Spce│ │Prev│Vol-│Next│ │Entr│ │ Fn ├────┴────┘
     *                          └────┘ │    │ └────┴────┴────┘ │    │ └────┘
     *                                 └────┘                  └────┘
     */

    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TAB,  KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,                                                KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F12,  KC_DEL,
        KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,                                                KC_MINS, KC_BSLS, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN,  KC_1,    KC_UP,   KC_1,     KC_RPRN, KC_UNDS, KC_PIPE, KC_TILD, XXXXXXX, XXXXXXX, KC_RSFT,
                               KC_LGUI, KC_LALT, MO(1),       KC_SPC,   KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT,      MO(1),   KC_RALT, KC_RGUI
    )
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

#ifdef OLED_ENABLE

#include "progmem.h"
#include "animation.c"

#define ANIM_FRAMES 8

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint32_t anim_frame_duration = 500;
uint8_t current_anim_frame = 0;

void animation_phase(void) {
    current_anim_frame = (current_anim_frame + 1) % ANIM_FRAMES;
    oled_write_raw_P(animation[abs((ANIM_FRAMES-1)-current_anim_frame)], sizeof(animation[abs((ANIM_FRAMES-1)-current_anim_frame)]));
}

bool oled_task_user(void) {
  if(get_current_wpm() != 000) {
    oled_on(); // not essential but turns on animation OLED with any alpha keypress

    if(timer_elapsed32(anim_timer) > anim_frame_duration) {
      anim_timer = timer_read32();
      animation_phase();
    }

    anim_sleep = timer_read32();

  } else {
    if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
      oled_off();
    } else {
      if(timer_elapsed32(anim_timer) > anim_frame_duration) {
        anim_timer = timer_read32();
        animation_phase();
      }
    }
  }
  return false;
}
#endif // OLED_ENABLE
