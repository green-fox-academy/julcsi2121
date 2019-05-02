//
// Created by Varga Júlia on 2019-05-02.
//

#ifndef TASK3_ANIMALSHELTER_H
#define TASK3_ANIMALSHELTER_H

#include "Animal.h"
#include <vector>
#include <map>


class AnimalShelter {
public:
    AnimalShelter();
    int rescue(Animal* animal);
    int heal();
    void addAdopter(std::string name);
    void findNewOwner();
    int earnDonation(int amount);
    void toString();
    void showAdoptations();

private:
    int _budget;
    std::vector<std::string> _adopters;
    std::vector<Animal*> _animals;
    std::map<std::string, Animal*> _adoptations;
    int findRadomAdoptableAnimal();
    bool isThereAdoptable();
};


#endif //TASK3_ANIMALSHELTER_H
