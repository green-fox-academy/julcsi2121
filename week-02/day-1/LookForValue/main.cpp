#include <iostream>

int findValue (int numbers[], int size, int value);

int main()
{
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    int size;
    std::cout << "Give me the length of you array." << std::endl;
    std::cin >> size;
    int numbers[size];
    std::cout << "Now give me the elements one by one" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i+1 << ". elementh: ";
        std::cin >> numbers[i];
    }
    int value;
    std::cout << "Now give me the number you're looking for!" << std::endl;
    std::cin >> value;
    int i = findValue(numbers, size, value);
    std::cout << "Your index is: " << i << std::endl;

    return 0;
}

int findValue (int numbers[], int size, int value)
{
    int *pointer = numbers;
    for (int i = 0; i < size; ++i) {
        pointer = &numbers[i];
        std::cout << "I'm pointing to " << *pointer << std::endl;
        if (*pointer == value) {
            std::cout << "I've found a match!" << std::endl;
            return i;
        }
    }
    std::cout << "I've found nothing :(" << std::endl;
    return -1;
}