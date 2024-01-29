#pragma once

#include "quantum.h"

enum {
  _QWERTY,
  _Num,
  _Mouse,
  _Extra,
  
  #ifdef SUPTAB
  _Tab,
  #endif
  
  _Sym,
  _FN,
  _Media
};

enum{    
  SUP_TAB = SAFE_RANGE,
  TAB_PRE,
  TAB_UP,
  TAB_NXT,
  TAB_LFT,
  TAB_DWN,
  TAB_RHT,
  END_TAB_RANGE
};