//
// Created by Varga Júlia on 2019-04-30.
//

#ifndef LINE_IN_THE_MIDDLE_DRAWCHARACTER_H
#define LINE_IN_THE_MIDDLE_DRAWCHARACTER_H

#include <string>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include "Character.h"
#include "Map.h"


class DrawCharacter : public Character{
public:
    DrawCharacter(Map* actualMap);
    SDL_Texture* loadTexture(SDL_Renderer* gRenderer, std::string path);
    void drawTexture(SDL_Renderer* gRenderer);

protected:
    SDL_Rect _character;
    SDL_Texture* _texture;
    std::string _path;
    Map* _actualMap;
};


#endif //LINE_IN_THE_MIDDLE_DRAWCHARACTER_H
