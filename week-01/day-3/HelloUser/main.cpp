#include <iostream>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string UsersName;
    std::cout << "What's your name?" << std::endl;
    std::cin >> UsersName;
    std::cout << "Hello " << UsersName << "!" << std::endl;

    return 0;
}