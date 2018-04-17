#include "joystickindicator.hpp"
#include "game.hpp"

JoystickIndicator::JoystickIndicator(int axis1,
                                     int axis2,
                                     int x,
                                     int y,
                                     int width,
                                     int height)
    : axis1(axis1), axis2(axis2), x(x), y(y), width(width), height(height) {
    joystick = EnG->input.getJoystick(0);
}

void JoystickIndicator::init() {}
void JoystickIndicator::preUpdate() {}
void JoystickIndicator::update() {}
void JoystickIndicator::postUpdate() {}
