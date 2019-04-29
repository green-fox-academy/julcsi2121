#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include "Tile.h"
#include "Floor.h"
#include "Wall.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//attemption to draw a tile
//void drawTile(std::string path);

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

/*
void drawTile(std::string path) {
    //tile::floor, tile::wall, screen: std::vector<std::vector<tile*>>
    //load image - floor vs wall
    SDL_Surface* loadedTile = IMG_Load( path.c_str());
    if(loadedTile == nullptr) {
        SDL_Log("PNG image couldn't be loaded, SDL_image Error: %s", IMG_GetError());
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface( gRenderer, loadedTile );
    SDL_FreeSurface( loadedTile );

    //draw tile fgv - mindkettőt kéne kezelnie, mert a pozíció típusfüggetlen
    SDL_Rect tile;
    tile.x = 0;
    tile.y = 0;
    tile.w = 50;
    tile.h = 50;

    SDL_RenderCopy(gRenderer, texture, NULL, &tile);

}
 */

bool init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL Error: %s", SDL_GetError());
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Center box function", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        SDL_Log("Window could not be created! SDL Error: %s", SDL_GetError());
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL Error: %s", SDL_GetError());
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Handle loading of .png-s
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        SDL_Log("PNG image could not be loaded! SDL_image error: %s", IMG_GetError());
        return false;
    }

    return true;
}

void close()
{
    //Destroy window
    IMG_Quit();
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init()) {
        SDL_Log("Failed to initialize!");
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        //Floor tile;
        //tile.createTexture(gRenderer);
        //tile.drawTexture(gRenderer);

        Wall wal;
        wal.createTexture(gRenderer);
        wal.drawTexture(gRenderer);

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}