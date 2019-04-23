//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GARDENAPPLICATION_TREE_H
#define GARDENAPPLICATION_TREE_H

#include <iostream>
#include <string>
#include "Plant.h"


class Tree : public Plant{
public:
    Tree(std::string color);
    Tree(std::string color, int waterAmount);
    std::string needsWater() override;
    void info() override;
private:
    double _absorptionRate;
};


#endif //GARDENAPPLICATION_TREE_H
