#include "halconf.h"
#include "ch.h"
#include "hal.h"


void dacInit(void);
void setDAC(uint8_t addr, uint8_t DB1, uint8_t  DB2);
float readDAC(uint8_t addr, float v_ref);

