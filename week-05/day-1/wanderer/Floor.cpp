//
// Created by Varga Júlia on 2019-04-29.
//

#include "Floor.h"

Floor::Floor() {
    _path = "../img/floor.png";
}

Floor::Floor(int i, int j) {
    _x = i;
    _y = j;
    _path = "../img/floor.png";
    _tileType = FLOOR;
}