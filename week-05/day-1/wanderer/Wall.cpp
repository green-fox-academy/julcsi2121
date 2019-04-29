//
// Created by Varga Júlia on 2019-04-29.
//

#include "Wall.h"

Wall::Wall() {
    _path = "../img/wall.png";
}

Wall::Wall(int i, int j) {
    _x = i;
    _y = j;
    _path = "../img/wall.png";
    _tileType = WALL;
}