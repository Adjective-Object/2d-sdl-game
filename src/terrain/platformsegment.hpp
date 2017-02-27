#ifndef __GAME_PLATFORM_SEGMENT
#define __GAME_PLATFORM_SEGMENT
#include "engine/pair.hpp"

class Platform;

class PlatformSegment {
    friend class Platform;
    Platform* platform;
    int index;

   public:
    PlatformSegment();
    PlatformSegment(Platform* platform, int index);
    Pair* firstPoint();
    Pair* secondPoint();
    Pair slope();
    Platform* getPlatform();


    bool operator==(const PlatformSegment& p) const;
    friend std::ostream& operator<<(std::ostream& strm, const PlatformSegment& p);
};

std::ostream& operator<<(std::ostream& strm, const PlatformSegment& p);

#endif
