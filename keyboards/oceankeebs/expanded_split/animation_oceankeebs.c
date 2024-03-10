#pragma once

#include animation.c

#define ANIM_FRAMES 8

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint32_t anim_frame_duration = 500;
uint8_t current_anim_frame = 0;

#ifdef OLED_DISPLAY_128X64
    void animation_phase(void) {
        current_anim_frame = (current_anim_frame + 1) % ANIM_FRAMES;
        oled_write_raw_P(animation[abs((ANIM_FRAMES-1)-current_anim_frame)], sizeof(animation[abs((ANIM_FRAMES-1)-current_anim_frame)]));
    }

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
#endif
