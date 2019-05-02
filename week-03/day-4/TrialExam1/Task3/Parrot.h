//
// Created by Varga Júlia on 2019-05-02.
//

#ifndef TASK3_PARROT_H
#define TASK3_PARROT_H

#include "Animal.h"

class Parrot : public Animal {
public:
    Parrot(Healthy healthy);
    Parrot(Healthy healthy, std::string animalName);

    void setHealingCost() override;
};


#endif //TASK3_PARROT_H
