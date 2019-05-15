#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE* fileptr = fopen("../my-file.txt", "r");

    char buffer[30];

    while (fgets(buffer, 30, fileptr) != NULL)
    {
        printf("%s", buffer);
    }


    return 0;
}