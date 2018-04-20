#include "player.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include "../engine/game.hpp"
#include "../util.hpp"
#include "action.hpp"
#include "constants.hpp"
#include "engine/gl.h"
#include "engine/mesh/cube.hpp"
#include "engine/model/loader/modelloader.hpp"
#include "engine/shader/meshshader.hpp"
#include "inputhandler.hpp"
#include "playerconfig.hpp"

using namespace InputMapping;

Player::Player(PlayerConfig* config, InputHandler* input, Pair initialPosition)
    : input(input), config(config) {
    position = initialPosition;
    previousCollision->reset(position + PLAYER_ECB_OFFSET);
    currentCollision->reset(position + PLAYER_ECB_OFFSET);
    changeAction(FALL);
}

Player::~Player() {}

void Player::init() {
    mEcbMesh.init(currentCollision->postCollision);
    ecbMeshRenderer = new MeshRenderer(&vertexColorShader, &mEcbMesh);

    ModelLoader loader;
    if (loader.load("test-assets/cube_move.dae")) {
        model = loader.queryScene("Cube");
    }

    if (model) {
        std::cout << "loaded model." << std::endl;
        std::cout << "animations {" << std::endl;
        for (ModelMesh m : model->meshes) {
            for (std::pair<std::string, MeshAnim*> namedAnim : m.animations) {
                std::cout << '"' << namedAnim.first << '"' << " : "
                          << namedAnim.second->getDuration() << std::endl;
            }
        }
        std::cout << "}" << std::endl;
        std::cout << "making player renderer" << std::endl;
        modelMeshRenderer = model->makeRenderer();
        std::cout << "generated " << modelMeshRenderer << std::endl;
    } else {
        std::cout << "failed loading mesh. using fallback cube" << std::endl;
        WorldspaceMesh* cube = new WorldspaceMesh();
        *cube = makeCube();
        modelMeshRenderer = new MultiMeshRenderer(std::vector<MeshRenderer*>(
            {new MeshRenderer(&vertexColorShader, cube)}));
    }

    multiRenderer =
        new AbstractMultiRenderer({modelMeshRenderer, ecbMeshRenderer});
}

void Player::updateMesh() {
    // update ecb
    mEcbMesh.update(currentCollision->postCollision);

    // update location
    glm::mat4 modelTransform;
    modelTransform = glm::translate(
        modelTransform, glm::vec3(position.x + PLAYER_ECB_OFFSET.x,
                                  position.y + PLAYER_ECB_OFFSET.y, 0));
    ecbMeshRenderer->setModelTransform(
        glm::translate(modelTransform, glm::vec3(0, 0, -0.5)));

    // update model base transform
    modelTransform = glm::mat4();
    modelTransform =
        glm::translate(modelTransform, glm::vec3(position.x, position.y, 0));
    modelTransform =
        glm::rotate(modelTransform, (float)face * glm::half_pi<float>(),
                    glm::vec3(0, 1, 0));
    modelTransform = glm::scale(modelTransform, glm::vec3(0.1, -0.1, 0.1));
    modelMeshRenderer->setModelTransform(modelTransform);
}

void Player::moveTo(Pair newPos) {
    position = newPos;
    currentCollision->reset(position + PLAYER_ECB_OFFSET);
    updateMesh();
}

void Player::moveTo(Ecb& ecb) {
    position = ecb.origin - PLAYER_ECB_OFFSET;
    currentCollision->reset(ecb);
    updateMesh();
}

void Player::update() {
    previousPosition.x = position.x;
    previousPosition.y = position.y;

    Sprite::update();

    timer++;
    ledgeRegrabCounter--;
    action->step(*this);

    // reset position when player presses START.
    if (input->down(START)) {
        position.x = 1.15;
        position.y = 0.6;
        currentPlatform = NULL;
        changeAction(FALL);
        currentCollision->reset(position + PLAYER_ECB_OFFSET);
    }

    // swap previous and current collision, reset the new current collision
    PlayerCollision* tmp = previousCollision;
    previousCollision = currentCollision;
    currentCollision = tmp;

    // here we _would_ get the ecb from the animation
    currentCollision->root.widthLeft = ECB_DEFAULT_WIDTH;
    currentCollision->root.widthRight = ECB_DEFAULT_WIDTH;
    currentCollision->root.heightTop = ECB_DEFAULT_HEIGHT;
    currentCollision->root.heightBottom = ECB_DEFAULT_HEIGHT;
    currentCollision->reset(position + PLAYER_ECB_OFFSET);

    // if we are currently grounded, adapt the x of cVel to
    // move along the platform
    if (!action->isGrounded(*this)) {
        if (actionState != ESCAPEAIR) {
            cVel.x =
                sign(cVel.x) * std::min(std::abs(cVel.x),
                                        getAttribute("max_aerial_h_velocity"));
        }
    }

    velocity = cVel + kVel;

    if (action->isGrounded(*this)) {
        currentCollision->playerModified.heightBottom = -PLAYER_ECB_OFFSET.y;
        currentCollision->postCollision.heightBottom = -PLAYER_ECB_OFFSET.y;
        currentCollision->playerModified.setOrigin(position +
                                                   PLAYER_ECB_OFFSET);
        currentCollision->postCollision.setOrigin(position + PLAYER_ECB_OFFSET);
    } else if (ecbFixedCounter > 0) {
        ecbFixedCounter--;
        currentCollision->playerModified.heightBottom =
            -PLAYER_ECB_OFFSET.y + ecbBottomFixedSize;
        currentCollision->postCollision.heightBottom =
            -PLAYER_ECB_OFFSET.y + ecbBottomFixedSize;
    }

    float animationTime = timer * 1.0f / 60;
    model->applyAnimation(
        "unnamed_0",
        (float)fmod(animationTime, model->getAnimationDuration("anima_0")));
}

