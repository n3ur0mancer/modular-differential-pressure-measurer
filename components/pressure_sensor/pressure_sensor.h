#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

void init_pressure_sensor();
float get_pressure();

extern const int sampleInterval;

#endif // PRESSURE_SENSOR_H
