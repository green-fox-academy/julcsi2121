#include <stdio.h>
#include <stdlib.h>

int is_prime(int number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int number;
    printf("Give me a number\n");
    scanf("%d", &number);

    if (is_prime(number)) {
        printf("You have a prime number");
    } else {
        printf("You don't have a prime number");
    }

    return 0;
}

int is_prime(int number)
{
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;

}