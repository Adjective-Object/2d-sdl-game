#ifndef __ENGINE_TEXT
#define __ENGINE_TEXT

#include "engine/renderer/abstractrenderer.hpp"
#include "engine/renderer/screenrenderer.hpp"
#include "engine/texture/texture.hpp"

#include "entity.hpp"
#include "pair.hpp"
#include <SDL.h>
#include <SDL_ttf.h>

class Text : public Entity {
   public:
    Texture* texture;
    Pair position;
    TTF_Font* font;
    SDL_Color color;
    SDL_Rect rect;
    ScreenRenderer* renderer;
    ScreenSpaceQuad* model;
    const char* text;

    Text(Pair position,
         TTF_Font* font,
         SDL_Color color,
         const char* initialText);
    ~Text();
    void updateText(const char* newText);
    virtual void init() override;
    virtual void update() override;
    virtual void preUpdate() override;
    virtual void postUpdate() override;
    AbstractRenderer* getRenderer() override;
};

#endif
