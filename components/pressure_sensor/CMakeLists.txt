idf_component_register(SRCS "pressure_sensor.c" "adc.c" "filter.c"
                       INCLUDE_DIRS "."
                       REQUIRES driver esp_adc)
