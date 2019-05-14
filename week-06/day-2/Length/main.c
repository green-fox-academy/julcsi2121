#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char name[]);
int alternative_length(char name[]);

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name[20];
    printf("Give me your name\n");
    scanf("%s", name);

    printf("%d\n", length(name));
    printf("%d\n", alternative_length(name));

    return 0;
}

int length(char name[])
{
    return strlen(name);
}

int alternative_length(char name[])
{
    int counter = 0;
    while (*name != '\0') {
        counter++;
        name++;
    }
    return counter;
}