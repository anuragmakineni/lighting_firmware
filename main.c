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
#define SERIAL_RX_BUFFER_SIZE (1024)
#define PACKET_LENGTH (18)
static uint8_t serial_rx_buffer[SERIAL_RX_BUFFER_SIZE];
static uint8_t packet[PACKET_LENGTH];
static int serial_rx_read_pos = 0;
static int serial_rx_write_pos = 0;
static int packet_index = 0;
static bool valid_packet = false;

// process serial byte
void process_byte(uint8_t data_byte) {
    // check for terminator
    if (data_byte == '\n'){
       chprintf((BaseSequentialStream *)&SDU1, "%s\n", "end of packet");
       chprintf((BaseSequentialStream *)&SDU1, "%d\n", packet_index);
        if (valid_packet && packet_index == PACKET_LENGTH){
            chprintf((BaseSequentialStream *)&SDU1, "%s\n", packet);
        }
        packet_index = 0;
        valid_packet = false;
    }

    // save valid byte
    if (valid_packet){
        if (packet_index >= PACKET_LENGTH){
            packet_index = 0;
            valid_packet = false;
            chprintf((BaseSequentialStream *)&SDU1, "%s\n", "too long, reset");
        }
        packet[packet_index++] = data_byte;
    }

    // check for start
    if (data_byte == 'P') {
        packet_index = 0;
        valid_packet = true;
        chprintf((BaseSequentialStream *)&SDU1, "%s\n", "start of packet");
    }


}


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

        // listen for serial byte
        uint8_t buffer[128];
        int i;
        int len;
        int had_data = 0;

        for(;;) {
            len = chSequentialStreamRead(&SDU1, (uint8_t*) buffer, 1);

            for (i = 0; i < len; i++) {
                serial_rx_buffer[serial_rx_write_pos++] = buffer[i];

                if (serial_rx_write_pos == SERIAL_RX_BUFFER_SIZE) {
                    serial_rx_write_pos = 0;
                }

            had_data = 1;
        }

        if (had_data){
            process_byte(serial_rx_buffer[serial_rx_read_pos++]);
        }

        if (serial_rx_read_pos == SERIAL_RX_BUFFER_SIZE) {
            serial_rx_read_pos = 0;
            }
        }

        chThdSleepMilliseconds(1);
    }
}
