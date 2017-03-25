#include "engine/gl.h"
#include "engine/shader/basicshader.hpp"
#include <iostream>
#include "./lib/loadshaders.hpp"

BasicShader::BasicShader() {}
void BasicShader::init() {
    programId =
        LoadShaders("assets/shaders/id.vert", "assets/shaders/red.frag");
    attributes.position = glGetAttribLocation(programId, "position");
    attributes.color = glGetAttribLocation(programId, "vertexColor");
    uniforms.baseTransform = glGetUniformLocation(programId, "baseTransform");
    std::cout << "attributes.position:" << attributes.position << std::endl;
    std::cout << "attributes.color: " << attributes.color << std::endl;
    std::cout << "uniforms.baseTransform: " << uniforms.baseTransform
              << std::endl;
}

BasicShader basicShader;
