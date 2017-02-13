#ifndef __GAME_MAINPLAYER
#define __GAME_MAINPLAYER

#include <SDL.h>
#include "../engine/sprite.hpp"
#include "../engine/input.hpp"
#include "playerconfig.hpp"
#include "action.hpp"
#include "animationbank.hpp"

#define FACE_LEFT -1;
#define FACE_RIGHT 1;


class Player : public Sprite {
    AnimationBank * bank;
public:

    Joystick * joystick;
    PlayerConfig config;

    Pair cVel = Pair(0, 0);
    Pair kVel = Pair(0, 0);

    Action * action;
    bool fastfalled = false;
    bool grounded = false;
    int times_jumped = 0;
    int timer = 0;
    JumpType jumpType;
    bool isShortHop;
    bool actionable = true;
    double face = FACE_LEFT;
    int hitlagFrames = 0;


    void init() override;
    void render(SDL_Renderer * ren) override;
    void update() override;

    void fall();
    void aerialDrift();
    void land(double y);

    Player(std::string attributeFile, double x, double y);
    ~Player();

    void changeAction(ActionState state);

};

#endif
