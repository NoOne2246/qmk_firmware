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

#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_ROTATION_270
#define POINTING_DEVICE_ROTATION_90_RIGHT	

#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_X_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 8 //125Hz

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_RGB_TEST  // required for LED test
#endif