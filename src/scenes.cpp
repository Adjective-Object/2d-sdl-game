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
            Pair(0.4, 1), Pair(0.8, 1),
        },
        true);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform(
        {
            Pair(1.5, 1), Pair(1.9, 1),
        },
        true);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform(
        {
            Pair(0.95, 0.7), Pair(1.35, 0.7),
        },
        true);
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform({
        Pair(2.1, 0.5), Pair(2.5, 0.5), Pair(2.5, 1), Pair(2.1, 1),
        Pair(2.1, 0.5),
    });
    platforms.push_back(p);
    entities.push_back(p);

    p = new Platform({
        Pair(0.1, 2.0), Pair(0.1, 1.6), Pair(0.7, 1.6), Pair(0.7, 1.2),
        Pair(0.9, 1.2), Pair(0.9, 1.6), Pair(2.2, 1.6), Pair(2.0, 2.0),
        Pair(2.0, 2.0), Pair(2.4, 2.0), Pair(3, 1.0), Pair(3.4, 1.0),

    });
    platforms.push_back(p);
    entities.push_back(p);

    Scene::init();
}

void MainScene::update() {
    // update player positions
    Scene::update();

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

    // perform collisions
    for (Platform* p : platforms) {
        Pair collPos = Pair(0, 0);
        TerrainCollisionType collisionType;

        Ecb* oldEcb = &(player->previousCollision->postCollision);
        Ecb* newEcb = &(player->currentCollision->postCollision);

        collisionType =
            p->checkCollision(oldEcb->bottom, newEcb->bottom, collPos);

        if (player->velocity.y > 0 &&
            player->getAction()->isLandable(*player, p) &&
            collisionType == FLOOR_COLLISION) {
            player->land(p, collPos);
        }

        collisionType =
            p->checkCollision(oldEcb->origin, newEcb->right, collPos);

        if (collisionType == WALL_COLLISION) {
            std::cout << "wall on right" << std::endl;

            std::cout << "player moving at " << player->cVel << std::endl;
            std::cout << "player at " << player->position << std::endl;
            std::cout << "right ecb at " << newEcb->right << std::endl;
            std::cout << "collision at " << collPos << std::endl;
            std::cout << (newEcb->right - collPos) << std::endl;
            player->moveTo(player->position - (newEcb->right - collPos));
            std::cout << "player ends at " << player->position << std::endl;
            std::cout << "right ecb end sat "
                      << player->currentCollision->postCollision.right
                      << std::endl;
        }
    }
}

void MainScene::render(SDL_Renderer* r) {
    Scene::render(r);
}
