#include <stdio.h>
#include <string.h>

typedef struct sandwich {
    char name[30];
    float price;
    float weight;
} sandwich;

float getPrice(sandwich sandwich1, int amount);

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

int main()
{
    sandwich sandwich1;
    strcpy(sandwich1.name, "blabla");
    sandwich1.price = 2.50;
    sandwich1.weight = 1.3;
    
    printf("Price of your order: %.2f\n", getPrice(sandwich1, 3));
    return 0;
}

float getPrice(sandwich sandwich1, int amount)
{
    return sandwich1.price * amount;
}