#ifndef __ENGINE_MATERIAL
#define __ENGINE_MATERIAL

#include <SDL.h>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>

class Material {
    SDL_Surface * ambientTexture;
    public:
    GLuint glAmbientTexture = 0;

    void setAmbientTexture(SDL_Surface * ambientTexture);
    bool hasTexture();
};

#endif

