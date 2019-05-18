#include <stdio.h>
#include <string.h>

void split_to_words(char string[]);

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];

    gets(string);
    split_to_words(string);

    return(0);
}

void split_to_words(char string[])
{
    char* word = strtok(string, " ");

    while (word != '\0'){
        puts(word);
        word = strtok(NULL, " ");
    }
}