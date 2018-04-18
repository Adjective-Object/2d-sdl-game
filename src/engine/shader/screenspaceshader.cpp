#include "screenspaceshader.hpp"
#include <iostream>

ScreenShader::ScreenShader(const char* v, const char* f)
    : PrimitiveShader(v, f) {}
void ScreenShader::init() {
    PrimitiveShader::init();

    uniforms.screenDimensions =
        _glGetUniformLocation(programId, "screenDimensions");
    uniforms.ambientTexture = _glGetUniformLocation(programId, "ambientTexture");

    attributes.uvs = _glGetAttribLocation(programId, "uvs");
    attributes.pixelPosition = _glGetAttribLocation(programId, "pixelPosition");

    std::cout << "uniforms.screenDimensions: " << uniforms.screenDimensions
              << std::endl;
    std::cout << "uniforms.ambientTexture: " << uniforms.ambientTexture
              << std::endl;
    std::cout << "attributes.pixelPosition: " << attributes.pixelPosition
              << std::endl;
    std::cout << "attributes.uvs:" << attributes.uvs << std::endl;
}

ScreenShader screenShader("assets/shaders/screen_shader.vert",
                          "assets/shaders/screen_shader.frag");
