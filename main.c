#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "hw_conf.h"
#include "gpio.h"

//i2c configuration
static const I2CConfig i2cconfig = {
    STM32_TIMINGR_PRESC(15U) |
    STM32_TIMINGR_SCLDEL(4U) | STM32_TIMINGR_SDADEL(2U) |
    STM32_TIMINGR_SCLH(15U)  | STM32_TIMINGR_SCLL(21U),
    0,
    0
};

int main(void) {

    halInit();
    chSysInit();
    gpioInit();
    i2cStart(&I2C_DEV, &i2cconfig);

    while(1)
    {
        i2cAcquireBus(&I2C_DEV);
        uint8_t tx[1];
        uint8_t rx[1];

        tx[0] = 0x0F;
        tx[1] = 0xFF;
        i2cMasterTransmitTimeout(&I2C_DEV, 0x0C, tx, 2, rx, 0, MS2ST(10));
        i2cReleaseBus(&I2C_DEV);
        chThdSleepMilliseconds(20);
    }
}
