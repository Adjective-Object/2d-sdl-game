#include <iterator>
#include "../engine/pair.hpp"
#include "platform.hpp"
#include "platform_point_iterator.hpp"

PlatformPointArray::PlatformPointArray(Platform* p) : platform(p) {}

std::vector<Pair>::iterator PlatformPointArray::begin() {
    return platform->points.begin();
}

std::vector<Pair>::iterator PlatformPointArray::end() {
    return platform->points.end();
}
