#include <SDL.h>
#include <iostream>
#include "../engine/game.hpp"
#include "animationbank.hpp"
#include "player.hpp"

AnimationBank::AnimationBank() {
    std:: cout << "loading land-wait" << std::endl;
    SDL_Texture * land_squat = EnG->loadPNG("./assets/land-jumpsquat.png");
    images = new SDL_Texture * [__NUM_ACTION_STATES];
    for(size_t i=0; i<__NUM_ACTION_STATES; i++) {
        images[i] = NULL;
    }

    std:: cout << "loading wait" << std::endl;
    images[WALK] = EnG->loadPNG("./assets/wait.png"); //walk
    images[WAIT] = EnG->loadPNG("./assets/wait.png"); //wait

    images[LANDING] = land_squat; //land
    images[KNEEBEND] = land_squat; // jump squat
    std:: cout << "loading jumpf" << std::endl;
    images[JUMPF] = EnG->loadPNG("./assets/jumpf.png"); //jumpf
    std:: cout << "loading jumpb" << std::endl;
    images[JUMPB] = EnG->loadPNG("./assets/jumpb.png"); //jumpb
    std:: cout << "loading escapeair" << std::endl;
    images[ESCAPEAIR] = EnG->loadPNG("./assets/escapeair.png"); //airdodge
}

AnimationBank::~AnimationBank() {
    
}

void AnimationBank::playAnimation(ActionState action) {
    if (images[action] != NULL) {
        current = images[action];
    } else {
        current = FALLBACK_TEXTURE;
    }
}

SDL_Texture * AnimationBank::getCurrentTexture(Player & p) {
    return current;
}
