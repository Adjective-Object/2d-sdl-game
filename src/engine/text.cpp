#include <SDL.h>
#include <SDL_ttf.h>
#include "text.hpp"

Text::Text(SDL_Renderer * ren,
            Pair position,
            const char * fontName,
            int fontsize,
            SDL_Color color,
            const char * text) :
    position(position),
    ren(ren),
    color(color) {

    font = TTF_OpenFont(fontName, fontsize);
    this->updateText(text);
}

Text::~Text() {
    // SDL_DestorySurface(surface);
    // SDL_DestoryTexture(texture);
}

void Text::updateText(const char * newText){
    surface = TTF_RenderText_Solid(font, newText, color);
    texture = SDL_CreateTextureFromSurface(ren, surface);
    rect = {
        .x = (int) position.x,
        .y = (int) position.y,
        .w = surface->w,
        .h = surface->h
    };
}

void Text::init(){

}

void Text::update(){

}

void Text::preUpdate(){

}

void Text::postUpdate(){

}

void Text::render(SDL_Renderer * ren){
    SDL_RenderCopy(ren, texture, NULL, &rect);
}

