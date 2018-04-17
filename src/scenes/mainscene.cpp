#include <SDL.h>
#include <SDL_ttf.h>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

#include "./mainscene.hpp"
#include "engine/game.hpp"
#include "engine/joystickindicator.hpp"
#include "engine/shader/meshshader.hpp"
#include "engine/shader/screenspaceshader.hpp"
#include "engine/shader/skinnedmeshshader.hpp"
#include "engine/text.hpp"
#include "player/action.hpp"
#include "player/player.hpp"
#include "terrain/map.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

using namespace Terrain;

Map mainSceneMap = Map(
    {
        // left passable platform
        Platform(
            {
                Pair(0.4, 0.5),
                Pair(0.8, 0.5),
            },
            true),

        // center passable platform
        Platform(
            {
                Pair(1.5, 1),
                Pair(1.9, 1),
            },
            true),

        // right passable platform
        Platform(
            {
                Pair(0.95, 0.7),
                Pair(1.35, 0.7),
            },
            true),

        // far right passable platform
        Platform(
            {
                Pair(2.95, 1.1),
                Pair(3.1, 1.1),
            },
            true),

        // floating box
        Platform({
            Pair(2.1, 0.5),
            Pair(2.55, 0.5),
            Pair(2.5, 1),
            Pair(2.1, 1),
            Pair(2.1, 0.5),
        }),

        // convoluted floor surface
        Platform({
            Pair(0.1, 2.0),
            Pair(0.1, 1.35),
            Pair(0.7, 1.35),
            Pair(0.7, 1.2),
            Pair(0.9, 1.2),
            Pair(0.9, 1.6),
            Pair(2.2, 1.6),
            Pair(2.0, 2.0),
            Pair(2.2, 2.0),
            Pair(2.4, 2.0),
            Pair(3, 1.5),
            Pair(3.4, 1.5),
            Pair(3.4, 1.1),
            Pair(3.5, 1.1),

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
    CHECK_GL_ERROR(foo);

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
    CHECK_GL_ERROR(foo);

    PlayerConfig* marthConfig = new PlayerConfig("assets/attributes.yaml");
    player = new Player(marthConfig, playerInput, Pair(0.5, 0.5));

    TTF_Font* fontMonaco = TTF_OpenFont("assets/monaco.ttf", 20);

    stateText =
        new Text(Pair(130, 10), fontMonaco, {255, 255, 255, 255}, "???");

    posText = new Text(Pair(130, 40), fontMonaco, {255, 255, 255, 255}, ".");

    cameraPosition = glm::vec3(player->position.x, player->position.y, -2);
    cameraTarget = glm::vec3(player->position.x, player->position.y, 0);

    entities.push_back(player);
    entities.push_back(stateText);
    entities.push_back(posText);
    entities.push_back(map);

    // set camera
    glm::vec3 up = glm::vec3(0.0f, -1.0f, 0.0f);
    cameraMatrix = glm::lookAt(cameraPosition, cameraTarget, up);
    cameraStickOffset = glm::vec3(0.0f, 0.0f, 0.0f);

    // load shaders we plan on using
    vertexColorShader.init();
    CHECK_GL_ERROR(foo);
    textureShader.init();
    CHECK_GL_ERROR(foo);
    screenShader.init();
    CHECK_GL_ERROR(foo);
    fallbackShader.init();
    CHECK_GL_ERROR(foo);
    skinnedShader.init();
    CHECK_GL_ERROR(foo);

    Scene::init();
    CHECK_GL_ERROR(foo);
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
    glm::vec3 cameraTilt =
        glm::vec3(playerInput->axis(InputMapping::ATTACK_AXIS_X, 0),
                  playerInput->axis(InputMapping::ATTACK_AXIS_Y, 0), 0) *
        0.2f;

    glm::vec3 projectedPos =
        glm::vec3(player->position.x, player->position.y - 0.25, -2.0f) +
        cameraTilt;

    glm::vec3 projectedTarget =
        glm::vec3(player->position.x, player->position.y, 0);

    float easingSpeed = 5;

    cameraPosition = cameraPosition + cameraTilt +
                     (projectedPos - cameraPosition) *
                         std::min(1.0f, (float)EnG->elapsed * easingSpeed);

    cameraTarget =
        cameraTarget + (projectedTarget - cameraTarget) *
                           std::min(1.0f, (float)EnG->elapsed * easingSpeed);

    glm::vec3 up = glm::vec3(0.0f, -1.0f, 0.0f);
    cameraMatrix = glm::lookAt(cameraPosition, cameraTarget, up);

    Scene::render();
}
