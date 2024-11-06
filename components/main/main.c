#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pressure_sensor.h"

void app_main() {
    init_pressure_sensor();

    while (1) {
        float pressure = get_pressure();
        printf("Pressure (Pa): %.2f\n", pressure);
        
        // Wait until the next sample interval
        vTaskDelay(pdMS_TO_TICKS(sampleInterval));
    }
}