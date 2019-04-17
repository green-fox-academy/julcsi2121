//
// Created by Varga Júlia on 2019-04-17.
//

#include "DiceSet.h"

#include <stdlib.h>
#include <time.h>

DiceSet::DiceSet()
{
    srand(time(nullptr));
    dices = std::vector<int>(6);
}

void DiceSet::roll()
{
    for (int i = 0; i < dices.size(); i++) {
        dices[i] = (int) (rand() % 6) + 1;
    }
}

void DiceSet::roll(int i)
{
    dices[i] = (int) (rand() % 6) + 1;
}

std::vector<int> DiceSet::getCurrent() const
{
    return dices;
}

int DiceSet::getCurrent(int i) const
{
    return dices[i];
}

void DiceSet::printCurrent() {
    getCurrent();
    for (int i = 0; i < dices.size(); ++i) {
        std::cout << "Dice " << std::to_string(i+1) << ": " << dices.at(i) << std::endl;
    }
}
