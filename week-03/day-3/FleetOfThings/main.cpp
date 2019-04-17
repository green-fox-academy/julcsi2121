#include <iostream>

#include "fleet.h"

int main(int argc, char* args[])
{
    Thing task3("Stand up");
    task3.complete();
    Thing task4("Eat lunch");
    task4.complete();
    Fleet fleet;
    fleet.add(Thing ("Get milk"));
    fleet.add(Thing ("Remove the obstacles"));
    fleet.add(task3);
    fleet.add(task4);


    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    //std::cout << task1.toString() << std::endl;
    std::cout << fleet.toString() << std::endl;
    return 0;
}