/*
This is the c configuration file for the keymap

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

#pragma once

#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_ROTATION_90

#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_TASK_THROTTLE_MS 8 //125Hz

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define AUTO_MOUSE_TIME 500

#ifdef TAP_DANCE_ENABLE
#   define TAPPING_TERM 175
#   define TAPPING_TERM_PER_KEY
#endif

#define SPLIT_LAYER_STATE_ENABLE

#define ONESHOT_TIMEOUT 5000
#define ONESHOT_TAP_TOGGLE 2

#ifdef JOYSTICK_ENABLE
#   define JOYSTICK_BUTTON_COUNT 1
#   define JOYSTICK_AXIS_COUNT 2
#   define JOYSTICK_AXIS_RESOLUTION 8
#endif


#ifdef OLED_ENABLE
#   define OLED_FONT_H "keyboards/keyball/keyball44/keymaps/noone2246/glcdfont.c"
#   define OLED_FONT_START 32
#   define OLED_FONT_END 90
#endif