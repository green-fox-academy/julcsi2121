//
// Created by Varga Júlia on 2019-04-23.
//

#include "Tree.h"

Tree::Tree(std::string color) : Plant(color) {
    _absorptionRate = 0.4;
    setType("Tree");
}

Tree::Tree(std::string color, int waterAmount) : Plant(color, waterAmount){
    _absorptionRate = 0.4;
    setType("Tree");
}

std::string Tree::needsWater() {
    if (getCurrentWaterAmount() < 10) {
        return " needs water.";
    }
    return " doesn't need water.";
}

void Tree::info() {
    std::cout << "The " << getColor() << " " << getType() << needsWater() << std::endl;
}
