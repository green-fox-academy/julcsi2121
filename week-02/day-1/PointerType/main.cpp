#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";
    int *pointerOfA = &a;
    double *pointerOfB = &b;
    std::string *pointerOfName = &name;
    std::cout << "This is the address of a: " << &a << std::endl;
    std::cout << "This is the value of pointer of a: " << pointerOfA << std::endl;
    std::cout << "This is the address of b: " << &b << std::endl;
    std::cout << "This is the value of pointer of b: " << pointerOfA << std::endl;
    std::cout << "This is the address of name: " << &name << std::endl;
    std::cout << "This is the value of pointer of name: " << pointerOfA << std::endl;

    return 0;
}