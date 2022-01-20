#include "noone2246.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"


#ifdef SUPTAB
#include "suptab.h"
#endif


uint8_t Mouse_Mod = 0;
uint16_t Gui_timer = 0;
uint16_t FN_timer = 0;

void Three_Cancel(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        reset_tap_dance(state);
    }
}
void Four_Cancel(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
        reset_tap_dance(state);
    }
}

uint8_t mod_dance(qk_tap_dance_state_t *state){
	if (state->count == 1) {
		if (state->pressed){
			return SINGLE_HOLD;
        } else if (state->interrupted){
            return SINGLE_INT;
		} else {
			return SINGLE_TAP;
		}
	}else if (state->count == 2) {
		return DOUBLE_TAP;
	} else {
		return SAFE_TAP;
	}
}



/*
	Ctrl tap
*/
static xtap ctrl_tap_state = {
    .is_press_action = true,
    .state = 0
};
void ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctrl_tap_state.state = mod_dance(state);
    switch (ctrl_tap_state.state) {
		case SINGLE_INT:
			if(get_mods() & MOD_MASK_CTRL){
				unregister_mods(MOD_MASK_CTRL);
			} else {
				set_oneshot_mods(MOD_MASK_CTRL | get_oneshot_mods());
			}
			break;
		case SINGLE_HOLD:
		case DOUBLE_TAP:
			register_mods(MOD_MASK_CTRL);
			break;
    }
}
void ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {  
    ctrl_tap_state.state = 0;
}

/*
	Alt tap
*/
static xtap alt_tap_state = {
    .is_press_action = true,
    .state = 0
};
void alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    alt_tap_state.state = mod_dance(state);
    switch (alt_tap_state.state) {
		case SINGLE_INT:
			if(get_mods() & MOD_MASK_ALT){
				unregister_mods(MOD_MASK_ALT);
			} else {
				set_oneshot_mods(MOD_MASK_ALT | get_oneshot_mods());
			}
			break;
		case SINGLE_HOLD:
		case DOUBLE_TAP:
			register_mods(MOD_MASK_ALT);
			break;
    }
}
void alt_reset(qk_tap_dance_state_t *state, void *user_data) {  
    alt_tap_state.state = 0;
}

/*
	Shift tap
*/
static xtap shft_tap_state = {
    .is_press_action = true,
    .state = 0
};
void shft_finished(qk_tap_dance_state_t *state, void *user_data) {
    shft_tap_state.state = mod_dance(state);
    switch (shft_tap_state.state) {
		case SINGLE_INT:
			if(get_mods() & MOD_MASK_SHIFT){
				unregister_mods(MOD_MASK_SHIFT);
			} else {
				set_oneshot_mods(MOD_MASK_SHIFT | get_oneshot_mods());
			}
			break;
		case SINGLE_HOLD:
		case DOUBLE_TAP:
			register_mods(MOD_MASK_SHIFT);
			break;
    }
}
void shft_reset(qk_tap_dance_state_t *state, void *user_data) {  
    shft_tap_state.state = 0;
}

/*
	Gui tap
*/
static xtap gui_tap_state = {
    .is_press_action = true,
    .state = 0
};

void gui_each(qk_tap_dance_state_t *state, void *user_data){
    if (state->pressed){
        register_mods(MOD_LGUI);
    }else if (state->interrupted){
        set_oneshot_mods(MOD_LGUI | get_oneshot_mods());
    }else{
    register_code16(KC_LGUI);
    }
}
void gui_finished(qk_tap_dance_state_t *state, void *user_data) {
    gui_tap_state.state = mod_dance(state);
    switch (gui_tap_state.state){
        case SINGLE_INT:
        case SINGLE_HOLD:
        register_mods(MOD_LGUI);
        break;
    }
}
void gui_reset(qk_tap_dance_state_t *state, void *user_data) { 
    if(get_mods() & MOD_MASK_GUI){
    unregister_mods(MOD_LGUI);
    }else{
    tap_code16(KC_LGUI);
    }
    gui_tap_state.state = 0;
}


