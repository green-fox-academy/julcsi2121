//
// Created by Varga Júlia on 2019-04-18.
//

#include "Pirate.h"


Pirate::Pirate(){
    rumLevels = 1;
    alive = true;
    sleep = false;
}

void Pirate::drinkSomeRum() {
    if (alive) {
        rumLevels++;
    } else {
        std::cout << "Pirate is dead!" << std::endl;
    }
}

void Pirate::howsItGoingMate() {
    if (rumLevels < 4 && alive) {
        std::cout << "Pour me anudder" << std::endl;
    } else if(rumLevels >= 4 && alive){
        sleep = true;
    } else {
        std::cout << "Pirate is dead!" << std::endl;
    }

}

void Pirate::die() {
    alive = false;
}

int Pirate::getRumLevels() {
    return rumLevels;
}

bool Pirate::isSleep() {
    return sleep;
}

bool Pirate::isAlive() {
    return alive;
}

void Pirate::brawl(Pirate& pirate) {
    int random = rand() % 3;

    if(this->alive && pirate.isAlive() == true) {
        if (random == 1) {
            setAlive(false);
            std::cout << "Your pirate is dead now!" << std::endl;
        } else if (random == 2) {
            pirate.setAlive(false);
            std::cout << "The other pirate is dead now!" << std::endl;
        } else {
            setSleep(true);
            pirate.setSleep(true);
            std::cout << "Both fell asleep!" << std::endl;
        }
    } else {
        std::cout << "At least one of the pirates is already dead!" << std::endl;
    }
}

void Pirate::printStats() {
    std::cout << "Your pirate's stats: " << std::endl;
    std::cout << "\t - Rum levels: " << getRumLevels() << std::endl;
    std::cout << "\t - Sleep status: " << isSleep() << std::endl;
    std::cout << "\t - Alive: " << isAlive() << std::endl;
}

void Pirate::setRumLevels(int rumLevels) {
    Pirate::rumLevels = rumLevels;
}

void Pirate::setSleep(bool sleep) {
    Pirate::sleep = sleep;
}

void Pirate::setAlive(bool alive) {
    Pirate::alive = alive;
}
