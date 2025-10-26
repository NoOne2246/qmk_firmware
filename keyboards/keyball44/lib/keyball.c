/*
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"
#include "keyball.h"

// clip2int8 clips an integer fit into int8_t.
static inline int8_t clip2int8(int16_t v) {
    return (v) < -127 ? -127 : (v) > 127 ? 127 : (int8_t)v;
}

static const char *format_4d(int8_t d) {
    static char buf[5] = {0}; // max width (4) + NUL (1)
    char        lead   = ' ';
    if (d < 0) {
        d    = -d;
        lead = '-';
    }
    buf[3] = (d % 10) + '0';
    d /= 10;
    if (d == 0) {
        buf[2] = lead;
        lead   = ' ';
    } else {
        buf[2] = (d % 10) + '0';
        d /= 10;
    }
    if (d == 0) {
        buf[1] = lead;
        lead   = ' ';
    } else {
        buf[1] = (d % 10) + '0';
        d /= 10;
    }
    buf[0] = lead;
    return buf;
}
static char to_1x(uint8_t x) {
    x &= 0x0f;
    return x < 10 ? x + '0' : x + 'a' - 10;
}

// clang-format off
const char PROGMEM code_to_name[] = {
    'a', 'b', 'c', 'd', 'e', 'f',  'g', 'h', 'i',  'j',
    'k', 'l', 'm', 'n', 'o', 'p',  'q', 'r', 's',  't',
    'u', 'v', 'w', 'x', 'y', 'z',  '1', '2', '3',  '4',
    '5', '6', '7', '8', '9', '0',  'R', 'E', 'B',  'T',
    '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`',
    ',', '.', '/',
};
// clang-format on


report_mouse_t held_report = {};
uint16_t held_kc = 0;
keypos_t held_keypos = {};
uint8_t mouse_cpi = 0;
uint8_t scroll_cpi = 0;
bool scroll_mode = false;

void keyboard_pre_init_kb(void){
    keyball_apply_cpi(PMW33XX_CPI, PMW33XX_CPI_SCR);
    keyboard_pre_init_user();
}

void keyball_save_mouse_report(report_mouse_t mouse_report) {
      held_report.x = mouse_report.x;
      held_report.y = mouse_report.y;
      held_report.v = mouse_report.v;
      held_report.h = mouse_report.h;
}
void keyball_save_keyboard_report(uint16_t last_kc, keypos_t last_pos){
    held_kc = last_kc;
    held_keypos = last_pos;
}
void keyball_apply_cpi(uint16_t mouse, uint16_t scroll){
    mouse_cpi = mouse / 100;
    scroll_cpi = scroll / 100;
    keyball_set_scroll_mode(scroll_mode);
}
uint16_t keyball_get_mouse_cpi(void){
    return mouse_cpi * 100;
}
uint16_t keyball_get_scroll_cpi(void){
    return scroll_cpi * 100;
}
void keyball_set_scroll_mode(bool scroll){
    scroll_mode = scroll;
    if (scroll_mode){
        pointing_device_set_cpi_on_side(true,scroll_cpi*100);
        pointing_device_set_cpi_on_side(false,scroll_cpi*100);
    }else{
        pointing_device_set_cpi_on_side(true,mouse_cpi*100);
        pointing_device_set_cpi_on_side(false,mouse_cpi*100);
    }
}

void keyball_oled_render_ballinfo(void) {
    // Format: `Ball:{mouse x}{mouse y}{mouse h}{mouse v}`
    //         `    CPI{CPI} S{SCROLL_MODE} D{SCROLL_DIV}`
    //
    // Output example:
    //
    //     Ball: -12  34   0   0
    //
    oled_write_P(PSTR("Ball:"), false);
    oled_write(format_4d(held_report.x), false);
    oled_write(format_4d(held_report.y), false);
    oled_write(format_4d(held_report.h), false);
    oled_write(format_4d(held_report.v), false);
    // CPI
    oled_write_P(PSTR("    CPI"), false);
    oled_write(format_4d(mouse_cpi) + 1, false);
    oled_write_P(PSTR("00 "), false);
    oled_write_char(!scroll_mode ? '<' : '>', false);
    oled_write(format_4d(scroll_cpi) + 1, false);
    oled_write_ln_P(PSTR("00"), false);
}

void keyball_oled_render_keyinfo(void) {
    // Format: `Key :  R{row}  C{col} K{kc}  '{name}`
    //
    // Where `kc` is lower 8 bit of keycode.
    // Where `name` is readable label for `kc`, valid between 4 and 56.
    //
    // It is aligned to fit with output of keyball_oled_render_ballinfo().
    // For example:
    //
    //     Key :  R2  C3 K06  'c
    //     Ball:   0   0   0   0
    //
    oled_write_P(PSTR("Key :  R"), false);
    oled_write_char(to_1x(held_keypos.row), false);
    oled_write_P(PSTR("  C"), false);
    oled_write_char(to_1x(held_keypos.col), false);
    if (held_kc) {
        oled_write_P(PSTR(" K"), false);
        oled_write_char(to_1x(held_kc >> 4), false);
        oled_write_char(to_1x(held_kc), false);
    }
    if (held_kc >= 4 && held_kc < 57) {
        oled_write_P(PSTR("  '"), false);
        char name = pgm_read_byte(code_to_name + held_kc - 4);
        oled_write_char(name, false);
    } else {
        oled_advance_page(true);
    }
}

void keyball_oled_render_layerinfo(void) {
    // Format: `Layer:{layer state}`
    //
    // Output example:
    //
    //     Layer:-23------------
    //
    oled_write_P(PSTR("Layer:"), false);
    for (uint8_t i = 1; i < 16; i++) {
        oled_write_char((layer_state_is(i) ? to_1x(i) : '_'), false);
    }
}

