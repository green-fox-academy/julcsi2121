#include <iostream>
#include <vector>
#include "Scanner.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Copier.h"

int main() {
    Printer3D printer1(2, 4, 6);
    Printer3D printer2(4, 7, 8);
    Copier copier(4, 2, 8);
    copier.copy();
    Printer2D printer3(3, 7);
    Printer2D printer4(7, 1);
    Printer2D printer5(2, 2);

    std::vector<Printer *> printers;
    printers.push_back(&printer1);
    printers.push_back(&printer2);
    printers.push_back(&printer3);
    printers.push_back(&printer4);
    printers.push_back(&printer5);
    printers.push_back(&copier);

    for (int i = 0; i < printers.size(); ++i) {
        printers.at(i)->print();
    }

    Scanner scanner1(5);
    Scanner scanner2(8);
    Copier copier2(4, 8, 2);
    std::vector<Scanner *> scanners;
    scanners.push_back(&copier);
    scanners.push_back(&copier2);
    scanners.push_back(&scanner1);
    scanners.push_back(&scanner2);

    for (int j = 0; j < scanners.size(); ++j) {
        scanners.at(j)->scan();
        std::cout << std::endl;
    }

    return 0;
}