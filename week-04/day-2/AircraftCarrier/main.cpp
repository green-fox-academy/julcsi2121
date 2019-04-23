#include <iostream>
#include "Aircraft.h"

int main() {
    Aircraft air(20, 10, 5);
    air.getStatus();
    //std::cout << "Left: " << air.refill(40) << std::endl;
    int left = air.refill(8);
    std::cout << "Left: " << left << std::endl;
    air.getStatus();

    std::cout << "Damage dealt: " << air.fight() << std::endl;
    return 0;
}