#include <stdio.h>

// print out the characters that corresponds to these ascii values

int main()
{
    int array[] = { 103, 114, 101, 101, 110, 32, 102, 111, 120};

    int size = sizeof(array) / sizeof(int);
    for (int i = 0; i < size; ++i) {
        printf("%c\n", array[i]);
    }

    return 0;
}