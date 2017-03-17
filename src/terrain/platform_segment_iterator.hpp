#ifndef __GAME_PLATFORM_SEGMENT_ITERATOR
#define __GAME_PLATFORM_SEGMENT_ITERATOR

#include "platform.hpp"
#include "platformsegment.hpp"

class PlatformSegmentArray {
    const Platform* platform;

   public:
    PlatformSegmentArray(const Platform* p);

    class iterator {
        PlatformSegment segment;

       public:
        typedef PlatformSegment& reference;
        typedef PlatformSegment* pointer;

        iterator(PlatformSegment segment);
        iterator();
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
