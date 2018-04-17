#ifndef __GAME_PLATFORM_POINT_WRAP
#define __GAME_PLATFORM_POINT_WRAP
#include "engine/pair.hpp"
#include "platform.hpp"

class PlatformPoint {
    friend class Platform;
    friend class PlatformPointArray;
    const Platform* platform;
    size_t index;

   public:
    PlatformPoint(const Platform* platform, size_t index);
    Pair point() const;
    PlatformSegment firstSegment() const;
    PlatformSegment secondSegment() const;

    bool operator==(const PlatformPoint& p) const;
    bool operator<(const PlatformPoint& p) const;
    const Platform* getPlatform() const;
};

#endif
