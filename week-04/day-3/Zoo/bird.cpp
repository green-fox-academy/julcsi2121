//
// Created by Varga Júlia on 2019-04-24.
//

#include "bird.h"

Bird::Bird(std::string name) {
    _name = name;
    _age = 2;
    _legNumber = 2;
    _bloodType = WARM;
}

std::string Bird::getName() {
    return _name;
}

std::string Bird::breed() {
    return  "laying eggs";
}

std::string Bird::coveredBy() {
    return " is covered by scales";
}

std::string Bird::getBloodType() {
    if(_bloodType == WARM) {
        return " is warm-blooded";
    } else {
        return " is cold-blooded";
    }
}
