#include <stdio.h>
#include <string.h>

int count_lines(char* path);

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int main ()
{
    printf("Number of lines: %d\n", count_lines("../my-file.txt"));

    return 0;
}

int count_lines(char* path)
{
    FILE* fileptr = fopen("../my-file.txt", "r");

    if (fileptr == NULL) {
        return 0;
    }

    char buffer;
    int counter = 0;

    while (buffer != EOF) {
        buffer = fgetc(fileptr);

        if (buffer == '\n') {
            counter++;
        }
    }

    fclose(fileptr);
    return counter + 1;

}