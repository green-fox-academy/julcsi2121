#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have
    int chickens;
    int pigs;
    std::cout << "Give me the number of chickens" << std::endl;
    std::cin >> chickens;
    std::cout << "Give me the number of pigs" << std::endl;
    std::cin >> pigs;
    std::cout << "Total leg number is: " << (chickens * 2) + (pigs * 4) << std::endl;

    return 0;
}