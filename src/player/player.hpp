#ifndef __GAME_MAINPLAYER
#define __GAME_MAINPLAYER

#include "../engine/input.hpp"
#include "../engine/sprite.hpp"
#include "action.hpp"
#include "animationbank.hpp"
#include "playerconfig.hpp"
#include <SDL.h>

#define FACE_LEFT -1;
#define FACE_RIGHT 1;

#define PLAYER_FLOOR 1.2
#define PLAYER_SCALE 275

class Player : public Sprite {
    AnimationBank* bank;

   public:
    Joystick* joystick;
    PlayerConfig config;

    Pair cVel = Pair(0, 0);
    Pair kVel = Pair(0, 0);

    Action* action;
    ActionState actionState;
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
    void render(SDL_Renderer* ren) override;
    void update() override;

    void fall();
    void aerialDrift();
    void land(double y);

    Player(std::string attributeFile, double x, double y);
    ~Player();

    void changeAction(ActionState state);
    ActionState getActionState();
    double getXInput(int frames = 0);
};

#endif
