#include <SDL.h>
#include <iostream>
#include "scenes.hpp"
#include "player/player.hpp"
#include "engine/game.hpp"
#include "engine/joystickindicator.hpp"

MainScene::MainScene() : Scene() {
}

MainScene::~MainScene() {
}

void MainScene::init() {
    Joystick * joystick = EnG->input.getJoystick(0);

    joystick->calibrateAxis(0, -30000, 32800, 450);
    joystick->calibrateAxis(1, -32000, 32000, 450);
    joystick->calibrateAxis(3, -29100, 32000, 450);
    joystick->calibrateAxis(4, -32000, 30000, 450);

    this->entities.push_back(new Player("attributes.yaml"));
    this->entities.push_back(new JoystickIndicator(0, 1, 10, 10, 50, 50));
    this->entities.push_back(new JoystickIndicator(3, 4, 70, 10, 50, 50));
    Scene::init();
}

void MainScene::update() {
    Scene::update();
}

void MainScene::render(SDL_Renderer * r) {
    Scene::render(r);
}

