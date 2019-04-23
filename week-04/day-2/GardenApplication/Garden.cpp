//
// Created by Varga Júlia on 2019-04-23.
//

#include "Garden.h"

void Garden::addPlant(Plant* plant){
    _myGarden.push_back(plant);
}

void Garden::printPlantInfo() {
    for (int i = 0; i < _myGarden.size(); ++i) {
        _myGarden.at(i)->info();
    }
}

int Garden::countThirsty() {
    int count = 0;
    for (int i = 0; i < _myGarden.size(); ++i) {
        if (_myGarden.at(i)->needsWater() == " needs water.") {
            count++;
        }
    }
    return count;
}

void Garden::watering(int amount) {
    int amountPerFlower = amount / countThirsty();
    std::cout << "Watering with " << amount << std::endl;
    for (int i = 0; i < _myGarden.size(); ++i) {
        _myGarden.at(i)->setCurrentWaterAmount(amountPerFlower);
        _myGarden.at(i)->info();
    }
}