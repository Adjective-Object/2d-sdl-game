#ifndef __GAME_PLATFORM_POINT_ITERATOR
#define __GAME_PLATFORM_POINT_ITERATOR
#include <iterator>
#include "engine/pair.hpp"
#include "platform.hpp"
#include "platformpoint.hpp"

class PlatformPointArray {
   private:
    const Platform* platform;

   public:
    PlatformPointArray(const Platform* p);

    class iterator {
        PlatformPoint point;

       public:
        typedef PlatformPoint& reference;
        typedef PlatformPoint* pointer;

        iterator(PlatformPoint point);
        iterator();
        iterator operator++();
        iterator operator++(int offset);
        reference operator*();
        pointer operator->();
        bool operator==(const iterator rhs);
        bool operator!=(const iterator rhs);
    };

    iterator begin();
    iterator end();
};

#endif
