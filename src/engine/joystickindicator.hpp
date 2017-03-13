#ifndef __ENGINE_JOYSTICK_INDICATOR
#define __ENGINE_JOYSTICK_INDICATOR
#include "entity.hpp"
#include "input/joystick.hpp"

class JoystickIndicator : public Entity {
    int axis1, axis2;
    int x, y, width, height;
    Joystick* joystick;

   public:
    JoystickIndicator(int axis1,
                      int axis2,
                      int x,
                      int y,
                      int width,
                      int height);
    virtual void init();

    virtual void preUpdate();
    virtual void update();
    virtual void postUpdate();

    virtual void render(SDL_Renderer* ren);
};

#endif
