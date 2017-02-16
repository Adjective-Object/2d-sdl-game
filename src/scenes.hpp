#ifndef __GAME_SCENES
#define __GAME_SCENES

#include "engine/input.hpp"
#include "engine/scene.hpp"
#include "engine/text.hpp"
#include "player/player.hpp"
#include <SDL.h>

class MainScene : public Scene {
    Joystick* joystick;
    Player* player;
    Text* text;
    ActionState lastActionState = __NUM_ACTION_STATES;

   public:
    MainScene();
    ~MainScene();
    void init() override;
    void update() override;
    void render(SDL_Renderer* r) override;
};

#endif
