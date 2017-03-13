#ifndef __ENGINE_KEYBOARD
#define __ENGINE_KEYBOARD
#include <stddef.h>
#include <set>

class Input;

class Keyboard {
    friend Input;
    size_t historySize;
    size_t currentHistory = 0;

    std::set<int>* heldKeys;
    std::set<int>* downKeys;
    std::set<int>* upKeys;

   public:
    Keyboard(size_t historySize = 10);
    void setDown(unsigned int keyId);
    void setUp(unsigned int keyId);
    void clear();
    bool down(int keySym, int framesBack = 0);
    bool held(int keySym, int framesBack = 0);
    bool up(int keySym, int framesBack = 0);
};

#endif
