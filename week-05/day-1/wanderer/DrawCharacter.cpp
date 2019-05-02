//
// Created by Varga Júlia on 2019-04-30.
//

#include "DrawCharacter.h"

DrawCharacter::DrawCharacter(Map* actualMap) : Character(actualMap) {
    _path = "../img/hero-down.png";
}

void DrawCharacter::drawTexture(SDL_Renderer* gRenderer)
{

    _character.x = _posX;
    _character.y = _posY;
    _character.w = 50;
    _character.h = 50;

    SDL_RenderCopy(gRenderer, _texture, NULL, &_character);
}

SDL_Texture* DrawCharacter::loadTexture(SDL_Renderer* gRenderer, std::string path)
{
    _path = path;
    SDL_Surface* loadedCharacter = IMG_Load( _path.c_str());
    if(loadedCharacter == nullptr) {
        SDL_Log("PNG image couldn't be loaded, SDL_image Error: %s", IMG_GetError());
    }
    _texture = SDL_CreateTextureFromSurface( gRenderer, loadedCharacter );
    SDL_FreeSurface( loadedCharacter );
}
