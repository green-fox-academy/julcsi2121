//
// Created by Varga Júlia on 2019-04-29.
//

#ifndef LINE_IN_THE_MIDDLE_TILE_H
#define LINE_IN_THE_MIDDLE_TILE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>


class Tile {
public:
    Tile();
    void drawTexture(SDL_Renderer* gRenderer);
    SDL_Texture* createTexture(SDL_Renderer* gRenderer);
protected:
    SDL_Texture* _texture;
    std::string _path;
private:
    int _x;
    int _y;
    SDL_Rect _tile;
};


#endif //LINE_IN_THE_MIDDLE_TILE_H
