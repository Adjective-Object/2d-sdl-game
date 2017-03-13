#include "inputhandler.hpp"
#include "engine/input/input.hpp"
#include <iostream>

using namespace InputMapping;

InputHandler::InputHandler() {
    virtualJoystick.calibrateAxis(MOVEMENT_AXIS_X, -1, 1, 0);
    virtualJoystick.calibrateAxis(MOVEMENT_AXIS_Y, -1, 1, 0);
    virtualJoystick.calibrateAxis(ATTACK_AXIS_Y, -1, 1, 0);
    virtualJoystick.calibrateAxis(ATTACK_AXIS_X, -1, 1, 0);
    virtualJoystick.calibrateAxis(SHIELD_AXIS, -1, 1, 0);
}

BUTTON_MAPPING InputMapping::gamecubeButtons[] = {
    {0, ATTACK},        {1, JUMP},          {2, JUMP},    {7, START},
    {4, SHIELD_BUTTON}, {5, SHIELD_BUTTON}, {3, SPECIAL}, {-1, __NUM_BUTTONS}};

AXIS_MAPPING InputMapping::gamecubeAxies[] = {
    {0, MOVEMENT_AXIS_X}, {1, MOVEMENT_AXIS_Y}, {2, ATTACK_AXIS_X},
    {3, ATTACK_AXIS_Y},   {4, SHIELD_AXIS},     {5, SHIELD_AXIS},
    {-1, __NUM_AXIES}};

JoystickInputHandler::JoystickInputHandler(BUTTON_MAPPING* buttonMap,
                                           AXIS_MAPPING* axisMap,
                                           Joystick* j)
    : buttonMap{buttonMap}, axisMap{axisMap}, j(j) {}

void JoystickInputHandler::step() {
    virtualJoystick.clear();
    for (size_t i = 0;; i++) {
        BUTTON_MAPPING mapping = buttonMap[i];
        if (mapping.virtualButtonId == __NUM_BUTTONS)
            break;
        if (j->down(mapping.physicalButtonId)) {
            virtualJoystick.setDown(mapping.virtualButtonId);
        } else {
            virtualJoystick.setUp(mapping.virtualButtonId);
        }
    }

    for (size_t i = 0;; i++) {
        AXIS_MAPPING mapping = axisMap[i];
        if (mapping.virtualAxisId == __NUM_AXIES)
            break;
        virtualJoystick.setAxis(mapping.virtualAxisId,
                                j->axis(axisMap[i].physicalAxisId));
    }
}

bool InputHandler::up(BUTTON buttonId, int framesBack) {
    return virtualJoystick.up(buttonId, framesBack);
}

bool InputHandler::down(BUTTON buttonId, int framesBack) {
    return virtualJoystick.down(buttonId, framesBack);
}

bool InputHandler::held(BUTTON buttonId, int framesBack) {
    return virtualJoystick.held(buttonId, framesBack);
}

double InputHandler::axis(AXIS axisId, int framesBack) {
    return virtualJoystick.axis(axisId, framesBack);
}

KEYBOARD_MAPPING InputMapping::gamecubeKeys[] = {{SDLK_z, JUMP},
                                                 {-1, __NUM_BUTTONS}};

KEYBOARD_AXIS_MAPPING InputMapping::gamecubeKeyAxies[] = {
    {SDLK_LEFT, MOVEMENT_AXIS_X, -1.0},
    {SDLK_RIGHT, MOVEMENT_AXIS_X, +1.0},
    {SDLK_UP, MOVEMENT_AXIS_Y, -1.0},
    {SDLK_DOWN, MOVEMENT_AXIS_Y, +1.0},
    {-1, __NUM_AXIES},
};

KeyboardInputHandler::KeyboardInputHandler(KEYBOARD_MAPPING* keyMap,
                                           KEYBOARD_AXIS_MAPPING* keyAxisMap,
                                           Keyboard* k)
    : keyMap{keyMap}, keyAxisMap{keyAxisMap}, k(k) {}

std::ostream& operator<<(std::ostream& o, KEYBOARD_MAPPING& m) {
    return o << "{" << m.keysym << " => " << m.virtualButtonId << "}";
}

std::ostream& operator<<(std::ostream& o, KEYBOARD_AXIS_MAPPING& m) {
    return o << "{" << m.keysym << " => " << m.virtualAxisId << "@" << m.value
             << "}";
}

void KeyboardInputHandler::step() {
    virtualJoystick.clear();
    for (size_t i = 0;; i++) {
        KEYBOARD_MAPPING mapping = keyMap[i];
        if (mapping.virtualButtonId == __NUM_BUTTONS)
            break;
        if (k->down(mapping.keysym)) {
            virtualJoystick.setDown(mapping.keysym);
        } else {
            virtualJoystick.setUp(mapping.keysym);
        }
    }

    for (size_t i = 0; i < virtualJoystick.numAxies(); i++) {
        virtualJoystick.setAxis(i, 0);
    }

    for (size_t i = 0;; i++) {
        KEYBOARD_AXIS_MAPPING mapping = keyAxisMap[i];
        if (mapping.virtualAxisId == __NUM_AXIES)
            break;
        if (k->held(mapping.keysym)) {
            virtualJoystick.setAxis(mapping.virtualAxisId, mapping.value);
        }
    }
}
