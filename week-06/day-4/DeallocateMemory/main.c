#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int* pointer = NULL;

    pointer = (int*)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        if (i == 0) {
            pointer[i] = 0;
        } else {
            pointer[i] = pointer[i - 1] + 2;
        }

        printf("%d\n", pointer[i]);
    }

    pointer = realloc(pointer, 0);

    return 0;
}