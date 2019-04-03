#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5

    int firstNum;
    int secondNum;

    std::cout << "Write your 1st number" << std::endl;
    std::cin >> firstNum;
    std::cout << "Write your 2nd number" << std::endl;
    std::cin >> secondNum;

    if (secondNum < firstNum) {
        std::cout << "The second number should be bigger" << std::endl;
    } else {
        while ( firstNum != secondNum ) {
            std::cout << firstNum << std::endl;
            firstNum ++;
        }
    }
    return 0;
}