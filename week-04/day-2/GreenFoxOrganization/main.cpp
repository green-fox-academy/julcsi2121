#include <iostream>
#include "Person.h"

int main() {
    Person jane;
    Person mark("Mark", 28, MALE);
    jane.introduce();
    jane.getGoal();
    mark.introduce();
    return 0;
}