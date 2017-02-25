#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "hw_conf.h"
#include "gpio.h"

int main(void) {

    halInit();
    chSysInit();
    gpioInit();

    while(1)
    {
        palClearPad(EN_GPIO, EN1_PIN);
        chThdSleepMilliseconds(100);
        palSetPad(EN_GPIO, EN1_PIN);
        chThdSleepMilliseconds(100);
    }
}
