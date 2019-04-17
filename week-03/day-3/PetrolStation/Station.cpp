//
// Created by Varga Júlia on 2019-04-17.
//

#include "Station.h"

Station::Station(int gasAmount) {
    this->gasAmount = gasAmount;
}

void Station::fill(Car& car) {
    while (car.isFull() == false) {
        car.fill();
        this->gasAmount--;
        std::cout << "Filling car!" << std::endl;
    }
    std::cout << "Car is full now. Remaining gas amount: " << this->gasAmount << std::endl;
}
