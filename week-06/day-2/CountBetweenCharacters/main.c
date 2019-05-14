#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char* word, char repeat);

main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";
    char repeat = 'g';

    printf("%s\n", word);


    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d\n", count_between_chars(word, repeat));

    return 0;
}

int count_between_chars(char* word, char repeat)
{
    int counter = 0;

    while (*word != repeat) {
        word++;
    }

    while (*word != '\0') {
        counter++;
        word++;
    }

    return counter - 2;


}