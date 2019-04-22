//
// Created by Varga Júlia on 2019-04-22.
//

#include "Ship.h"

void Ship::fillShip() {
    int random = rand() % 20 + 1;
    for (int i = 0; i < random; ++i) {
        if (i == 0) {
            Pirate captain;
            captain.setHasParrot(true);
            ship.push_back(captain);
        } else {
            ship.push_back(Pirate());
        }
    }
}

Pirate Ship::getPirate(int i) {
    return ship.at(i);
}

void Ship::printEveryInfo() {
    for (int i = 0; i < ship.size(); ++i) {
        Pirate actualPirate = getPirate(i);
        actualPirate.printStats();
    }
}

int Ship::count() {
    int counter;
    for (int i = 0; i < ship.size(); ++i) {
        if (getPirate(i).isAlive() == true) {
            counter++;
        }
    }
    return counter;
}

void Ship::printStandardInfo() {
    ship.at(0).printStats();
    std::cout << "Number of alive people: " << count() << std::endl;
}