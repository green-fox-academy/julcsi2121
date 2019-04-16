#include <iostream>
#include <fstream>
#include <string>

bool copy(std::string fileIn, std::string fileOut);

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

int main() {

    bool success = copy("../input.txt", "../output.txt");
    if (success == true) {
        std::cout << "Copying was successful" << std::endl;
    } else {
        std::cout << "Error occured with file opening" << std::endl;
    }

    return 0;
}

bool copy(std::string fileIn, std::string fileOut)
{
    try {
        std::ifstream input;
        input.open(fileIn);

        if(input.is_open() == 0) {
            throw std::string("Can't open file");
        }

        std::ofstream output;
        output.open(fileOut);

        std::string temp;

        while (std::getline(input, temp)) {
            output << temp << "\n";
        }
        input.close();
        output.close();
    } catch (std::string& e) {
        return false;
    }
    return true;
}