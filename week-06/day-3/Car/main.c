#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

char* get_car_type(enum car_type type);
void print_stats(struct car car);

int main()
{
    struct car car1;
    car1.type = VOLVO;
    car1.gas = 2.4;
    car1.km = 20000;

    struct car car2;
    car2.type = TESLA;
    car2.km = 300;

    print_stats(car1);
    print_stats(car2);

    return 0;
}

char* get_car_type(enum car_type type)
{
    switch (type)
    {
        case VOLVO: return  "Volvo";
        case TOYOTA: return "Toyota";
        case LAND_ROVER: return "Land Rover";
        case TESLA: return "Tesla";
    }
}

void print_stats(struct car car){
    if (car.type == TESLA) {
        printf("You have a %s with %.1f kilometers in it.\n", get_car_type(car.type), car.km);
    } else {
        printf("You have a %s with %.1f kilometers and %.1f gas in it.\n", get_car_type(car.type), car.km, car.gas);
    }
}