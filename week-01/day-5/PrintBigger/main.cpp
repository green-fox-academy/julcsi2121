#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    int first;
    int second;
    std::cout << "Write your 1st number: ";
    std::cin >> first;
    std::cout << "Write your 2nd number: ";
    std::cin >> second;
    if(first > second) {
        std::cout << first << " is bigger" << std::endl;
    } else if (first < second) {
        std::cout << second << " is bigger" << std::endl;
    } else {
        std::cout << "They're equal!" << std::endl;
    }

    return 0;
}