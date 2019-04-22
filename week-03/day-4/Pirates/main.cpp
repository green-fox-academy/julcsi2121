#include <iostream>
#include "Pirate.h"
#include "Ship.h"

int main() {
    srand (time(NULL));
    Pirate EdwardKenway;
    Pirate templar;
    EdwardKenway.printStats();
    EdwardKenway.drinkSomeRum();
    EdwardKenway.howsItGoingMate();
    EdwardKenway.drinkSomeRum();
    EdwardKenway.drinkSomeRum();
    EdwardKenway.drinkSomeRum();
    EdwardKenway.drinkSomeRum();
    EdwardKenway.printStats();
    EdwardKenway.howsItGoingMate();
    EdwardKenway.brawl(templar);
    EdwardKenway.printStats();
    templar.printStats();

    Ship Jackdaw;
    Jackdaw.fillShip();
    Jackdaw.printEveryInfo();
    Jackdaw.printStandardInfo();

    return 0;
}