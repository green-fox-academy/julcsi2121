#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int percentile(int n, int* array, size_t size);
int comparator (const int * a, const int * b);

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int main()
{
    const int rows = 2;
    const int columns = 3;
    int matrix[rows][columns] = {{3, 5, 1}, {4, 8, 6}};

    int* result = NULL;
    size_t size = sizeof(matrix)/ sizeof(int);
    result = (int*)calloc(size, sizeof(int));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[(i + j) + (i * rows)] = matrix[i][j];
        }
    }

    qsort(result, size, sizeof(int), comparator);

    for (int k = 0; k < size; ++k) {
        printf("%d\n", result[k]);
    }

    printf("Element you need: %d\n", percentile(80, result, size));
    

    return 0;
}

int percentile(int n, int* array, size_t size)
{
    float ordinal_rank = (float)n / 100 * size;
    //printf("%.2f\n", ordinal_rank);
    return array[(int)roundf(ordinal_rank)];

}

int comparator (const int * a, const int * b)
{
    int left = *a;
    int right = *b;

    if (left > right) {
        return 1;
    }
    return -1;
}