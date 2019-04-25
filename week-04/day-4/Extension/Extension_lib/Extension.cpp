//
// Created by Varga Júlia on 2019-04-25.
//

#include "Extension.h"

#include <iostream>
#include <algorithm>
#include <sstream>

int add(int a, int b)
{
    return a + b;
}

int maxOfThree(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (c > b && c > a)
        return c;
    else
        return b;
}

int median(const std::vector<int>& pool) {
    //std::sort(pool.begin(), pool.end());
    if (pool.size() % 2 == 0) {
        int element1 = pool.at(pool.size()/2 - 1);
        int element2 = pool.at(pool.size()/2);
        return ((element1 + element2) / 2);
    }
    return pool.at(pool.size()/2);
}

bool isVowel(char c) {
    static const std::vector<char> vowels = {'a', 'u', 'o', 'e', 'i', 'A', 'E', 'U', 'O', 'I'};
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

std::vector<std::string> split(const std::string& str, char delim)
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> v;
    while (std::getline(ss, token, delim)) {
        v.push_back(token);
    }

    return v;
}

std::string join(const std::string& separator, const std::vector<std::string>& array)
{
    std::stringstream ss;
    for(int i = 0; i < array.size(); ++i)
    {
        std::cout << separator << std::endl;
        ss << array[i];
        if(i != array.size() - 1)
        {
            ss << separator;
        }
    }

    return ss.str();
}

std::string translate(const std::string& hungarian)
{
    std::string teve = hungarian;
    int length = teve.size();
    for (int i = 0; i < length; i++) {
        const char c = teve.at(i);
        if (isVowel(c) == true && i == length - 1) {
            teve += "v" + std::string(1, c);
        }else if (isVowel(c)) {
            teve = join(std::string(1, c) + "v" + std::string(1, c), split(teve, c));
            i+=2;
            length+=2;
        }
    }
    return teve;
}