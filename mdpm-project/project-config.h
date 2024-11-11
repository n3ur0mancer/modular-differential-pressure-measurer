#pragma once

// GPIO pin definitions
#define SENSOR_PIN          GPIO_NUM_34       // ADC1 channel for the pressure sensor
#define TOGGLE_SWITCH_PIN   GPIO_NUM_15       // GPIO for MTS-103 toggle switch

// Modes
#define STANDBY_MODE        0
#define LOW_DYNAMICS_MODE   1
#define HIGH_DYNAMICS_MODE  2

// Sample rates
#define SAMPLE_RATE_200HZ   200
#define SAMPLE_RATE_700HZ   700
