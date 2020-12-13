#include "user_config.h"
#include "power.h"


void power_init() {
    PIN_FUNC_SELECT(RELAY_MUX, RELAY_FUNC);
    PIN_PULLUP_EN(RELAY_MUX);
    POWEROFF();
}
