#include <iostream>

int *findMinimum (int numbers[], int size);

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int *result = findMinimum(numbers, size);
    std::cout << *result << std::endl;

    return 0;
}

int *findMinimum (int numbers[], int size)
{
    int *pointer = numbers;
    for (int i = 0; i < size; ++i) {
        if (*pointer >= numbers[i]) {
            pointer = &numbers[i];    //ekvivalens, ha *pointer = numbers[i]
        }
    }
    return pointer;
}