#include "pressure_sensor.h"
#include "adc.h"
#include "filter.h"

#define SAMPLE_RATE_200HZ  // Default sample rate
// #define SAMPLE_RATE_700HZ  // Uncomment to use 700 Hz

#ifdef SAMPLE_RATE_200HZ
  const int sampleRate = 200;
#elif defined(SAMPLE_RATE_700HZ)
  const int sampleRate = 700;
#else
  const int sampleRate = 200;
#endif

const int sampleInterval = 1000 / sampleRate;

// Pressure sensor configuration
const float SENSOR_VOUT_MIN = 0.2;
const float SENSOR_VOUT_MAX = 4.7;
const float MAX_PRESSURE_PASCAL = 10000.0;

void init_pressure_sensor() {
    init_adc();
}

float get_pressure() {
    float voltage = read_adc_voltage();
    float pressure = ((voltage - SENSOR_VOUT_MIN) / (SENSOR_VOUT_MAX - SENSOR_VOUT_MIN)) * MAX_PRESSURE_PASCAL;

    if (pressure < 0) pressure = 0;
    if (pressure > MAX_PRESSURE_PASCAL) pressure = MAX_PRESSURE_PASCAL;

    #ifdef USE_MOVING_AVERAGE_FILTER
        pressure = apply_moving_average_filter(pressure);
    #endif

    return pressure;
}
