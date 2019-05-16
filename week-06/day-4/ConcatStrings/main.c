#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* concatenate_strings(char* string1, char* string2);

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

int main()
{
    char * result = concatenate_strings("macs", "ka");
    printf("%s\n", result);

    char * result2 = concatenate_strings("nagyonnagyonhosszú", "stringkndsknskfnakgnrkvnydfkvndkvnbdyvbndykvnfivnaivndfvndk");
    printf("%s\n", result2);
    return 0;
}

char* concatenate_strings(char* string1, char* string2)
{
    int size1 = strlen(string1);
    int size2 = strlen(string2);

    char* result = NULL;
    result = (char*)calloc(size1 + size2, sizeof(char));

    for (int i = 0; i < size1; ++i) {
        result[i] = string1[i];
    }

    for (int i = 0; i < size2; ++i) {
        result[size1 + i] = string2[i];
    }

    return result;

}