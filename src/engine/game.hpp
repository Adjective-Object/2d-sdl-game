#ifndef __ENGINE_GAME
#define __ENGINE_GAME

#include "scene.hpp"

class Game;
extern Game * EnG;

class Game {
private:
    SDL_Texture *engineFallbackTexture;
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
    Scene * currentScene;

    // Actual Game object API
    Game(unsigned int width, unsigned int height, 
            Scene & initialScene, 
            unsigned int zoomLevel = 1);

    ~Game();

    void start();
};

#endif
