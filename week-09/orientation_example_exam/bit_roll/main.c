#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert_file(char* path);
char convert_binary_to_char(char *binary_seq);

/*
Your task is to create an application that converts "binary code" to readable text.

The "binary code" that you need to convert is a series of "bytes" (8 characters that are either 1 or 0) separated by spaces. This can be interpreted as the ASCII code of a character.

Your task is the following:

Implement a function that takes a binary number as a parameter and returns the character identified by the corresponding ASCII code.
Implement a function that takes a file name as a parameter, reads and converts the code in the file and returns the result of the conversion.
The code you need to convert can be found here: input.txt.
 */

int main() {
    char* result = convert_file("../input.txt");
    printf("%s", result);
    free(result);
    result = NULL;
    return 0;
}

char* convert_file(char* path)
{
    FILE* my_file = fopen(path, "r");
    char buffer[100];
    size_t string_size = 1;
    char *result = (char*)calloc(string_size, sizeof(char));

    if (my_file == NULL) {
        printf("%s\n", "unable to open file");
    }

    while (fgets(buffer, 100, my_file) != NULL) {
        char *binary = strtok(buffer, " ");

        while (binary != NULL) {
            char c = convert_binary_to_char(binary);
            string_size++;
            result = (char*)realloc(result, string_size);
            result[string_size - 2] = c;
            result[string_size - 1] = '\0';
            //strcat miért nem működik?

            binary = strtok(NULL, " ");
        }
    }

    fclose(my_file);
    return result;
}

char convert_binary_to_char(char *binary_seq)
{
    char *data_temp = binary_seq;
    char c = strtol(data_temp, 0, 2);
    //printf("%c", c);
    return c;

}