void dance_NumLay(qk_tap_dance_state_t *state, void *user_data) {
	switch(state->count){
		case 1:
			layer_move(_Sym);
			break;
		case 2:
			layer_move(_Num);
			break;
    }
    reset_tap_dance(state);
}
void dance_LB(qk_tap_dance_state_t *state, void *user_data) {
	switch(state->count){
		case 1:
            if(state->pressed){
                tap_code16(KC_LCBR);
            }else{
                tap_code16(KC_LPRN);
            }
			break;
		case 2:
            if(state->pressed){
                tap_code16(KC_LT);
            }else{
                tap_code16(KC_LBRC);
            }
			break;
		case 3:
			tap_code16(KC_LT);
			break;
		case 4:
			tap_code16(KC_LCBR);
			break;
    }
    reset_tap_dance(state);
}
void dance_RB(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
		case 1:
            if(state->pressed){
                tap_code16(KC_RCBR);
            }else{
                tap_code16(KC_RPRN);
            }
			break;
		case 2:
            if(state->pressed){
                tap_code16(KC_GT);
            }else{
                tap_code16(KC_RBRC);
            }
			break;
		case 3:
			tap_code16(KC_GT);
			break;
		case 4:
			tap_code16(KC_RCBR);
			break;
    }
    reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_TAB_STAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, S(KC_TAB)),
	[TD_BSPC_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL),
	[TD_SAVE] = ACTION_TAP_DANCE_DOUBLE(C(KC_S), RCS(KC_S)),
	[TD_PASTE] = ACTION_TAP_DANCE_DOUBLE(C(KC_V), RCS(KC_V)),
	[TD_CLOSE] = ACTION_TAP_DANCE_DOUBLE(C(KC_W), C(KC_F4)),
	[TD_QUIT] = ACTION_TAP_DANCE_DOUBLE(C(KC_Q), A(KC_F4)),
	[TD_NLAY] = ACTION_TAP_DANCE_FN(dance_NumLay),
	[TD_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, pl_finished, pl_reset),
	[TD_MNUS] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, mn_finished, mn_reset),
	[TD_LT] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, lt_finished, lt_reset),
	[TD_GT] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, gt_finished, gt_reset),
	[TD_SL] = ACTION_TAP_DANCE_FN_ADVANCED(Four_Cancel, sl_finished, sl_reset),
	[TD_ST] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, st_finished, st_reset),
	[TD_EM] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, em_finished, em_reset),
	[TD_PIP] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, pi_finished, pi_reset),
	[TD_AMP] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, am_finished, am_reset),
	[TD_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, mo_finished, mo_reset),
	[TD_CIR] = ACTION_TAP_DANCE_FN_ADVANCED(Three_Cancel, ka_finished, ka_reset),
	[TD_LB] = ACTION_TAP_DANCE_FN(dance_LB),
	[TD_RB] = ACTION_TAP_DANCE_FN(dance_RB),
	[TD_SHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shft_finished, shft_reset),
	[TD_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset),
	[TD_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_finished, gui_reset),
	[TD_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset),
    [TD_Q1] = ACTION_TAP_DANCE_FN(dance_Q1),
    [TD_W2] = ACTION_TAP_DANCE_FN(dance_W2),
    [TD_E3] = ACTION_TAP_DANCE_FN(dance_E3),
    [TD_R4] = ACTION_TAP_DANCE_FN(dance_R4),
    [TD_T5] = ACTION_TAP_DANCE_FN(dance_T5),
    [TD_Y6] = ACTION_TAP_DANCE_FN(dance_Y6),
    [TD_U7] = ACTION_TAP_DANCE_FN(dance_U7),
    [TD_I8] = ACTION_TAP_DANCE_FN(dance_I8),
    [TD_O9] = ACTION_TAP_DANCE_FN(dance_O9),
    [TD_P0] = ACTION_TAP_DANCE_FN(dance_P0),
	[TD_AT] = ACTION_TAP_DANCE_FN(dance_AT),
	[TD_DO] = ACTION_TAP_DANCE_FN(dance_DO),
	[TD_UN] = ACTION_TAP_DANCE_FN(dance_UN),
	[TD_SH] = ACTION_TAP_DANCE_FN(dance_SH),
    [TD_BS] = ACTION_TAP_DANCE_FN(dance_BS),
    [TD_TI] = ACTION_TAP_DANCE_FN(dance_TI),
    [TD_BQ] = ACTION_TAP_DANCE_FN(dance_BQ),
    [TD_PC] = ACTION_TAP_DANCE_FN(dance_PC),
    [TD_KA] = ACTION_TAP_DANCE_FN(dance_KA),
    [TD_AM] = ACTION_TAP_DANCE_FN(dance_AM),
    [TD_PI] = ACTION_TAP_DANCE_FN(dance_PI),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (Gui_timer > 0){
        if( record->event.pressed){
            add_oneshot_mods(MOD_LGUI);
            Gui_timer = 0;
        }
    }
    
