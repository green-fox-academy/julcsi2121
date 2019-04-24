//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <iostream>
#include <string>

enum blooded {
    COLD,
    WARM
};


class Animal {
public:
    virtual std::string getName() = 0;
    virtual std::string breed() = 0;
    virtual std::string coveredBy() = 0;
    virtual std::string getBloodType() = 0;
protected:
    std::string _name;
    int _age;
    int _legNumber;
    blooded _bloodType;
};


#endif //ZOO_ANIMAL_H
