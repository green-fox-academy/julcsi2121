//
// Created by Varga Júlia on 2019-04-18.
//

#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H


#include <iostream>


class Animal {
public:
    Animal();
    int getHunger();
    void setHunger(int hunger);
    int getThirst();
    void setThirst(int thirst);
    void eat();
    void drink();
    void play();
    void printValues();

private:
    int hunger;
    int thirst;

};


#endif //FARM_ANIMAL_H
