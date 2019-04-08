#include <iostream>

void swap(int *pointerofA, int *pointerofB, int a, int b);

int main ()
{
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;
    int *pointerOfA = &a;
    int *pointerOfB = &b;
    std::cout << "originally a is: " << *pointerOfA << " and b is " << *pointerOfB <<std::endl;
    swap(pointerOfA, pointerOfB, a, b);

    return 0;
}

void swap(int *pointerOfA, int *pointerOfB, int a, int b)
{
    pointerOfA = &b;
    pointerOfB = &a;
    std::cout << "now a is: " << *pointerOfA << " and b is " << *pointerOfB <<std::endl;
}