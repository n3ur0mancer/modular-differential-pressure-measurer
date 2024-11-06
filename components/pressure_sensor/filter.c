#include "filter.h"

#define FILTER_WINDOW_SIZE 10

static float pressureBuffer[FILTER_WINDOW_SIZE] = {0};
static int bufferIndex = 0;

void init_filter() {
    for (int i = 0; i < FILTER_WINDOW_SIZE; i++) {
        pressureBuffer[i] = 0;
    }
    bufferIndex = 0;
}

float apply_moving_average_filter(float newValue) {
    pressureBuffer[bufferIndex] = newValue;
    bufferIndex = (bufferIndex + 1) % FILTER_WINDOW_SIZE;

    float sum = 0;
    for (int i = 0; i < FILTER_WINDOW_SIZE; i++) {
        sum += pressureBuffer[i];
    }
    return sum / FILTER_WINDOW_SIZE;
}
