#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was
    int number;
    std::cout << "Give me a number!" << std::endl;
    std::cin >> number;

    for (int i = 0; i < number; ++i) {
        for (int j = number - 1; j > i ; --j) {
            std::cout << " ";
        }
        for (int k = 0; k < (i * 2) + 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    return 0;
}