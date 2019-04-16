#include <iostream>
#include <fstream>

void divideWithTen(int number);

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0
    divideWithTen(0);

    return 0;
}

void divideWithTen(int number)
{
    try {
        if(number == 0) {
            throw std::string("fail");
        } else {
            std::cout << number / 10 << std::endl;
        }

    } catch (std::string& error) {
        std::cout << error << std::endl;
    }

}

// ha 2x dobok vmi custom stringet, honnan tudja, hogy mit kapjon el a fenti kifejezéssel?