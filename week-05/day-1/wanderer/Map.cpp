//
// Created by Varga Júlia on 2019-04-30.
//

#include "Map.h"

void Map::fillMatrixWithTiles()
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> temp;
        for (int j = 0; j < 10; ++j) {
            temp.push_back(1);
        }
        _mapOfTiles.push_back(temp);
    }
}

void Map::createPath(int nOfTunnels, int tunnelLength)
{
    int startX = 0;
    int startY = 0;
    for (int i = 0; i < nOfTunnels; ++i) {
        int randomLength = rand() % tunnelLength + 1;
        int randomDirection = rand() % 4;

        if (randomDirection == 0 && startY + randomLength < _mapOfTiles.size()) {
            for (int j = 0; j < randomLength; ++j) {    //balra
                _mapOfTiles[startX][startY] = 0;
                startY++;
            }

        } else if (randomDirection == 1 && startY - randomLength > 0) {   // jobbra
            for (int j = 0; j < randomLength; ++j) {
                _mapOfTiles[startX][startY] = 0;
                startY--;
            }

        } else if (randomDirection == 2 && startX + randomLength < _mapOfTiles.size()) {
            for (int j = 0; j < randomLength; ++j) {
                _mapOfTiles[startX][startY] = 0;
                startX++;
            }

        } else if (randomDirection == 3 && startX - randomLength > 0) {
            for (int j = 0; j < randomLength; ++j) {
                _mapOfTiles[startX][startY] = 0;
                startX--;
            }

        }
    }
}

int Map::getValue(int posX, int posY) {
    if (posX >= 0 && posY >=0 && posX < 500 && posY < 500) {
        return _mapOfTiles[posX / 50][posY / 50];
    } else {
        return 0;
    }
}
