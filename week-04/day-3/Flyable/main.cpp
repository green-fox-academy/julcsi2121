#include <iostream>
#include "helicopter.h"
#include "bird.h"

int main() {
    Helicopter helicopter("red", 2);
    helicopter.takeOff();
    helicopter.fly();
    helicopter.land();

    Bird sas("sas", 5);
    sas.printAnimalRelatedInfo();
    sas.takeOff();
    sas.fly();
    sas.land();
    return 0;
}