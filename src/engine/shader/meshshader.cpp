#include "engine/gl.h"
#include "engine/shader/meshshader.hpp"
#include <iostream>

MeshShader::MeshShader(const char* v, const char* f) : PrimitiveShader(v, f) {}
void MeshShader::init() {
    PrimitiveShader::init();

    attributes.position = glGetAttribLocation(programId, "position");
    attributes.uvs = glGetAttribLocation(programId, "uvs");
    attributes.color = glGetAttribLocation(programId, "vertexColor");
    uniforms.baseTransform = glGetUniformLocation(programId, "baseTransform");
    uniforms.ambientTexture = glGetUniformLocation(programId, "ambientTexture");
    std::cout << "attributes.position:" << attributes.position << std::endl;
    std::cout << "attributes.color: " << attributes.color << std::endl;
    std::cout << "uniforms.baseTransform: " << uniforms.baseTransform
              << std::endl;
    std::cout << "uniforms.ambientTexture: " << uniforms.ambientTexture
              << std::endl;
}

MeshShader vertexColorShader =
    MeshShader("assets/shaders/id.vert", "assets/shaders/red.frag");
MeshShader textureShader =
    MeshShader("assets/shaders/id_texture.vert", "assets/shaders/texture.frag");
MeshShader fallbackShader = MeshShader("assets/shaders/id_texture.vert",
                                       "assets/shaders/fallback.frag");
