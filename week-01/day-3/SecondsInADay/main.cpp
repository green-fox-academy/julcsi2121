#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables
    int secondsInADay = 24 * 60 * 60;
    int secondsPassed = currentHours * 60 * 60 + currentMinutes * 60 + currentSeconds;
    int remainingSeconds = secondsInADay - secondsPassed;
    std::cout << "Remaining seconds: " << remainingSeconds << std::endl;

    return 0;
}