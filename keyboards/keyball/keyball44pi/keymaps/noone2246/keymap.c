/*

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

#ifdef OLED_ENABLE
#    include "keyball44pi/keymaps/noone2246/oledkit.h"
#endif

enum custom_keycodes{
    KCC_SCROLL = SAFE_RANGE,
    KCC_MOUSE,
#ifdef JOYSTICK_ENABLE
    JS_UP,
    JS_DWN,
    JS_LFT,
    JS_RHT,
#endif
};

enum custom_layers {
    _QWERTY,
    _NUMPAD,
    _FUNCTION,
    _MOUSE,
    _FFXIV
};

#ifdef TAP_DANCE_ENABLE
// Tap Dance declarations
enum {
    TD_SU,
    TD_AA,
    TD_DD,
    TD_FS,
    TD_GB
};

void dance_SU(tap_dance_state_t *state, void *user_data) {
    for(int i =0; i < state->count;i++){
        if(state->pressed){
            tap_code16(KC_UNDS);
        }else{
            tap_code16(KC_S);
        }
    }
    reset_tap_dance(state);
}
void dance_AA(tap_dance_state_t *state, void *user_data) {
    for(int i =0; i < state->count;i++){
        if(state->pressed){
            tap_code16(KC_AT);
        }else{
            tap_code16(KC_A);
        }
    }
    reset_tap_dance(state);

}
void dance_DD(tap_dance_state_t *state, void *user_data) {
    for(int i =0; i < state->count;i++){
        if(state->pressed){
            tap_code16(KC_DLR);
        }else{
            tap_code16(KC_D);
        }
    }
    reset_tap_dance(state);
}
void dance_FS(tap_dance_state_t *state, void *user_data) {
    for(int i =0; i < state->count;i++){
        if(state->pressed){
            tap_code16(KC_HASH);
        }else{
            tap_code16(KC_F);
        }
    }
    reset_tap_dance(state);
}
void dance_GB(tap_dance_state_t *state, void *user_data) {
    for(int i =0; i < state->count;i++){
        if(state->pressed){
            tap_code16(KC_BSLS);
        }else{
            tap_code16(KC_G);
        }
    }
    reset_tap_dance(state);
}


tap_dance_action_t tap_dance_actions[] = {
	[TD_SU] = ACTION_TAP_DANCE_FN(dance_SU),
	[TD_AA] = ACTION_TAP_DANCE_FN(dance_AA),
	[TD_DD] = ACTION_TAP_DANCE_FN(dance_DD),
	[TD_FS] = ACTION_TAP_DANCE_FN(dance_FS),
	[TD_GB] = ACTION_TAP_DANCE_FN(dance_GB),
};
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_right_ball(
    KC_TAB        , KC_Q          , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , TO(_FFXIV) ,
    KC_ESC        , TD(TD_AA)     , TD(TD_SU), TD(TD_DD), TD(TD_FS), TD(TD_GB),                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT    ,
    OSM(MOD_LSFT) , OSM(MOD_LCTL) , KC_Z     , KC_X     , KC_C     , KC_V     ,                                        KC_B     , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH    , 
                    KC_LGUI , OSM(MOD_LALT),KC_BSPC, LT(_NUMPAD, KC_DEL), KC_ENT   ,                  KC_ENT  , KC_SPC    ,                                        MO(_FUNCTION)
  ),
  [_NUMPAD] = LAYOUT_right_ball(
    _______       , KC_GRV   , KC_HOME  , KC_UP   , KC_END   , KC_PGUP  ,                                        KC_PIPE , KC_P7     , KC_P8     , KC_P9     , KC_PAST  , KC_PSLS  ,
    _______       , KC_CIRC  , KC_LEFT  , KC_DOWN , KC_RGHT  , KC_PGDN  ,                                        KC_AMPR , KC_P4     , KC_P5     , KC_P6     , KC_PPLS  , KC_PMNS  , 
    _______       , _______  , KC_LPRN  , KC_RPRN , KC_LBRC  , KC_RBRC  ,                                        KC_EXLM , KC_P1     , KC_P2     , KC_P3     , KC_EQL   , KC_PERC  , 
                         _______  , _______ , _______  , _______   , _______   ,                 KC_SPC ,    KC_P0  ,                        KC_PDOT
  ),
  [_FUNCTION] = LAYOUT_right_ball(
    KC_NUM        , KC_VOLU  , KC_F1    , KC_F2   , KC_F3    , KC_F4   ,                                         KC_F13  , KC_F14  , KC_F15  , KC_F16  , _______  , QK_BOOT  ,
    KC_SCRL       , KC_MUTE  , KC_F5    , KC_F6   , KC_F7    , KC_F8   ,                                         KC_F17  , KC_F18  , KC_F19  , KC_F20  , _______  , QK_RBT  , 
    KC_CAPS       , KC_VOLD  ,  KC_F9   , KC_F10  , KC_F11   , KC_F12  ,                                         KC_F21  , KC_F22  , KC_F23  , KC_F24  , _______  , _______  , 
                        _______  , _______  , KC_MPRV  ,KC_MPLY,KC_MNXT,                  KC_BRIU  ,  KC_BRID  ,                             _______
  ),
  [_MOUSE] = LAYOUT_right_ball(
    _______       , _______  , _______  , _______  , _______   , _______  ,                                        _______     , _______     , KC_WH_U     , _______     , _______ , _______  ,
    _______       , C(KC_A)  , C(KC_S)  , _______  , C(KC_F)   , _______  ,                                        _______     , KC_BTN1     , KC_BTN3     , KC_BTN2     , _______  , _______  ,
    OSM(MOD_LSFT) , _______  , C(KC_Z)  , C(KC_X)  , C(KC_C)   , C(KC_V)  ,                                        _______     , KC_WH_L     , KC_WH_D     , KC_WH_R     , _______   , _______  , 
                    _______  , _______  , _______  ,       _______   , KCC_SCROLL ,                  _______  ,  _______  ,                             _______
  ),
  [_FFXIV] = LAYOUT_right_ball(//FFXIV
    KC_TAB        , KC_F5  , KC_Q     , KC_W   , KC_E    , KC_F8        ,                                     XXXXXXX , KC_1  , KC_2 , KC_3    , KC_4     , TO(_QWERTY),
    KC_ESC        , KC_F6  , KC_A     , KC_S   , KC_D    , KC_F9        ,                                     XXXXXXX , KC_5  , KC_6 , KC_7    , KC_8     , KC_LBRC  ,
    KC_P0         , KC_F7  , KC_F2    , KC_F1  , KC_F12  , KC_F10       ,                                     XXXXXXX , KC_9  , KC_0 , KC_MINS , KC_EQL   , KC_RBRC , 
                             KC_LT    , KC_GT  , KC_LSFT , KC_LEFT_CTRL , KC_SPC ,                  KC_ENT  , KC_SPC  ,                          KCC_MOUSE
  ),
};

// clang-format off
static bool scrolling_mode = false;
static bool joystick_mode = false;
static bool FFXIV_CHAT = false;
report_mouse_t held_report = {};

#ifdef JOYSTICK_ENABLE
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
    set_auto_mouse_layer(_MOUSE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KCC_SCROLL:
        if (record->event.pressed) {
            scrolling_mode = true;
            pointing_device_set_cpi(100);
        }else{
            scrolling_mode = false;
            pointing_device_set_cpi(500);
        }
        break;
    case KC_ENT:
        if(record->event.pressed) {
            if(layer_state_is(_FFXIV)){
                FFXIV_CHAT = true;
                layer_clear();
            }else if(FFXIV_CHAT){
                FFXIV_CHAT = false;
                layer_on(_FFXIV);
            }
        }
        break;
    case KCC_MOUSE:
        if (record->event.pressed) {
            joystick_mode = false;
        }else{
            joystick_mode = true;
        }
        break;
#ifdef JOYSTICK_ENABLE
    case JS_UP:
        joystick_set_axis(1, record->event.pressed ? 127 : 0);
        return false;
    case JS_DWN:
        joystick_set_axis(1, record->event.pressed ? -127 : 0);
        return false;
    case JS_LFT:
        joystick_set_axis(0, record->event.pressed ? -127 : 0);
        return false;
    case JS_RHT:
        joystick_set_axis(0, record->event.pressed ? 127 : 0);
        return false; 
#endif
    }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(remove_auto_mouse_layer(state, true))) {
    case _FFXIV:
        scrolling_mode = false;
        joystick_mode = true;
        state = remove_auto_mouse_layer(state, false);
        set_auto_mouse_enable(false); 
        break;
    case _MOUSE:
        joystick_mode = false;
    default: 
        scrolling_mode = false;
        joystick_mode = false;
        pointing_device_set_cpi(500);
        set_auto_mouse_enable(true); 
        break;
    }
    return state;
}

// clip2int8 clips an integer fit into int8_t.
static inline int8_t clip2int8(int16_t v) {
    return (v) < -127 ? -127 : (v) > 127 ? 127 : (int8_t)v;
}

 report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
   
    static uint32_t last_exec = 0;

    if(abs(mouse_report.x) + abs(mouse_report.y) > 0){
        held_report = mouse_report;
        last_exec = timer_read32();
        held_report.buttons = MOUSE_BTN2;
    }
    if ( timer_elapsed32(last_exec) > POINTING_DEVICE_TASK_THROTTLE_MS * 3){
        held_report.x = 0;
        held_report.y = 0;
        held_report.buttons &= ~MOUSE_BTN2;
    }
    
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    if (joystick_mode) {
#ifdef JOYSTICK_ENABLE
        joystick_set_axis(0, clip2int8(held_report.x * 10));
        joystick_set_axis(1, clip2int8(held_report.y * 10));
        mouse_report.x = 0;
        mouse_report.y = 0;
#else
        mouse_report.buttons = held_report.buttons;
#endif
    }
    return mouse_report;
}
