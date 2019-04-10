#include <iostream>
#include <SDL.h>
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

void drawSquare(int size, std::string color);

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void draw() {
    // Create a square drawing function that takes 2 parameters:
    // The square size, and the fill color,
    // and draws a square of that size and color to the center of the canvas.
    // Create a loop that fills the canvas with rainbow colored squares.
    /* initialize "random" seed: */
    std::vector<std::string> colors = {"red", "orange", "yellow", "green", "blue", "purple"};
    for (int i = 0; i < colors.size(); ++i) {
        drawSquare(100, colors[i]);
    }
}

void drawSquare(int a, std::string color)
{
    if (color == "green") {
        SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 0xFF);
    } else if (color == "red") {
        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 0xFF);
    } else if (color == "orange") {
        SDL_SetRenderDrawColor(gRenderer, 255, 110, 0, 0xFF);
    } else if (color == "yellow"){
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 0xFF);
    } else if (color == "blue") {
        SDL_SetRenderDrawColor(gRenderer, 0, 110, 255, 0xFF);
    } else if (color == "purple") {
        SDL_SetRenderDrawColor(gRenderer, 155, 0, 255, 0xFF);
    } else {
        std::cout << "Invalid color!" << std::endl;
    }
    SDL_Rect fillRect = { rand() % 480 + 1, rand() % 480 + 1, a, a};
    SDL_RenderFillRect( gRenderer, &fillRect );
    SDL_Delay(100);

}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Rainbow box function", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
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

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}