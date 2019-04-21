#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Create a program that decrypts the file called "duplicated-chars.txt",
    // and pritns the decrypred text to the terminal window.
    std::ifstream  myFile;
    myFile.open("../duplicated-chars.txt");
    std::string line;

    while (getline(myFile, line)) {
        for (int i = 0; i < line.length(); ++i) {
            if (i % 2 == 0) {
                std::cout << line[i];
            }
        }
        std::cout << std::endl;
    }
    myFile.close();

    return 0;
}