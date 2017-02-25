#include "ch.h"
#include "hal.h"
#include "hw_conf.h"

void gpioInit(void)
{
    //GPIO
    palSetPadMode(EN_GPIO, EN1_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN1_PIN);

    palSetPadMode(EN_GPIO, EN2_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN2_PIN);
    
    palSetPadMode(EN_GPIO, EN3_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN3_PIN);
    
    palSetPadMode(EN_GPIO, EN4_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN4_PIN);
    
    palSetPadMode(EN_GPIO, EN5_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN5_PIN);
    
    palSetPadMode(EN_GPIO, EN6_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN6_PIN);
    
    palSetPadMode(EN_GPIO, EN7_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN7_PIN);
    
    palSetPadMode(EN_GPIO, EN8_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN8_PIN);
    
    palSetPadMode(EN_GPIO, EN9_PIN, PAL_MODE_OUTPUT_PUSHPULL |
                        PAL_STM32_OSPEED_HIGHEST);
    palClearPad(EN_GPIO, EN9_PIN);
    
    // I2C
    palSetPadMode(SDA_GPIO, SDA_PIN, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP | PAL_STM32_OSPEED_MID1);
    palSetPadMode(SCL_GPIO, SCL_PIN, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP | PAL_STM32_OSPEED_MID1);

    // USB
    palSetPadMode(USB_DM_GPIO, USB_DM_PIN, PAL_MODE_ALTERNATE(14));
    palSetPadMode(USB_DP_GPIO, USB_DP_PIN, PAL_MODE_ALTERNATE(14));
}
