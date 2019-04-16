#include <iostream>
#include <fstream>
#include <string>

int countNoOfLines(std::string filename);

int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
    int numberOfLines = countNoOfLines("../my-file1.txt");
    std::cout << "Number of lines: " << numberOfLines << std::endl;

    return 0;
}

int countNoOfLines(std::string filename)
{
    std::ifstream kiscica;

    try {
        kiscica.open(filename);
        if (kiscica.is_open() == 0) {
            throw std::string("Opening failed");
        }
        std::string text;
        int count;

        while(std::getline(kiscica, text)) {
            count++;
        }
        kiscica.close();
        return count;

    } catch (std::string& e) {
        std::cerr << e << std::endl;
        return 0;
    }

}