//
// Created by Varga Júlia on 2019-04-17.
//

#include "Animal.h"

Animal::Animal(){
    this->hunger = 50;
    this->thirst = 50;
}

int Animal::getHunger() {
    return hunger;
}

void Animal::setHunger(int hunger) {
    Animal::hunger = hunger;
}

int Animal::getThirst() {
    return thirst;
}

void Animal::setThirst(int thirst) {
    Animal::thirst = thirst;
}

void Animal::eat() {
    this->hunger -= 1;

}
void Animal::drink() {
    this->thirst -= 1;

}
void Animal::play() {
    this->hunger += 1;
    this->thirst += 1;
}

void Animal::printValues() {
    std::cout << "Hunger: " << getHunger() << ", Thirst: " << getThirst() << std::endl;
}
