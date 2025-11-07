// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY = 0,
    _FUNCTION,
    _QMK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐  ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┐ ┌───┐
     * │Esc│  │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │Del│ │MUT│
     * └───┘  └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┘ └───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐      ┌───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│      │HOM│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤      ├───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │      │PgU│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤      ├───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │      │PgD│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤┌───┐ ├───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift ││ ↑ │ │END│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬─┬──┴┼───┼─┴─┬─┘
     * │Ctrl│GUI │Alt │                        │ Alt│ FN │Ctrl│ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┘ └───┴───┴───┘
     */
    [_QWERTY] = LAYOUT(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_DEL,    KC_PAUS,

        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,                KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,                KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                 KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,       KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FUNCTION), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FUNCTION] = LAYOUT(
        QK_BOOT,          KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,      XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,
        XXXXXXX, RM_ON,   RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,
        XXXXXXX, RM_OFF,  RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,               XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          MO(_QMK),     XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_QMK] = LAYOUT(
        QK_BOOT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      EE_CLR,  XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,               XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,      XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FUNCTION] = {ENCODER_CCW_CW(KC_MRWD, KC_MFFD)},
    [_QMK]      = {ENCODER_CCW_CW(XXXXXXX, XXXXXXX)},
};
#endif


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(52, 254, 0, 0);
    }
    return false;
}

// clang-format on