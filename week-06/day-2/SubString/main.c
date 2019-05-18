#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_substring(char* big_string, char* little_string);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    char big_string[20];
    char short_string[20];

    printf("%s\n", "Type in the long string!");
    scanf("%s", big_string);

    printf("%s\n", "Type in the short string!");
    scanf("%s", short_string);

    printf("%d\n", is_substring(big_string, short_string));

    return 0;
}

int is_substring(char* big_string, char* little_string)
{
    if (strlen(big_string) == strlen(little_string)) {
        return -1;
    }

    if (strstr(big_string, little_string) != NULL) {
        return 1;
    }
    return 0;
}