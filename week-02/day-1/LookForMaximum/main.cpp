#include <iostream>

void findMaximum (int numbers[], int size);

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int size;
    std::cout << "Give me the length of you array." << std::endl;
    std::cin >> size;
    int numbers[size];
    std::cout << "Now give me the elements one by one" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i+1 << ". elementh: ";
        std::cin >> numbers[i];
    }
    findMaximum(numbers, size);

    return 0;
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