#ifndef __GAME_SCREENSHADER
#define __GAME_SCREENSHADER

#include "engine/gl.h"
#include "primitiveshader.hpp"

class ScreenShader : public PrimitiveShader {
   public:
    struct {
        GLint screenDimensions;
        GLint ambientTexture;
    } uniforms;
    struct {
        GLint pixelPosition;
        GLint uvs;
    } attributes;

    void init();
    ScreenShader(const char* vec, const char* frag);
};

extern ScreenShader screenShader;

#endif
