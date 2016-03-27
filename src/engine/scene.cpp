#include <iostream>
#include <algorithm>

#include <SDL.h>
#include "scene.hpp"
#include "entity.hpp"

Scene::Scene(SDL_Window * win, SDL_Renderer * ren) :
    win(win), ren(ren) {
}

Scene::~Scene() {
    for(Entity * e: entities) {
        delete e;
    }
}

void Scene::start() {
    uint32_t lastTick = SDL_GetTicks();
    while (!this->readyToExit) {
        uint32_t thisTick = SDL_GetTicks(),
                 tickDiff = thisTick - lastTick;
        lastTick = thisTick;

        // Process SDL events into something easier to use

        SDL_Event e;
        while (SDL_PollEvent(&e)){
            //If user closes the window, ready to exit
            if (e.type == SDL_QUIT){
                this->readyToExit = true;
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

        update(tickDiff);

        // clear the renderer & render all entities
        SDL_RenderClear(ren);

        render();

        // Update the screen
        SDL_RenderPresent(ren);

        // Cap framerate at 60fps
        long unsigned int millis_to_delay = 16; // - (SDL_GetTicks() - lastTick));
        SDL_Delay(std::min(0UL, millis_to_delay));
    }
}

void Scene::update(unsigned long elapsed_millis) {
    // update all the entities
    for (Entity * e: this->entities) {
        e->update(elapsed_millis/ 16.6666);
    }
}

void Scene::render() {
    for (Entity * e: this->entities) {
        e->render(ren);
    }
}


