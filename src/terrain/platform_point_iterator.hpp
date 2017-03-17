#ifndef __GAME_PLATFORM_POINT_ITERATOR
#define __GAME_PLATFORM_POINT_ITERATOR
#include <iterator>
#include "platform.hpp"
#include "engine/pair.hpp"
class PlatformPointArray {
   private:
    Platform* platform;

   public:
    PlatformPointArray(Platform* p);
    typedef std::vector<Pair>::iterator iterator;
    std::vector<Pair>::iterator begin();
    std::vector<Pair>::iterator end();
};

#endif
