#include "platform_point_iterator.hpp"
#include <iterator>
#include "../engine/pair.hpp"
#include "platform.hpp"
#include "platformpoint.hpp"

typedef PlatformPointArray::iterator itr;

PlatformPointArray::PlatformPointArray(const Platform* p) : platform(p) {}

itr PlatformPointArray::begin() {
    return itr(PlatformPoint(platform, 0));
}

itr PlatformPointArray::end() {
    return itr(PlatformPoint(platform, platform->points.size()));
}

itr::iterator(PlatformPoint p) : point(p) {}
itr::iterator() : point(PlatformPoint(NULL, 0)) {}

itr itr::operator++() {
    point.index++;
    return *this;
}

itr itr::operator++(int offset) {
    point.index++;
    return *this;
}

itr::reference itr::operator*() {
    return point;
}

itr::pointer itr::operator->() {
    return &point;
}

bool itr::operator==(itr other) {
    return other.point == point;
}

bool itr::operator!=(itr other) {
    return !operator==(other);
}
