#include "engine/renderer/screenrenderer.hpp"
#include "text.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include "string.h"

Text::Text(SDL_Renderer* ren,
           Pair position,
           TTF_Font* font,
           SDL_Color color,
           const char* text)
    : ren(ren), color(color), position(position), font(font), text(text) {}

Text::~Text() {
    // SDL_DestorySurface(surface);
    // SDL_DestoryTexture(texture);
}

void Text::updateText(const char* newText) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, newText, color);
    rect = {.x = (int)position.x,
            .y = (int)position.y,
            .w = surface->w,
            .h = surface->h};
    if (texture == NULL) {
        texture = SDL_CreateTextureFromSurface(ren, surface);
    } else {
        SDL_Rect updateRect = {.x = 0, .y = 0, .w = rect.w, .h = rect.h};
        uint8_t* pixels;
        int pitch;

        SDL_LockTexture(texture, &updateRect, (void**)(&pixels), &pitch);
        for (size_t y = 0; y < updateRect.h; y++) {
            for (size_t x = 0; x < updateRect.w; x++) {
                uint8_t* pix = pixels + (y * pitch) + (x * 4);
                uint8_t* srcPix =
                    (uint8_t*)surface->pixels + y * surface->pitch + x;

                if (*srcPix == 1) {
                    pix[0] = 0xFF;
                    pix[1] = 0xFF;
                    pix[2] = 0xFF;
                    pix[3] = 0xFF;
                } else {
                    pix[0] = 0x00;
                    pix[1] = 0x00;
                    pix[2] = 0x00;
                    pix[3] = 0xFF;
                }
            }
        }
        SDL_UnlockTexture(texture);
    }
    renderer->updateMesh(rect);
    text = newText;
    SDL_FreeSurface(surface);
}

void Text::init() {
    texture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA32,
                                SDL_TEXTUREACCESS_STREAMING, 400, 100);
    renderer = new ScreenRenderer(texture, rect);
    this->updateText(text);
}

void Text::update() {}

void Text::preUpdate() {}

void Text::postUpdate() {}

void Text::render(SDL_Renderer* ren) {
    SDL_RenderCopy(ren, texture, NULL, &rect);
}

AbstractRenderer* Text::getRenderer() {
    return renderer;
}
