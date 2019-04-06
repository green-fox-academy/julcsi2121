#include <iostream>

bool palindromeDecider(std::string substring, int size);
void substringFinder(std::string, int size);



int main() {
    std::string example;
    std::cout << "Write your string" << std::endl;
    std::getline(std::cin, example);
    int size = example.length();
    substringFinder(example, size);
    return 0;
}

bool palindromeDecider(std::string substring, int size)
{
    bool isItPalindrome = true;
    for (int m = 0; m < size / 2; m++) {
        if (substring[m] != substring[size - m - 1]) {
            isItPalindrome = false;
        }
    }
    return isItPalindrome;
}

void substringFinder(std::string example, int size) {
    std::string palindromeSubStrings;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            std::string subString;
            for (int k = i; k <= j; ++k) {
                subString += example[k];
            }
            int subStringLength = subString.length();
            if (subStringLength >= 3 ) {
                if (palindromeDecider(subString, subStringLength) == 1) {
                    palindromeSubStrings += subString;
                    palindromeSubStrings += ", ";
                }
            }

        }

    }
    std::cout << palindromeSubStrings << std::endl;

}