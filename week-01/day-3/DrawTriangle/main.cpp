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
    int i = 0;
    std::cout << "Write your number please" << std::endl;
    std::cin >> number;

    // two counters: i and j. i counts lines, j counts number of *-s
    // In order to execute both loops, i should be always +1 bigger than j.

    while(i != number) {
        i++;
        for (int j = 0; j != i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
