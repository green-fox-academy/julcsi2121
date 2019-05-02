//
// Created by Varga Júlia on 2019-05-02.
//

#include "Dog.h"

Dog::Dog(Healthy healthy) : Animal(healthy) {
    setHealingCost();
}

Dog::Dog(Healthy healthy, std::string animalName) : Animal(healthy, animalName)
{
    setHealingCost();
}

void Dog::setHealingCost() {
    _healCost = rand() % 8 + 1;
}
