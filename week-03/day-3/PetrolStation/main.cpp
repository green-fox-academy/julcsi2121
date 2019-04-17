#include <iostream>
#include "Station.h"
#include <vector>

int main() {
    Car merci(30, 50);
    Car beemve(0, 100);
    Car rollsroyce(80, 90);
    Car trabant(10, 20);
    Car motor(50, 70);
    Station mol(500);
    mol.fill(merci);
    mol.fill(beemve);
    mol.fill(rollsroyce);
    mol.fill(trabant);
    mol.fill(motor);
    return 0;
}