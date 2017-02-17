#ifndef __ENGINE_UTIL
#define __ENGINE_UTIL

#include "util.hpp"
#include <iostream>
#include <limits>

#define DOUBLE_INFINITY std::numeric_limits<double>::infinity()

void logSDLError(std::ostream& os, const std::string& msg);

double computeVelocity(double velocity,
                       double acceleration,
                       double drag,
                       double cap);

#endif
