
#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%%
    // %    %
    // %    %
    // %    %
    // %    %
    // %%%%%%
    //
    // The square should have as many lines as the number was
    int number;
    std::cout << "Give me a number" << std::endl;
    std::cin >> number;
    for (int i = 0; i < number; ++i) {
        std::cout << "%";
    }
    std::cout << std::endl;

    for (int j = 0; j < number - 2; ++j) {
        std::cout << "%";
        for (int i = 0; i < number - 2; ++i) {
            std::cout << " ";
        }
        std::cout << "%" << std::endl;
    }

    for (int i = 0; i < number; ++i) {
        std::cout << "%";
    }
    std::cout << std::endl;

    return 0;
}