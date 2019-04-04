#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was

    int number;
    std::cout << "Write your number" << std::endl;
    std::cin >> number;

    //első sor
    for (int i = 1; i <= number ; ++i) {
        std::cout << "*";
    }
    std::cout << std::endl;

    //közepe
    for (int j = 1; j <= number-2 ; ++j) {
        std::cout << "*";
        for (int k = 0; k < j; ++k) {
            if (k == 0) {
                continue;
            } else {
                std::cout << " ";

        }
        }
        std::cout << "*";
        for (int l = number-j-2; l >=0  ; --l) {
            if (l == 0) {
                continue;
            } else {
                std::cout << " ";
            }

        }
        std::cout << "*" << std::endl;

    }

    //utolsó
    for (int i = 1; i <= number ; ++i) {
        std::cout << "*";
    }

    return 0;
}