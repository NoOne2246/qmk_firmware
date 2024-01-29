#pragma once

#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"
#include "layer.h"



void handle_tab(uint16_t keycode, bool pressed);

void end_tab(void);

void check_tab(void);