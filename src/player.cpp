#include <iostream>
#include <algorithm>
#include "engine/game.hpp"
#include "playerconfig.hpp"
#include "player.hpp"

double DEADZONE = 0.2;
double LIMIT_WALK_SLOW_UPPER = 0.4;
double LIMIT_WALK_MIDDLE_UPPER = 0.6;
double LIMIT_WALK_FAST_UPPER = 0.8;

double slow = 0.1;
double med = 0.6;
double fast = 2;

Player::Player(std::string fpath) :
    config(PlayerConfig(fpath)) {
    acceleration.y = 1;
    maxVelocity.y = 40;
}

Player::~Player() {

}

void Player::init() {
    joystick = EnG->input.getJoystick(0);
}

void Player::update() {
    Sprite::update();
    if (joystick->down(1) || joystick->down(2)) {
        this->velocity.y = -20;
    }
    double x = joystick->axis(0);

    if (x < -LIMIT_WALK_MIDDLE_UPPER) {
        maxVelocity.x = fast;
        acceleration.x = -fast;
    } else if (x < -LIMIT_WALK_SLOW_UPPER) {
        maxVelocity.x = med;
        acceleration.x = -med;
    } else if (x < -DEADZONE) {
        maxVelocity.x = slow;
        acceleration.x = -slow;
    } else if (x < DEADZONE) {
        maxVelocity.x = DOUBLE_INFINITY;
        acceleration.x = 0;
    } else if (x < LIMIT_WALK_SLOW_UPPER) {
        maxVelocity.x = slow;
        acceleration.x = slow;
    } else if (x < LIMIT_WALK_MIDDLE_UPPER) {
        maxVelocity.x = med;
        acceleration.x = med;
    } else {
        maxVelocity.x = fast;
        acceleration.x = fast;
    }

    // trigger landing
    // TODO this is just to fake collision with terrain
    if (position.y > 300) {
        position.y = 300;
        velocity.y = std::min(0.0, velocity.y);
    }

    Sprite::updateMotion();

}

void Player::render(SDL_Renderer * ren) {
    Sprite::render(ren);
}
