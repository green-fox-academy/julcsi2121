#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_char(char string[], char c);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char string[20];
    char c;

    printf("Give me your string\n");
    scanf("%s", string);

    printf("Give me a character to find\n");
    scanf(" %c", &c);

    printf("%d\n", find_char(string, c));

    return 0;
}

int find_char(char string[], char c)
{
    int counter = 0;

    while (*string != '\0') {
        if (*string == c) {
            return counter;
        }

        string++;
        counter++;
    }
    return -1;

}