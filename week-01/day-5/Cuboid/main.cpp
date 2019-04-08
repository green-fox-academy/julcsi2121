#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    double a = 3;
    double b = 5;
    double c = 8;
    double volume = a * b * c;
    double surface = (a * b * 2) + (a * c * 2) + (b * c * 2);
    std::cout << "The volume is: " << volume << " and the surface is: " << surface << std::endl;

    return 0;
}