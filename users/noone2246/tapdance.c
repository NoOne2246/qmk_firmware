#include "tapdance.h"


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