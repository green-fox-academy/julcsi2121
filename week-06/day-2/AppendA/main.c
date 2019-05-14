#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* appendA(char string[], char result[]);

main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char string[20];
    char result[20];
    printf("Give me your string\n");
    scanf("%s", string);

    printf("%s\n", appendA(string, result));

    return 0;
}

char* appendA(char string[], char result[])
{
    strcpy(result, string);
    strcat(result, "a");
    return result;
}