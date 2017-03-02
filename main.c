#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "hw_conf.h"
#include "gpio.h"
#include "dac121c081.h"
#include "led_conf.h"

int main(void) {

    halInit();
    chSysInit();
    gpioInit();
    dacInit();

    while(1)
    {
       setDAC(LED1_ADDR, 0x0F, 0xFF);
       chThdSleepMilliseconds(10);
    }
}
