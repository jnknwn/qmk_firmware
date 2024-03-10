#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "quantum.h"
#include "i2c_master.h"
#include "print.h"


static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

#define EXPANDER_COLS 16
#define EXPANDER_ROWS 6

static void unselect_cols(void) {
    uint8_t send_data[2] = { 0xFF, 0xFF};

    // i2c_writeReg(uint8_t devaddr, uint8_t regaddr, const uint8_t* data, uint16_t length, uint16_t timeout)
    // Registers:
    // 0x00     IODIRA      Input(1)/Output(0)
    // 0x01     IODIRB      Input(1)/Output(0)
    // 0x0C     GPPUA       PullUp
    // 0x0D     GPPUB       PullUp
    // 0x12     GPIOA       Level of IO
    // 0x13     GPIOB       Level of IO

    // Set all I/O to input
    i2c_writeReg((PORT_EXPANDER0_ADDRESS << 1), 0x00, &send_data[0], 2, 20);
    i2c_writeReg((PORT_EXPANDER1_ADDRESS << 1), 0x00, &send_data[0], 2, 20);
    
    // Set Pull-up
    i2c_writeReg((PORT_EXPANDER0_ADDRESS << 1), 0x0C, &send_data[0], 2, 20);
    i2c_writeReg((PORT_EXPANDER1_ADDRESS << 1), 0x0C, &send_data[0], 2, 20);
    
    // Set Input for Pins on Pro Micro
    for(uint8_t x = EXPANDER_COLS; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }

}

static void select_col(uint8_t col) {
    // Set corresponding I/O pin to col to output
    uint8_t send_data[2] = { 0xFF, 0xFF};

    if (col > EXPANDER_COLS) {
        setPinOutput(col_pins[col]);
        writePinLow(col_pins[col]);
    }
    else {
        // Set send_data to mask pins from Expander
        send_data[0] = col;

        // Set Output of the selected col pin
        i2c_writeReg((PORT_EXPANDER0_ADDRESS << 1), 0x00, &send_data[0], 2, 20);
        i2c_writeReg((PORT_EXPANDER1_ADDRESS << 1), 0x00, &send_data[0], 2, 20);
    }
}


static void init_pins(void) {
    unselect_cols();

    // Set all rows with pins on Pro Micro as Input
    for (uint8_t x = EXPANDER_ROWS; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

void matrix_init_custom(void) {
    // Initialize I2C
    i2c_init();

    // Initialize key pins
    init_pins();
    wait_ms(50);
}

void read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col, matrix_row_t row_shifter) {
    // Select col and wait for col selecton to stabilize
    select_col(current_col);
    wait_us(30);

    uint8_t port_expander0_row_buffer[1];
    uint8_t port_expander1_row_buffer[1];
    i2c_readReg((PORT_EXPANDER0_ADDRESS << 1), 0x12, &port_expander0_row_buffer[0], 1, 20);
    i2c_readReg((PORT_EXPANDER1_ADDRESS << 1), 0x12, &port_expander1_row_buffer[0], 1, 20);

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        uint8_t pin_state;
        // Select the row pin to read (active low)
        switch (row_index) {
            case 0 :
                pin_state = port_expander0_row_buffer[0] & (1 << 0) || port_expander1_row_buffer[0] & (1 << 0);
                break;
            case 1 :
                pin_state = port_expander0_row_buffer[0] & (1 << 1) || port_expander1_row_buffer[0] & (1 << 1);
                break;
            case 2 :
                pin_state = port_expander0_row_buffer[0] & (1 << 2) || port_expander1_row_buffer[0] & (1 << 2);
                break;
            case 3 :
                pin_state = port_expander0_row_buffer[0] & (1 << 3) || port_expander1_row_buffer[0] & (1 << 3);
                break;
            case 4 :
                pin_state = port_expander0_row_buffer[0] & (1 << 4) || port_expander1_row_buffer[0] & (1 << 4);
                break;
            case 5 :
                pin_state = port_expander0_row_buffer[0] & (1 << 5) || port_expander1_row_buffer[0] & (1 << 5);
                break;
            default :
                pin_state = readPin(row_pins[row_index]);
        }

        // Check row pin state
        if (pin_state == 0) {
            // Pin LO, set col bit
            current_matrix[row_index] |= row_shifter;
            key_pressed = true;
        } else {
            // Pin HI, clear col bit
            current_matrix[row_index] &= ~row_shifter;
        }
    }

    // Unselect col
    unselect_cols();
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    // Store last value of col prior to reading
    matrix_row_t last_col_value = current_matrix[current_col];

    // Clear data in matrix col
    current_matrix[current_col] = 0;

    // Select col and wait for col selecton to stabilize
    select_col(current_col);
    wait_us(30);

    uint8_t port_expander0_row_buffer[2];
    uint8_t port_expander1_row_buffer[2];
    i2c_readReg((PORT_EXPANDER0_ADDRESS << 1), 0x12, &port_expander0_row_buffer[0], 2, 20);
    i2c_readReg((PORT_EXPANDER1_ADDRESS << 1), 0x12, &port_expander1_row_buffer[0], 2, 20);

    // For each row...
    for(uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        uint8_t pin_state;
        // Select the row pin to read (active low)
        switch (row_index) {
            case 0 :
                pin_state = port_expander0_row_buffer[1] & (1 << 0) || port_expander1_row_buffer[1] & (1 << 0);
                break;
            case 1 :
                pin_state = port_expander0_row_buffer[1] & (1 << 1) || port_expander1_row_buffer[1] & (1 << 1);
                break;
            case 2 :
                pin_state = port_expander0_row_buffer[1] & (1 << 2) || port_expander1_row_buffer[1] & (1 << 2);
                break;
            case 3 :
                pin_state = port_expander0_row_buffer[1] & (1 << 3) || port_expander1_row_buffer[1] & (1 << 3);
                break;
            case 4 :
                pin_state = port_expander0_row_buffer[1] & (1 << 4) || port_expander1_row_buffer[1] & (1 << 4);
                break;
            case 5 :
                pin_state = port_expander0_row_buffer[1] & (1 << 5) || port_expander1_row_buffer[1] & (1 << 5);
                break;
            default :
                pin_state = readPin(row_pins[row_index]);
        }

        // Populate the matrix col with the state of the row pin
        current_matrix[current_col] |=  pin_state ? 0 : (MATRIX_ROW_SHIFTER << row_index);
    }

    // Unselect col
    unselect_cols();

    return (last_col_value != current_matrix[current_col]);
}

bool matrix_scan_custom(matrix_row_t curr_matrix[]) {

    // Set col, read rows
    matrix_row_t row_shifter = MATRIX_ROW_SHIFTER;
    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++, row_shifter <<= 1) {
        read_rows_on_col(curr_matrix, current_col, row_shifter);
    }

    bool changed = memcmp(raw_matrix, curr_matrix, sizeof(curr_matrix)) != 0;
    if (changed) memcpy(raw_matrix, curr_matrix, sizeof(curr_matrix));
    
    return (uint8_t)changed;
}
