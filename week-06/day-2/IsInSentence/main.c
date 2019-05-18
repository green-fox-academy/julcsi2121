#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_sentence(char* word, char* sentence);

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "apple";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 1
    printf("%d\n", is_in_sentence(word, sentence));

    return 0;
}

int is_in_sentence(char* word, char* sentence)
{
    if (strcasestr(sentence, word) != NULL) {
        return 1;
    }
    return 0;
}