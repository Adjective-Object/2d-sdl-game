#include "player.hpp"
#include "engine/game.hpp"
#include <iostream>
#include <algorithm>

double DEADZONE = 0.2;
double LIMIT_WALK_SLOW_UPPER = 0.4;
double LIMIT_WALK_MIDDLE_UPPER = 0.6;
double LIMIT_WALK_FAST_UPPER = 0.8;

int LIMIT_LOW = -30000;
int LIMIT_HIGH = 32800;
int NEUTRAL = 450;

double slow = 0.1;
double med = 0.6;
double fast = 2;

Player::Player() {
    acceleration.y = 1;
    maxVelocity.y = 40;
    drag.x = 1;
    drag.y = 1;
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
    int x = joystick->axis(0);
    #define somelim(limit_percent,control_edge,neutral) \
        (limit_percent * (control_edge + neutral)) + neutral

    if (x < somelim(LIMIT_WALK_MIDDLE_UPPER, LIMIT_LOW, NEUTRAL)) {
        maxVelocity.x = fast;
        acceleration.x = -fast;
    } else if (x < somelim(LIMIT_WALK_SLOW_UPPER, LIMIT_LOW, NEUTRAL)) {
        maxVelocity.x = med;
        acceleration.x = -med;
    } else if (x < somelim(DEADZONE, LIMIT_LOW, NEUTRAL)) {
        maxVelocity.x = slow;
        acceleration.x = -slow;
    } else if (x < somelim(DEADZONE, LIMIT_HIGH, NEUTRAL)) {
        maxVelocity.x = slow;
        acceleration.x = 0;
    } else if (x < somelim(LIMIT_WALK_SLOW_UPPER, LIMIT_HIGH, NEUTRAL)) {
        maxVelocity.x = slow;
        acceleration.x = slow;
    } else if (x < somelim(LIMIT_WALK_MIDDLE_UPPER, LIMIT_HIGH, NEUTRAL)) {
        maxVelocity.x = med;
        acceleration.x = med;
    } else {
        maxVelocity.x = fast;
        acceleration.x = fast;
    }

    if (position.y > 300) {
        position.y = 300;
        velocity.y = std::min(0.0, velocity.y);
    }

    maxVelocity.x *= 5;

    Sprite::updateMotion();

}

void Player::render(SDL_Renderer * ren) {
    Sprite::render(ren);
}