// void Player::physics() {
//     if(hitlagFrames > 0) {
//         hitlagFrames--;

//         // launch the player
//         if (hitlagFrames == 0) {
//             // launch();
//         // while in hitlag (freeze frames, perform SDI)
//         } else {
//             // sdi();
//         }
//     }
// }

/** Fall the player slowly, and allow the player to fastfall */
void Player::fall(bool fast) {
    if (fastfalled)
        return;
    cVel.y += getAttribute("gravity");
    cVel.y = std::min(cVel.y, getAttribute("terminal_velocity"));

    if (fast || (input->axis(MOVEMENT_AXIS_Y) > 0.65 &&
                 input->axis(MOVEMENT_AXIS_Y, 3) < 0.1 && cVel.y > 0)) {
        std::cout << "fastfalling" << std::endl;
        fastfalled = true;
        cVel.y = getAttribute("fast_fall_terminal_velocity");
    }
}

void Player::fallOffPlatform() {
    currentPlatform = NULL;
    changeAction(FALL);
}

void Player::grabLedge(Ledge const* l) {
    currentLedge = l;
    changeAction(CLIFFCATCH);
}

bool Player::canGrabLedge() const {
    return ledgeRegrabCounter <= 0 && action->canGrabLedge(*this);
}

bool Player::canLand(const Platform* p) const {
    return action->isLandable(*this, p);
};

bool Player::canFallOff() const {
    return action->canWalkOff(*this);
}

/** Transition from falling to being on ground
    Determine what state to enter from the state we are in */
void Player::land(const Platform* p) {
    double yvel = cVel.y;
    cVel.y = 0;
    grounded = true;
    fastfalled = false;
    times_jumped = 0;

    currentPlatform = p;
    printf("landing on %p\n", (void*)p);

    currentCollision->postCollision.heightBottom = -PLAYER_ECB_OFFSET.y;

    switch (action->getLandType(*this)) {
        case NORMAL_LANDING:
            // Trigger landing when velocity > 1
            std::cout << "cVel : " << yvel << std::endl;
            changeAction(yvel > 1 ? LANDING : WAIT);
            break;
        case KNOCKDOWN_LANDING:
            std::cout << "knockdown_landing not handled!" << std::endl;
            // TODO check the tech buffer
            break;
        case SPECIAL_LANDING:
            std::cout << "special landing.." << std::endl;
            action->onLanding(*this);
            break;
    }
}

Ecb Player::getLandedEcb(const Platform* p) const {
    Ecb tmp = currentCollision->postCollision;
    tmp.heightBottom = -PLAYER_ECB_OFFSET.y;
    return tmp;
}

/** Move the player horizontally when they are in the air */
void Player::aerialDrift() {
    bool joystickMoving = std::abs(input->axis(MOVEMENT_AXIS_X)) > 0.3;
    float inputDrift = (joystickMoving)
                           ? input->axis(MOVEMENT_AXIS_X) *
                                 getAttribute("max_aerial_h_velocity")
                           : 0;

    // std::cout << inputDrift << " ";

    // if the player is moving more than inputDrift, slow then with air friction
    if (std::abs(inputDrift) > std::abs(cVel.x) &&
        sign(cVel.x) == sign(inputDrift)) {
        // std::cout << "too fast, dragging";
        if (cVel.x > 0) {
            cVel.x = std::max(cVel.x - getAttribute("air_friction"), 0.0);
        } else {
            cVel.x = std::min(cVel.x + getAttribute("air_friction"), 0.0);
        }
    }

    // otherwise, move them according to their aerial mobility
    else if (joystickMoving) {
        // std::cout << "moving according to mobility";
        cVel.x +=
            input->axis(MOVEMENT_AXIS_X) * getAttribute("aerial_mobility") +
            sign(input->axis(MOVEMENT_AXIS_X)) *
                getAttribute("aerial_stopping_mobility");
    }

    // if the joystick is not moving, slow the player down with aerial friciton
    if (!joystickMoving) {
        // std::cout << "not moving, slowing with friction";
        if (cVel.x > 0) {
            cVel.x = std::max(cVel.x - getAttribute("air_friction"), 0.0);
        } else {
            cVel.x = std::min(cVel.x + getAttribute("air_friction"), 0.0);
        }
    }
    // std::cout << std::endl;
}

void Player::changeAction(ActionState state) {
    std::cout << "change to state [" << state << "] "
              << "(" << actionStateName(state) << ")" << std::endl;
    timer = 0;
    action = ACTIONS[state];
    action->step(*this);
    actionState = state;
}

void Player::fixEcbBottom(int frames, double size) {
    ecbFixedCounter = frames;
    ecbBottomFixedSize = size;
}

ActionState Player::getActionState() const {
    return actionState;
}

Action* Player::getAction() const {
    return action;
}

bool Player::isGrounded() const {
    return action->isGrounded(*this);
}

double Player::getXInput(int frames) const {
    return input->axis(MOVEMENT_AXIS_X, frames) * face;
}

const Platform* Player::getCurrentPlatform() const {
    return currentPlatform;
}

const PlatformSegment Player::getCurrentPlatformSegment() const {
    int seg = currentPlatform->getSegmentIndexByLocation(position);
    return PlatformSegment(currentPlatform, seg);
}

void Player::setPosition(Pair newPosition) {
    position = newPosition;
    currentCollision->postCollision.setOrigin(position + PLAYER_ECB_OFFSET);
}

double Player::getAttribute(char const* name) const {
    return config->getAttribute(name);
}

AbstractRenderer* Player::getRenderer() {
    return multiRenderer;
}
