
//
// Created by Varga Júlia on 2019-04-18.
//

#ifndef SHARPIESET_SHARPIESET_H
#define SHARPIESET_SHARPIESET_H


#include <string>
#include <iostream>
#include <vector>
#include "Sharpie.h"

class SharpieSet {
public:
    void addSharpie(Sharpie& sharpie);
    void countUseable();
    void removeTrash();
    void printSet();
    Sharpie* getSharpie(int i);
private:
    std::vector<Sharpie> Sharpies;
};
#endif //SHARPIESET_SHARPIESET_H
