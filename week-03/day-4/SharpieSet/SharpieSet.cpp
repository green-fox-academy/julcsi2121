//
// Created by Varga Júlia on 2019-04-18.
//

#include "SharpieSet.h"

void SharpieSet::addSharpie(Sharpie& sharpie) {
    Sharpies.push_back(sharpie);
}

Sharpie* SharpieSet::getSharpie(int i) {
    return &Sharpies[i];
}

void SharpieSet::countUseable() {
    int counter = 0;
    for (int i = 0; i < Sharpies.size(); ++i) {
        if(Sharpies.at(i).getInkAmount() > 0) {
            counter++;
        }
    }
    std::cout << "No of not empty sharpies: " << std::to_string(counter) << std::endl;
}

void SharpieSet::removeTrash() {
    for (int i = 0; i < Sharpies.size(); ++i) {
        if (Sharpies.at(i).getInkAmount() == 0) {
            Sharpies.erase(Sharpies.begin() + i);
        }
    }
}

void SharpieSet::printSet() {
    for (int i = 0; i < Sharpies.size(); ++i) {
        std::cout << "There is a sharpie: " << Sharpies.at(i).getColor() << " with ink amount: " << std::to_string(Sharpies.at(i).getInkAmount()) << std::endl;
    }
}

