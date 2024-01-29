#pragma once

#include "quantum.h"

enum
{
    TD_Q1,
    TD_W2,
    TD_E3,
    TD_R4,
    TD_T5,
    TD_Y6,
    TD_U7,
    TD_I8,
    TD_O9,
    TD_P0,
	TD_AT,
	TD_DO,
	TD_SH,
	TD_UN,
    TD_BS,
    TD_TI,
    TD_BQ,
    TD_PC,
    TD_KA,
    TD_AM,
    TD_PI,
    TD_END_TAP_HOLD
};


void dance_Q1(qk_tap_dance_state_t *state, void *user_data);
void dance_W2(qk_tap_dance_state_t *state, void *user_data);
void dance_E3(qk_tap_dance_state_t *state, void *user_data);
void dance_R4(qk_tap_dance_state_t *state, void *user_data);
void dance_T5(qk_tap_dance_state_t *state, void *user_data);
void dance_Y6(qk_tap_dance_state_t *state, void *user_data);
void dance_U7(qk_tap_dance_state_t *state, void *user_data);
void dance_I8(qk_tap_dance_state_t *state, void *user_data);
void dance_O9(qk_tap_dance_state_t *state, void *user_data);
void dance_P0(qk_tap_dance_state_t *state, void *user_data);
void dance_AT(qk_tap_dance_state_t *state, void *user_data);
void dance_LB(qk_tap_dance_state_t *state, void *user_data);
void dance_RB(qk_tap_dance_state_t *state, void *user_data);
void dance_DO(qk_tap_dance_state_t *state, void *user_data);
void dance_UN(qk_tap_dance_state_t *state, void *user_data);
void dance_SH(qk_tap_dance_state_t *state, void *user_data);
void dance_BS(qk_tap_dance_state_t *state, void *user_data);
void dance_TI(qk_tap_dance_state_t *state, void *user_data);
void dance_BQ(qk_tap_dance_state_t *state, void *user_data);
void dance_PC(qk_tap_dance_state_t *state, void *user_data);
void dance_KA(qk_tap_dance_state_t *state, void *user_data);
void dance_AM(qk_tap_dance_state_t *state, void *user_data);
void dance_PI(qk_tap_dance_state_t *state, void *user_data);

void presskey(qk_tap_dance_state_t *state, uint16_t keyhold, uint16_t keytap);