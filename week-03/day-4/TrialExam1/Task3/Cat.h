//
// Created by Varga Júlia on 2019-05-02.
//

#ifndef TASK3_CAT_H
#define TASK3_CAT_H

#include "Animal.h"


class Cat : public Animal {
public:
    Cat(Healthy healthy);
    Cat(Healthy healthy, std::string animalName);

    void setHealingCost() override;
};


#endif //TASK3_CAT_H
