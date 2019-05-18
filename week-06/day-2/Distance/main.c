#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

int find_first(char* string);
int find_last(char* string);
int distance(char* string);

int main ()
{
    char str[] = "This is a sample string";

    printf("%d\n", find_first(str));
    printf("%d\n", find_last(str));
    printf("%d\n", distance(str));

    return 0;
}

int distance(char* string)
{
    return find_last(string) - find_first(string);
}

int find_first(char* string)
{
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == 's') {
            return i;
        }
    }
}

int find_last(char* string)
{
    for (int i = strlen(string)-1; i > 0; --i) {
        if (string[i] == 's') {
            return i;
        }
    }
}