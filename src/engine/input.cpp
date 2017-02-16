#include "input.hpp"
#include <SDL.h>
#include <iostream>

Input::Input() {}

Input::~Input() {
    if (this->joysticks != nullptr) {
        for (size_t i = 0; i < num_joysticks; i++) {
            delete this->joysticks[i];
        }
        delete[](this->joysticks);
    }
}

void Input::init() {
    num_joysticks = SDL_NumJoysticks();
    if (num_joysticks == 0) {
        std::cout << "Warning: no joysticks connected!" << std::endl;
        return;
    }
    std::cout << "found " << num_joysticks << " joystick(s)" << std::endl;

    this->joysticks = new Joystick*[num_joysticks];

    for (size_t i = 0; i < num_joysticks; i++) {
        SDL_Joystick* gGameController = SDL_JoystickOpen(0);
        if (gGameController == nullptr) {
            std::cout << "Warning: Unable to open game controller! SDL Error: "
                      << SDL_GetError() << std::endl;
            joysticks[i] = nullptr;
        } else {
            joysticks[i] = new Joystick(gGameController);
        }
    }
}

void Input::clear() {
    for (size_t i = 0; i < num_joysticks; i++) {
        Joystick* j = joysticks[i];
        if (j != nullptr) {
            j->clear();
        }
    }
}

void Input::processEvent(SDL_Event* evt) {
    if (evt->type == SDL_JOYAXISMOTION) {
        Joystick* j = joysticks[evt->jaxis.which];
        if (j != nullptr)
            j->setAxis(evt->jaxis.axis, evt->jaxis.value);
    } else if (evt->type == SDL_JOYBUTTONDOWN) {
        Joystick* j = joysticks[evt->jbutton.which];
        if (j != nullptr)
            j->setDown(evt->jbutton.button);
    } else if (evt->type == SDL_JOYBUTTONUP) {
        Joystick* j = joysticks[evt->jbutton.which];
        if (j != nullptr)
            j->setUp(evt->jbutton.button);
    }
}

Joystick* Input::getJoystick(unsigned int joystickId) {
    return this->joysticks[joystickId];
}

Joystick::Joystick(SDL_Joystick* controller, int historySize) {
    this->controller = controller;
    this->historySize = historySize;

    // find out num buttons
    if (SDL_JoystickNumButtons(controller) > 64) {
        std::cout << "Warning: no support for controllers with >64 buttons"
                  << std::endl;
    }

    // find out num axies
    num_axies = SDL_JoystickNumAxes(controller);
    if (num_axies > 64) {
        std::cout << "Warning: no support for controllers with >64 axies"
                  << std::endl;
    }

    // initialize and zero axies values
    axies = new double*[historySize];
    for (size_t i = 0; i < historySize; i++) {
        axies[i] = new double[num_axies];
        for (size_t y = 0; y < num_axies; y++) {
            axies[i][y] = 0;
        }
    }

    axisCalibrations = new AxisCalibration[num_axies];
    for (size_t i = 0; i < num_axies; i++) {
        axisCalibrations[i].enabled = false;
    }

    heldMask = new uint64_t[historySize];
    downMask = new uint64_t[historySize];
    upMask = new uint64_t[historySize];

    for (size_t i = 0; i < historySize; i++) {
        heldMask[i] = 0;
        downMask[i] = 0;
        upMask[i] = 0;
    }
}

Joystick::~Joystick() {
    delete[] heldMask;
    delete[] downMask;
    delete[] upMask;
    for (size_t i = 0; i < num_axies; i++) {
        delete[] axies[i];
    }
    delete[] axies;
}

void Joystick::calibrateAxis(unsigned int axisId,
                             double lower,
                             double upper,
                             double neutral) {
    axisCalibrations[axisId].enabled = true;
    axisCalibrations[axisId].upper = upper;
    axisCalibrations[axisId].lower = lower;
    axisCalibrations[axisId].neutral = neutral;
}

void Joystick::setDown(unsigned int buttonId) {
    downMask[currentHistory] |= 1 << buttonId;
    heldMask[currentHistory] |= 1 << buttonId;
}

void Joystick::setUp(unsigned int buttonId) {
    upMask[currentHistory] &= ~(1 << buttonId);
    heldMask[currentHistory] &= ~(1 << buttonId);
}

void Joystick::clear() {
    size_t oldHistory = currentHistory;

    currentHistory = (currentHistory + 1) % historySize;
    downMask[currentHistory] = 0;
    upMask[currentHistory] = 0;

    heldMask[currentHistory] = heldMask[oldHistory];
    for (size_t i = 0; i < num_axies; i++) {
        axies[currentHistory][i] = axies[oldHistory][i];
    }
}

bool Joystick::held(unsigned int buttonId, int framesBack) {
    size_t frame = ((currentHistory - framesBack) + historySize) % historySize;
    return (heldMask[frame] >> buttonId) & 1;
}

bool Joystick::down(unsigned int buttonId, int framesBack) {
    size_t frame = ((currentHistory - framesBack) + historySize) % historySize;
    return (downMask[frame] >> buttonId) & 1;
}

bool Joystick::up(unsigned int buttonId, int framesBack) {
    size_t frame = ((currentHistory - framesBack) + historySize) % historySize;
    return (upMask[frame] >> buttonId) & 1;
}

void Joystick::setAxis(unsigned int axisId, double value) {
    axies[currentHistory][axisId] = value;
}

double Joystick::axis(unsigned int axisId, int framesBack) {
    size_t frame = ((currentHistory - framesBack) + historySize) % historySize;
    if (axisId < 0 || axisId > num_axies) {
        std::cout << "Warning: axis " << axisId << " out of range" << std::endl;
        return 0;
    }
    AxisCalibration* calibration = &axisCalibrations[axisId];
    if (calibration->enabled) {
        double denom = (axies[frame][axisId] > calibration->neutral)
                           ? (calibration->upper - calibration->neutral)
                           : (calibration->neutral - calibration->lower);
        return (this->axies[frame][axisId] - calibration->neutral) / denom;
    } else {
        return 0;
    }
}
