//
// Created by Varga Júlia on 2019-04-18.
//

#include "Farm.h"

void Farm::addAnimal(Animal& animal) {
    farmMembers.push_back(animal);
}

void Farm::printSlots() {
    for (int i = 0; i < farmMembers.size(); ++i) {
        std::cout << "there is an animal" << std::endl;
    }
    for (int j = 0; j < freeSlots; ++j) {
        std::cout << "empty" << std::endl;
    }
}

void Farm::breed(Animal& animal) {
    if(freeSlots > 0) {
        farmMembers.push_back(animal);
        freeSlots--;
    } else{
        std::cout << "No slot for animal!" << std::endl;
    }
}

Animal* Farm::getAnimal(int i) {
    return &farmMembers[i];
}

void Farm::slaughter() {
    Animal hungriest = *getAnimal(0);
    for (int i = 0; i < farmMembers.size(); ++i) {
        if (hungriest.getHunger() < getAnimal(i)->getHunger()) {
            hungriest = *getAnimal(i);
        }
    }
    for (int j = 0; j < farmMembers.size(); ++j) {
        if (hungriest.getHunger() == getAnimal(j)->getHunger()) {
            farmMembers.erase(farmMembers.begin() + j);
            freeSlots++;
        }
    }
}