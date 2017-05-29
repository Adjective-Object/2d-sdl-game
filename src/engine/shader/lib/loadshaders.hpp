#ifndef __ENGINE_LOAD_SHADERS
#define __ENGINE_LOAD_SHADERS

#include "engine/gl.h"
#include <map>
#include <string>

GLuint LoadShaders(const char* vertex_file_path,
                   const char* fragment_file_path,
                   const std::map<std::string, std::string> * defines = NULL);

#endif
