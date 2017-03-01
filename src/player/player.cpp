#include "player.hpp"
#include "../engine/game.hpp"
#include "../util.hpp"
#include "constants.hpp"
#include "action.hpp"
#include "playerconfig.hpp"
#include "inputhandler.hpp"
#include <algorithm>
#include <iostream>

using namespace InputMapping;

Player::Player(PlayerConfig* config,
               InputHandler* input,
               AnimationBank* animationBank,
               Pair initialPosition)
    : bank(animationBank), input(input), config(config) {
    position = initialPosition;
    previousCollision->reset(position + PLAYER_ECB_OFFSET);
    currentCollision->reset(position + PLAYER_ECB_OFFSET);
    changeAction(FALL);
}

Player::~Player() {}

void Player::init() {}

void Player::moveTo(Pair newPos) {
    position = newPos;
    currentCollision->reset(position + PLAYER_ECB_OFFSET);
}

void Player::moveTo(Ecb& ecb) {
    position = ecb.origin - PLAYER_ECB_OFFSET;
    currentCollision->reset(ecb);
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
    } else if (ecbFixedCounter > 0) {
        ecbFixedCounter--;
        currentCollision->playerModified.heightBottom =
            -PLAYER_ECB_OFFSET.y + ecbBottomFixedSize;
        currentCollision->postCollision.heightBottom =
            -PLAYER_ECB_OFFSET.y + ecbBottomFixedSize;
    }
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

void Player::grabLedge(Ledge* l) {
    currentLedge = l;
    changeAction(CLIFFCATCH);
}

bool Player::canGrabLedge() {
    return ledgeRegrabCounter <= 0 && action->canGrabLedge(*this);
}

bool Player::canLand(Platform* p) {
    return action->isLandable(*this, p);
};

/** Transition from falling to being on ground
    Determine what state to enter from the state we are in */
void Player::land(Platform* p) {
    double yvel = cVel.y;
    cVel.y = 0;
    grounded = true;
    fastfalled = false;
    times_jumped = 0;

    currentPlatform = p;
    printf("landing on %p\n", p);

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

/** Move the player horizontally when they are in the air */
void Player::aerialDrift() {
    bool joystickMoving = std::abs(input->axis(MOVEMENT_AXIS_X)) > 0.3;
    float inputDrift = (joystickMoving)
                           ? input->axis(MOVEMENT_AXIS_X) *
                                 getAttribute("max_aerial_h_velocity")
                           : 0;

    // std::cout << inputDrift << " ";

    // if the player is moving more than inputDrift, slow then with air friction
    if (abs(inputDrift) > abs(cVel.x) && sign(cVel.x) == sign(inputDrift)) {
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

void Player::render(SDL_Renderer* ren) {
    SDL_SetRenderDrawColor(ren, 255, 215, 0, 255);
    previousCollision->postCollision.render(ren, PLAYER_SCALE);

    SDL_SetRenderDrawColor(ren, 255, 127, 80, 255);
    currentCollision->postCollision.render(ren, PLAYER_SCALE);

    SDL_Rect destination{(int)(position.x * PLAYER_SCALE) - 64,
                         (int)(position.y * PLAYER_SCALE) - 110, 128, 128};
    SDL_RenderCopyEx(ren, bank->getCurrentTexture(*this), NULL, &destination, 0,
                     NULL, face < 0 ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);

    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    // SDL_RenderDrawRect(ren, &destination);

    SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
    SDL_RenderDrawLine(ren, ((int)(position.x * PLAYER_SCALE)) - 3,
                       ((int)(position.y * PLAYER_SCALE)),
                       ((int)(position.x * PLAYER_SCALE)) + 3,
                       ((int)(position.y * PLAYER_SCALE)));
    SDL_RenderDrawLine(ren, ((int)(position.x * PLAYER_SCALE)),
                       ((int)(position.y * PLAYER_SCALE)) - 3,
                       ((int)(position.x * PLAYER_SCALE)),
                       ((int)(position.y * PLAYER_SCALE)) + 3);

    SDL_SetRenderDrawColor(ren, 100, 255, 100, 255);
    SDL_Rect ledgeGrabBox = {
        ((int)(position.x * PLAYER_SCALE)),
        ((int)((position.y - LEDGEBOX_BASE) * PLAYER_SCALE)),
        ((int)((face * LEDGEBOX_WIDTH) * PLAYER_SCALE)),
        ((int)((-LEDGEBOX_HEIGHT) * PLAYER_SCALE))};
    SDL_RenderDrawRect(ren, &ledgeGrabBox);
}

void Player::changeAction(ActionState state) {
    std::cout << "change to state [" << state << "] "
              << "(" << actionStateName(state) << ")" << std::endl;
    timer = 0;
    action = ACTIONS[state];
    bank->playAnimation(state);
    action->step(*this);
    actionState = state;
}

void Player::fixEcbBottom(int frames, double size) {
    ecbFixedCounter = frames;
    ecbBottomFixedSize = size;
}

ActionState Player::getActionState() {
    return actionState;
}

Action* Player::getAction() {
    return action;
}

bool Player::isGrounded() {
    return action->isGrounded(*this);
}

double Player::getXInput(int frames) {
    return input->axis(MOVEMENT_AXIS_X, frames) * face;
}

Platform* Player::getCurrentPlatform() {
    return currentPlatform;
}

void Player::setPosition(Pair newPosition) {
    position = newPosition;
    currentCollision->postCollision.setOrigin(position + PLAYER_ECB_OFFSET);
}

double Player::getAttribute(char const* name) {
    return config->getAttribute(name);
}
