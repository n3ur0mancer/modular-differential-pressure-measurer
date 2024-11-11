#include "pressure_sensor.h"
#include "filter.h"
#include "driver/adc.h"
#include "project_config.h"
#include <stdio.h>

static int sampleRate = SAMPLE_RATE_200HZ;

void init_pressure_sensor() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(SENSOR_PIN, ADC_ATTEN_DB_11);
    init_filter();
}

float get_raw_pressure() {
    int adcValue = adc1_get_raw(SENSOR_PIN);
    return (adcValue / 4095.0) * 3.3;  // Normalize ADC reading to voltage (VREF = 3.3V)
}

float get_pressure() {
    float voltage = get_raw_pressure();
    float pressure = ((voltage - 0.2) / (4.7 - 0.2)) * 10000.0;  // Convert to Pascals
    if (pressure < 0) pressure = 0;
    if (pressure > 10000.0) pressure = 10000.0;

    // Apply filter
    return apply_moving_average_filter(pressure);
}

void set_sample_rate(int rate) {
    sampleRate = rate;
}

int get_sample_interval() {
    return 1000 / sampleRate;  // Interval in milliseconds
}
