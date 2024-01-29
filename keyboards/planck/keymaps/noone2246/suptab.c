#include "suptab.h"

int Tab_Dance = 0;
uint16_t Tab_timer = 0;

void handle_tab(uint16_t keycode, bool pressed){
    if(!pressed){
        return;
    }
    if(Tab_Dance>0){
        Tab_timer = timer_read();
        switch(keycode){
            case TAB_PRE:
                tap_code16(S(KC_TAB));
                break;
            case TAB_UP:
                tap_code(KC_UP);
                break;
            case TAB_NXT:
                tap_code(KC_TAB);
                break;
            case TAB_LFT:
                tap_code(KC_LEFT);
                break;
            case TAB_DWN:
                tap_code(KC_DOWN);
                break;
            case TAB_RHT:
                tap_code(KC_RGHT);
                break;
            default:
                end_tab();
                break;
        }
    }
    
    if (keycode == SUP_TAB){
        Tab_timer = timer_read();
        layer_on(_Tab);
        uint8_t mods = get_oneshot_mods();
        clear_oneshot_mods();
        mods |= get_mods();
        if (mods & MOD_MASK_CTRL) {
            if (mods & MOD_MASK_ALT) {
                register_mods(MOD_MASK_ALT);
                Tab_Dance = 1;
            }else{
                Tab_Dance = 2;
            }
            register_mods(MOD_MASK_CTRL);
        } else if (mods & MOD_MASK_ALT) {
            register_mods(MOD_MASK_ALT);
            Tab_Dance = 3;
        } else if (mods & MOD_MASK_GUI) {
            register_mods(MOD_MASK_GUI);
            Tab_Dance = 4;
        }
        tap_code(KC_TAB);
        if(Tab_Dance == 0){
            end_tab();
        }else if(Tab_Dance == 1){
            unregister_mods(MOD_MASK_CTRL);
            unregister_mods(MOD_MASK_ALT);
        }else if (Tab_Dance == 4){
            unregister_mods(MOD_MASK_GUI);
        }
	}
}

void end_tab(){
    layer_off(_Tab);
    switch(Tab_Dance){
		case 1:
        case 4:
			tap_code(KC_ENT);
			break;
		case 2:
			unregister_mods(MOD_MASK_CTRL);
			break;
		case 3:
			unregister_mods(MOD_MASK_ALT);
			break;
	}
	Tab_Dance = 0;
}

void check_tab(){
    if (Tab_Dance > 0) {
        if (timer_elapsed(Tab_timer) > TAPPING_TERM*5) {
            end_tab();
        }
    }
}