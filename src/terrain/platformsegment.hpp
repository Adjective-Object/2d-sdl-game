#ifndef __GAME_PLATFORM_SEGMENT
#define __GAME_PLATFORM_SEGMENT
#include "engine/pair.hpp"

class Platform;

class PlatformSegment {
    friend class Platform;
    friend class PlatformSegmentArray;
    const Platform* platform;
    int index;

   public:
    PlatformSegment();
    PlatformSegment(const Platform* platform, int index);
    const Pair* firstPoint() const;
    const Pair* secondPoint() const;
    const Pair slope() const;
    const Platform* getPlatform() const;

    bool operator==(const PlatformSegment& p) const;
    bool operator<(const PlatformSegment& p) const;
    friend std::ostream& operator<<(std::ostream& strm,
                                    const PlatformSegment& p);
};

std::ostream& operator<<(std::ostream& strm, const PlatformSegment& p);

#endif
