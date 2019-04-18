//
// Created by Varga Júlia on 2019-04-18.
//

#ifndef FARM_FARM_H
#define FARM_FARM_H

#include <iostream>
#include <vector>
#include "Animal.h"


class Farm {
public:
    void addAnimal(Animal& animal);
    void breed(Animal& animal);
    void slaughter();
    void printSlots();
    Animal* getAnimal(int i);

private:
    std::vector<Animal> farmMembers;
    int freeSlots = 5;
};


#endif //FARM_FARM_H
