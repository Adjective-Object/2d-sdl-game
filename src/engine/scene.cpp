#include <SDL.h>
#include <algorithm>
#include <iostream>

#include "entity.hpp"
#include "scene.hpp"
#include "renderer/abstractrenderer.hpp"

Scene::Scene() {
    entities = std::vector<Entity*>();
}

Scene::~Scene() {
    for (Entity* e : entities) {
        delete e;
    }
}

void Scene::init() {
    // init all the entities
    for (Entity* e : this->entities) {
        e->init();
    }
}

void Scene::start() {}

void Scene::update() {
    // update all the entities
    for (Entity* e : this->entities) {
        e->update();
    }
}

void Scene::render() {
    for (Entity* e : this->entities) {
        AbstractRenderer* r = e->getRenderer();
        if (r) {
            r->render();
        }
    }
}
