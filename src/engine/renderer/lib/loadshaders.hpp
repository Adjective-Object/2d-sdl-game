#ifndef __ENGINE_LOAD_SHADERS
#define __ENGINE_LOAD_SHADERS

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

GLuint LoadShaders(const char* vertex_file_path,
                   const char* fragment_file_path);

#endif
