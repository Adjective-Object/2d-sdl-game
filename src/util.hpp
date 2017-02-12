#ifndef __GAME_UTIL
#define __GAME_UTIL

template <typename T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

#endif