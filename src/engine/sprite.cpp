#include "sprite.hpp"
#include "game.hpp"
#include "util.hpp"

Sprite :: Sprite() {

}

Sprite :: ~Sprite() {

}

void Sprite :: update() {}

void Sprite :: updateMotion() {
    double vdelta;

    // update angle and angular velocity
    vdelta = (computeVelocity(angularVelocity, angularAcceleration,
                             angularDrag, maxAngular) - angularVelocity) / 2;
    angularVelocity += vdelta;
    angle += angularVelocity * EnG->elapsed;
    angularVelocity += vdelta;


    // limit velocity
    if (velocity.x < -maxVelocity.x) {
        velocity.x = -maxVelocity.x;
    }
    if (velocity.x > maxVelocity.x) {
        velocity.x = maxVelocity.x;
    }
    if (velocity.y < -maxVelocity.y) {
        velocity.y = -maxVelocity.y;
    }
    if (velocity.y > maxVelocity.y) {
        velocity.y = maxVelocity.y;
    }

    // update x position
    vdelta = (computeVelocity(velocity.x, acceleration.x,
                              drag.x, maxVelocity.x) - velocity.x) / 2;
    velocity.x += vdelta;
    position.x += velocity.x * EnG->elapsed;
    velocity.x += vdelta;

    // update y position
    vdelta = (computeVelocity(velocity.y, acceleration.y,
                              drag.y, maxVelocity.y) - velocity.y) / 2;
    velocity.y += vdelta;
    position.y += velocity.y * EnG->elapsed;
    velocity.y += vdelta;
}

void Sprite :: render (SDL_Renderer * ren) {
    SDL_Rect destination {
        (int) position.x,
        (int) position.y,
        32,
        32
    };
    SDL_RenderCopy( ren, FALLBACK_TEXTURE, NULL, &destination );
}

void Sprite::preUpdate() {

};

void Sprite::postUpdate() {

};





