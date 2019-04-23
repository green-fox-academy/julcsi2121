//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_MENTOR_H
#define GREENFOXORGANIZATION_MENTOR_H


#include "Person.h"
#include <iostream>
#include <string>

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : private Person {
public:
    Mentor();
    Mentor(std::string name, int age, Gender gender, Level level);

    Level getLevel() const;
    void setLevel(Level level);

    void getGoal();
    void introduce();
    std::string translateLevel(Level level);

private:
    Level _level;
};


#endif //GREENFOXORGANIZATION_MENTOR_H
