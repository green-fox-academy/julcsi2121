//
// Created by Varga Júlia on 2019-05-15.
//

#include "car.h"

const char* get_transmission_type(transmission_t transmission)
{
    switch (transmission)
    {
        case MANUAL: return "manual";
        case AUTOMATIC: return "automatic";
        case CVT: return "CVT";
        case SEMIAUTOMATIC: return "semi-automatic";
        case DUALCLUTCH: return "dual-clutch";
    }
}

car_t create_car(char* manufacturer, float price, int year, transmission_t transmission)
{
    car_t result;
    strcpy(result.manufacturer, manufacturer);
    result.price = price;
    result.year = year;
    result.transmission = transmission;
    return result;
}

void print_info(car_t car)
{
    printf("- Car's manufacturer: %s\n -Year of production: %d\n -Transmission type: %s\n -Price: %.2f\n", car.manufacturer, car.year, get_transmission_type(car.transmission), car.price);
}

int get_older_cars(car_t* car[], int length, int age)
{
    int counter = 0;

    for (int i = 0; i < length; ++i) {
        if (car[i]->year < age) {
            counter++;
        }
    }

    return counter;
}

int get_transmission_count (car_t* car[], int length, transmission_t trnsm)
{
    int counter = 0;

    for (int i = 0; i < length; ++i) {
        if (car[i]->transmission == trnsm) {
            counter++;
        }
    }

    return counter;
}