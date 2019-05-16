#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat_string(char* string, int number);

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

int main()
{
    char* result = repeat_string("alma", 3);
    printf("%s\n", result);

    free(result);
    result = NULL;
    return 0;
}


char* repeat_string(char* string, int number)
{
    int size = strlen(string);

    char* result = NULL;
    result = (char*)calloc((size * number), sizeof(char));

    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < size; ++j) {
            //printf("%d\n", (i + j) + (i * number));
            result[(i + j) + (i * number)] = string[j];
        }
    }

    return result;

}