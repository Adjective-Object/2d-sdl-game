#ifndef __GAME_SCENES
#define __GAME_SCENES

#include <vector>
#include <SDL.h>

#include "engine/input.hpp"
#include "engine/scene.hpp"
#include "engine/text.hpp"
#include "player/player.hpp"
#include "terrain/platform.hpp"

#define PLAYER_FLOOR 1.2
#define PLAYER_SCALE 275

class MainScene : public Scene {
    Joystick* joystick;
    Player* player;
    Text *stateText, *posText;
    ActionState lastActionState = __NUM_ACTION_STATES;
    std::vector<Platform*> platforms = std::vector<Platform*>();

   public:
    MainScene();
    ~MainScene();
    void init() override;
    void update() override;
    void render(SDL_Renderer* r) override;
};

#endif
