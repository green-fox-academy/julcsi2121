//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GARDENAPPLICATION_PLANT_H
#define GARDENAPPLICATION_PLANT_H

#include <iostream>
#include <string>


class Plant {
public:
    Plant(std::string color);
    Plant(std::string color, int currentWaterAmount);

    std::string getColor() const;
    void setColor(std::string color);
    std::string getType() const;
    void setType(std::string type);
    int getCurrentWaterAmount() const;
    void setCurrentWaterAmount(int currentWaterAmount);

    std::string needsWater();
    void info();
private:
    std::string _color;
    std::string _type;
    int _currentWaterAmount;
};


#endif //GARDENAPPLICATION_PLANT_H
