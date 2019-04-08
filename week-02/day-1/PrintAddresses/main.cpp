#include <iostream>

void askForElements(int numbers[], int size);
void printByPointer(int numbers[], int size);

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again
    int numbers[5];
    askForElements(numbers, 5);
    printByPointer(numbers, 5);

    return 0;
}


void askForElements(int numbers[], int size)
{
    std::cout << "Now give me the elements one by one. You can write 5 numbers total." << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i+1 << ". elementh: ";
        std::cin >> numbers[i];
    }
}

void printByPointer(int numbers[], int size)
{
    int *pointer = numbers;
    std::cout << "Printed by pointer: " << std::endl;
    for (int i = 0; i < size; ++i) {
        pointer = &numbers[i];
        std::cout << *pointer << std::endl;
    }
}