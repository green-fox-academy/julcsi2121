#include <iostream>
#include "Sharpie.h"
#include "SharpieSet.h"

int main() {


    Sharpie sharpie1("red", 2.1);
    Sharpie sharpie2("blue", 3.0);
    Sharpie sharpie3("black", 1.5);
    Sharpie sharpie4("green", 2.5);

    SharpieSet sharpieSet;
    sharpieSet.addSharpie(sharpie1);
    sharpieSet.addSharpie(sharpie2);
    sharpieSet.addSharpie(sharpie3);
    sharpieSet.addSharpie(sharpie4);

    sharpieSet.printSet();

    while (sharpieSet.getSharpie(0)->getInkAmount() > 0) {
        sharpieSet.getSharpie(0)->use();
    }


    sharpieSet.printSet();

    sharpieSet.removeTrash();
    sharpieSet.printSet();
    return 0;
}