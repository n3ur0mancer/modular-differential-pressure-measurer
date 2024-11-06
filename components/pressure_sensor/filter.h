#ifndef FILTER_H
#define FILTER_H

#define USE_MOVING_AVERAGE_FILTER
void init_filter();
float apply_moving_average_filter(float newValue);

#endif // FILTER_H
