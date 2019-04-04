#include <iostream>
#include <string>

void factorio(int& uselessInput, int usefulInput);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    int uselessInput = 4;
    factorio(uselessInput, 4);
    std::cout << "Yey, useless input is now: " << uselessInput << std::endl;

    return 0;
}

void factorio(int& uselessInput, int usefulInput)
{
    uselessInput = 1;
    for (int i = 1; i <= usefulInput; ++i) {
         uselessInput *= i;
    }
}