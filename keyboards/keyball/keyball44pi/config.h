#pragma once

#define MATRIX_MASKED

#define PMW33XX_CS_PIN GP10
#define PMW33XX_CPI 500
#define PMW33XX_CPI_SCR 100
#define PMW33XX_SPI_DIVISOR 64

#define SERIAL_USART_TX_PIN GP1
#define SERIAL_PIO_USE_PIO1 

#define SPLIT_POINTING_ENABLE

#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

#define LAYER_State_8BIT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// #ifdef OLED_ENABLE 
// #   define OLED_FONT_H "keyboards/keyball/keyball44/glcdfont.c"
// #   define OLED_FONT_START 32
// #   define OLED_FONT_END 127
// #endif