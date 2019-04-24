//
// Created by Varga Júlia on 2019-04-24.
//

#include "mammal.h"

Mammal::Mammal(std::string name) {
    _name = name;
    _age = 20;
    _legNumber = 4;
    _bloodType = WARM;
}

std::string Mammal::getName() {
    return _name;
}

std::string Mammal::breed() {
    return  "pushing miniature versions out";
}

std::string Mammal::coveredBy() {
    return " is covered by hair";
}

std::string Mammal::getBloodType() {
    if(_bloodType == WARM) {
        return "is warm-blooded";
    } else {
        return "is cold-blooded";
    }
}