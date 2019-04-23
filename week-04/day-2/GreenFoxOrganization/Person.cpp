//
// Created by Varga Júlia on 2019-04-23.
//

#include "Person.h"

Person::Person() {
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

Person::Person(std::string name, int age, Gender gender) {
    _name = name;
    _age = age;
    _gender = gender;
}

std::string Person::getName() const {
    return _name;
}

void Person::setName(std::string name) {
    _name = name;
}

int Person::getAge() const {
    return _age;
}

void Person::setAge(int age) {
    _age = age;
}

Gender Person::getGender() const {
    return _gender;
}

void Person::setGender(Gender gender) {
    _gender = gender;
}

std::string Person::translateGender(Gender gender) {
    switch (_gender) {
        case MALE:
            return "male";
        case FEMALE:
            return "female";
    }
}

void Person::introduce() {
    std::cout << "Hi, I'm " << getName() << ", a " <<  getAge() << " year old " << translateGender(getGender()) << std::endl;
}

void Person::getGoal() {
    std::cout << "My goal is: Live for the moment!" << std::endl;
}