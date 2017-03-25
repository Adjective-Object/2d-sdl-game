#ifndef __ENGINE_LOAD_SHADERS
#define __ENGINE_LOAD_SHADERS

#include "engine/gl.h"

GLuint LoadShaders(const char* vertex_file_path,
                   const char* fragment_file_path);

#endif
