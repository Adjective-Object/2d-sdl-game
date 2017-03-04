#include <SDL.h>
#include <vector>
#include <iostream>
#include <SDL_ttf.h>

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
                Pair(0.4, 0.5), Pair(0.8, 0.5),
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
            Pair(0.1, 2.0), Pair(0.1, 1.35), Pair(0.7, 1.35), Pair(0.7, 1.2),
            Pair(0.9, 1.2), Pair(0.9, 1.6), Pair(2.2, 1.6), Pair(2.0, 2.0),
            Pair(2.2, 2.0), Pair(2.4, 2.0), Pair(3, 1.5), Pair(3.4, 1.5),
            Pair(3.4, 1.1), Pair(3.5, 1.1),

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
    if (joystick) {
        joystick->calibrateAxis(0, -30000, 32800, 450);
        joystick->calibrateAxis(1, -32000, 32000, 450);
        joystick->calibrateAxis(3, -29100, 32000, 450);
        joystick->calibrateAxis(4, -32000, 30000, 450);

        entities.push_back(new JoystickIndicator(0, 1, 10, 10, 50, 50));
        entities.push_back(new JoystickIndicator(3, 4, 70, 10, 50, 50));
    }

    playerInput = new InputMapping::JoystickInputHandler();
    PlayerConfig* marthConfig = new PlayerConfig("assets/attributes.yaml");
    AnimationBank* animationBank = new AnimationBank();
    animationBank->loadImages();
    player =
        new Player(marthConfig, playerInput, animationBank, Pair(0.5, 0.5));

    TTF_Font* fontMonaco = TTF_OpenFont("assets/monaco.ttf", 20);

    SDL_Renderer* r = EnG->getRenderer();
    stateText = new Text(r, Pair(130, 10), fontMonaco,
                         {
                             .r = 255, .g = 255, .b = 255, .a = 255,
                         },
                         "???");

    posText = new Text(r, Pair(130, 40), fontMonaco,
                       {
                           .r = 255, .g = 255, .b = 255, .a = 255,
                       },
                       ".");

    entities.push_back(player);
    entities.push_back(stateText);
    entities.push_back(posText);
    Scene::init();
}

void MainScene::update() {
    // update player positions
    Scene::update();
    Pair playerMotion = player->velocity * EnG->elapsed;
    map->movePlayer(*player, playerMotion);

    Joystick* j = EnG->input.getJoystick(0);
    if (j) {
        playerInput->step(j);
    }

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
