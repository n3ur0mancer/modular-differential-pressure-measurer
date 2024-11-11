#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "pressure_sensor.h"
#include "project_config.h"
#include <stdio.h>

// Current system mode
static int currentMode = STANDBY_MODE;

// Function to initialize the toggle switch
void init_toggle_switch() {
    gpio_pad_select_gpio(TOGGLE_SWITCH_PIN);
    gpio_set_direction(TOGGLE_SWITCH_PIN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(TOGGLE_SWITCH_PIN, GPIO_PULLUP_ONLY); // Use internal pull-up resistor
}

// Function to read the state of the toggle switch
int read_toggle_switch() {
    return gpio_get_level(TOGGLE_SWITCH_PIN);  // Returns HIGH or LOW depending on switch state
}

// Function to change mode based on the toggle switch
void update_mode() {
    static int lastSwitchState = 1;  // Assume switch is in high state initially
    int switchState = read_toggle_switch();

    if (switchState == 0 && lastSwitchState == 1) { // On toggle to LOW
        if (currentMode == STANDBY_MODE) {
            currentMode = LOW_DYNAMICS_MODE;
            set_sample_rate(SAMPLE_RATE_200HZ);
            printf("Switched to Low Dynamics Mode (200Hz)\n");
        } 
        else if (currentMode == LOW_DYNAMICS_MODE) {
            currentMode = HIGH_DYNAMICS_MODE;
            set_sample_rate(SAMPLE_RATE_700HZ);
            printf("Switched to High Dynamics Mode (700Hz)\n");
        } 
        else {
            currentMode = STANDBY_MODE;
            printf("Switched to Standby Mode\n");
        }
    }

    lastSwitchState = switchState;
}

void app_main() {
    init_pressure_sensor();
    init_toggle_switch();

    printf("Starting system in Standby Mode...\n");

    while (1) {
        update_mode();  // Check the toggle switch and update mode if necessary

        if (currentMode == STANDBY_MODE) {
            // No measurement in standby mode; add small delay
            vTaskDelay(500 / portTICK_PERIOD_MS);
        } 
        else {
            // Take and print pressure measurements in active modes
            float pressure = get_pressure();
            printf("Pressure: %.2f Pa\n", pressure);

            // Delay based on current sample rate
            vTaskDelay(get_sample_interval() / portTICK_PERIOD_MS);
        }
    }
}
