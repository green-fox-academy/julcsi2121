#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was
    int number;
    int i = 1;
    std::cout << "Write your number please" << std::endl;
    std::cin >> number;

    while(i <= number) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
        i++;
    }

    return 0;
}
