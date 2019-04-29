//
// Created by Varga Júlia on 2019-04-29.
//

#include "Tile.h"

Tile::Tile() {
    _x = 0;
    _y = 0;
}

Tile::Tile(int x, int y)
{
    _x = x;
    _y = y;

}

void Tile::drawTexture(SDL_Renderer* gRenderer)
{

    _tile.x = _x;
    _tile.y = _y;
    _tile.w = 50;
    _tile.h = 50;

    SDL_RenderCopy(gRenderer, _texture, NULL, &_tile);
}

SDL_Texture* Tile::createTexture(SDL_Renderer* gRenderer)
{
    SDL_Surface* loadedTile = IMG_Load( _path.c_str());
    if(loadedTile == nullptr) {
        SDL_Log("PNG image couldn't be loaded, SDL_image Error: %s", IMG_GetError());
    }

    _texture = SDL_CreateTextureFromSurface( gRenderer, loadedTile );
    SDL_FreeSurface( loadedTile );
}

tile_type Tile::getTileType() const {
    return _tileType;
}
