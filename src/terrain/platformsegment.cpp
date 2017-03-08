#include "./platform.hpp"
#include "platformsegment.hpp"
#include "engine/pair.hpp"

PlatformSegment::PlatformSegment() : platform(NULL), index(0) {}
PlatformSegment::PlatformSegment(Platform* platform, int index)
    : platform(platform), index(index) {}

Pair* PlatformSegment::firstPoint() {
    return &(platform->points[index]);
}

Pair* PlatformSegment::secondPoint() {
    return &(platform->points[index + 1]);
}

Pair PlatformSegment::slope() {
    Pair diff = *firstPoint() - *secondPoint();
    return diff / diff.euclid();
}

Platform* PlatformSegment::getPlatform() {
    return platform;
}

bool PlatformSegment::operator==(const PlatformSegment& p) const {
    return p.platform == platform &&
           (p.index == index || p.index == -1 || index == -1);
}

std::ostream& operator<<(std::ostream& strm, const PlatformSegment& p) {
    return strm << "PlatformSegment { "
                << "platform = " << p.platform << ", "
                << "index = " << p.index << ", "
                << "}";
}
