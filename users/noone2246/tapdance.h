#pragma once

#include "quantum.h"
#include "taphold.h"


typedef struct {
  bool is_press_action;
  uint8_t state;
} xtap;

enum
{
    TD_PLUS = TD_END_TAP_HOLD,
	TD_MNUS,
	TD_GT,
	TD_LT,
	TD_SL,
	TD_ST,
	TD_EM,
	TD_PIP,
	TD_AMP,
	TD_MOD,
	TD_CIR,
    TD_END_SYM
};

enum {
    SINGLE_HOLD = 1,
    SINGLE_INT,
	SINGLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_INT,
	DOUBLE_TAP,
    TRI_HOLD,
    TRI_INT,
    TRI_TAP,
	SAFE_TAP
};

uint8_t cur_dance (qk_tap_dance_state_t *state);

void pl_finished(qk_tap_dance_state_t *state, void *user_data);
void pl_reset(qk_tap_dance_state_t *state, void *user_data);

void mn_finished(qk_tap_dance_state_t *state, void *user_data);
void mn_reset(qk_tap_dance_state_t *state, void *user_data);

void lt_finished(qk_tap_dance_state_t *state, void *user_data);
void lt_reset(qk_tap_dance_state_t *state, void *user_data);

void gt_finished(qk_tap_dance_state_t *state, void *user_data);
void gt_reset(qk_tap_dance_state_t *state, void *user_data);

void sl_finished(qk_tap_dance_state_t *state, void *user_data);
void sl_reset(qk_tap_dance_state_t *state, void *user_data);

void st_finished(qk_tap_dance_state_t *state, void *user_data);
void st_reset(qk_tap_dance_state_t *state, void *user_data);

void em_finished(qk_tap_dance_state_t *state, void *user_data);
void em_reset(qk_tap_dance_state_t *state, void *user_data);

void pi_finished(qk_tap_dance_state_t *state, void *user_data);
void pi_reset(qk_tap_dance_state_t *state, void *user_data);

void am_finished(qk_tap_dance_state_t *state, void *user_data);
void am_reset(qk_tap_dance_state_t *state, void *user_data);

void mo_finished(qk_tap_dance_state_t *state, void *user_data);
void mo_reset(qk_tap_dance_state_t *state, void *user_data);

void ka_finished(qk_tap_dance_state_t *state, void *user_data);
void ka_reset(qk_tap_dance_state_t *state, void *user_data);