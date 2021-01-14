#include "noone2246.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

int Tab_Dance = 0;
uint16_t Tab_timer = 0;
uint8_t Mouse_Mod = 0;

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

uint8_t cur_dance (qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->pressed){
			return SINGLE_HOLD;
		} else if (state->interrupted){
			return SINGLE_INT;
		} else {
			return SINGLE_TAP;
		}
	}else if (state->count == 2) {
		if (state->pressed){ 
			return DOUBLE_HOLD;
		}else if (state->interrupted){ 
			return DOUBLE_INT;
		} else {
			return DOUBLE_TAP;
		}
	} else if (state->count == 3) {
		if (state->pressed){
			return TRI_HOLD;
		}else if (state->interrupted){ 
			return TRI_INT;
		} else {
			return TRI_TAP;
		}
	} else {
		return SAFE_TAP;
	}
}
uint8_t mod_dance(qk_tap_dance_state_t *state){
	if (state->count == 1) {
		if (state->pressed){
			return SINGLE_HOLD;
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
	Plus
	tap:	+
	hold:	+=
	double: ++
*/
static xtap pl_tap_state = {
    .is_press_action = true,
    .state = 0
};
void pl_finished(qk_tap_dance_state_t *state, void *user_data) {
    pl_tap_state.state = cur_dance(state);
    switch (pl_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code(KC_PPLS);
			break;
		case SINGLE_HOLD:
			tap_code(KC_PPLS);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code(KC_PPLS);
			register_code(KC_PPLS);
			break;
    }
}
void pl_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (pl_tap_state.state != SINGLE_HOLD){
		unregister_code(KC_PPLS);
	}
    pl_tap_state.state = 0;
}

/*
	Minus
	tap:	-
	hold:	-=
	double: --
*/
static xtap mn_tap_state = {
    .is_press_action = true,
    .state = 0
};
void mn_finished(qk_tap_dance_state_t *state, void *user_data) {
    mn_tap_state.state = cur_dance(state);
    switch (mn_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code(KC_PMNS);
			break;
		case SINGLE_HOLD:
			tap_code(KC_PMNS);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code(KC_PMNS);
			register_code(KC_PMNS);
			break;
    }
}
void mn_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (mn_tap_state.state != SINGLE_HOLD){
		unregister_code(KC_PMNS);
	}
    mn_tap_state.state = 0;
}

/*
	Less than
	tap:	<
	hold:	<=
	double: <<
*/
static xtap lt_tap_state = {
    .is_press_action = true,
    .state = 0
};
void lt_finished(qk_tap_dance_state_t *state, void *user_data) {
    lt_tap_state.state = cur_dance(state);
    switch (lt_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code16(KC_LT);
			break;
		case SINGLE_HOLD:
			tap_code16(KC_LT);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
			tap_code16(KC_LT);
			register_code16(KC_LT);
			break;
		case DOUBLE_HOLD:
			tap_code16(KC_LT);
			tap_code16(KC_LT);
			tap_code(KC_EQL);
			break;
    }
}
void lt_reset(qk_tap_dance_state_t *state, void *user_data) { 
	switch (lt_tap_state.state) {
		default:
			unregister_code16(KC_LT);
			break;
    } 
    lt_tap_state.state = 0;
}

/*
	Greater than
	tap:	>
	hold:	>=
	double: >>
*/
static xtap gt_tap_state = {
    .is_press_action = true,
    .state = 0
};
void gt_finished(qk_tap_dance_state_t *state, void *user_data) {
    gt_tap_state.state = cur_dance(state);
    switch (gt_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code16(KC_GT);
			break;
		case SINGLE_HOLD:
			tap_code16(KC_GT);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code16(KC_GT);
			register_code16(KC_GT);
			break;
    }
}
void gt_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (gt_tap_state.state != SINGLE_HOLD){
		unregister_code16(KC_GT);
	}
    gt_tap_state.state = 0;
}

