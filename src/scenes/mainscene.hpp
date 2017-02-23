#ifndef __GAME_SCENES
#define __GAME_SCENES

#include <vector>
#include <SDL.h>

#include "engine/input.hpp"
#include "engine/scene.hpp"
#include "engine/text.hpp"
#include "player/player.hpp"
#include "terrain/map.hpp"

class MainScene : public Scene {
    Joystick* joystick;
    Player* player;
    Text *stateText, *posText;
    ActionState lastActionState = __NUM_ACTION_STATES;
    Map* map;

   public:
    MainScene();
    ~MainScene();
    void init() override;
    void update() override;
    void render(SDL_Renderer* r) override;
};

#endif
