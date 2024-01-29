#pragma once


#include "quantum.h"
#include "process_keycode/process_tap_dance.h"
#include "layer.h"
#include "tapdance.h"
#include "taphold.h"

#ifdef SUPTAB
#include "suptab.h"
#endif

enum
{
    TD_TAB_STAB = TD_END_SYM,
	TD_BSPC_DEL,
	TD_SAVE,
	TD_PASTE,
	TD_CLOSE,
	TD_QUIT,
	TD_NLAY,
	TD_LB,
	TD_RB,
	TD_SHFT,
	TD_ALT,
	TD_GUI,
	TD_CTRL
};

enum planck_keycodes {
  #ifdef SUPTAB
  LAY_CLR = END_TAB_RANGE,
  #else
  LAY_CLR = SAFE_RANGE,
  #endif
  GOTO_L,
  MSE_LFT,
  MSE_MID,
  MSE_RHT,
  TG_SHFT,
  TG_CTRL,
  TG_GUI,
  TG_ALT,
  OS_GUI,
  LAY_FNC,
};



void Three_Cancel(qk_tap_dance_state_t *state, void *user_data);
void Four_Cancel(qk_tap_dance_state_t *state, void *user_data);

uint8_t mod_dance(qk_tap_dance_state_t *state);

void ctrl_finished(qk_tap_dance_state_t *state, void *user_data) ;
void ctrl_reset(qk_tap_dance_state_t *state, void *user_data);

void alt_finished(qk_tap_dance_state_t *state, void *user_data) ;
void alt_reset(qk_tap_dance_state_t *state, void *user_data);

void shft_finished(qk_tap_dance_state_t *state, void *user_data);
void shft_reset(qk_tap_dance_state_t *state, void *user_data) ;

void gui_each(qk_tap_dance_state_t *state, void *user_data);
void gui_finished(qk_tap_dance_state_t *state, void *user_data);
void gui_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_NumLay(qk_tap_dance_state_t *state, void *user_data);
