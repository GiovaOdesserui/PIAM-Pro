#pragma once

#ifdef __cplusplus
#include "SensorPCF85063.hpp"
#include "driver/i2c_master.h"

extern SensorPCF85063 rtc;
#else
#include "driver/i2c_master.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void esp_pcf85063_port_init(i2c_master_bus_handle_t bus_handle);

// PIAM Pro: puente en C puro para leer hora/minuto sin necesitar
// incluir los headers de C++ de SensorLib desde un archivo .c.
void piam_rtc_get_hour_minute(int *hour, int *minute);

// PIAM Pro: idem, para dia/mes.
void piam_rtc_get_date(int *day, int *month);

#ifdef __cplusplus
}
#endif
