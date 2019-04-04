#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
    int aj[5] = {3, 4, 5, 6, 7};
    for (int i = 0; i < (sizeof(aj) / sizeof(aj[0])/2); ++i) {
        int temp1 = aj[i];
        int temp2 = aj[sizeof(aj) / sizeof(aj[0])-1-i];
        aj[i] = temp2;
        aj[sizeof(aj) / sizeof(aj[0])-1-i] = temp1;
        std::cout << temp2 <<std::endl;
        //aj[i] = temp2;
        //aj[sizeof(aj) / sizeof(aj[0])-1-i] = temp1;
    }

    std::cout << "Reversed list: " << std::endl;
    for (int j = 0; j < (sizeof(aj) / sizeof(aj[0])); ++j) {
        std::cout << aj[j] << std::endl;
    }

    return 0;
}