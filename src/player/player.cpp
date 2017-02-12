#include <iostream>
#include <algorithm>
#include "../engine/game.hpp"
#include "playerconfig.hpp"
#include "player.hpp"
#include "action.hpp"
#include "../util.hpp"

double DEADZONE = 0.2;
double LIMIT_WALK_SLOW_UPPER = 0.4;
double LIMIT_WALK_MIDDLE_UPPER = 0.6;
double LIMIT_WALK_FAST_UPPER = 0.8;

double slow = 0.1;
double med = 0.6;
double fast = 2;

Player::Player(std::string fpath) :
    config(PlayerConfig(fpath)) {
    action = ACTIONS[FALL];
} 

Player::~Player() {

}

void Player::init() {
    joystick = EnG->input.getJoystick(0);
}

void Player::update() {
    Sprite::update();

    timer++;
    action->step(*this);

    velocity = cVel + kVel;
    Sprite::updateMotion();

    if (velocity.y > 0 && position.y > 0.6) {
        this->land(0.6);
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
void Player::fall() {
    if (fastfalled) return;
    cVel.y += config.getAttribute("gravity");
    cVel.y = std::min(cVel.y, config.getAttribute("terminal_velocity"));

    std::cout << joystick->axis(1) << ", " << joystick->axis(1, 3) << std::endl;
    if (joystick->axis(1) > 0.65 && joystick->axis(1, 3) < 0.1 && std::abs(cVel.y > -0.1)) {
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
    
    switch(action->getLandType(*this)) {
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
    float inputDrift = (joystickMoving)
        ? joystick->axis(0) * config.getAttribute("max_aerial_h_velocity")
        : 0;

    // std::cout << inputDrift << " ";

    // if the player is moving more than inputDrift, slow then with air friction
    if (abs(inputDrift) > abs(cVel.x) && sign(cVel.x) == sign(inputDrift)) {
        // std::cout << "too fast, dragging";
        if (cVel.x > 0) {
          cVel.x = std::max(cVel.x - config.getAttribute("air_friction"), 0.0);
        } else {
          cVel.x = std::min(cVel.x + config.getAttribute("air_friction"), 0.0);
        }
    }

    // otherwise, move them according to their aerial mobility
    else if (joystickMoving) { 
        // std::cout << "moving according to mobility";
        cVel.x += 
            joystick->axis(0) * config.getAttribute("aerial_mobility") +
            sign(joystick->axis(0)) * config.getAttribute("aerial_stopping_mobility");
    }

    // if the joystick is not moving, slow the player down with aerial friciton
    if (!joystickMoving) {
        // std::cout << "not moving, slowing with friction";
        if (cVel.x > 0) {
            cVel.x = std::max(cVel.x - config.getAttribute("air_friction"), 0.0);
        } else {
            cVel.x = std::min(cVel.x + config.getAttribute("air_friction"), 0.0);
        }
    }
    // std::cout << std::endl;
}

void Player::render(SDL_Renderer * ren) {
    SDL_Rect destination {
        (int) (position.x * 400),
        (int) (position.y * 400),
        32,
        32
    };
    SDL_RenderCopy( ren, FALLBACK_TEXTURE, NULL, &destination );

}

void Player::changeAction(ActionState state) {
    std::cout << "change to state [" << state << "] "
              << "(" << actionStateName(state) << ")"
              << std::endl;
    timer = 0;
    action = ACTIONS[state];
    action->step(*this);
}