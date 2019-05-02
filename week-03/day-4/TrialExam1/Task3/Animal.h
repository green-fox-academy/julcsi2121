//
// Created by Varga Júlia on 2019-05-02.
//

#ifndef TASK3_ANIMAL_H
#define TASK3_ANIMAL_H

#include <iostream>
#include <string>
#include <ctime>

enum Healthy {
    HEALTHY,
    NOT_HEALTHY
};


class Animal {
public:
    Animal(Healthy healthy);
    Animal(Healthy healthy, std::string animalName);

    int getHealCost() const;
    std::string getAnimalName() const;
    bool isAdoptable();

    virtual void setHealingCost() = 0;
    void heal();
    void toString();

protected:
    int _healCost;

private:
    std::string _animalName;
    std::string _ownerName;
    bool _isHealthy;
};


#endif //TASK3_ANIMAL_H
