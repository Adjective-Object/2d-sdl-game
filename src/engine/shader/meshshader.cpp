#include "engine/gl.h"
#include "engine/shader/meshshader.hpp"
#include "meshshader.hpp"
#include <iostream>

#define attribute(name)                                             \
    {                                                               \
        attributes.name = glGetAttribLocation(programId, #name);    \
        std::cout << "attributes." << #name ": " << attributes.name \
                  << std::endl;                                     \
    }

#define uniform(name)                                                         \
    {                                                                         \
        uniforms.name = glGetUniformLocation(programId, #name);               \
        std::cout << "uniforms." << #name ": " << uniforms.name << std::endl; \
    }

MeshShader::MeshShader(const char* v, const char* f) : PrimitiveShader(v, f) {}
void MeshShader::init() {
    defines["MAX_BONES"] = std::to_string(16);
    defines["MAX_BONES_PER_VERT"] = std::to_string(4);

    PrimitiveShader::init();

    // use macros to define the initialization of attributes & macros
    MESH_SHADER_ATTRIBUTES
    MESH_SHADER_UNIFORMS
}

#undef attribute
#undef uniform

bool MeshShader::hasAttribute(MESH_SHADER_ATTRIBUTE attr) {
    // because the enum values are equal to the offsets within
    // the attribute/uniform structs, we can just check that they do
    // not have value -1
    return ((GLint*)&attributes)[(size_t)attr] != -1;
}

bool MeshShader::hasUniform(MESH_SHADER_UNIFORM uniform) {
    // see above (hasAttribute) for explanation
    return ((GLint*)&uniforms)[(size_t)uniform] != -1;
}

MeshShader vertexColorShader =
    MeshShader("assets/shaders/id.vert", "assets/shaders/red.frag");

MeshShader textureShader =
    MeshShader("assets/shaders/id_texture.vert", "assets/shaders/texture.frag");
MeshShader fallbackShader = MeshShader("assets/shaders/id_texture.vert",
                                       "assets/shaders/fallback.frag");
