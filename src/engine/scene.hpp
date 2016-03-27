#ifndef __ENGINE_SCENE
#define __ENGINE_SCENE
#include <SDL.h>
#include <vector>

#include "entity.hpp"

class Scene {
    std::vector<Entity *> entities;

    // SDL INTERNALS
    SDL_Window * win;
    SDL_Renderer * ren;

    // SCENE INTERNAL STATE
    bool readyToExit;

    void update(unsigned long elapsed_millis);
    void render();
public:
    Scene(SDL_Window * win, SDL_Renderer * ren);
    ~Scene();
    void start();
};

#endif
