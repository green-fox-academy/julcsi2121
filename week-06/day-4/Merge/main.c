#include <stdio.h>
#include <stdlib.h>

int comparator (const void * a, const void * b);

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{

    int* pointer = NULL;
    int size = 10;

    printf("List1: \n");
    pointer = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < 10; ++i) {
        if (i == 0) {
            pointer[i] = 0;
        } else {
            pointer[i] = pointer[i - 1] + 2;
        }
        printf("%d\n", pointer[i]);
    }

    printf("List2: \n");
    int* pointer2 = NULL;
    pointer2 = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < 10; ++i) {
        if (i == 0) {
            pointer2[i] = 1;
        } else {
            pointer2[i] = pointer2[i - 1] + 2;
        }
        printf("%d\n", pointer2[i]);
    }

    pointer = (int*)realloc(pointer, 2 * size * sizeof(int));

    for (int j = 0; j < size; ++j) {
        pointer[size + j] = pointer2[j];
    }

    qsort(pointer, 20, sizeof(int), comparator);

    printf("Merged list1: \n");
    for (int j = 0; j < size * 2; ++j) {
        printf("%d\n", pointer[j]);
    }

    free(pointer);
    free(pointer2);

    return 0;
}

int comparator (const void * a, const void * b)
{
    int left = *(const int*)a;
    int right = *(const int*)b;

    if (left < right) {
        return 1;
    }
    return -1;
}