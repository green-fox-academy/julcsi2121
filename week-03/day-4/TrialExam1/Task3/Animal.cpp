//
// Created by Varga Júlia on 2019-05-02.
//

#include "Animal.h"

Animal::Animal(Healthy healthy) {
    if (healthy == HEALTHY) {
        _isHealthy = true;
    } else {
        _isHealthy = false;
    }
    _animalName = "Animal";
}

Animal::Animal(Healthy healthy, std::string animalName) {
    if (healthy == HEALTHY) {
        _isHealthy = true;
    } else {
        _isHealthy = false;
    }
    _animalName = animalName;
}

void Animal::heal() {
    _isHealthy = true;
}

bool Animal::isAdoptable() {
    return _isHealthy;
}

void Animal::toString() {
    if(isAdoptable()) {
        std::cout << getAnimalName() << " is healthy and adoptable." << std::endl;
    } else {
        std::cout << getAnimalName() << " is not healthy (" << getHealCost() << "€) and not adoptable." << std::endl;
    }
}

std::string Animal::getAnimalName() const {
    return _animalName;
}

int Animal::getHealCost() const {
    return _healCost;
}
