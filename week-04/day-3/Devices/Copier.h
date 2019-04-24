//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef DEVICES_COPIER_H
#define DEVICES_COPIER_H

#include "Scanner.h"
#include "Printer2D.h"


class Copier : public Scanner, public Printer2D {
public:
    Copier(int sizeX, int sizeY, int speed);
    void copy();
};


#endif //DEVICES_COPIER_H
