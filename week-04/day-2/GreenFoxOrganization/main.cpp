#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Mentor.h"
#include "Sponsor.h"
#include "Cohort.h"

int main() {
    std::vector<Person*> people;
    Person mark("Mark", 46, Gender::MALE);
    people.push_back(&mark);
    Person jane;
    people.push_back(&jane);
    Student john("John Doe", 20, Gender::MALE, "BME");
    people.push_back(&john);
    Student student;
    people.push_back(&student);
    Mentor gandhi("Gandhi", 148, Gender::MALE, Level::SENIOR);
    people.push_back(&gandhi);
    Mentor mentor;
    people.push_back(&mentor);
    Sponsor sponsor;
    people.push_back(&sponsor);
    Sponsor elon("Elon Musk", 46, Gender::MALE, "SpaceX");
    people.push_back(&elon);

    student.skipDays(3);

    for (int i = 0; i < 5; i++) {
        elon.hire();
    }

    for (int i = 0; i < 3; i++) {
        sponsor.hire();
    }

    for(Person* person : people) {
        person->introduce();
        person->getGoal();
    }

    Cohort awesome = Cohort("AWESOME");
    awesome.addStudent(&student);
    awesome.addStudent(&john);
    awesome.addMentor(&mentor);
    awesome.addMentor(&gandhi);
    awesome.info();

    /*   OWN TESTCODE
    Person mark("Mark", 28, MALE);
    mark.introduce();

    Student david("David", 22, MALE, "Elte");
    david.skipDays(2);
    david.introduce();
    david.getGoal();
    Student mary("Mary", 25, FEMALE, "Corvinus");

    Mentor john("John", 33, MALE, SENIOR);
    john.introduce();

    Sponsor jane;
    jane.getGoal();
    jane.hire();
    jane.introduce();
    Sponsor jenny("Jennifer", 43, FEMALE, "Facebook");
    jenny.introduce();

    Cohort students("stonedFox");
    students.addStudent(&david);
    students.addStudent(&mary);
    students.printStudentList();

    students.addMentor(&john);
    students.printMentorList();

    students.info();
     */


    return 0;
}