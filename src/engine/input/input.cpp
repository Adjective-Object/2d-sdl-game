#include "input.hpp"
#include <SDL.h>
#include <iostream>

Input::Input() {
    this->keyboard = new Keyboard();
}

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
            joysticks[i] = new Joystick(SDL_JoystickNumButtons(gGameController),
                                        SDL_JoystickNumAxes(gGameController));
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
    keyboard->clear();
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
    } else if (evt->type == SDL_KEYUP) {
        keyboard->setUp(((SDL_KeyboardEvent*)evt)->keysym.sym);
    } else if (evt->type == SDL_KEYDOWN) {
        keyboard->setDown(((SDL_KeyboardEvent*)evt)->keysym.sym);
    }
}

Joystick* Input::getJoystick(unsigned int joystickId) {
    if (joystickId >= this->num_joysticks) {
        return NULL;
    }
    return this->joysticks[joystickId];
}

Keyboard* Input::getKeyboard() {
    return this->keyboard;
}
