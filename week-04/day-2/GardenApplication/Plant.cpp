//
// Created by Varga Júlia on 2019-04-23.
//

#include "Plant.h"

Plant::Plant(std::string color) {
    _color = color;
    _type = "unspecified plant";
    int _currentWateramount = 0;
}

Plant::Plant(std::string color, int currentWaterAmount) {
    _color = color;
    _type = "unspecified plant";
    _currentWaterAmount = currentWaterAmount;
}

std::string Plant::needsWater() {
    if (_currentWaterAmount < 2) {
        return " needs water.";
    }
    return " doesn't need water.";
}

void Plant::info(){
    std::cout << "The " << getColor() << " " << getType() << needsWater() << std::endl;
}

std::string Plant::getColor() const {
    return _color;
}

void Plant::setColor(std::string color) {
    _color = color;
}

std::string Plant::getType() const {
    return _type;
}

void Plant::setType(std::string type) {
    _type = type;
}

int Plant::getCurrentWaterAmount() const {
    return _currentWaterAmount;
}

void Plant::setCurrentWaterAmount(int currentWaterAmount) {
    _currentWaterAmount = currentWaterAmount;
}
