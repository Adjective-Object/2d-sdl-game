#ifndef __ENGINE_INPUT
#define __ENGINE_INPUT

#include <SDL.h>
#include <vector>

class Input;
class Joystick;

class Input {
    Joystick ** joysticks = nullptr;
    size_t num_joysticks;
public:
    Input();
    ~Input();
    void init();
    void clear();
    void processEvent(SDL_Event *);
    Joystick * getJoystick(unsigned int id);
};

typedef struct AxisCalibration {
    bool enabled = false;
    double lower = 0;
    double upper = 0;
    double neutral = 0;
} AxisCalibration;

class Joystick {
    friend Input;
    SDL_Joystick * controller;

    uint64_t heldMask = 0;
    uint64_t downMask = 0;
    uint64_t upMask = 0;

    size_t num_axies;
    double * axies;
    AxisCalibration * axisCalibrations;

    void setDown(unsigned int buttonId);
    void setUp(unsigned int buttonId);
    void clear();
    void setAxis(unsigned int axisId, double value);
public:
    Joystick(SDL_Joystick *);
    ~Joystick();
    void calibrateAxis(
        unsigned int axisId,
        double lower,
        double upper,
        double neutral);
    bool up(unsigned int buttonId);
    bool down(unsigned int buttonId);
    bool held(unsigned int buttonId);
    double axis(unsigned int axisId);
};

#endif
