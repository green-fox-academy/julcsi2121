#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    std::cout << "An average Green Fox attende codes " << 6 * 5 * 17 << " hours in a semester." << std::endl;
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52
    std::cout << "If the amount of weekly working hours is 52, then this is " << (52. * 17.) / (7.*24.*17.) * 100 << " % of the whole semester ." << std::endl;

    return 0;
}