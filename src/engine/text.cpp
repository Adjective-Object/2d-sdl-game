#include "text.hpp"
#include <SDL.h>
#include <SDL_ttf.h>

Text::Text(SDL_Renderer* ren,
           Pair position,
           TTF_Font* font,
           SDL_Color color,
           const char* text)
    : ren(ren), color(color), position(position), font(font) {
    this->updateText(text);
}

Text::~Text() {
    // SDL_DestorySurface(surface);
    // SDL_DestoryTexture(texture);
}

void Text::updateText(const char* newText) {
    surface = TTF_RenderText_Solid(font, newText, color);
    texture = SDL_CreateTextureFromSurface(ren, surface);
    rect = {.x = (int)position.x,
            .y = (int)position.y,
            .w = surface->w,
            .h = surface->h};
}

void Text::init() {}

void Text::update() {}

void Text::preUpdate() {}

void Text::postUpdate() {}

void Text::render(SDL_Renderer* ren) {
    SDL_RenderCopy(ren, texture, NULL, &rect);
}
