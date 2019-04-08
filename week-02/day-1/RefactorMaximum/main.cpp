#include <iostream>

void askForSize(int &size);
void askForElements(int numbers[], int size);
void findMaximum (int numbers[], int size);

int main()
{
    // Refactor time!
    // use your 'refactor_maximum.cpp', solve the same exercise by creating a separate function
    // for each functionality

    int size = 0;
    askForSize(size);
    int numbers[size];
    askForElements(numbers, size);
    findMaximum(numbers, size);

    return 0;
}

void askForSize(int &size)
{
    std::cout << "Give me the length of you array." << std::endl;
    std::cin >> size;
}
void askForElements(int numbers[], int size)
{
    std::cout << "Now give me the elements one by one" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i+1 << ". elementh: ";
        std::cin >> numbers[i];
    }
}

void findMaximum (int numbers[], int size)
{
    int *pointer = numbers;
    for (int i = 0; i < size; ++i) {
        if (*pointer < numbers[i]) {
            pointer = &numbers[i];    //ekvivalens, ha *pointer = numbers[i] ?
            //*pointer = numbers[i];
        }
    }
    std::cout << "The maximum is: " << *pointer << " with memory address of " << pointer << std::endl;
}