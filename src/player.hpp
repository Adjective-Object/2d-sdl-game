#ifndef __GAME_MAINPLAYER
#define __GAME_MAINPLAYER

#include <SDL.h>
#include "engine/sprite.hpp"
#include "engine/input.hpp"
#include "playerconfig.hpp"

class Player : public Sprite {
    Joystick * joystick;
    PlayerConfig config;
public:
    void init() override;
    void render(SDL_Renderer * ren) override;
    void update() override;
    Player(std::string attributeFile);
    ~Player();
};

#endif
