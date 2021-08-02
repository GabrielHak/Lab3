#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

int min_temp_his(WeatherTable w);

void max_temp_anual(WeatherTable w, int t[YEARS]);

void max_month_rain(WeatherTable w, t_month m[YEARS]);

#endif