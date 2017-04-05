#include "engine/gl.h"
#include "engine/shader/basicshader.hpp"
#include <iostream>
#include "./lib/loadshaders.hpp"

BasicShader::BasicShader(const char * v, const char * f) : vec(v), frag(f) {}
void BasicShader::init() {
    programId = LoadShaders(vec, frag);
    attributes.position = glGetAttribLocation(programId, "position");
    attributes.uvs = glGetAttribLocation(programId, "uvs");
    attributes.color = glGetAttribLocation(programId, "vertexColor");
    uniforms.baseTransform = glGetUniformLocation(programId, "baseTransform");
    uniforms.ambientTexture = glGetUniformLocation(programId, "ambientTexture");
    std::cout << "attributes.position:" << attributes.position << std::endl;
    std::cout << "attributes.color: " << attributes.color << std::endl;
    std::cout << "uniforms.baseTransform: " << uniforms.baseTransform
              << std::endl;
    std::cout << "uniforms.ambientTexture: " << uniforms.ambientTexture<< std::endl;
}

BasicShader basicShader = BasicShader(
        "assets/shaders/id.vert", "assets/shaders/red.frag");
BasicShader textureShader = BasicShader(
        "assets/shaders/id_texture.vert", "assets/shaders/texture.frag");

