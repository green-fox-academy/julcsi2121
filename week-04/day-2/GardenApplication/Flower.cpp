//
// Created by Varga Júlia on 2019-04-23.
//

#include "Flower.h"

Flower::Flower(std::string color) : Plant(color) {
    _absorptionRate = 0.75;
    setType("Flower");
}

Flower::Flower(std::string color, int waterAmount) : Plant(color, waterAmount){
    _absorptionRate = 0.75;
    setType("Flower");
}

std::string Flower::needsWater() {
    if (getCurrentWaterAmount() < 5) {
        return " needs water.";
    }
    return " doesn't need water.";
}

void Flower::info() {
    std::cout << "The " << getColor() << " " << getType() << needsWater() << std::endl;
}