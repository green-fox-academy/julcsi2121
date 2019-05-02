//
// Created by Varga Júlia on 2019-04-29.
//

#include "Screen.h"

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
