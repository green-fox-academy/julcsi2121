#include <iostream>

std::string reverseString(std::string example, int size);

int main() {
    std::cout << "Give me a string" << std::endl;
    std::string example;
    std::cin >> example;
    int size = example.length();
    std::string palindrom = reverseString(example, size);
    std::cout << example << palindrom << std::endl;
    return 0;
}

std::string reverseString(std::string example, int size)
{
    std::string palindrom;
    for (int i = 0; i < size; ++i) {
        palindrom += example[size-i-1];
    }
    return palindrom;

}