#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it
    int km;
    std::cout << "Write a distance in kilometers" << std::endl;
    std::cin >> km;
    float kmToMile = km * 0.62137f;
    std::cout << "Your distance equals to " << kmToMile << " miles." << std::endl;

    return 0;
}