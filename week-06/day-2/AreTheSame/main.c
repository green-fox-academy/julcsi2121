#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int are_the_same(char string1[], char string2[]);

main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.
    char string1[20];
    char string2[20];

    puts("Give me your first string");
    gets(string1);
    puts("Give me your second string");
    gets(string2);

    if (are_the_same(string1, string2)) {
        printf("The two strings are equal");
    } else {
        printf("The two strings are not equal");
    }

    return 0;
}

int are_the_same(char string1[], char string2[])
{
    if (strcasecmp(string1, string2) == 0) {
        return 1;
    }
    return 0;
}