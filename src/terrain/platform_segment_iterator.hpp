#ifndef __GAME_PLATFORM_SEGMENT_ITERATOR
#define __GAME_PLATFORM_SEGMENT_ITERATOR

#include "platform.hpp"
#include "platformsegment.hpp"

class PlatformSegmentArray {
    Platform* platform;

   public:
    PlatformSegmentArray(Platform* p);

    class iterator {
        PlatformSegment segment;

       public:
        iterator(PlatformSegment segment);
        iterator operator++();
        iterator operator++(int offset);
        PlatformSegment& operator*();
        PlatformSegment* operator->();
        bool operator==(const iterator rhs);
        bool operator!=(const iterator rhs);
    };

    iterator begin();
    iterator end();
};

#endif
