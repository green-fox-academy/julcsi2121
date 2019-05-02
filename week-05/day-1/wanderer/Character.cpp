//
// Created by Varga Júlia on 2019-04-30.
//

#include "Character.h"
Character::Character(Map* actualMap) {
    _posX = 0;
    _posY = 0;
    _actualMap = actualMap;
}

void Character::moveDown() {
    //getMap(_actualMap)->getValue(_posX, _posY);
    if (isAvailable(_posX, _posY + 50) && _posY + 50 < 500) {
        _posY += 50;
    }
}

void Character::moveUp() {
    if (isAvailable(_posX, _posY - 50) && _posY - 50 >= 0) {
        _posY -= 50;
    }
}

void Character::moveLeft() {
    if (isAvailable(_posX - 50, _posY) && _posX - 50 >= 0) {
        _posX -= 50;
    }
}

void Character::moveRight() {
    if (isAvailable(_posX + 50, _posY) && _posX + 50 < 500) {
        _posX += 50;
    }
}

Map *Character::getActualMap() const {
    return _actualMap;
}

bool Character::isAvailable(int goalPosX, int goalPosY) {
    bool canStepInto = true;
    if (getActualMap()->getValue(goalPosX, goalPosY) == 1) {
        canStepInto = false;
    }
    return canStepInto;
}