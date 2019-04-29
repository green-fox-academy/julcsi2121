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

enum tile_type {
    FLOOR,
    WALL
};


class Tile {
public:
    Tile();
    Tile(int x, int y);
    void drawTexture(SDL_Renderer* gRenderer);
    SDL_Texture* createTexture(SDL_Renderer* gRenderer);
protected:
    SDL_Texture* _texture;
    std::string _path;
    int _x;
    int _y;
    SDL_Rect _tile;
public:
    tile_type getTileType() const;

protected:
    tile_type _tileType;
};


#endif //LINE_IN_THE_MIDDLE_TILE_H