/*
	Slash
	tap:	/
	hold:	/=
	double: //
	d hold:	start quote
	tripe:	///
	t hold: close quote
*/
static xtap sl_tap_state = {
    .is_press_action = true,
    .state = 0
};
void sl_finished(qk_tap_dance_state_t *state, void *user_data) {
    sl_tap_state.state = cur_dance(state);
    switch (sl_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code(KC_PSLS);
			break;
		case SINGLE_HOLD:
			tap_code(KC_PSLS);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
			tap_code(KC_PSLS);
			register_code(KC_PSLS);
			break;
		case DOUBLE_HOLD:
			tap_code(KC_PSLS);
			register_code(KC_PAST);
			break;
		case TRI_INT:
		case TRI_TAP:
			tap_code(KC_PSLS);
			tap_code(KC_PSLS);
			register_code(KC_PSLS);
			break;
		case TRI_HOLD:
			tap_code(KC_PAST);
			register_code(KC_PSLS);
			break;
    }
}
void sl_reset(qk_tap_dance_state_t *state, void *user_data) { 
	switch (sl_tap_state.state) {
		case DOUBLE_HOLD:
			unregister_code(KC_PAST);
			break;
		default:
			unregister_code(KC_PSLS);
			break;
    } 
    sl_tap_state.state = 0;
}

/*
	Asterisk
	tap:	*
	hold:	*=
	double: **
*/
static xtap st_tap_state = {
    .is_press_action = true,
    .state = 0
};
void st_finished(qk_tap_dance_state_t *state, void *user_data) {
    st_tap_state.state = cur_dance(state);
    switch (st_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code(KC_PAST);
			break;
		case SINGLE_HOLD:
			tap_code(KC_PAST);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code(KC_PAST);
			register_code(KC_PAST);
			break;
    }
}
void st_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (st_tap_state.state != SINGLE_HOLD){
		unregister_code(KC_PAST);
	}
    st_tap_state.state = 0;
}

/*
	Exclamation mark
	tap:	!
	other:	!=
*/
static xtap em_tap_state = {
    .is_press_action = true,
    .state = 0
};
void em_finished(qk_tap_dance_state_t *state, void *user_data) {
    em_tap_state.state = cur_dance(state);
    switch (em_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code16(KC_EXLM);
			break;
		default:
			tap_code16(KC_EXLM);
			tap_code(KC_EQL);
			break;
    }
}
void em_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (em_tap_state.state != SINGLE_HOLD){
		unregister_code16(KC_EXLM);
	}
    em_tap_state.state = 0;
}

/*
	Pipe
	tap:	|
	hold:	|=
	double: ||
*/
static xtap pi_tap_state = {
    .is_press_action = true,
    .state = 0
};
void pi_finished(qk_tap_dance_state_t *state, void *user_data) {
    pi_tap_state.state = cur_dance(state);
    switch (pi_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code16(KC_PIPE);
			break;
		case SINGLE_HOLD:
			tap_code16(KC_PIPE);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code16(KC_PIPE);
			register_code16(KC_PIPE);
			break;
    }
}
void pi_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (pi_tap_state.state != SINGLE_HOLD){
		unregister_code16(KC_PIPE);
	}
    pi_tap_state.state = 0;
}

/*
	Ampersand
	tap:	&
	hold:	&=
	double: &&
*/
static xtap am_tap_state = {
    .is_press_action = true,
    .state = 0
};
void am_finished(qk_tap_dance_state_t *state, void *user_data) {
    am_tap_state.state = cur_dance(state);
    switch (am_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code16(KC_AMPR);
			break;
		case SINGLE_HOLD:
			tap_code16(KC_AMPR);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code16(KC_AMPR);
			register_code16(KC_AMPR);
			break;
    }
}
void am_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (am_tap_state.state != SINGLE_HOLD){
		unregister_code16(KC_AMPR);
	}
    am_tap_state.state = 0;
}

/*
	Modulus
	tap:	%
	hold:	%=
	double: %%
*/
static xtap mo_tap_state = {
    .is_press_action = true,
    .state = 0
};
void mo_finished(qk_tap_dance_state_t *state, void *user_data) {
    mo_tap_state.state = cur_dance(state);
    switch (mo_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code16(KC_PERC);
			break;
		case SINGLE_HOLD:
			tap_code16(KC_PERC);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code16(KC_PERC);
			register_code16(KC_PERC);
			break;
    }
}
void mo_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (mo_tap_state.state != SINGLE_HOLD){
		unregister_code16(KC_PERC);
	}
    mo_tap_state.state = 0;
}

