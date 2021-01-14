#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

#define SAFE_TAP 10

typedef struct {
  bool is_press_action;
  uint8_t state;
} xtap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  SINGLE_INT,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_INT,
  TRI_TAP,
  TRI_HOLD,
  TRI_INT
};

enum
{
    TD_TAB_STAB,
	TD_BSPC_DEL,
	TD_SAVE,
	TD_PASTE,
	TD_CLOSE,
	TD_QUIT,
	TD_NLAY,
	TD_AT,
	TD_DO,
	TD_SH,
	TD_UN,
	TD_LB,
	TD_RB,
	TD_PLUS,
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
	TD_SHFT,
	TD_ALT,
	TD_GUI,
	TD_CTRL
};

enum planck_keycodes {
  LAY_CLR = SAFE_RANGE,
  GOTO_L,
  SUP_TAB,
  TAB_PRE,
  TAB_UP,
  TAB_NXT,
  TAB_LFT,
  TAB_DWN,
  TAB_RHT,
  MSE_LFT,
  MSE_MID,
  MSE_RHT
};


enum planck_layers {
  _QWERTY,
  _FN,
  _Num,
  _Sym,
  _Mouse,
  _Tab
};

void Three_Cancel(qk_tap_dance_state_t *state, void *user_data);
void Four_Cancel(qk_tap_dance_state_t *state, void *user_data);

uint8_t cur_dance (qk_tap_dance_state_t *state);
uint8_t mod_dance(qk_tap_dance_state_t *state);

void pl_finished (qk_tap_dance_state_t *state, void *user_data);
void pl_reset (qk_tap_dance_state_t *state, void *user_data);

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

void ka_finished(qk_tap_dance_state_t *state, void *user_data) ;
void ka_reset(qk_tap_dance_state_t *state, void *user_data);

void ctrl_finished(qk_tap_dance_state_t *state, void *user_data) ;
void ctrl_reset(qk_tap_dance_state_t *state, void *user_data);

void alt_finished(qk_tap_dance_state_t *state, void *user_data) ;
void alt_reset(qk_tap_dance_state_t *state, void *user_data);

void shft_finished(qk_tap_dance_state_t *state, void *user_data);
void shft_reset(qk_tap_dance_state_t *state, void *user_data) ;

void gui_finished(qk_tap_dance_state_t *state, void *user_data);
void gui_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_NumLay(qk_tap_dance_state_t *state, void *user_data);
void dance_AT(qk_tap_dance_state_t *state, void *user_data);
void dance_LB(qk_tap_dance_state_t *state, void *user_data);
void dance_RB(qk_tap_dance_state_t *state, void *user_data);
void dance_DO(qk_tap_dance_state_t *state, void *user_data);
void dance_UN(qk_tap_dance_state_t *state, void *user_data);
void dance_SH(qk_tap_dance_state_t *state, void *user_data);

void end_sup_tab(void);