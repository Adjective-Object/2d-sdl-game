#ifndef __GAME_MAINPLAYER
#define __GAME_MAINPLAYER

#include <SDL.h>
#include "action.hpp"
#include "ecbmesh.hpp"
#include "engine/model/model.hpp"
#include "engine/renderer/meshrenderer.hpp"
#include "engine/renderer/multimeshrenderer.hpp"
#include "engine/renderer/multirenderer.hpp"
#include "engine/sprite.hpp"
#include "inputhandler.hpp"
#include "playercollision.hpp"
#include "playerconfig.hpp"
#include "terrain/ledge.hpp"
#include "terrain/platform.hpp"

#define FACE_LEFT -1
#define FACE_RIGHT 1

class Player : public Sprite {
    MeshRenderer* ecbMeshRenderer;
    MultiMeshRenderer* modelMeshRenderer;
    AbstractMultiRenderer* multiRenderer;
    EcbMesh mesh;
    WorldspaceMesh modelMesh;

    void updateMesh();
    Model* model = NULL;

   public:
    const Platform* currentPlatform = NULL;
    const Ledge* currentLedge = NULL;

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
    void update() override;

    void fall(bool fast = false);
    void aerialDrift();
    void grabLedge(Ledge const* l);
    void fixEcbBottom(int frames, double size);
    void moveTo(Pair newPos);
    void moveTo(Ecb& ecb);

    Player(PlayerConfig* config,
           InputMapping::InputHandler* input,
           Pair initialPosition);
    ~Player();

    bool canGrabLedge() const;
    bool isGrounded() const;
    bool canFallOff() const;
    bool canLand(const Platform* p) const;
    const Platform* getCurrentPlatform() const;
    const PlatformSegment getCurrentPlatformSegment() const;
    ActionState getActionState() const;
    Action* getAction() const;

    void fallOffPlatform();
    void land(const Platform* p);
    Ecb getLandedEcb(const Platform*) const;

    void changeAction(ActionState state);
    double getXInput(int frames = 0) const;
    void setPosition(Pair newPosition);
    double getAttribute(char const* name) const;

    AbstractRenderer* getRenderer() override;
};

#endif
