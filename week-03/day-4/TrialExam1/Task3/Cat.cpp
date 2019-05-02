//
// Created by Varga Júlia on 2019-05-02.
//

#include "Cat.h"

Cat::Cat(Healthy healthy) : Animal(healthy) {
    setHealingCost();
}

Cat::Cat(Healthy healthy, std::string animalName) : Animal(healthy, animalName)
{
    setHealingCost();
}

void Cat::setHealingCost() {
    _healCost = rand() % 6 + 1;
}
