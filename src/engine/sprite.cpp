#include "sprite.hpp"
#include "game.hpp"
#include "util.hpp"

Sprite :: Sprite() {

}

Sprite :: ~Sprite() {

}

void Sprite :: preUpdate() {

}

void Sprite :: postUpdate() {
    
}

void Sprite :: update() {}

void Sprite :: updateMotion() {
    double delta, vdelta;

    // update angle and angular velocity
    vdelta = (computeVelocity(angularVelocity, angularAcceleration,
                             angularDrag, maxAngular) - angularVelocity) / 2;
    angularVelocity += vdelta;
    angle += angularVelocity * EnG->elapsed;
    angularVelocity += vdelta;

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
    // TODO
}



