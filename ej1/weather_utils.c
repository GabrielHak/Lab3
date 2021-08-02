#include <stdio.h>
#include <stdlib.h>

#include "weather_utils.h"
#include "array_helpers.h"

int min_temp_his(WeatherTable w){

    int min = w[0][0][0]._min_temp;

    for(int i = 0; i < YEARS; i++){
        for(int j = 0; j < MONTHS; j++){
            for(int k = 0; k < DAYS; k++){
                if(w[i][j][k]._min_temp < min){
                    min = w[i][j][k]._min_temp;
                }
            }
        }
    }

    return min;
}

void max_temp_anual(WeatherTable w, int t[YEARS]){

    for(int i = 0; i < YEARS; i++){
        
        t[i] = w[i][0][0]._max_temp;
        
        for(int j = 0; j < MONTHS; j++){
            for(int k = 0; k < DAYS; k++){
                if(w[i][j][k]._max_temp > t[i]){
                    t[i] = w[i][j][k]._max_temp;
                }
            }
        }
    }
}

void max_month_rain(WeatherTable w, t_month m[YEARS]){
    
    for(int i = 0; i < YEARS; i++){
        unsigned int max_rain = w[i][0][0]._rainfall;
        for(int j = 0; j < MONTHS; j++){
            for(int k = 0; k < DAYS; k++){
                if(w[i][j][k]._rainfall > max_rain){
                    max_rain = w[i][j][k]._rainfall;
                    m[i] = j;
                }
            }
        }
    }
}