#ifndef __ENGINE_MATERIAL
#define __ENGINE_MATERIAL

#include <SDL.h>
#include "engine/gl.h"

class Material {
    SDL_Surface* ambientSurface = NULL;

   public:
    SDL_Texture* ambientTexture = NULL;

    void setAmbientTexture(SDL_Texture* texture);
    bool hasTexture();
};

#endif
