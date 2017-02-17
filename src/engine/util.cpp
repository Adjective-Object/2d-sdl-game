#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "game.hpp"
#include "util.hpp"

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error:
*SDL_GetError()
**/
void logSDLError(std::ostream& os, const std::string& msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

double computeVelocity(double v, double a, double drag, double cap) {
    if (a != 0) {
        v += a * EnG->elapsed;
    }

    else if (drag != 0) {
        drag = drag * EnG->elapsed;

        if (v - drag > 0)
            v = v - drag;
        else if (v + drag < 0)
            v += drag;
        else
            v = 0;
    }

    if ((v != 0) && (cap != DOUBLE_INFINITY)) {
        if (v > cap)
            v = cap;
        else if (v < -cap)
            v = -cap;
    }

    return v;
}
