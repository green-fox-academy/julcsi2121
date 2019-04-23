#include <iostream>
#include "Person.h"
#include "Student.h"

int main() {
    //Person jane;
    Person mark("Mark", 28, MALE);
    //jane.introduce();
    //jane.getGoal();
    mark.introduce();
    Student jane;
    jane.skipDays(5);
    jane.introduce();
    Student david("David", 22, MALE, "Elte");
    david.skipDays(2);
    david.introduce();
    david.getGoal();
    return 0;
}