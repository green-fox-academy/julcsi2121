//
// Created by Varga Júlia on 2019-04-18.
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <iostream>
#include <ctime>


class Pirate {
public:
    Pirate();
    void drinkSomeRum();
    void howsItGoingMate();
    void die();
    void brawl(Pirate& pirate);
    int getRumLevels();
    bool isSleep();
    bool isAlive();
    void printStats();

    void setRumLevels(int rumLevels);

    void setSleep(bool sleep);

    void setAlive(bool alive);

private:
    int rumLevels;
    bool sleep;
    bool alive;
};


#endif //PIRATES_PIRATE_H
