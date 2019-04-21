#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // Create a program that decrypts the file called "reversed-order.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream myFile;
    myFile.open("../reversed-order.txt");
    std::vector<std::string> reversed;
    std::string line;

    while (getline(myFile, line)) {
        reversed.insert(reversed.begin(), line);
    }

    myFile.close();

    for (int i = 0; i < reversed.size(); ++i) {
        std::cout << reversed.at(i) << std::endl;
    }


    return 0;
}