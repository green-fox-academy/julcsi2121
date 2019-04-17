//
// Created by Varga Júlia on 2019-04-17.
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

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


#endif //ANIMAL_ANIMAL_H
