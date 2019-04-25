#include <iostream>
#include "CountLetters.h"

int main() {
    std::map<char, int> result;
    result = countLetters("Randomstring");
    std::map<char, int>::iterator it = result.begin();
    for (; it != result.end(); ++it) {
        std::cout << it->first << std::endl;
    }
    return 0;
}