#ifndef __ENGINE_MATERIAL
#define __ENGINE_MATERIAL

#include <SDL.h>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>

class Material {
    SDL_Surface* ambientSurface = NULL;

   public:
    SDL_Texture* ambientTexture = NULL;

    void setAmbientTexture(SDL_Texture* texture);
    bool hasTexture();
};

#endif
