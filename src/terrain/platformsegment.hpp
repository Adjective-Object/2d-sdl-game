#ifndef __GAME_PLATFORM_SEGMENT
#define __GAME_PLATFORM_SEGMENT
#include "engine/pair.hpp"

class Platform;

class PlatformSegment {
    friend class Platform;
    const Platform* platform;
    int index;

   public:
    PlatformSegment();
    PlatformSegment(const Platform* platform, int index);
    const Pair* firstPoint();
    const Pair* secondPoint();
    const Pair slope();
    const Platform* getPlatform();

    bool operator==(const PlatformSegment& p) const;
    friend std::ostream& operator<<(std::ostream& strm,
                                    const PlatformSegment& p);
};

std::ostream& operator<<(std::ostream& strm, const PlatformSegment& p);

#endif
