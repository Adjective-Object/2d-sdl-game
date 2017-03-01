#ifndef __GAME_MAINPLAYER
#define __GAME_MAINPLAYER

#include <SDL.h>
#include "engine/input.hpp"
#include "engine/sprite.hpp"
#include "terrain/platform.hpp"
#include "terrain/ledge.hpp"
#include "action.hpp"
#include "animationbank.hpp"
#include "playerconfig.hpp"
#include "playercollision.hpp"
#include "inputhandler.hpp"

#define FACE_LEFT -1;
#define FACE_RIGHT 1;

class Player : public Sprite {
    AnimationBank* bank;

   public:
    Platform* currentPlatform = NULL;
    Ledge* currentLedge = NULL;

    PlayerCollision* previousCollision = new PlayerCollision();
    PlayerCollision* currentCollision = new PlayerCollision();

    InputMapping::InputHandler* input;
    PlayerConfig* config;

    int ecbFixedCounter = 0;
    int ledgeRegrabCounter = 0;
    double ecbBottomFixedSize = 0;

    Pair cVel = Pair(0, 0);
    Pair kVel = Pair(0, 0);
    Pair previousPosition;

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

    void fall(bool fast = false);
    void aerialDrift();
    void grabLedge(Ledge* l);
    void land(Platform* p);
    void fixEcbBottom(int frames, double size);
    void moveTo(Pair newPos);
    void moveTo(Ecb& ecb);

    Player(PlayerConfig* config,
           InputMapping::InputHandler* input,
           AnimationBank* animationBank,
           Pair initialPosition);
    ~Player();

    bool canGrabLedge();
    bool isGrounded();
    bool canFallOff();
    void fallOffPlatform();

    void changeAction(ActionState state);
    double getXInput(int frames = 0);
    Platform* getCurrentPlatform();
    ActionState getActionState();
    Action* getAction();

    void setPosition(Pair newPosition);
    double getAttribute(char const* name);
};

#endif
