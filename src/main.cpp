#include <iostream>
#include <SDL.h>

#include "engine/scene.hpp"
#include "engine/util.hpp"
#include "scenes.hpp"

#define WINDOW_NAME "poop"

// TODO move this kind of behavior to an engine Game class
// to handle SDL initialization and shit
SDL_Texture *engineFallbackTexture;

/**
 * Makes the SDL window, exits program on error
 */
SDL_Window * makeWindow() {
    SDL_Window * win = SDL_CreateWindow(WINDOW_NAME, 
            100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    return win;
}


/**
 * Makes a renderer for the SDL window
 **/
SDL_Renderer * makeRenderer(SDL_Window * win) {
    SDL_Renderer *ren = SDL_CreateRenderer(
        win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (ren == nullptr){
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    return ren;
}


/*
 * Lesson 0: Test to make sure SDL is setup properly
 */
int main(int argc, char** argv){
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window *win = makeWindow();
    SDL_Renderer *ren = makeRenderer(win);
    engineFallbackTexture = loadPNG("./default.png", ren);

    MainScene m = MainScene(win, ren);
    std::cout << "entering main loop" << std::endl;
    m.start();
    std::cout << "exiting main loop" << std::endl;
   
    // quit everything
    std::cout << "shutting down" << std::endl;
    SDL_Quit();
    return 0;
}

