#include "halconf.h"
#include "ch.h"
#include "hal.h"


void dacInit(void);
void setDAC(uint8_t addr, float v_set, float v_ref);
float readDAC(uint8_t addr, float v_ref);

