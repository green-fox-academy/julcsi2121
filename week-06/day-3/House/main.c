#include <stdio.h>
#include <string.h>
#include "house.h"

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

int main()
{
    house house1 = create_house("Blaha Lujza tér 2.", 1000, 2, 50);
    print_info(house1);

    house house2 = create_house("Rózsadomb 41.", 3000000, 5, 200);
    print_info(house2);

    house house3 = create_house("Népszínház utca 2.", 5000, 3, 100);
    print_info(house3);

    printf("%d\n", is_it_worth(&house1));
    printf("%d\n", is_it_worth(&house2));
    printf("%d\n", is_it_worth(&house3));

    house* list_of_houses[3] = {&house1, &house2, &house3};
    int size = sizeof(list_of_houses) / sizeof(house*);

    printf("%d\n", count_worthy_houses(list_of_houses, size));

    house list_of_houses_not_pointer[3] = {house1, house2, house3};
    int size2 = sizeof(list_of_houses_not_pointer) / sizeof(house);

    printf("%d\n", count_worthy_houses_not_pointer(list_of_houses_not_pointer, size2));

    return 0;
}