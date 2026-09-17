#pragma once

#ifdef __cplusplus
#include <stdio.h>
#include "driver/i2c_master.h"

#define XPOWERS_CHIP_AXP2101
#include "XPowersLib.h"

extern XPowersPMU power;

esp_err_t esp_axp2101_port_init(i2c_master_bus_handle_t bus_handle);
void pmu_isr_handler(void);
#endif

#ifdef __cplusplus
extern "C" {
#endif

// PIAM Pro: puente en C puro para leer el porcentaje de bateria sin
// necesitar incluir XPowersLib.h (C++) desde un archivo .c.
int piam_battery_get_percent(void);

#ifdef __cplusplus
}
#endif
