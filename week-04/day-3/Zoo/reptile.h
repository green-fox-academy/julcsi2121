//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef ZOO_REPTILE_H
#define ZOO_REPTILE_H

#include "animal.h"

class Reptile : public Animal {
public:
    Reptile(std::string name);
    std::string getName() override;
    std::string breed() override;
    std::string coveredBy() override;
    std::string getBloodType() override;

};

#endif //ZOO_REPTILE_H
