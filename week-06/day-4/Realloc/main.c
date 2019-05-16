#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* pointer = NULL;
    int x;
    int sum;

    printf("Please give me a number. This will be the length of your first list.\n");
    scanf("%d", &x);
    pointer = (int*)calloc(x, sizeof(int));

    printf("Now give me the elements of this list one by one\n");
    for (int i = 0; i < x; ++i) {
        printf("Elementh %i:", i + 1);
        scanf("%d", &pointer[i]);
        sum += pointer[i];
    }
    printf("Sum is: %d\n", sum);

    int* pointer2 = NULL;
    pointer2 = (int*)calloc(sum, sizeof(int));

    for (int k = 0; k < sum; ++k) {
        pointer2[k] = k;
    }

    printf("Final list: \n");
    for (int j = 0; j < sum; ++j) {
        printf("%d\n", pointer2[j]);

    }

    return 0;
}