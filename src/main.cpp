#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. SDL_Error: " << SDL_GetError() << std::endl;
    
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("Game v1.0", 1280, 720);

    // load textures
    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
    
    // set up game loop
    bool gameRunning = true;
    SDL_Event event;

    // start game loop
    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();
        window.render(grassTexture);
        window.display();
    }

    // exit and clean up
    window.cleanUp();
    SDL_Quit();
    
    return 0;
}