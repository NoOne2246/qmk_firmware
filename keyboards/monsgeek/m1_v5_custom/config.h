// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define NKRO_DEFAULT_ON true

// #define USB_POWER_EN_PIN                    B1 // USB ENABLE pin
// #define LED_POWER_EN_PIN                    A5 // LED ENABLE pin
// #define HS_BAT_CABLE_PIN                    A7 // USB insertion detection pin
// #define HS_LED_BOOSTING_PIN                 D2 // LED BOOSTING

// #define HS_RGB_INDICATOR_COUNT              99
// #define HS_RGB_BAT_COUNT                    1

// /* UART */
// #define SERIAL_DRIVER                       SD3
// #define SD1_TX_PIN                          C10
// #define SD1_RX_PIN                          C11

/* Encoder */
#define ENCODER_MAP_KEY_DELAY               1

/* SPI */
#define SPI_DRIVER                          SPIDQ
#define SPI_SCK_PIN                         B3
#define SPI_MOSI_PIN                        B5
#define SPI_MISO_PIN                        B4

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12
// #define WEAR_LEVELING_LOGICAL_SIZE          (WEAR_LEVELING_BACKING_SIZE / 2)

// /* RGB Matrix */
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_MATRIX_KEYPRESSES

// // /* WS2812 */
#define WS2812_SPI_DRIVER  SPIDM2
#define WS2812_SPI_DIVISOR 32

#define RGB_MATRIX_LED_COUNT 83