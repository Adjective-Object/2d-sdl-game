#include "joystickindicator.hpp"
#include "game.hpp"

JoystickIndicator::JoystickIndicator(int axis1,
                                     int axis2,
                                     int x,
                                     int y,
                                     int width,
                                     int height)
    : axis1(axis1), axis2(axis2), x(x), y(y), width(width), height(height) {
    joystick = EnG->input.getJoystick(0);
}

void JoystickIndicator::render(SDL_Renderer* ren) {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_RenderDrawRect(ren, &rect);

    rect.x = (int)(x + width / 2.0 + (width / 2.0) * joystick->axis(axis1)) - 2;
    rect.y = (int)(y + width / 2.0 + (width / 2.0) * joystick->axis(axis2)) - 2;
    rect.w = 4;
    rect.h = 4;

    SDL_RenderDrawRect(ren, &rect);
}

void JoystickIndicator::init() {}
void JoystickIndicator::preUpdate() {}
void JoystickIndicator::update() {}
void JoystickIndicator::postUpdate() {}
