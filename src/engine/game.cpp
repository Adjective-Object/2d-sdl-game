#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include "game.hpp"
#include "util.hpp"

Game *EnG = nullptr;

// TODO use zoomLevel at all
Game::Game(unsigned int width, unsigned int height,
            Scene & initialScene, unsigned int zoomLevel) :
        currentScene(&initialScene){

    // check if there is an existing global reference to Game. If there is
    // not, register this as the Game singleton
    if (EnG != nullptr) {
        std::cerr << "Tried to create another instance of singleton Game" 
                  << std::endl;
        exit(1);
    } else {
        // init SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        EnG = this;
    }

    // create the game stuff
    win = makeWindow("poop", width, height);
    ren = makeRenderer(win);

    //TODO replace this with a string constant
    engineFallbackTexture = loadPNG("fallback.png");
}


Game::~Game() {
    SDL_Quit();
}


/**
 * Makes the SDL window, exits program on error
 */
SDL_Window * Game::makeWindow(const std::string & name, 
        unsigned int width, unsigned int height) {
    SDL_Window * win = SDL_CreateWindow(name.c_str(),
            100, 100, (int) width, (int) height, SDL_WINDOW_SHOWN);

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
SDL_Renderer * Game::makeRenderer(SDL_Window * win) {
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


/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* Game::loadPNG(const std::string &file) {
    //Initialize to nullptr to avoid dangling pointer issues
    SDL_Texture *texture = engineFallbackTexture;
    //Load the image
    SDL_Surface *loadedImage = IMG_Load(file.c_str());
    //If the loading went ok, convert to texture and return the texture
    if (loadedImage != nullptr){
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        //Make sure converting went ok too
        if (texture == nullptr){
            logSDLError(std::cout, "CreateTextureFromSurface");
        }
    }
    else {
        logSDLError(std::cout, "LoadIMG");
    }
    return texture;
}


void Game::start() {
    uint32_t lastTick = SDL_GetTicks();
    while (!readyToExit) {
        // figure out the elased milliseconds
        uint32_t thisTick = SDL_GetTicks(),
                 tickDiff = thisTick - lastTick;
        lastTick = thisTick;
        this->elapsed = (tickDiff / 16.66666);

        // Process SDL events into internal format
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            //If user closes the window, ready to exit
            if (e.type == SDL_QUIT){
                readyToExit = true;
            } 

            /*
            //If user presses a key, collect the key down information
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }

            //If user clicks the mouse
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
            */
        }

        // update the game's state
        currentScene->update();

        // update the frame buffer
        SDL_RenderClear(ren);
        currentScene->render();

        // Update the screen
        SDL_RenderPresent(ren);

        // Cap framerate at 60fps
        long unsigned int millis_to_delay = 16; // - (SDL_GetTicks() - lastTick));
        SDL_Delay(std::min(0UL, millis_to_delay));
    }
}



