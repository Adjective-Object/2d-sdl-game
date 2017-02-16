#include <SDL.h>
#include <iostream>
#include "scenes.hpp"
#include "player/player.hpp"
#include "player/action.hpp"
#include "engine/game.hpp"
#include "engine/joystickindicator.hpp"
#include "engine/text.hpp"

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

    player = new Player("attributes.yaml", 0.5, 0.5);
    this->entities.push_back(player);

    SDL_Renderer * r = EnG->getRenderer();
    text = new Text(
        r,
        Pair(130, 10),
        "assets/monaco.ttf",
        20,
        {
            .r = 255,
            .g = 255,
            .b = 255,
            .a = 255,
        },
        "???"
    );
    this->entities.push_back(text);

    this->entities.push_back(new JoystickIndicator(0, 1, 10, 10, 50, 50));
    this->entities.push_back(new JoystickIndicator(3, 4, 70, 10, 50, 50));
    Scene::init();
}

void MainScene::update() {
    Scene::update();

    ActionState newState = player->getActionState();
    if (lastActionState != newState) {
        text->updateText(actionStateName(newState));
        lastActionState = newState;
    }

}

void MainScene::render(SDL_Renderer * r) {
    Scene::render(r);
}

