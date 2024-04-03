/*
Copyright 2022 @Yowkees
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

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "lib/keyball.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_no_ball(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
                    KC_LCTL  , KC_LGUI  , KC_LALT  ,       KC_SPC   , KC_DEL   ,                  KC_BSPC  , KC_ENT   ,      KC_RALT  , KC_RGUI  , KC_RCTL
  ),
};
// clang-format off

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
  
  static uint32_t last_exec = 0;
  report_mouse_t combined_report = pointing_device_combine_reports(left_report,right_report);
  if(abs(combined_report.x) + abs(combined_report.y) + abs(combined_report.v) + abs(combined_report.h)>0){
      keyball_save_mouse_report(combined_report);
      last_exec = timer_read32();
  }
  else if ( timer_elapsed32(last_exec) > POINTING_DEVICE_TASK_THROTTLE_MS + 1){
      keyball_save_mouse_report(combined_report);
  }
  return combined_report;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  
  static uint32_t last_exec = 0;
  if(abs(mouse_report.x) + abs(mouse_report.y) + abs(mouse_report.v) + abs(mouse_report.h)>0){
      keyball_save_mouse_report(mouse_report);
      last_exec = timer_read32();
  }
  else if ( timer_elapsed32(last_exec) > POINTING_DEVICE_TASK_THROTTLE_MS + 1){
      keyball_save_mouse_report(mouse_report);
  }
  return mouse_report;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record){
    keyball_save_keyboard_report(keycode, record->event.key);
    return process_record_user(keycode, record);
}
#ifdef OLED_ENABLE

#    include "lib/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}

#endif

