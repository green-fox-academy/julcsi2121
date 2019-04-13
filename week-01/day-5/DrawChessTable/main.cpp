#include <iostream>

int main(int argc, char* args[]) {

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    int num;
    std::cout << "How many squares do you want in a row!"  << std::endl;
    std::cin >> num;

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if(i % 2 == 0) {
                if ( j % 2 == 0) {
                    std::cout << " ";
                } else {
                    std::cout << "%";
                }

            } else {
                if (j % 2 == 0) {
                    std::cout << "%";
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}