//
// Created by adjective on 4/28/17.
//

#include "skinnedmeshshader.hpp"
#include "primitiveshader.hpp"

SkinnedMeshShader::SkinnedMeshShader(const char* v,
                                     const char* f,
                                     size_t maxBones,
                                     size_t maxBonesPerVert)
    : PrimitiveShader(v, f),
      maxBones(maxBones),
      maxBonesPerVert(maxBonesPerVert) {}
void SkinnedMeshShader::init() {
    PrimitiveShader::init();

    attributes.position = glGetAttribLocation(programId, "position");
    attributes.uvs = glGetAttribLocation(programId, "uvs");
    uniforms.baseTransform = glGetUniformLocation(programId, "baseTransform");
}

MeshShader vertexColorShader =
    MeshShader("assets/shaders/id.vert", "assets/shaders/red.frag");
