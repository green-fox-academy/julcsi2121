//
// Created by Varga Júlia on 2019-05-02.
//

#include "Parrot.h"

Parrot::Parrot(Healthy healthy) : Animal(healthy) {
    setHealingCost();
}

Parrot::Parrot(Healthy healthy, std::string animalName) : Animal(healthy, animalName)
{
    setHealingCost();
}

void Parrot::setHealingCost() {
    _healCost = rand() % 7 + 4;
}
