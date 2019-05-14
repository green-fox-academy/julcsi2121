#include <stdio.h>
#include <stdlib.h>

int is_even(int number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int number;
    printf("Give me a number\n");
    scanf("%d", &number);

    if(is_even(number)) {
        printf("Your number is even");
    } else {
        printf("Your number is odd");
    }

    return 0;
}

int is_even(int number)
{
    if (number % 2 == 1) {
        return 0;
    }
    return 1;
}