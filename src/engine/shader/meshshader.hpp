#ifndef __GAME_BASICSHADER
#define __GAME_BASICSHADER

#include "engine/gl.h"
#include "primitiveshader.hpp"

class MeshShader : public PrimitiveShader {
   public:
    struct {
        GLint baseTransform;
        GLint ambientTexture;
    } uniforms;

    struct {
        GLint position;
        GLint color;
        GLint uvs;
    } attributes;

    MeshShader(const char* vec, const char* frag);
    void init();
};

extern MeshShader vertexColorShader;
extern MeshShader textureShader;
extern MeshShader fallbackShader;

#endif
