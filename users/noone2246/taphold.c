#include "taphold.h"

void dance_Q1(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_1, KC_Q);
}
void dance_W2(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_2, KC_W);
}
void dance_E3(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_3, KC_E);
}
void dance_R4(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_4, KC_R);
}
void dance_T5(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_5, KC_T);
}
void dance_Y6(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_6, KC_Y);
}
void dance_U7(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_7, KC_U);
}
void dance_I8(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_8, KC_I);
}
void dance_O9(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_9, KC_O);
}
void dance_P0(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_0, KC_P);
}
void dance_AT(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_AT, KC_A);
}
void dance_DO(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_DLR, KC_D);
}
void dance_UN(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_UNDS, KC_S);
}
void dance_SH(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_HASH, KC_F);
}
void dance_BS(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_BSLS, KC_B);
}
void dance_TI(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_TILD, KC_Z);
}
void dance_BQ(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_GRV, KC_X);
}
void dance_PC(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_PERC, KC_C);
}
void dance_KA(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_CIRC, KC_V);
}
void dance_AM(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_AMPR, KC_G);
}
void dance_PI(qk_tap_dance_state_t *state, void *user_data) {
    presskey(state, KC_PIPE, KC_H);
}
void presskey(qk_tap_dance_state_t *state, uint16_t keyhold, uint16_t keytap){
    bool press = (state->pressed);
    for(int i = 0; i < state->count;i++){
        if (press){
            tap_code16(keyhold);
        }else{        
            tap_code16(keytap);
        }
    }
	reset_tap_dance(state);
}