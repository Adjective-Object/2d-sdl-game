#include <SDL.h>
#include <vector>
#include <iostream>

#include "engine/game.hpp"
#include "engine/joystickindicator.hpp"
#include "engine/text.hpp"
#include "player/action.hpp"
#include "player/player.hpp"
#include "terrain/map.hpp"
#include "./mainscene.hpp"

Map mainSceneMap = Map(
    {
        // left passable platform
        Platform(
            {
                Pair(0.4, 1), Pair(0.8, 1),
            },
            true),

        // center passable platform
        Platform(
            {
                Pair(1.5, 1), Pair(1.9, 1),
            },
            true),

        // right passable platform
        Platform(
            {
                Pair(0.95, 0.7), Pair(1.35, 0.7),
            },
            true),

        // floating box
        Platform({
            Pair(2.1, 0.5), Pair(2.5, 0.5), Pair(2.5, 1), Pair(2.1, 1),
            Pair(2.1, 0.5),
        }),

        // convoluted floor surface
        Platform({
            Pair(0.1, 2.0), Pair(0.1, 1.6), Pair(0.7, 1.6), Pair(0.7, 1.2),
            Pair(0.9, 1.2), Pair(0.9, 1.6), Pair(2.2, 1.6), Pair(2.0, 2.0),
            Pair(2.0, 2.0), Pair(2.4, 2.0), Pair(3, 1.0), Pair(3.4, 1.0),

        }),
    },
    {
        Ledge(Pair(2.1, 0.5), FACING_LEFT), Ledge(Pair(2.5, 0.5), FACING_RIGHT),

    });

MainScene::MainScene() : Scene() {
    map = &mainSceneMap;
}

MainScene::~MainScene() {}

void MainScene::init() {
    Joystick* joystick = EnG->input.getJoystick(0);

    joystick->calibrateAxis(0, -30000, 32800, 450);
    joystick->calibrateAxis(1, -32000, 32000, 450);
    joystick->calibrateAxis(3, -29100, 32000, 450);
    joystick->calibrateAxis(4, -32000, 30000, 450);

    player = new Player("assets/attributes.yaml", 0.5, 0.5);
    entities.push_back(player);

    SDL_Renderer* r = EnG->getRenderer();
    stateText = new Text(r, Pair(130, 10), "assets/monaco.ttf", 20,
                         {
                             .r = 255, .g = 255, .b = 255, .a = 255,
                         },
                         "???");

    posText = new Text(r, Pair(130, 40), "assets/monaco.ttf", 20,
                       {
                           .r = 255, .g = 255, .b = 255, .a = 255,
                       },
                       ".");

    entities.push_back(stateText);
    entities.push_back(posText);

    entities.push_back(new JoystickIndicator(0, 1, 10, 10, 50, 50));
    entities.push_back(new JoystickIndicator(3, 4, 70, 10, 50, 50));
    Scene::init();
}

void MainScene::update() {
    // update player positions
    Scene::update();
    Pair playerMotion = player->velocity * EnG->elapsed;
    map->updateCollision(*player, playerMotion);

    // update action label when the player's action state updates
    ActionState newState = player->getActionState();
    if (lastActionState != newState) {
        stateText->updateText(actionStateName(newState));
        lastActionState = newState;
    }

    // update position text to the player's position
    char tmp[128];
    sprintf(tmp, "(%.2f, %.2f)", player->position.x, player->position.y);
    posText->updateText(tmp);
}

void MainScene::render(SDL_Renderer* r) {
    Scene::render(r);
    map->render(r);
}
