//
// Created by Varga Júlia on 2019-04-17.
//

#ifndef DICESET_DICESET_H
#define DICESET_DICESET_H

#include <iostream>
#include <vector>

class DiceSet
{
public:

    DiceSet();

    void roll();
    void roll(int i);
    std::vector<int> getCurrent() const;
    int getCurrent(int i) const;
    void printCurrent();
private:
    std::vector<int> dices;
};


#endif //DICE_SET_DICE_SET_H
