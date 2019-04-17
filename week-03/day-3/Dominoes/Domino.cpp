//
// Created by Varga Júlia on 2019-04-17.
//

#include "Domino.h"


Domino::Domino(int valueA, int valueB)
{
    _values = std::make_pair(valueA, valueB);
}

std::pair<int,int> Domino::getValues()
{
    return _values;
}

std::string Domino::toString()
{
    return "[" + std::to_string(_values.first) + ", " + std::to_string(_values.second) + "]";
}
