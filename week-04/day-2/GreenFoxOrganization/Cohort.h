//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_COHORT_H
#define GREENFOXORGANIZATION_COHORT_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Mentor.h"


class Cohort {
public:
    Cohort(std::string name);
    std::string getName() const;

    void addStudent(Student* student);
    void addMentor(Mentor* mentor);
    void info();

    void printStudentList();
    void printMentorList();
private:
    std::string _name;
    std::vector<Student*> _studentList;
    std::vector<Mentor*> _mentorList;
};


#endif //GREENFOXORGANIZATION_COHORT_H
