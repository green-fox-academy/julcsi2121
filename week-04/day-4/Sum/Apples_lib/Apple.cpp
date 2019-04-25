//
// Created by Varga Júlia on 2019-04-25.
//

#include "Apple.h"

std::string getApple()
{
    return "Apple";
}

int sum(std::vector<int> numbers)
{
    int sum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers.at(i);
    }
    return sum;
}