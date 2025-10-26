/*
Copyright 2021 @Yowkees
Copyright 2021 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#if defined(OLED_ENABLE) && !defined(OLEDKIT_DISABLE)

/// oled_render_left_user and oled_render_right_user renders the left and right
/// half of the keyboard display. Since we share layer, mod and lock information
/// we can display regardless of which keypad is master and slave. This slows
/// down the data transfer, but allows for all information to be displayed.
void oledkit_render_master_user(void);
void oledkit_render_slave_user(void);

/// keyball_oled_render_modinfo renders current mod status information to
/// OLED. It shows the mod enabled with a "+". It shows the mod as a row and
/// the type of mod as a column.
/// M for Mod, O for Oneshot, L for Locked.
/// C for Control, S for Shift, A for Alt.
/// Next it shows the keylock with num, caps and scroll.
void keyball_oled_render_modinfo(void);

/// keyball_oled_render_layerinfo renders current layer status information to
/// OLED. It shows the layers and displays the name if the layer is on, otherwise
/// it shows a blank row if the layer is off.
void keyball_oled_render_layerinfo(void);

#endif // OLED_ENABLE