//
// Created by Varga Júlia on 2019-04-24.
//

#include "bassGuitar.h"

BassGuitar::BassGuitar() {
    _numberOfStrings = 4;
    _name = "Bass guitar";
}

BassGuitar::BassGuitar(int numberOfStrings) {
    _numberOfStrings = numberOfStrings;
    _name = "Bass guitar";
}

std::string BassGuitar::sound() {
    return "Duum-duum-duum";
}