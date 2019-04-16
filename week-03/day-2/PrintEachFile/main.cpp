#include <iostream>
#include <fstream>
#include <string>

int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory
    std::ifstream kiscica;
    kiscica.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        kiscica.open("../my-file.txt");
        std::string text;
        while(getline(kiscica, text)) {
            std::cout << text << std::endl;
        }
        kiscica.close();
    } catch (std::ifstream::failure& e) {
        std::cerr << e.what() << std::endl;
    }

//hogy működik az itteni exception? ifstream::failure megtalálja a kiscica.exceptionbe beleírt hibákat?

    return 0;
}