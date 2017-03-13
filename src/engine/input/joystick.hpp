#ifndef __ENGINE_JOYSTICK
#define __ENGINE_JOYSTICK
#include <SDL.h>
#include <stdint.h>

class Input;

typedef struct AxisCalibration {
    bool enabled = false;
    double lower = 0;
    double upper = 0;
    double neutral = 0;
} AxisCalibration;

class Joystick {
    friend Input;
    SDL_Joystick* controller;

    size_t historySize;
    size_t currentHistory = 0;
    uint64_t* heldMask;
    uint64_t* downMask;
    uint64_t* upMask;

    size_t num_axies;
    double** axies;
    AxisCalibration* axisCalibrations;

   public:
    void setDown(unsigned int buttonId);
    void setUp(unsigned int buttonId);
    void clear();
    void setAxis(unsigned int axisId, double value);
    size_t numAxies();

    Joystick(int numButtons, int numAxies, size_t historySize = 10);
    ~Joystick();
    void calibrateAxis(unsigned int axisId,
                       double lower,
                       double upper,
                       double neutral);
    bool up(unsigned int buttonId, int framesBack = 0);
    bool down(unsigned int buttonId, int framesBack = 0);
    bool held(unsigned int buttonId, int framesBack = 0);
    double axis(unsigned int axisId, int framesBack = 0);
};

#endif
