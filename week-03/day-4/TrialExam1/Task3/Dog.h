//
// Created by Varga Júlia on 2019-05-02.
//

#ifndef TASK3_DOG_H
#define TASK3_DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    Dog(Healthy healthy);
    Dog(Healthy healthy, std::string animalName);

    void setHealingCost() override;
};


#endif //TASK3_DOG_H
