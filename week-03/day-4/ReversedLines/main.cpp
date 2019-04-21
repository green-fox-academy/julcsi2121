#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Create a program that decrypts the file called "reversed-lines.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream myFile;
    myFile.open("../reversed-lines.txt");
    std::string line;

    while (getline(myFile, line)) {
        for (int i = 0; i < line.length() / 2; ++i) {
            std::swap(line[i], line[line.length()-1-i]);
        }
        std::cout << line << std::endl;
    }

    return 0;
}