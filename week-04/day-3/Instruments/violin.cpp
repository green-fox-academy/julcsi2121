//
// Created by Varga Júlia on 2019-04-24.
//

#include "violin.h"

Violin::Violin() {
    _numberOfStrings = 4;
    _name = "Violin";
}

Violin::Violin(int numberOfStrings) {
    _numberOfStrings = numberOfStrings;
    _name = "Violin";
}

std::string Violin::sound() {
    return "Screech";
}