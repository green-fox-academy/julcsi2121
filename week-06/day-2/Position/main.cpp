#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void position(char* string);

int main ()
{
	char string[55] = "This is a string for testing";
	position(string);
	
	return 0;
}

void position(char* string)
{
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == 'i') {
            printf("%d\n", i);
        }
    }
}