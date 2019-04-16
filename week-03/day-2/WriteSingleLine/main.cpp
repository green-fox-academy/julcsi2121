#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line
    try {
        std::ofstream myName;
        myName.open("../myName.txt");
        if (myName.is_open() == 0) {
            throw std::string("Error occured around file opening");
        }
        myName << "Júlia Varga \n";
        myName.close();
    } catch (std::string& e) {
        std::cerr << e << std::endl;
    }


    return 0;
}