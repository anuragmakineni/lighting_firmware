#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "hw_conf.h"
#include "gpio.h"
#include "dac121c081.h"
#include "led_conf.h"
#include "usbcfg.h"
#include "chprintf.h"

#define usb_lld_connect_bus(usbp)
#define usb_lld_disconnect_bus(usbp)

int main(void) {

    halInit();
    chSysInit();
    gpioInit();
    dacInit();
    
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(150);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    while(1)
    {
       setDAC(LED1_ADDR, 1.0, LED1_VREF);
       chprintf((BaseSequentialStream *)&SDU1, "%s\n", "test");
       chThdSleepMilliseconds(10);
    }
}
