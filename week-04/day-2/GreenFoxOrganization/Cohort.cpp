//
// Created by Varga Júlia on 2019-04-23.
//

#include "Cohort.h"

Cohort::Cohort(std::string name) {
    _name = name;
}

void Cohort::addStudent(Student* student) {
    _studentList.push_back(student);
}

void Cohort::printStudentList() {
    for (int i = 0; i < _studentList.size(); ++i) {
        _studentList.at(i)->introduce();
    }
}

void Cohort::addMentor(Mentor* mentor){
    _mentorList.push_back(mentor);
}

void Cohort::printMentorList() {
    for (int i = 0; i < _mentorList.size(); ++i) {
        _mentorList.at(i)->introduce();
    }
}

void Cohort::info() {
    std::cout << "The " << getName() << " cohort has " << _studentList.size() << " students and " << _mentorList.size() << " mentors." << std::endl;
}

std::string Cohort::getName() const {
    return _name;
}
