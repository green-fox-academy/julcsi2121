//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_STUDENT_H
#define GREENFOXORGANIZATION_STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"


class Student : public Person {
public:
    Student();
    Student(std::string name, int age, Gender gender, std::string previousOrganization);

    std::string getPreviousOrganization() const;
    void setPreviousOrganization(std::string previousOrganization);
    int getSkippedDays() const;
    void setSkippedDays(int skippedDays);

    void getGoal();
    void introduce();
    void skipDays(int numberOfDays);

private:
    std::string _previousOrganization;
    int _skippedDays;
};


#endif //GREENFOXORGANIZATION_STUDENT_H
