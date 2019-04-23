//
// Created by Varga Júlia on 2019-04-23.
//

#include "Mentor.h"

Mentor::Mentor() : Person() {
    _level = INTERMEDIATE;
}

Mentor::Mentor(std::string name, int age, Gender gender, Level level) : Person(name, age, gender) {
    _level = level;
}

Level Mentor::getLevel() const {
    return _level;
}

void Mentor::setLevel(Level level) {
    _level = level;
}

void Mentor::getGoal() {
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce() {
    //std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " <<  translateGender(getGender()) << " " << translateLevel(getLevel()) << " level mentor." << std::endl;
    Person::introduce();
    std::cout << " " << translateLevel(getLevel()) << " level mentor." << std::endl;
}

std::string Mentor::translateLevel(Level level) {
    switch (_level) {
        case JUNIOR:
            return "junior";
        case INTERMEDIATE:
            return "intermediate";
        case SENIOR:
            return "senior";
    }
}