//
// Created by Varga Júlia on 2019-05-15.
//

#ifndef HOUSE_HOUSE_H
#define HOUSE_HOUSE_H

#include <stdio.h>
#include <string.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct
{
    char address[100];
    float price;
    int no_of_rooms;
    float area;
}house;

house create_house(char* address, float price, int no_of_rooms, float area);
void print_info(house house);
int is_it_worth(house* house);

int count_worthy_houses(house* house[], int size);
int count_worthy_houses_not_pointer(house house[], int size);

#endif //HOUSE_HOUSE_H
