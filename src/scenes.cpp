#include "scenes.hpp"
#include "engine/game.hpp"
#include "engine/joystickindicator.hpp"
#include "engine/text.hpp"
#include "player/action.hpp"
#include "player/player.hpp"
#include "terrain/collisiontype.hpp"
#include <SDL.h>
#include <vector>
#include <iostream>

MainScene::MainScene() : Scene() {}

MainScene::~MainScene() {}

void MainScene::init() {
    Joystick* joystick = EnG->input.getJoystick(0);

    joystick->calibrateAxis(0, -30000, 32800, 450);
    joystick->calibrateAxis(1, -32000, 32000, 450);
    joystick->calibrateAxis(3, -29100, 32000, 450);
    joystick->calibrateAxis(4, -32000, 30000, 450);

    player = new Player("attributes.yaml", 0.5, 0.5);
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

    Platform* p;
    p = new Platform(
        {
            Pair(0.4, 0.8), Pair(0.8, 0.8),
        },
        true);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform(
        {
            Pair(1.5, 0.8), Pair(1.9, 0.8),
        },
        true);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform(
        {
            Pair(0.95, 0.5), Pair(1.35, 0.5),
        },
        true);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform(
        {
            Pair(2.2, 0.5), Pair(2.0, 0.2),
        },
        false);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform(
        {
            Pair(1.9, 1.0), Pair(2.2, 0.5),
        },
        false);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform(
        {
            Pair(2.1, 1.2), Pair(1.9, 1.0),
        },
        false);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform({
        Pair(0.1, 1.2), Pair(0.3, 1.15), Pair(1.0, 1.2), Pair(1.5, 1.15),
        Pair(2.1, 1.2),
    });
    platforms.push_back(p);
    entities.push_back(p);

    Scene::init();
}

void MainScene::update() {
    Scene::update();

    ActionState newState = player->getActionState();
    if (lastActionState != newState) {
        stateText->updateText(actionStateName(newState));
        lastActionState = newState;
    }

    char tmp[128];
    sprintf(tmp, "(%.2f, %.2f)", player->position.x, player->position.y);
    posText->updateText(tmp);

    for (Platform* p : platforms) {
        Pair position = Pair(0, 0);
        TerrainCollisionType collisionType;

        collisionType = p->checkCollision(
            player->previousCollision->postCollision.bottom,
            player->currentCollision->postCollision.bottom, position);

        if (player->velocity.y > 0 &&
            player->getAction()->isLandable(*player, p) &&
            collisionType == FLOOR_COLLISION) {
            player->land(p, position);
            break;
        } else if (collisionType != NO_COLLISION) {
            std::cout << "ignoring collision of type " << collisionType
                      << " against " << p << std::endl;
        }
    }
}

void MainScene::render(SDL_Renderer* r) {
    Scene::render(r);
}
