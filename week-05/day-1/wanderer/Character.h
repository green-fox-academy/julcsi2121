//
// Created by Varga Júlia on 2019-04-30.
//

#ifndef LINE_IN_THE_MIDDLE_CHARACTER_H
#define LINE_IN_THE_MIDDLE_CHARACTER_H

#include "Map.h"

class Character {
public:
    Character(Map* actualMap);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    Map *getActualMap() const;
    bool isAvailable(int goalPosX, int goalPosY);

protected:
    int _HP;
    int _DP;
    int _SP;
    int _posX;
    int _posY;
    Map* _actualMap;
};


#endif //LINE_IN_THE_MIDDLE_CHARACTER_H
