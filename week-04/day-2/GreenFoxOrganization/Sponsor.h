//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_SPONSOR_H
#define GREENFOXORGANIZATION_SPONSOR_H

#include <iostream>
#include <string>
#include "Person.h"


class Sponsor : public Person {
public:
    Sponsor();
    Sponsor(std::string name, int age, Gender gender, std::string company);

    std::string getCompany() const;
    void setCompany(std::string company);
    int getHiredStudents() const;
    void setHiredStudents(int hiredStudents);

    void introduce() override;
    void getGoal() override;
    void hire();

private:
    std::string _company;
    int _hiredStudents;
};


#endif //GREENFOXORGANIZATION_SPONSOR_H
