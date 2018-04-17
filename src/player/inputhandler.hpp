#ifndef __GAME_INPUT_MANAGER
#define __GAME_INPUT_MANAGER
#include "engine/input/input.hpp"

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

extern BUTTON_MAPPING gamecubeButtons[];
extern AXIS_MAPPING gamecubeAxies[];

class InputHandler {
   protected:
    Joystick virtualJoystick = Joystick(__NUM_BUTTONS, __NUM_AXIES, 10);

   public:
    InputHandler();
    virtual void step() = 0;
    virtual bool up(BUTTON buttonId, int framesBack = 0);
    virtual bool down(BUTTON buttonId, int framesBack = 0);
    virtual bool held(BUTTON buttonId, int framesBack = 0);
    virtual double axis(AXIS axisId, int framesBack = 0);
};

class JoystickInputHandler : public InputHandler {
    BUTTON_MAPPING* buttonMap;
    AXIS_MAPPING* axisMap;
    Joystick* j;

   public:
    JoystickInputHandler(BUTTON_MAPPING* b, AXIS_MAPPING* a, Joystick* j);
    void step() override;
};

typedef struct KEYBOARD_MAPPING {
    int keysym;
    BUTTON virtualButtonId;
} KEYBOARD_MAPPING;

typedef struct KEYBOARD_AXIS_MAPPING {
    int keysym;
    AXIS virtualAxisId;
    double value;
} KEYBOARD_AXIS_MAPPING;

extern KEYBOARD_MAPPING gamecubeKeys[];
extern KEYBOARD_AXIS_MAPPING gamecubeKeyAxies[];

class KeyboardInputHandler : public InputHandler {
    KEYBOARD_MAPPING* keyMap;
    KEYBOARD_AXIS_MAPPING* keyAxisMap;
    Keyboard* k;

   public:
    KeyboardInputHandler(KEYBOARD_MAPPING* keyMap,
                         KEYBOARD_AXIS_MAPPING* keyAxisMap,
                         Keyboard* k);
    void step() override;
};
}  // namespace InputMapping

#endif
