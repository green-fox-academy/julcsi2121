//
// Created by Varga Júlia on 2019-04-24.
//

#include "electricGuitar.h"

ElectricGuitar::ElectricGuitar() {
    _numberOfStrings = 6;
    _name = "Electric guitar";
}

ElectricGuitar::ElectricGuitar(int numberOfStrings) {
    _numberOfStrings = numberOfStrings;
    _name = "Electric guitar";
}

std::string ElectricGuitar::sound() {
    return "Twang";
}