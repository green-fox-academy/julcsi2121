//
// Created by Varga Júlia on 2019-04-17.
//

#ifndef PETROLSTATION_STATION_H
#define PETROLSTATION_STATION_H

#include "Car.h"
#include <string>
#include <iostream>


class Station {
public:
    Station(int gasAmount);
    void fill(Car& car);

private:
    int gasAmount;
};


#endif //PETROLSTATION_STATION_H
