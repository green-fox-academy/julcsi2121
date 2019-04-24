//
// Created by Varga Júlia on 2019-04-24.
//

#include "reptile.h"

Reptile::Reptile(std::string name) {
    _name = name;
    _age = 10;
    _legNumber = 4;
    _bloodType = COLD;
}

std::string Reptile::getName() {
    return _name;
}

std::string Reptile::breed() {
    return  "laying eggs";
}

std::string Reptile::coveredBy() {
    return " is covered by scales";
}

std::string Reptile::getBloodType() {
    if(_bloodType == WARM) {
        return " is warm-blooded";
    } else {
        return " is cold-blooded";
    }
}
