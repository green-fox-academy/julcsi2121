//
// Created by Varga Júlia on 2019-04-24.
//

#include "bird.h"

Bird::Bird(std::string name, int age) {
    _name = name;
    _age = age;
    _legNumber = 2;
    _bloodType = WARM;
}

void Bird::takeOff() {
    std::cout << "Bird is taking off" << std::endl;
}

void Bird::fly() {
    std::cout << "Bird is flying" << std::endl;
}

void Bird::land() {
    std::cout << "Bird is landing" << std::endl;
}

std::string Bird::getBloodType() {
    return "Birds are warm-blooded animals.";
}

std::string Bird::getName() {
    return "Your choosen bird is: " + _name;
}

std::string Bird::coveredBy() {
    return "Birds are covered by feathers.";
}

std::string Bird::breed() {
    return "Birds are breeding by laying down eggs.";
}

void Bird::printAnimalRelatedInfo() {
    std::cout << getName() << ", here is a few info about birds:\n\t - " << breed() << "\n\t - " << coveredBy() << "\n\t - " << getBloodType() << std::endl;
}