#include <SDL.h>
#include <vector>
#include <iostream>
#include <SDL_ttf.h>
#include <cmath>
#include <cstring>

#include "engine/game.hpp"
#include "engine/joystickindicator.hpp"
#include "engine/text.hpp"
#include "player/action.hpp"
#include "player/player.hpp"
#include "terrain/map.hpp"
#include "./mainscene.hpp"
#include "engine/shader/basicshader.hpp"
#include "engine/shader/screenspaceshader.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Terrain;

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

        // far right passable platform
        Platform(
            {
                Pair(2.95, 1.1), Pair(3.1, 1.1),
            },
            true),

        // floating box
        Platform({
            Pair(2.1, 0.5), Pair(2.55, 0.5), Pair(2.5, 1), Pair(2.1, 1),
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
        Ledge(Pair(2.1, 0.5), FACING_LEFT),
        Ledge(Pair(2.55, 0.5), FACING_RIGHT),

    });

MainScene::MainScene() : Scene() {
    map = &mainSceneMap;
}

MainScene::~MainScene() {}

void MainScene::init() {
    joystick = EnG->input.getJoystick(0);
    if (joystick) {
        joystick->calibrateAxis(0, -30000, 32800, 450);
        joystick->calibrateAxis(1, -32000, 32000, 450);
        joystick->calibrateAxis(3, -29100, 32000, 450);
        joystick->calibrateAxis(4, -32000, 30000, 450);

        entities.push_back(new JoystickIndicator(0, 1, 10, 10, 50, 50));
        entities.push_back(new JoystickIndicator(3, 4, 70, 10, 50, 50));

        playerInput = new InputMapping::JoystickInputHandler(
            InputMapping::gamecubeButtons, InputMapping::gamecubeAxies,
            joystick);
    } else {
        playerInput = new InputMapping::KeyboardInputHandler(
            InputMapping::gamecubeKeys, InputMapping::gamecubeKeyAxies,
            EnG->input.getKeyboard());
    }

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

    cameraPosition = glm::vec3(player->position.x, player->position.y, -2);
    cameraTarget = glm::vec3(player->position.x, player->position.y, 0);

    entities.push_back(player);
    entities.push_back(stateText);
    entities.push_back(posText);
    entities.push_back(map);

    // set camera
    glm::vec3 up = glm::vec3(0.0f, -1.0f, 0.0f);
    cameraMatrix = glm::lookAt(cameraPosition, cameraTarget, up);

    // load shaders we plan on using
    basicShader.init();
    textureShader.init();
    // screenShader.init();

    Scene::init();
}

void MainScene::update() {
    // update player positions

    if (joystick) {
        if (joystick->down(11)) {
            frameByFrame = !frameByFrame;
        }
        if (!frameByFrame || joystick->down(10) || joystick->held(6)) {
            playerInput->step();

            player->update();
            Pair playerMotion = player->velocity * EnG->elapsed;
            map->movePlayer(*player, playerMotion);
            if (std::isnan(player->position.x) ||
                std::isnan(player->position.y)) {
                exit(1);
            }
        }
    } else {
        playerInput->step();
        player->update();
        Pair playerMotion = player->velocity * EnG->elapsed;
        map->movePlayer(*player, playerMotion);
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

void MainScene::render() {
    glm::vec3 projectedPos =
        glm::vec3(player->position.x, player->position.y - 0.25, -2.0f);

    glm::vec3 projectedTarget =
        glm::vec3(player->position.x, player->position.y, 0);

    float easingSpeed = 5;

    cameraPosition = cameraPosition +
                     (projectedPos - cameraPosition) *
                         std::min(1.0f, (float)EnG->elapsed * easingSpeed);

    cameraTarget = cameraTarget +
                   (projectedTarget - cameraTarget) *
                       std::min(1.0f, (float)EnG->elapsed * easingSpeed);

    glm::vec3 up = glm::vec3(0.0f, -1.0f, 0.0f);
    cameraMatrix = glm::lookAt(cameraPosition, cameraTarget, up);

    Scene::render();
}
