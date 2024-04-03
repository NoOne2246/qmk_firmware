
#include "quantum.h"

#if defined(OLED_ENABLE) && !defined(OLEDKIT_DISABLE)


__attribute__((weak)) void keyball_oled_render_modinfo(void) {
    // Format: `Layer:{layer state}`
    //
    // Output example:
    //        MOL
    //      C:---
    //      S:---
    //      A:---
    //      Lock: (note that the exclamation mark in custom font pack is a padlock)
    //      NUM:
    //      CAP:
    //      SCR:
    //
    oled_write_P(PSTR("  MOLC:"), false);
    oled_write_char(get_mods() & MOD_MASK_CTRL?'+':' ',false);
    oled_write_char(get_oneshot_mods() & MOD_MASK_CTRL?'+':' ',false);
    oled_write_char(get_oneshot_locked_mods() & MOD_MASK_CTRL?'+':' ',false);
    oled_write_P(PSTR("S:"), false);
    oled_write_char(get_mods() & MOD_MASK_SHIFT?'+':' ',false);
    oled_write_char(get_oneshot_mods() & MOD_MASK_SHIFT?'+':' ',false);
    oled_write_char(get_oneshot_locked_mods() & MOD_MASK_SHIFT?'+':' ',false);
    oled_write_P(PSTR("A:"), false);
    oled_write_char(get_mods() & MOD_MASK_ALT?'+':' ',false);
    oled_write_char(get_oneshot_mods() & MOD_MASK_ALT?'+':' ',false);
    oled_write_char(get_oneshot_locked_mods() & MOD_MASK_ALT?'+':' ',false);
    oled_write_P(PSTR("         !NUM:"), false);
    oled_write_char(host_keyboard_led_state().num_lock?'+':' ',false);
    oled_write_P(PSTR("CAP:"), false);
    oled_write_char(host_keyboard_led_state().caps_lock?'+':' ',false);
    oled_write_P(PSTR("SCR:"), false);
    oled_write_char(host_keyboard_led_state().scroll_lock?'+':' ',false);
}


__attribute__((weak)) void keyball_oled_render_layerinfo(void) {
    // Format: `Layer:{layer state}`
    //
    // Output example:
    //
    //      LAY: 
    //       LXIV
    //       LMSE
    //       L
    //       L
    //       LQWE
    //
    oled_write_P(PSTR("LAY: "), false);
    oled_write_P(layer_state_is(4)?PSTR(" #XIV"):PSTR(" #   "),false);
    oled_write_P(layer_state_is(3)?PSTR(" #MSE"):PSTR(" #   "),false);
    oled_write_P(layer_state_is(2)?PSTR(" #FNC"):PSTR(" #   "),false);
    oled_write_P(layer_state_is(1)?PSTR(" #NUM"):PSTR(" #   "),false);
    oled_write_P(layer_state_is(0)?PSTR(" #QWE"):PSTR(" #   "),false);
}

__attribute__((weak)) void oledkit_render_master_user(void){
    keyball_oled_render_modinfo();
}
__attribute__((weak)) void oledkit_render_slave_user(void) {
    keyball_oled_render_layerinfo();
}

__attribute__((weak)) bool oled_task_user(void) {
    if (is_keyboard_master()){
        oledkit_render_master_user();
    }else{
        oledkit_render_slave_user();
    }
    return true;
}

__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

#endif // OLED_ENABLE
