//
// Created by Varga Júlia on 2019-04-29.
//

#include "Screen.h"

void Screen::fillMatrixWithTiles()
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> temp;
        for (int j = 0; j < 10; ++j) {
            temp.push_back(1);
        }
        _mapOfTiles.push_back(temp);
    }
}

void Screen::createPath(int nOfTunnels, int tunnelLength)
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

void Screen::drawScreen(SDL_Renderer* gRenderer)
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (_mapOfTiles[i][j] == 0) {
                Floor floor(i * 50, j * 50);
                floor.createTexture(gRenderer);
                floor.drawTexture(gRenderer);
            } else {
                Wall wall(i * 50, j * 50);
                wall.createTexture(gRenderer);
                wall.drawTexture(gRenderer);
            }
        }
    }
}


/*
 * functionality to choose wall of floor
 * srand 0-1 - if 0, it is a wall, if 1, it is a floor
 */