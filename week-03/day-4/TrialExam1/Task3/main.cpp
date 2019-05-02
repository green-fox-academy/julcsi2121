#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"
#include "AnimalShelter.h"


int main() {
    srand(time(NULL));

    Cat cat1(NOT_HEALTHY, "Cirmi");
    Cat cat2(NOT_HEALTHY, "Kormi");
    Cat cat3(NOT_HEALTHY, "Bandi");
    Dog dog1(NOT_HEALTHY, "Bodri");
    Parrot parrot1(NOT_HEALTHY, "Lori");

    AnimalShelter shelter;
    shelter.rescue(&cat1);
    shelter.rescue(&cat2);
    shelter.rescue(&cat3);
    shelter.rescue(&dog1);
    shelter.rescue(&parrot1);
    shelter.toString();

    shelter.addAdopter("John");
    shelter.addAdopter("Mary");

    shelter.earnDonation(20);
    //shelter.heal();
    shelter.toString();

    shelter.findNewOwner();
    shelter.toString();
    shelter.showAdoptations();



    return 0;
}