//
// Created by Varga Júlia on 2019-04-25.
//

#include "Anagram.h"

#include <iostream>
#include <algorithm>

bool anagramItIs(std::string string1, std::string string2)
{
    int length1 = string1.length();
    int length2 = string2.length();

    if (length1 != length2) {
        return false;
    }

    if (string1 == "" || string2 == "") {
        return false;
    }

    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());

    for (int i = 0; i < length1; i++) {
        if (string1[i] != string2[i]) {
            return false;
        }
    }
    return true;
}