//
// Created by Varga Júlia on 2019-04-23.
//

#include "Student.h"

Student::Student() : Person(){
    _previousOrganization = "The school of life";
    _skippedDays = 0;
}

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) : Person(name, age, gender){
    _previousOrganization = previousOrganization;
    _skippedDays = 0;
}

std::string Student::getPreviousOrganization() const {
    return _previousOrganization;
}

void Student::setPreviousOrganization(std::string previousOrganization) {
    _previousOrganization = previousOrganization;
}

int Student::getSkippedDays() const {
    return _skippedDays;
}

void Student::setSkippedDays(int skippedDays) {
    _skippedDays = skippedDays;
}

void Student::getGoal() {
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::introduce() {
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " <<  translateGender(getGender()) << " from " << getPreviousOrganization() << " who skipped " << getSkippedDays() << " days from the course already." << std::endl;
}

void Student::skipDays(int numberOfDays) {
    _skippedDays += numberOfDays;
}