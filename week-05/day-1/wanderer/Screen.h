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
#include "Map.h"


class Screen : public Map {
public:
    void drawScreen(SDL_Renderer* gRenderer);
};


#endif //LINE_IN_THE_MIDDLE_SCREEN_H
