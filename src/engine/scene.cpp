#include <iostream>
#include <algorithm>

#include <SDL.h>
#include "scene.hpp"
#include "entity.hpp"

Scene::Scene() {
    entities = std::vector<Entity *>();
}

Scene::~Scene() {
    for(Entity * e: entities) {
        delete e;
    }
}

void Scene::init() {
    // init all the entities
    for (Entity * e : this->entities) {
        e->init();
    }
}

void Scene::start() {
}

void Scene::update() {
    // update all the entities
    for (Entity * e : this->entities) {
        e->update();
    }
}

void Scene::render(SDL_Renderer * r) {

    SDL_SetRenderDrawColor(r, 180, 180, 180, 255);
    SDL_Rect rect = {
        0, 400, 800, 100
    };
    SDL_RenderFillRect(r, &rect);

    for (Entity * e: this->entities) {
        e->render(r);
    }

}