#ifdef SUPTAB
    handle_tab(keycode, record->event.pressed);
#endif
        
    switch (keycode) {
		case LAY_CLR:
            if(record->event.pressed){
                if (get_mods()){
                    clear_mods();
                    return false;
                }
                if (layer_is_default()){
                    layer_clear();
                    return false;
                }
                tap_code(KC_ESC);
            }
            break;
		case GOTO_L:
			if (record->event.pressed) {
				tap_code16(C(KC_G));
				layer_move(_Num);
			}
            break;
		case MSE_LFT:
			if(record->event.pressed){
				uint8_t Mouse_Mod = get_oneshot_mods();
				clear_oneshot_mods();
				register_mods(Mouse_Mod);
				register_code(KC_BTN1);
			}else{
				unregister_code(KC_BTN1);
				unregister_mods(Mouse_Mod);
			}
			break;
		case MSE_RHT:
			if(record->event.pressed){
				uint8_t Mouse_Mod = get_oneshot_mods();
				clear_oneshot_mods();
				register_mods(Mouse_Mod);
				register_code(KC_BTN2);
			}else{
				unregister_code(KC_BTN2);
				unregister_mods(Mouse_Mod);
			}
			break;
		case MSE_MID:
			if(record->event.pressed){
				uint8_t Mouse_Mod = get_oneshot_mods();
				clear_oneshot_mods();
				register_mods(Mouse_Mod);
				register_code(KC_BTN3);
			}else{
				unregister_code(KC_BTN3);
				unregister_mods(Mouse_Mod);
			}
			break;
		case TG_CTRL:
            if(record ->event.pressed){
                toggle_mods(MOD_LCTL);
            }
            break;
		case TG_SHFT:
            if(record ->event.pressed){
                toggle_mods(MOD_LSFT);
            }
            break;
		case TG_ALT:
            if(record ->event.pressed){
                toggle_mods(MOD_LALT);
            }
            break;
        case OS_GUI:
            if(record->event.pressed){ 
                Gui_timer=timer_read();	
            }
            return false;
        case LAY_FNC:
            if(record->event.pressed){
                layer_on(_Media);
            }else{
                layer_off(_Media);
                layer_on(_FN);
                FN_timer = timer_read();
                //set_oneshot_layer(_FN, ONESHOT_START);
                //clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            break;
        case KC_F1 ... KC_F12:
        case KC_F13 ... KC_F24:
            if (!(record -> event.pressed)){
                layer_off(_FN);
            }
            break;
    }
    return true;
};

void matrix_scan_user(void) {     // The very important timer.
    
    
#ifdef SUPTAB
check_tab();
#endif
    if (Gui_timer > 0){
        if(timer_elapsed(Gui_timer)>2*TAPPING_TERM){
            tap_code16(KC_LGUI);
            Gui_timer = 0;
        }
    }
    if(FN_timer > 0){
        if (timer_elapsed(FN_timer)>5*TAPPING_TERM){
            layer_off(_FN);
            FN_timer = 0;
        }
    }
}
