#include <iostream>
#include "Pirate.h"

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

    return 0;
}