#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE* fileptr = fopen("../my-file.txt", "w");
    fputs("Varga Júlia", fileptr);
    fclose(fileptr);

    return 0;
}