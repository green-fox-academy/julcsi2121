#include <iostream>

int main(int argc, char* args[]) {

    // Define several things as a variable then print their values
    // Your name as a string
    std::string myName = "Julcsi";
    std::cout << "My name is " << myName << " ." << std::endl;
    // Your age as an integer
    int myAge = 24;
    std::cout << "I am " << myAge << " years old." << std::endl;
    // Your height in meters as a double
    double myHeight = 1.63;
    std::cout << "I am " << myHeight << " meters tall." << std::endl;
    // Whether you are married or not as a boolean
    bool marriageStatus = false;
    std::cout << "Am I married? (1 means true, 0 means false) - " << marriageStatus << std::endl;

    return 0;
}