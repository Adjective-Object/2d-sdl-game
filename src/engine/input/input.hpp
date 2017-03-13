#ifndef __ENGINE_INPUT
#define __ENGINE_INPUT

#include <SDL.h>
#include <vector>
#include "./joystick.hpp"
#include "./keyboard.hpp"

class Input {
    Joystick** joysticks = nullptr;
    Keyboard* keyboard = nullptr;
    size_t num_joysticks;

   public:
    Input();
    ~Input();
    void init();
    void clear();
    void processEvent(SDL_Event*);
    Joystick* getJoystick(unsigned int id);
    Keyboard* getKeyboard();
};

#endif
