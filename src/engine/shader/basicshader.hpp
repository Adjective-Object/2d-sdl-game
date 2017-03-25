#ifndef __GAME_BASICSHADER
#define __GAME_BASICSHADER

#include "engine/gl.h"

class BasicShader {
   public:
    GLuint programId;

    struct {
        GLint baseTransform;
    } uniforms;

    struct {
        GLint position;
        GLint color;
    } attributes;

    BasicShader();
    void init();
};

extern BasicShader basicShader;

#endif
