#include <driver/adc.h>
#include "adc.h"

#define ADC_MAX 4095.0
#define VREF 3.3
#define SENSOR_PIN ADC1_CHANNEL_6  // GPIO34 in ADC1

void init_adc() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(SENSOR_PIN, ADC_ATTEN_DB_11);
}

float read_adc_voltage() {
    int adcValue = adc1_get_raw(SENSOR_PIN);
    return (adcValue / ADC_MAX) * VREF;
}
