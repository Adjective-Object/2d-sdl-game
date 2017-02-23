#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "engine/pair.hpp"
#include "constants.hpp"
#include "facing.hpp"
#include "./ledge.hpp"

Ledge::Ledge(Pair position, Facing facing)
    : position(position), facing(facing) {}

void Ledge::render(SDL_Renderer* r) {
    Pair bottom = position + Pair(0, 0.1);
    Pair side = position + Pair(-facing * 0.1, 0);

    Pair first, second;
    if (facing > 0) {
        first = bottom;
        second = side;
    } else {
        first = side;
        second = bottom;
    }

    aatrigonRGBA(r, (int)(position.x * PLAYER_SCALE),
                 (int)(position.y * PLAYER_SCALE),
                 (int)(first.x * PLAYER_SCALE), (int)(first.y * PLAYER_SCALE),
                 (int)(second.x * PLAYER_SCALE), (int)(second.y * PLAYER_SCALE),
                 0, 255, 0, 255);
}