#include "text.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include "engine/renderer/screenrenderer.hpp"
#include "engine/util.hpp"
#include "string.h"

Text::Text(Pair position, TTF_Font* font, SDL_Color color, const char* text)
    : position(position), font(font), color(color), text(text) {}

Text::~Text() {
    // SDL_DestorySurface(surface);
    // SDL_DestoryTexture(texture);
}

#define INITIAL_TEXTURE_WIDTH 400
#define INITIAL_TEXTURE_HEIGHT 50

void Text::updateText(const char* newText) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, newText, color);
    if (surface == NULL) {
        logSDLError(std::cout, "TTF_RenderText_Blended");
        exit(1);
    }
    rect = {.x = (int)position.x,
            .y = (int)position.y,
            .w = surface->w,
            .h = surface->h};
    if (texture == NULL) {
        texture = Texture::fromSurface(surface);
    } else {
        SDL_Rect updateRect = {.x = 0, .y = 0, .w = rect.w, .h = rect.h};
        texture->update(surface, &updateRect);
    }
    model->updateMesh(rect, INITIAL_TEXTURE_WIDTH, INITIAL_TEXTURE_HEIGHT);
    text = newText;
    SDL_FreeSurface(surface);
}

void Text::init() {
    texture =
        Texture::createEmpty(INITIAL_TEXTURE_WIDTH, INITIAL_TEXTURE_HEIGHT);
    rect = {
        .x = 0,
        .y = 0,
        .w = INITIAL_TEXTURE_WIDTH,
        .h = INITIAL_TEXTURE_HEIGHT,
    };
    model = new ScreenSpaceQuad();
    model->init(rect, INITIAL_TEXTURE_WIDTH, INITIAL_TEXTURE_HEIGHT);
    renderer = new ScreenRenderer(texture, model);
    this->updateText(text);
}

void Text::update() {}

void Text::preUpdate() {}

void Text::postUpdate() {}

AbstractRenderer* Text::getRenderer() {
    return renderer;
}
