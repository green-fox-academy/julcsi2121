#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int number;
    std::cout << "Give me a number!" << std::endl;
    std::cin >> number;

    for (int i = 0; i < number / 2; ++i) {
        for (int j = number / 2; j > i; --j) {
            std::cout << " ";
        }
        for (int k = 0; k < (i * 2) + 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    if(number % 2 == 1) {
        for (int i = 0; i < number; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < number / 2; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << " ";
        }
        if(number % 2 == 0) {
            for (int k = number - 1; k > i * 2; --k) {
                std::cout << "*";
            }
        }else {
                for (int k = number - 2; k > i * 2; --k) {
                    std::cout << "*";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}