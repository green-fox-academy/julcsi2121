#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(int a, int b);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    int a;
    int b;

    printf("Give me your first number\n");
    scanf("%d", &a);

    printf("Give me your second number\n");
    scanf("%d", &b);

    if (sum_of_digits(a, b)) {
        printf("Sum of digits is equal");
    } else {
        printf("Sum of digits is not equal");
    }

    return 0;
}

int sum_of_digits(int a, int b)
{
    int sum_a;
    while (a > 0) {
        sum_a += a % 10;
        a /= 10;
    }

    int sum_b;
    while (b > 0) {
        sum_b += b % 10;
        b /= 10;
    }

    if (sum_a == sum_b) {
        return 1;
    }
    return 0;

}