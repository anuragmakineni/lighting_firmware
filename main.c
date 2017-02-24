#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"

int main(void) {

    halInit();
    chSysInit();
    palSetPadMode(GPIOB, 0, PAL_MODE_OUTPUT_PUSHPULL |
                                PAL_STM32_OSPEED_HIGHEST);
    while(1)
    {
        palClearPad(GPIOB, 0);
        chThdSleepMilliseconds(100);
        palSetPad(GPIOB, 0);
        chThdSleepMilliseconds(100);
    }
}
