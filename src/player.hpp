#ifndef __GAME_MAINPLAYER
#define __GAME_MAINPLAYER

#include "engine/sprite.hpp"
#include "engine/input.hpp"
#include <SDL.h>

class Player : public Sprite {
    Joystick * joystick;
public:
    void init() override;
    void render(SDL_Renderer * ren) override;
    void update() override;
    Player();
    ~Player();
};

#endif
