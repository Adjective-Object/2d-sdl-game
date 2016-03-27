#ifndef __GAME_SCENES
#define __GAME_SCENES

#include <SDL.h>
#include "engine/scene.hpp"

class MainScene : public Scene {
public:
   MainScene();
   ~MainScene();
   void init();
   void update();
   void render();
};

#endif
