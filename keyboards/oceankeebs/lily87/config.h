// Copyright 2022 Jonas Lehner (@jnknwn)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1013
#define PRODUCT_ID      0x0087
#define DEVICE_VER      0x0100
#define MANUFACTURER    jnknwn
#define PRODUCT         Lily87

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 10

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6, F4, F5, D4, D3 }

#define DIODE_DIRECTION COL2ROW

#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

#define SPLIT_USB_DETECT

#define MASTER_LEFT

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
