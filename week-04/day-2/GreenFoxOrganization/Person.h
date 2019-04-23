//
// Created by Varga Júlia on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_PERSON_H
#define GREENFOXORGANIZATION_PERSON_H

#include <iostream>
#include <string>

enum Gender {
    MALE,
    FEMALE
};


class Person {
public:
    Person();
    Person(std::string name, int age, Gender gender);
    std::string getName() const;
    void setName(std::string name);
    int getAge() const;
    void setAge(int age);
    Gender getGender() const;
    void setGender(Gender gender);
    std::string translateGender(Gender gender);
    void introduce();
    void getGoal();

private:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GREENFOXORGANIZATION_PERSON_H
