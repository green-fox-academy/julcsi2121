//
// Created by Varga Júlia on 2019-05-15.
//

#ifndef CARREGISTER_CAR_H
#define CARREGISTER_CAR_H

#include <string.h>
#include <stdio.h>


/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

typedef enum {
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMIAUTOMATIC,
    DUALCLUTCH
}transmission_t;

const char* get_transmission_type(transmission_t transmission);

typedef struct
{
    char* manufacturer[256];
    float price;
    int year;
    transmission_t transmission;
}car_t;

car_t create_car(char* manufacturer, float price, int year, transmission_t transmission);
void print_info(car_t car);
int get_older_cars(car_t* car[], int length, int age);
int get_transmission_count (car_t* car[], int length, transmission_t trnsm);

#endif //CARREGISTER_CAR_H
