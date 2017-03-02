#include "ch.h"
#include "hal.h"
#include "hw_conf.h"
#include "math.h"

//i2c configuration
static const I2CConfig i2cconfig = {
    STM32_TIMINGR_PRESC(15U) |
    STM32_TIMINGR_SCLDEL(4U) | STM32_TIMINGR_SDADEL(2U) |
    STM32_TIMINGR_SCLH(15U)  | STM32_TIMINGR_SCLL(21U),
    0,
    0
};

void dacInit(void)
{
    i2cStart(&I2C_DEV, &i2cconfig);
}

void setDAC(uint8_t addr, float v_set, float v_ref)
{
    // calculate upper and lower data bytes
    int ctl = (int) roundf((v_set / v_ref) * 4095);
    uint8_t DB1 = ctl >> 8;
    uint8_t DB2 = ctl & 0xFF;

    // populate packet
    uint8_t tx[2];
    uint8_t rx[1];
    tx[0] = DB1;
    tx[1] = DB2;

    // send i2c command to dac
    i2cAcquireBus(&I2C_DEV);
    i2cMasterTransmitTimeout(&I2C_DEV, addr, tx, 2, rx, 0, MS2ST(10));
    i2cReleaseBus(&I2C_DEV);
}

float readDAC(uint8_t addr, float v_ref)
{
    // request two bytes from dac
    uint8_t rx[2];
    i2cAcquireBus(&I2C_DEV);
    i2cMasterReceiveTimeout(&I2C_DEV, addr, rx, 2, MS2ST(10));
    i2cReleaseBus(&I2C_DEV);

    // combine bytes and convert to float
    uint16_t data = (rx[0] << 8) | rx[1];
    float v_set = v_ref * (data / 4095.0);

    return v_set;
}
