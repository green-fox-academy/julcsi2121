//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef FLYABLE_BIRD_H
#define FLYABLE_BIRD_H


#include "animal.h"
#include "flyable.h"

class Bird : public Animal, public Flyable{
public:
    Bird(std::string name, int age);
    void land() override;
    void fly() override;
    void takeOff() override;
    std::string getName() override;
    std::string breed() override;
    std::string coveredBy() override;
    std::string getBloodType() override;
    void printAnimalRelatedInfo();
};


#endif //FLYABLE_BIRD_H
