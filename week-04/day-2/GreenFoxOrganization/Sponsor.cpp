//
// Created by Varga Júlia on 2019-04-23.
//

#include "Sponsor.h"

Sponsor::Sponsor() : Person() {
    _company = "Google";
    _hiredStudents = 0;
}

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) : Person(name, age, gender) {
    _company = company;
    _hiredStudents = 0;
}

std::string Sponsor::getCompany() const {
    return _company;
}

void Sponsor::setCompany(std::string company) {
    _company = company;
}

int Sponsor::getHiredStudents() const {
    return _hiredStudents;
}

void Sponsor::setHiredStudents(int hiredStudents) {
    _hiredStudents = hiredStudents;
}

void Sponsor::introduce() {
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " <<  translateGender(getGender()) << " who represents " << getCompany() << " and hired " << getHiredStudents() << " students so far." << std::endl;
}

void Sponsor::setGoal() {
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}

void Sponsor::hire() {
    _hiredStudents++;
}
