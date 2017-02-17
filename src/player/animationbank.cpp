#include "animationbank.hpp"
#include "../engine/game.hpp"
#include "player.hpp"
#include <SDL.h>
#include <iostream>

AnimationBank::AnimationBank() {
    images = new SDL_Texture*[__NUM_ACTION_STATES];
    for (size_t i = 0; i < __NUM_ACTION_STATES; i++) {
        images[i] = NULL;
    }

    images[WALK] = EnG->loadPNG("./assets/walk.png");
    images[WAIT] = EnG->loadPNG("./assets/wait.png");

    images[RUNTURN] = EnG->loadPNG("./assets/runturn.png");
    images[RUNBRAKE] = EnG->loadPNG("./assets/runbrake.png");

    images[LANDING] = EnG->loadPNG("./assets/land.png");        // land
    images[KNEEBEND] = EnG->loadPNG("./assets/jumpsquat.png");  // jump squat

    images[JUMPF] = EnG->loadPNG("./assets/jumpf.png");      // jumpf
    images[JUMPB] = EnG->loadPNG("./assets/jumpb.png");      // jumpb
    images[JUMPAIRF] = EnG->loadPNG("./assets/djumpf.png");  // jumpf
    images[JUMPAIRB] = EnG->loadPNG("./assets/djumpb.png");  // jumpb

    images[ESCAPEAIR] = EnG->loadPNG("./assets/escapeair.png");  // airdodge
    images[DASH] = EnG->loadPNG("./assets/dash.png");            // dash
    images[RUN] = EnG->loadPNG("./assets/run.png");              // r un
    images[FALL] = EnG->loadPNG("./assets/fall.png");            // jumpf
    images[TURN] = EnG->loadPNG("./assets/turn.png");            // jumpf
    images[SMASHTURN] = EnG->loadPNG("./assets/turn.png");       // jumpf
}

AnimationBank::~AnimationBank() {}

void AnimationBank::playAnimation(ActionState action) {
    if (images[action] != NULL) {
        current = images[action];
    } else {
        current = FALLBACK_TEXTURE;
    }
}

SDL_Texture* AnimationBank::getCurrentTexture(Player& p) {
    return current;
}
