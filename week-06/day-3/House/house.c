//
// Created by Varga Júlia on 2019-05-15.
//

#include "house.h"

house create_house(char* address, float price, int no_of_rooms, float area)
{
    house result;

    strcpy(result.address, address);
    result.price = price;
    result.area = area;
    result.no_of_rooms = no_of_rooms;

    return result;
}

void print_info(house house)
{
    printf("The house is for sale at address %s has %d rooms, and area of %.2f squaremeters for %.2f dollars.\n", house.address, house.no_of_rooms, house.area, house.price);
}

int is_it_worth(house* house)
{
    if (house->price / house->area <= 400) {
        return 1;
    } else {
        return 0;
    }
}

int count_worthy_houses(house* house[], int size)
{
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        if (is_it_worth(house[i])){
            counter++;
        }
    }
    return counter;
}

int count_worthy_houses_not_pointer(house house[], int size)
{
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        if (is_it_worth(&house[i])){
            counter++;
        }
    }
    return counter;

}