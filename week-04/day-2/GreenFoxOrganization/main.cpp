#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Mentor.h"

int main() {
    //Person jane;
    Person mark("Mark", 28, MALE);
    //jane.introduce();
    //jane.getGoal();
    mark.introduce();
    //Student jane;
    //jane.skipDays(5);
    //jane.introduce();
    Student david("David", 22, MALE, "Elte");
    david.skipDays(2);
    david.introduce();
    david.getGoal();
    Mentor jane;
    jane.getGoal();
    jane.introduce();
    Mentor john("John", 33, MALE, SENIOR);
    john.introduce();


    return 0;
}