//
// Created by adjective on 4/28/17.
//

#include "skinnedmeshshader.hpp"
#include "primitiveshader.hpp"
#include "lib/loadshaders.hpp"

SkinnedMeshShader::SkinnedMeshShader(const char* v,
                                     const char* f,
                                     size_t maxBones,
                                     size_t maxBonesPerVert)
    : PrimitiveShader(v, f),
      maxBones(maxBones),
      maxBonesPerVert(maxBonesPerVert) {}
void SkinnedMeshShader::init() {
    defines["MAX_BONES"] = std::to_string(16);
    defines["MAX_BONES_PER_VERT"] = std::to_string(4);
    PrimitiveShader::init();

    attributes.position = glGetAttribLocation(programId, "position");
    attributes.uvs = glGetAttribLocation(programId, "uvs");
    uniforms.baseTransform = glGetUniformLocation(programId, "baseTransform");
}

SkinnedMeshShader skinnedShader(
        "assets/shaders/skinned.vert",
        "assets/shaders/texture.frag",
        GL_MAX_VERTEX_UNIFORM_VECTORS,
        4
        );

