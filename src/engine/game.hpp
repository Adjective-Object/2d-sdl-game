#ifndef __ENGINE_GAME
#define __ENGINE_GAME

#include <SDL_image.h>
#include "scene.hpp"
#include "entity.hpp"
#include "input.hpp"
#include <string>

class Game;
extern Game * EnG;
extern SDL_Texture * FALLBACK_TEXTURE;

class Game {
private:
    SDL_Window *win;
    SDL_Renderer *ren;
    bool readyToExit = false;

    SDL_Window * makeWindow(const std::string & name,
            unsigned int width, unsigned int height);
    SDL_Renderer * makeRenderer(SDL_Window * win);
    SDL_Texture * loadPNG(const std::string & file);

public:
    // FlxG convenience values
    double elapsed;
    double fixedTickrate = 0;
    Scene * currentScene;
    Input input;

    // Actual Game object API
    Game(unsigned int width, unsigned int height, 
            Scene & initialScene, 
            unsigned int zoomLevel = 1);

    ~Game();
    void start();
};

#endif
