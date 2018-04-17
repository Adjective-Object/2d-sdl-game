#ifndef __ENGINE_MATERIAL
#define __ENGINE_MATERIAL

#include <SDL.h>
#include "engine/gl.h"
#include "engine/texture/texture.hpp"

class Material {
   public:
    Texture* ambientTexture = NULL;

    void setAmbientTexture(Texture* texture);
    bool hasTexture();
};

#endif