/*
	XOR
	tap:	^
	hold:	^=
	double: ^^
*/
static xtap ka_tap_state = {
    .is_press_action = true,
    .state = 0
};
void ka_finished(qk_tap_dance_state_t *state, void *user_data) {
    ka_tap_state.state = cur_dance(state);
    switch (ka_tap_state.state) {
		case SINGLE_INT:
        case SINGLE_TAP:
			register_code16(KC_CIRC);
			break;
		case SINGLE_HOLD:
			tap_code16(KC_CIRC);
			tap_code(KC_EQL);
			break;
		case DOUBLE_INT:
		case DOUBLE_TAP:
		case DOUBLE_HOLD:
			tap_code16(KC_CIRC);
			register_code16(KC_CIRC);
			break;
    }
}
void ka_reset(qk_tap_dance_state_t *state, void *user_data) {  
	if (ka_tap_state.state != SINGLE_HOLD){
		unregister_code16(KC_CIRC);
	}
    ka_tap_state.state = 0;
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
void gui_finished(qk_tap_dance_state_t *state, void *user_data) {
    gui_tap_state.state = mod_dance(state);
    switch (gui_tap_state.state) {
		case SINGLE_INT:
			if(get_mods() & MOD_MASK_GUI){
				unregister_mods(MOD_MASK_GUI);
			} else {
				set_oneshot_mods(MOD_MASK_GUI | get_oneshot_mods());
			}
			break;
		case SINGLE_HOLD:
		case DOUBLE_TAP:
			register_mods(MOD_MASK_GUI);
			break;
    }
}
void gui_reset(qk_tap_dance_state_t *state, void *user_data) {  
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
void dance_AT(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
		tap_code16(KC_AT);
	} else {
		tap_code(KC_A);
    }
	reset_tap_dance(state);
}
void dance_DO(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
		tap_code16(KC_DLR);
	} else {
		tap_code(KC_D);
    }
	reset_tap_dance(state);
}
void dance_UN(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
		tap_code16(KC_UNDS);
	} else {
		tap_code(KC_S);
    }
	reset_tap_dance(state);
}
void dance_SH(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
		tap_code16(KC_HASH);
	} else {
		tap_code(KC_F);
    }
	reset_tap_dance(state);
}
void dance_LB(qk_tap_dance_state_t *state, void *user_data) {
	switch(state->count){
		case 1:
			tap_code16(KC_LPRN);
			break;
		case 2:
			tap_code16(KC_LBRC);
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
			tap_code16(KC_RPRN);
			break;
		case 2:
			tap_code16(KC_RBRC);
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

void end_sup_tab(void){
    layer_off(_Tab);
    switch(Tab_Dance){
		case 1:
			tap_code(KC_ENT);
			break;
		case 2:
			unregister_mods(MOD_MASK_CTRL);
			break;
		case 3:
			unregister_mods(MOD_MASK_ALT);
			break;
		case 4:
			tap_code(KC_ENT);
			break;
			
	}
	Tab_Dance = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_TAB_STAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, S(KC_TAB)),
	[TD_BSPC_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL),
	[TD_SAVE] = ACTION_TAP_DANCE_DOUBLE(C(KC_S), RCS(KC_S)),
	[TD_PASTE] = ACTION_TAP_DANCE_DOUBLE(C(KC_V), RCS(KC_V)),
	[TD_CLOSE] = ACTION_TAP_DANCE_DOUBLE(C(KC_W), C(KC_F4)),
	[TD_QUIT] = ACTION_TAP_DANCE_DOUBLE(C(KC_Q), A(KC_F4)),
	[TD_NLAY] = ACTION_TAP_DANCE_FN(dance_NumLay),
	[TD_AT] = ACTION_TAP_DANCE_FN(dance_AT),
	[TD_DO] = ACTION_TAP_DANCE_FN(dance_DO),
	[TD_UN] = ACTION_TAP_DANCE_FN(dance_UN),
	[TD_SH] = ACTION_TAP_DANCE_FN(dance_SH),
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
	[TD_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset)	
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
                end_sup_tab();
                break;
        }
    }
        
    switch (keycode) {
		case LAY_CLR:
			layer_move(_QWERTY);
			return false;
		case GOTO_L:
			if (record->event.pressed) {
				tap_code16(C(KC_G));
				layer_move(_Num);
			}
            break;
        case SUP_TAB:
            if(record->event.pressed){
                Tab_timer = timer_read();
                layer_on(_Tab);
                uint8_t mods = get_oneshot_mods();
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
                if(Tab_Dance == 1){
                    unregister_mods(MOD_MASK_CTRL);
                    unregister_mods(MOD_MASK_ALT);
                }else if (Tab_Dance == 4){
                    unregister_mods(MOD_MASK_GUI);
                }
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
		
	}
    return true;
};

void matrix_scan_user(void) {     // The very important timer.
  if (Tab_Dance > 0) {
    if (timer_elapsed(Tab_timer) > 1000) {
        end_sup_tab();
    }
  }
}
