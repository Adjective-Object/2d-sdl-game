#ifndef __GAME_ANIM_BANK
#define __GAME_ANIM_BANK
#include "action.hpp"
#include <SDL.h>

class AnimationBank {
   public:
    SDL_Texture* current;
    SDL_Texture** images;
    AnimationBank();
    ~AnimationBank();
    void playAnimation(ActionState action);
    SDL_Texture* getCurrentTexture(Player& p);
};

#endif