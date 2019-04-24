//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H

#include <iostream>
#include <string>


class Vehicle {
public:
    virtual void printColor() = 0;
    virtual void printPropellerLength() = 0;
    virtual void printIdentity() = 0;
protected:
    std::string _color;
    int _propellerLength;
};


#endif //FLYABLE_VEHICLE_H
