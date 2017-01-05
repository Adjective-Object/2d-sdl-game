#ifndef __ENGINE_UTIL
#define __ENGINE_UTIL

#include <iostream>
#include <limits>
#include "util.hpp"

#define DOUBLE_INFINITY std::numeric_limits<double>::infinity()

void logSDLError(std::ostream &os, const std::string &msg);

double computeVelocity(
        double velocity, double acceleration,
        double drag, double cap);

#endif
