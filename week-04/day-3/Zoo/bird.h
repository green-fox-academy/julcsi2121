//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H


#include "animal.h"

class Bird : public Animal{
public:
    Bird(std::string name);
    std::string getName() override;
    std::string breed() override;
    std::string coveredBy() override;
    std::string getBloodType() override;

};


#endif //ZOO_BIRD_H
