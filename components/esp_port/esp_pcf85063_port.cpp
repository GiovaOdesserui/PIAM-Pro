
#include "esp_pcf85063_port.h"
#include "SensorPCF85063.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c_master.h"

SensorPCF85063 rtc;

void esp_pcf85063_port_init(i2c_master_bus_handle_t bus_handle)
{
    while (!rtc.begin(bus_handle, PCF85063_SLAVE_ADDRESS))
    {
        printf("Failed to find PCF8563 - check your wiring!\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    RTC_DateTime datetime = rtc.getDateTime();

    if (datetime.year < 2025)
    {
        datetime.year = 2025;
        datetime.month = 1;
        datetime.day = 1;
        datetime.hour = 12;
        datetime.minute = 0;
        datetime.second = 0;
        rtc.setDateTime(datetime.year, datetime.month, datetime.day, datetime.hour, datetime.minute, datetime.second);
    }
    rtc.start();
}
extern "C" void piam_rtc_get_hour_minute(int *hour, int *minute)
{
    RTC_DateTime dt = rtc.getDateTime();
    if (hour) *hour = dt.hour;
    if (minute) *minute = dt.minute;
}

extern "C" void piam_rtc_get_date(int *day, int *month)
{
    RTC_DateTime dt = rtc.getDateTime();
    if (day) *day = dt.day;
    if (month) *month = dt.month;
}
