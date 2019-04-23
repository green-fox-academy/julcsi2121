//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GARDENAPPLICATION_GARDEN_H
#define GARDENAPPLICATION_GARDEN_H


#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"

class Garden {
public:
    void addPlant(Plant* plant);
    void printPlantInfo();
    int countThirsty();
    void watering(int amount);
private:
    std::vector<Plant*> _myGarden;
};


#endif //GARDENAPPLICATION_GARDEN_H
