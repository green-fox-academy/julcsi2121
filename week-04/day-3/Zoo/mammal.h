//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H


#include "animal.h"

class Mammal : public Animal {
public:
    Mammal(std::string name);
    std::string getName() override;
    std::string breed() override;
    std::string coveredBy() override;
    std::string getBloodType() override;

};


#endif //ZOO_MAMMAL_H
