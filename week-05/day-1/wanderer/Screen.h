//
// Created by Varga Júlia on 2019-04-29.
//

#ifndef LINE_IN_THE_MIDDLE_SCREEN_H
#define LINE_IN_THE_MIDDLE_SCREEN_H

#include <vector>
#include "ctime"
#include "Tile.h"
#include "Floor.h"
#include "Wall.h"


class Screen {
public:
    void drawScreen(SDL_Renderer* gRenderer);
    void fillMatrixWithTiles();
    void createPath(int nOfTunnels, int tunnelLength);
private:
    std::vector<std::vector<int>> _mapOfTiles;
};


#endif //LINE_IN_THE_MIDDLE_SCREEN_H
