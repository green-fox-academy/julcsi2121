#include <string.h>
#include <stdio.h>

#include "car.h"

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

int main()
{
    car_t car1 = create_car("Volvo", 200000, 1994, MANUAL);
    car_t car2 = create_car("Suzuki", 10000, 1990, MANUAL);
    car_t car3 = create_car("Tesla", 3000000, 2017, AUTOMATIC);

    print_info(car1);

    car_t* list_of_cars[3] = {&car1, &car2, &car3};
    int size = sizeof(list_of_cars) / sizeof(car_t*);

    printf("%d", get_older_cars(list_of_cars, size, 2000));
    printf("%d", get_transmission_count(list_of_cars, size, MANUAL));

    return 0;
}