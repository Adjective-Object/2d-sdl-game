#ifndef __GAME_BASICSHADER
#define __GAME_BASICSHADER

#include "engine/gl.h"

class BasicShader {
    const char* vec;
    const char* frag;

   public:
    GLuint programId;

    struct {
        GLint baseTransform;
        GLint ambientTexture;
    } uniforms;

    struct {
        GLint position;
        GLint color;
        GLint uvs;
    } attributes;

    BasicShader(const char* vec, const char* frag);
    void init();
};

extern BasicShader basicShader;
extern BasicShader textureShader;

#endif
