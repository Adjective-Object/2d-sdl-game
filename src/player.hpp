#ifndef __GAME_MAINPLAYER
#define __GAME_MAINPLAYER

#include <SDL.h>
#include "engine/sprite.hpp"
#include "engine/input.hpp"
#include "playerconfig.hpp"

typedef enum PlayerState {
    STANDING,
    WALKING,
    FAST_WALKING,
    RUNNING,
    JUMP_SQUAT,
    LANDING,
    STOP_TURN,
} PlayerState;

class Player : public Sprite {
    Joystick * joystick;
    PlayerConfig config;
    bool on_ground = false;
    bool actionable = true;
public:
    void init() override;
    void render(SDL_Renderer * ren) override;
    void update() override;
    Player(std::string attributeFile);
    ~Player();
};

#endif
