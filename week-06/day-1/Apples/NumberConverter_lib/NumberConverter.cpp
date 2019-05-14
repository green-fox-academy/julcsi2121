//
// Created by Varga Júlia on 2019-04-25.
//

#include "NumberConverter.h"

NumberConverter::NumberConverter()
{
    _oneDigit['0'] = "";
    _oneDigit['1'] = "one";
    _oneDigit['2'] = "two";
    _oneDigit['3'] = "three";
    _oneDigit['4'] = "four";
    _oneDigit['5'] = "five";
    _oneDigit['6'] = "six";
    _oneDigit['7'] = "seven";
    _oneDigit['8'] = "eight";
    _oneDigit['9'] = "nine";

    _toTwenty['0'] = "ten";
    _toTwenty['1'] = "eleven";
    _toTwenty['2'] = "twelve";
    _toTwenty['3'] = "thirteen";
    _toTwenty['4'] = "fourteen";
    _toTwenty['5'] = "fifteen";
    _toTwenty['6'] = "sixteen";
    _toTwenty['7'] = "seventeen";
    _toTwenty['8'] = "eighteen";
    _toTwenty['9'] = "nineteen";

    _toHundred['0'] = "";
    _toHundred['2'] = "twenty";
    _toHundred['3'] = "thirty";
    _toHundred['4'] = "fourty";
    _toHundred['5'] = "fifty";
    _toHundred['6'] = "sixty";
    _toHundred['7'] = "seventy";
    _toHundred['8'] = "eighty";
    _toHundred['9'] = "ninety";
}

std::string NumberConverter::numToText(int number)
{
    std::string numToString = std::to_string(number);

    std::string result = "";
    std::string actualNumber = "";
    int size = numToString.size();

    for (int i = numToString.size()-1; i >= 0; --i) {

        actualNumber = _oneDigit[numToString[i]];

        if (numToString[i] == '1' && i == numToString.size() - 2) {
            actualNumber = _toTwenty[numToString[i]];
            result.clear();
        } else if (i == numToString.size() - 2) {
            actualNumber = _toHundred[numToString[i]];
        }

        result.insert(0, actualNumber + " ");

    }
    return result;
}