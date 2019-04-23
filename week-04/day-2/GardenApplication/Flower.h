//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GARDENAPPLICATION_FLOWER_H
#define GARDENAPPLICATION_FLOWER_H

#include <iostream>
#include <string>
#include "Plant.h"


class Flower : public Plant{
public:
    Flower(std::string color);
    Flower(std::string color, int waterAmount);
    std::string needsWater() override;
    void info() override;
private:
    double _absorptionRate;
};


#endif //GARDENAPPLICATION_FLOWER_H
