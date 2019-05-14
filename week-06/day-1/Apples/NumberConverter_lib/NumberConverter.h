//
// Created by Varga Júlia on 2019-04-25.
//

#ifndef APPLES_NUMBERCONVERTER_H
#define APPLES_NUMBERCONVERTER_H

#include <string>
#include <iostream>
#include <map>

/*
 * class:
 * map szám - string párok
 *
 * fgv: string -> szám
 * fgv: szám ->string
 *  szám konvertálás stringgé
 *  végigmennék a számon
 *
 *  kell a szám hossza
 *
 *  két infó: index, mi az értéke
 *      index - tizedesjegy
 *      szám - megadja, hogy mit kell behelyettesíteni a mapből
 *
 *  spec. eset: utolsó előtti számjegy
 *
 */

class NumberConverter {
public:
    NumberConverter();
    std::string numToText(int number);
private:
    std::map<char, std::string> _oneDigit;
    std::map<char, std::string> _toTwenty;
    std::map<char, std::string> _toHundred;
};


#endif //APPLES_NUMBERCONVERTER_H
