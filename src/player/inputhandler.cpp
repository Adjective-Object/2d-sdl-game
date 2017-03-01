#include "inputhandler.hpp"
#include "engine/input.hpp"

using namespace InputMapping;

BUTTON_MAPPING buttonMap[] = {
    {0, ATTACK},        {1, JUMP},          {2, JUMP},    {7, START},
    {4, SHIELD_BUTTON}, {5, SHIELD_BUTTON}, {3, SPECIAL},
};

AXIS_MAPPING axisMap[] = {
    {0, MOVEMENT_AXIS_X}, {1, MOVEMENT_AXIS_Y}, {2, ATTACK_AXIS_X},
    {3, ATTACK_AXIS_Y},   {4, SHIELD_AXIS},     {5, SHIELD_AXIS},
};

JoystickInputHandler::JoystickInputHandler() {
    virtualJoystick.calibrateAxis(MOVEMENT_AXIS_X, -1, 1, 0);
    virtualJoystick.calibrateAxis(MOVEMENT_AXIS_Y, -1, 1, 0);
    virtualJoystick.calibrateAxis(ATTACK_AXIS_Y, -1, 1, 0);
    virtualJoystick.calibrateAxis(ATTACK_AXIS_X, -1, 1, 0);
    virtualJoystick.calibrateAxis(SHIELD_AXIS, -1, 1, 0);
}

void JoystickInputHandler::step(Joystick* j) {
    virtualJoystick.clear();
    for (size_t i = 0; i < sizeof(buttonMap) / sizeof(BUTTON_MAPPING); i++) {
        BUTTON_MAPPING mapping = buttonMap[i];
        if (j->down(mapping.physicalButtonId)) {
            virtualJoystick.setDown(mapping.virtualButtonId);
        } else {
            virtualJoystick.setUp(mapping.virtualButtonId);
        }
    }

    for (size_t i = 0; i < sizeof(axisMap) / sizeof(AXIS_MAPPING); i++) {
        virtualJoystick.setAxis(axisMap[i].virtualAxisId,
                                j->axis(axisMap[i].physicalAxisId));
    }
}

bool JoystickInputHandler::up(BUTTON buttonId, int framesBack) {
    return virtualJoystick.up(buttonId, framesBack);
}

bool JoystickInputHandler::down(BUTTON buttonId, int framesBack) {
    return virtualJoystick.down(buttonId, framesBack);
}

bool JoystickInputHandler::held(BUTTON buttonId, int framesBack) {
    return virtualJoystick.held(buttonId, framesBack);
}

double JoystickInputHandler::axis(AXIS axisId, int framesBack) {
    return virtualJoystick.axis(axisId, framesBack);
}
