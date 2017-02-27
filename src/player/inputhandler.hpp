#ifndef __GAME_INPUT_MANAGER
#define __GAME_INPUT_MANAGER
#include "engine/input.hpp"

namespace InputMapping {

typedef enum BUTTON {
    ATTACK,
    SPECIAL,
    START,
    JUMP,
    SHIELD_BUTTON,
    DIRECTIONAL_UP,
    DIRECTIONAL_DOWN,
    DIRECTIONAL_LEFT,
    DIRECTIONAL_RIGHT,
    __NUM_BUTTONS
} BUTTON;

typedef enum AXIS {
    MOVEMENT_AXIS_X,
    MOVEMENT_AXIS_Y,
    ATTACK_AXIS_X,
    ATTACK_AXIS_Y,
    SHIELD_AXIS,
    __NUM_AXIES
} AXIS;

typedef struct BUTTON_MAPPING {
    int physicalButtonId;
    BUTTON virtualButtonId;
} BUTTON_MAPPING;

typedef struct AXIS_MAPPING {
    int physicalAxisId;
    AXIS virtualAxisId;
} AXIS_MAPPING;

class InputHandler {
   public:
    virtual bool up(BUTTON buttonId, int framesBack = 0) = 0;
    virtual bool down(BUTTON buttonId, int framesBack = 0) = 0;
    virtual bool held(BUTTON buttonId, int framesBack = 0) = 0;
    virtual double axis(AXIS axisId, int framesBack = 0) = 0;
};

class JoystickInputHandler : public InputHandler {
    Joystick virtualJoystick = Joystick(__NUM_BUTTONS, __NUM_AXIES, 10);

   public:
    JoystickInputHandler();
    void step(Joystick* j);
    bool up(BUTTON buttonId, int framesBack = 0) override;
    bool down(BUTTON buttonId, int framesBack = 0) override;
    bool held(BUTTON buttonId, int framesBack = 0) override;
    double axis(AXIS axisId, int framesBack = 0) override;
};
}

#endif
