#include "platformsegment.hpp"
#include "./platform.hpp"
#include "engine/pair.hpp"

PlatformSegment::PlatformSegment() : platform(NULL), index(0) {}
PlatformSegment::PlatformSegment(const Platform* platform, int index)
    : platform(platform), index(index) {}

const Pair* PlatformSegment::firstPoint() const {
    return &(platform->points[index]);
}

const Pair* PlatformSegment::secondPoint() const {
    return &(platform->points[index + 1]);
}

const Pair PlatformSegment::slope() const {
    Pair diff = *firstPoint() - *secondPoint();
    return diff / diff.euclid();
}

double PlatformSegment::angle() const {
    return platform->angles[index];
}

const Platform* PlatformSegment::getPlatform() const {
    return platform;
}

bool PlatformSegment::operator==(const PlatformSegment& p) const {
    return p.platform == platform &&
           (p.index == index || p.index == -1 || index == -1);
}

bool PlatformSegment::operator<(const PlatformSegment& p) const {
    return firstPoint() < p.firstPoint();
}

std::ostream& operator<<(std::ostream& strm, const PlatformSegment& p) {
    return strm << "PlatformSegment { "
                << "platform = " << p.platform << ", "
                << "index = " << p.index << ", "
                << "}";
}
