#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"


int main() {
    srand(time(NULL));

    Cat cat1(HEALTHY);
    cat1.toString();

    Cat cat2(NOT_HEALTHY, "Kormi");
    cat2.toString();

    Cat cat3(NOT_HEALTHY);
    cat3.toString();
    cat3.heal();
    cat3.toString();

    Dog dog1(NOT_HEALTHY, "Bodri");
    dog1.toString();

    Parrot parrot1(NOT_HEALTHY, "Lori");
    parrot1.toString();

    return 0;
}