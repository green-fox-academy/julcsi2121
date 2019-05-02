//
// Created by Varga Júlia on 2019-05-02.
//

#include "AnimalShelter.h"

AnimalShelter::AnimalShelter() {
    _budget = 50;
}

int AnimalShelter::rescue(Animal *animal) {
    _animals.push_back(animal);
    return _animals.size();
}

void AnimalShelter::toString() {
    std::cout << "Budget: " << _budget << "€," << std::endl;
    std::cout << "There are " << _animals.size() << " animals, and " << _adopters.size() << " potential adopters." << std::endl;
    for (int i = 0; i < _animals.size(); ++i) {
        _animals.at(i)->toString();
    }
}

void AnimalShelter::addAdopter(std::string name) {
    _adopters.push_back(name);
}

int AnimalShelter::earnDonation(int amount) {
    _budget += amount;
    return _budget;
}

int AnimalShelter::heal() {
    for (int i = 0; i < _animals.size(); ++i) {
        if (_animals.at(i)->isAdoptable() == false && _animals.at(i)->getHealCost() <= _budget) {
            _animals.at(i)->heal();
            return 1;
        }
    }
    return 0;
}

void AnimalShelter::findNewOwner() {

    if (isThereAdoptable() == false) {
        std::cout << "There is no adoptable animal in the shelter!" << std::endl;
        return;
    }

    int indexOfRandomAnimal = findRadomAdoptableAnimal();
    int indexOfRandomAdopter = rand() % _adopters.size();

    _adoptations[_adopters.at(indexOfRandomAdopter)] = _animals.at(indexOfRandomAnimal);
    _adopters.erase(_adopters.begin() + indexOfRandomAdopter);
    _animals.erase(_animals.begin() + indexOfRandomAnimal);

}

int AnimalShelter::findRadomAdoptableAnimal()
{
    int i = rand() % _animals.size();

    while (_animals.at(i)->isAdoptable() == false) {
        i = rand() % _animals.size();
    }
    return i;
}

void AnimalShelter::showAdoptations() {
    std::cout << "Adoptations:" << std::endl;
    std::map<std::string, Animal*>::iterator it = _adoptations.begin();
    for (; it != _adoptations.end(); ++it) {
        std::cout << it->first << ": " << it->second->getAnimalName() << std::endl;
    }
}

bool AnimalShelter::isThereAdoptable() {
    for (int i = 0; i < _animals.size(); ++i) {
        if (_animals.at(i)->isAdoptable() == true) {
            return true;
        }
    }
    return false;
}