//
// Created by Varga Júlia on 2019-04-30.
//


#ifndef LINE_IN_THE_MIDDLE_MAP_H
#define LINE_IN_THE_MIDDLE_MAP_H


#include <vector>
#include <iostream>
#include "ctime"

class Map {
public:
    void fillMatrixWithTiles();
    void createPath(int nOfTunnels, int tunnelLength);
    int getValue(int posX, int posY);

protected:
    std::vector<std::vector<int>> _mapOfTiles;

};


#endif //LINE_IN_THE_MIDDLE_MAP_H

