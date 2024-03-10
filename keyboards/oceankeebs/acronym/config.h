#pragma once

#include "config_common.h"

#define VENDOR_ID       0x1013
#define PRODUCT_ID      0x00AC
#define DEVICE_VER      0x0001
#define MANUFACTURER    jnknwn
#define PRODUCT         Acronym

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

/* A Custom matrix.c is used to poll the port expander C6 shows that the pins are hardwired there */
#define MATRIX_ROW_PINS { B2, B3, D7, E6, B4 }
#define MATRIX_COL_PINS { D5, D5, D5, D5, D5, D5, D5, D5, D5, D5, D5, D5, D5, D5, D5, D5, B5, B6 }
#define UNUSED_PINS
#define PORT_EXPANDER_ADDRESS 0x20

#define DIODE_DIRECTION ROW2COL

#define USB_MAX_POWER_CONSUMPTION 100

