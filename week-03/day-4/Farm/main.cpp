#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main() {
    Animal zsiraf;
    Animal beka;
    zsiraf.eat();
    beka.play();
    zsiraf.printValues();
    beka.printValues();


    Farm allatkert;
    allatkert.addAnimal(zsiraf);
    allatkert.addAnimal(beka);
    allatkert.printSlots();

    allatkert.breed(zsiraf);
    allatkert.printSlots();

    allatkert.slaughter();
    allatkert.printSlots();

    allatkert.getAnimal(1)->printValues();
    allatkert.getAnimal(1)->play();
    allatkert.getAnimal(1)->printValues();


    return 0;
}