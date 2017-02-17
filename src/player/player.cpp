#include "player.hpp"
#include "../engine/game.hpp"
#include "../util.hpp"
#include "action.hpp"
#include "playerconfig.hpp"
#include <algorithm>
#include <iostream>

Player::Player(std::string fpath, double x, double y)
    : config(PlayerConfig(fpath)) {
    action = ACTIONS[FALL];
    position.x = x;
    position.y = y;
}

Player::~Player() {}

void Player::init() {
    std::cout << "init player" << std::endl;
    joystick = EnG->input.getJoystick(0);
    bank = new AnimationBank();
    changeAction(FALL);
}

void Player::update() {
    Sprite::update();

    timer++;
    action->step(*this);

    velocity = cVel + kVel;
    Sprite::updateMotion();
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
void Player::fall() {
    if (fastfalled)
        return;
    cVel.y += config.getAttribute("gravity");
    cVel.y = std::min(cVel.y, config.getAttribute("terminal_velocity"));

    if (joystick->axis(1) > 0.65 && joystick->axis(1, 3) < 0.1 && cVel.y > 0) {
        std::cout << "fastfalling" << std::endl;
        fastfalled = true;
        cVel.y = config.getAttribute("fast_fall_terminal_velocity");
    }
}

/** Transition from falling to being on ground
    Determine what state to enter from the state we are in */
void Player::land(double y) {
    double yvel = cVel.y;
    position.y = y;
    cVel.y = 0;
    grounded = true;
    fastfalled = false;
    times_jumped = 0;

    switch (action->getLandType(*this)) {
        case NORMAL:
            // Trigger landing when velocity > 1
            std::cout << "cVel : " << yvel << std::endl;
            changeAction(yvel > 1 ? LANDING : WAIT);
            break;
        case KNOCKDOWN:
            // TODO check the tech buffer
            break;
        case SPECIAL:
            action->onLanding(*this);
            break;
    }
}

/** Move the player horizontally when they are in the air */
void Player::aerialDrift() {
    bool joystickMoving = std::abs(joystick->axis(0)) > 0.3;
    float inputDrift =
        (joystickMoving)
            ? joystick->axis(0) * config.getAttribute("max_aerial_h_velocity")
            : 0;

    // std::cout << inputDrift << " ";

    // if the player is moving more than inputDrift, slow then with air friction
    if (abs(inputDrift) > abs(cVel.x) && sign(cVel.x) == sign(inputDrift)) {
        // std::cout << "too fast, dragging";
        if (cVel.x > 0) {
            cVel.x =
                std::max(cVel.x - config.getAttribute("air_friction"), 0.0);
        } else {
            cVel.x =
                std::min(cVel.x + config.getAttribute("air_friction"), 0.0);
        }
    }

    // otherwise, move them according to their aerial mobility
    else if (joystickMoving) {
        // std::cout << "moving according to mobility";
        cVel.x += joystick->axis(0) * config.getAttribute("aerial_mobility") +
                  sign(joystick->axis(0)) *
                      config.getAttribute("aerial_stopping_mobility");
    }

    // if the joystick is not moving, slow the player down with aerial friciton
    if (!joystickMoving) {
        // std::cout << "not moving, slowing with friction";
        if (cVel.x > 0) {
            cVel.x =
                std::max(cVel.x - config.getAttribute("air_friction"), 0.0);
        } else {
            cVel.x =
                std::min(cVel.x + config.getAttribute("air_friction"), 0.0);
        }
    }
    // std::cout << std::endl;
}

void Player::render(SDL_Renderer* ren) {
    SDL_Rect destination{(int)(position.x * PLAYER_SCALE) - 64,
                         (int)(position.y * PLAYER_SCALE) - 110, 128, 128};
    SDL_RenderCopyEx(ren, bank->getCurrentTexture(*this), NULL, &destination,
                     NULL, NULL,
                     face < 0 ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
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

ActionState Player::getActionState() {
    return actionState;
}

double Player::getXInput(int frames) {
    return joystick->axis(frames) * face;
}