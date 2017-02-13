#include <SDL.h>
#include <iostream>
#include "../engine/game.hpp"
#include "animationbank.hpp"
#include "player.hpp"

AnimationBank::AnimationBank() {
    images = new SDL_Texture * [__NUM_ACTION_STATES];
    for(size_t i=0; i<__NUM_ACTION_STATES; i++) {
        images[i] = NULL;
    }

    SDL_Texture * wait = EnG->loadPNG("./assets/wait.png");
    images[WALK] = wait;
    images[WAIT] = wait;

    SDL_Texture * land_squat = EnG->loadPNG("./assets/land-jumpsquat.png");
    images[LANDING] = land_squat; //land
    images[KNEEBEND] = land_squat; // jump squat

    images[JUMPF] = EnG->loadPNG("./assets/jumpf.png"); //jumpf
    images[JUMPB] = EnG->loadPNG("./assets/jumpb.png"); //jumpb
    images[ESCAPEAIR] = EnG->loadPNG("./assets/escapeair.png"); //airdodge
    images[DASH] = EnG->loadPNG("./assets/dash.png"); // dash
    images[RUN] = EnG->loadPNG("./assets/run.png"); //r un
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
