#include <iostream>

void bubbleSort(std::string& string1);
bool anagram(std::string string1, std::string string2);

int main() {
    std::string string1;
    std::string string2;
    std::cout << "Write your 1st string" << std::endl;
    std::getline(std::cin, string1);
    std::cout << "Write your 2nd string" << std::endl;
    std::getline(std::cin, string2);
    bool value = anagram(string1, string2);
    if (value == true) {
        std::cout << "It's an anagram!" << std::endl;
    } else {
        std::cout << "It's not an anagram." << std::endl;
    }
    return 0;
}

void bubbleSort(std::string& string1)
{
    int size = string1.length();
    for (int l = 0; l < size; ++l) {
        for (int j = 0; j < size-1 ; ++j) {
            if (string1[j] > string1[j + 1]) {
                string1[j] = string1[j] - string1[j + 1];
                string1[j + 1] = string1[j] + string1[j + 1];
                string1[j] = string1[j + 1] - string1[j];
            }
        }
    }
}

bool anagram(std::string string1, std::string string2)
{
    bubbleSort(string1);
    bubbleSort(string2);
    for (int i = 0; i < string1.length()-1; ++i) {
        if(string1[i] != string2[i]) {
            return false;
        }
    }
    return true;
}