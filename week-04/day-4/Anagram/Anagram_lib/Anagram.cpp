//
// Created by Varga Júlia on 2019-04-25.
//

#include "Anagram.h"

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