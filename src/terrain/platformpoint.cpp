#include "platform.hpp"
#include "engine/pair.hpp"
#include "platformpoint.hpp"

PlatformPoint::PlatformPoint(const Platform* p, size_t index)
    : platform(p), index(index) {}

PlatformSegment PlatformPoint::firstSegment() const {
    if (index == 0)
        return PlatformSegment(platform, platform->points.size() - 2);
    return PlatformSegment(platform, index - 1);
}

PlatformSegment PlatformPoint::secondSegment() const {
    if (index == platform->points.size() - 1)
        return PlatformSegment(platform, 0);
    return PlatformSegment(platform, index);
}

const Platform* PlatformPoint::getPlatform() const {
    return platform;
}

Pair PlatformPoint::point() const {
    return platform->points[index];
}

bool PlatformPoint::operator==(const PlatformPoint& p) const {
    return platform == p.platform && index == p.index;
}

bool PlatformPoint::operator<(const PlatformPoint& p) const {
    return point() < p.point();
}
