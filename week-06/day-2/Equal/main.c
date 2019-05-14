#include <stdio.h>
#include <stdlib.h>

int isEqual(int a, int b);

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise
    int a;
    int b;

    printf("Give me your first number\n");
    scanf("%d", &a);

    printf("Give me your second number\n");
    scanf("%d", &b);

    if (isEqual(a, b)) {
        printf("The two numbers are equal");
    } else {
        printf("The two numbers are not equal");
    }

    return 0;
}

int isEqual(int a, int b)
{
    if (a == b) {
        return 1;
    }
    return 0;
}