#ifndef __GAME_PRIMITIVESHADER
#define __GAME_PRIMITIVESHADER

#include <map>
#include "engine/gl.h"

class PrimitiveShader {
   protected:
    const char* vec;
    const char* frag;
    std::map<std::string, std::string> defines;

   public:
    GLuint programId;
    PrimitiveShader(const char* vec, const char* frag);
    virtual void init();
};

#endif
