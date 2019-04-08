#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;
    int *pointerOfA = &a;
    int *pointerOfB = &b;
    //b += *pointerOfA;
    int c = *pointerOfA + *pointerOfB;

    std::cout << "Value of a+b: " << c << std::endl;

    return 0;
}