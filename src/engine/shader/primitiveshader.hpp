#ifndef __GAME_PRIMITIVESHADER
#define __GAME_PRIMITIVESHADER

#include "engine/gl.h"

class PrimitiveShader {
    const char* vec;
    const char* frag;

   public:
    GLuint programId;
    PrimitiveShader(const char* vec, const char* frag);
    void init();
};

#endif
