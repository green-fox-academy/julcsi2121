//
// Created by Varga Júlia on 2019-04-22.
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H


#include <vector>
#include "Pirate.h"

class Ship {
public:
    void fillShip();
    Pirate getPirate(int i);
    int count();
    void printEveryInfo();
    void printStandardInfo();
private:
    std::vector<Pirate> ship;

};


#endif //PIRATES_SHIP_H
