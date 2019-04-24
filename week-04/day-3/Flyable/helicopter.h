//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H


#include "vehicle.h"
#include "flyable.h"

class Helicopter : public Vehicle, public Flyable{
public:
    Helicopter(std::string color, int propellerLength);
    void land() override;
    void fly() override;
    void takeOff() override;
    void printColor();
    void printPropellerLength();
    void printIdentity();
};


#endif //FLYABLE_HELICOPTER_H
