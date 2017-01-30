#include <iostream>
#include <SDL.h>
#include "input.hpp"

Input::Input() {

}

Input::~Input() {
    if (this->joysticks != nullptr){
        for (size_t i=0; i<num_joysticks; i++) {
            delete this->joysticks[i];
        }
        delete[] (this->joysticks);
    }
}

void Input::init() {
    num_joysticks = SDL_NumJoysticks();
    if (num_joysticks == 0) {
        std::cout << "Warning: no joysticks connected!" << std::endl;
        return;
    }

    this->joysticks = new Joystick*[num_joysticks];

    for (size_t i=0; i<num_joysticks; i++) {
        SDL_Joystick * gGameController = SDL_JoystickOpen( 0 );
        if( gGameController == nullptr ) {
            std::cout << "Warning: Unable to open game controller! SDL Error: "
                 << SDL_GetError()
                 << std::endl;
            joysticks[i] = nullptr;
        } else {
            joysticks[i] = new Joystick(gGameController);
        }
    }
}

void Input::clear() {
    for (size_t i = 0; i<num_joysticks; i++) {
        Joystick * j = joysticks[i];
        if (j!=nullptr) {
            j->clear();
        }
    }
}

void Input::processEvent(SDL_Event * evt) {
    if (evt->type == SDL_JOYAXISMOTION) {
        Joystick * j = joysticks[evt->jaxis.which];
        if (j != nullptr) j->setAxis(evt->jaxis.axis, evt->jaxis.value);
    } else if (evt->type == SDL_JOYBUTTONDOWN) {
        Joystick * j = joysticks[evt->jbutton.which];
        if (j != nullptr) j->setDown(evt->jbutton.button);
    } else if (evt->type == SDL_JOYBUTTONUP) {
        Joystick * j = joysticks[evt->jbutton.which];
        if (j != nullptr) j->setUp(evt->jbutton.button);
    }
}

Joystick * Input::getJoystick(unsigned int joystickId) {
    return this->joysticks[joystickId];
}

Joystick::Joystick(SDL_Joystick * controller) {
    this->controller = controller;

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
    axies = new double[num_axies];
    for(size_t i=0; i<num_axies; i++) {
        axies[i] = 0;
    }
}

Joystick::~Joystick() {
}

void Joystick::setDown(unsigned int buttonId) {
    downMask |= 1 << buttonId;
    heldMask |= 1 << buttonId;
}

void Joystick::setUp(unsigned int buttonId) {
    upMask &= ~(1 << buttonId);
    heldMask &= ~(1 << buttonId);
}

void Joystick::clear() {
     downMask = 0;
     upMask = 0;
}

bool Joystick::held(unsigned int buttonId) {
    return (heldMask >> buttonId) && 1;
}

bool Joystick::down(unsigned int buttonId) {
    return (downMask >> buttonId) && 1;
}

bool Joystick::up(unsigned int buttonId) {
    return (upMask >> buttonId) && 1;
}

void Joystick::setAxis(unsigned int axisId, double value) {
    axies[axisId] = value;
}

double Joystick::axis(unsigned int axisId) {
    if (axisId < 0 || axisId > num_axies) {
        std::cout << "Warning: axis " << axisId 
             << " out of range" << std::endl;
        return 0;
    }
    return this->axies[axisId];
}
