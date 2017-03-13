#ifndef __ENGINE_GAME
#define __ENGINE_GAME

#include "entity.hpp"
#include "input/input.hpp"
#include "scene.hpp"
#include <SDL_image.h>
#include <string>

class Game;
extern Game* EnG;
extern SDL_Texture* FALLBACK_TEXTURE;

class Game {
   private:
    SDL_Window* win;
    SDL_Renderer* ren;
    bool readyToExit = false;

    SDL_Window* makeWindow(const std::string& name,
                           unsigned int width,
                           unsigned int height);
    SDL_Renderer* makeRenderer(SDL_Window* win);

   public:
    // FlxG convenience values
    double elapsed;
    double fixedTickrate = 0;
    Scene* currentScene;
    Input input;

    SDL_Texture* loadPNG(const std::string& file);

    // Actual Game object API
    Game(unsigned int width,
         unsigned int height,
         Scene& initialScene,
         unsigned int zoomLevel = 1);

    ~Game();
    void start();

    SDL_Renderer* getRenderer();
};

#endif
