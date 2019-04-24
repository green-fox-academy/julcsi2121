//
// Created by Varga Júlia on 2019-04-24.
//

#include "helicopter.h"

Helicopter::Helicopter(std::string color, int propellerLength) {
    _color = color;
    _propellerLength = propellerLength;
}

void Helicopter::fly() {
    std::cout << "Helicopter is flying" << std::endl;
}

void Helicopter::land() {
    std::cout << "Helicopter is landing now" << std::endl;
}

void Helicopter::takeOff() {
    std::cout << "Helicopter is taking off" << std::endl;
}

void Helicopter::printColor() {
    std::cout << "Helicopter's color: " << _color << std::endl;
}

void Helicopter::printIdentity() {
    std::cout << "I'm a helicopter" << std::endl;
}

void Helicopter::printPropellerLength() {
    std::cout << "The length of my propeller is: " << _propellerLength << std::endl;
}