#include <iostream>
#include "Sharpie.h"
#include "SharpieSet.h"

int main() {


    Sharpie sharpie1("red", 2.1);
    Sharpie sharpie2("blue", 3.0);
    Sharpie sharpie3("black", 1.5);
    Sharpie sharpie4("green", 2.5);

    while (sharpie3.getInkAmount() > 0) {
        sharpie3.use();
    }

    SharpieSet sharpieSet;
    sharpieSet.addSharpie(sharpie1);
    sharpieSet.addSharpie(sharpie2);
    sharpieSet.addSharpie(sharpie3);
    sharpieSet.addSharpie(sharpie4);

    while (sharpie2.getInkAmount() > 0) {
        sharpie2.use();
    }
    sharpieSet.printSet();
    sharpieSet.countUseable();
    sharpieSet.removeTrash();
    sharpieSet.printSet();
    return 0;
}