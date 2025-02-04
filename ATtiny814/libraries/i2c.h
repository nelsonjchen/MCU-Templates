// ===================================================================================
// Basic I2C Master Functions for tinyAVR 0-Series and 1-Series               * v1.1 *
// ===================================================================================
//
// Functions available:
// --------------------
// I2C_init()               Init I2C with defined clock rate (see below)
// I2C_start(addr)          I2C start transmission, addr must contain R/W bit
// I2C_restart(addr)        I2C restart transmission, addr must contain R/W bit
// I2C_write(b)             I2C transmit one data byte via I2C
// I2C_read(ack)            I2C receive one data byte from slave, ack=0: last byte
// I2C_stop()               I2C stop transmission
//
// I2C_writeBuffer(buf,len) Send buffer (*buf) with length (len) via I2C and stop
// I2C_readBuffer(buf,len)  Read buffer (*buf) with length (len) via I2C and stop
//
// I2C pin mapping (set below in I2C parameters):
// ----------------------------------------------
// I2C_MAP   0     1     2
// SDA-pin  PB1   PA1   No mapping
// SCL-pin  PB0   PA2   No mapping
//
// External pull-up resistors (4k7 - 10k) are mandatory!
// 2021 by Stefan Wagner:   https://github.com/wagiminator

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "system.h"

// I2C Parameters
#define I2C_CLKRATE   400000    // I2C bus clock rate (Hz)
#define I2C_MAP       0         // I2C pin mapping (see above)

// I2C Functions
void I2C_init(void);            // I2C init function
void I2C_start(uint8_t addr);   // I2C start transmission, addr must contain R/W bit
void I2C_restart(uint8_t addr); // I2C restart transmission
void I2C_write(uint8_t data);   // I2C transmit one data byte via I2C
uint8_t I2C_read(uint8_t ack);  // I2C receive one data byte from slave
void I2C_stop(void);            // I2C stop transmission

void I2C_writeBuffer(uint8_t* buf, uint16_t len);
void I2C_readBuffer(uint8_t* buf, uint16_t len);

#ifdef __cplusplus
};
#endif
