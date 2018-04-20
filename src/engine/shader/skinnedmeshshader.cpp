//
// Created by adjective on 4/28/17.
//

#include "skinnedmeshshader.hpp"
#include "engine/gl.h"
#include "lib/loadshaders.hpp"
#include "meshshader.hpp"
#include "primitiveshader.hpp"

SkinnedMeshShader::SkinnedMeshShader(const char* v,
                                     const char* f,
                                     size_t maxBones,
                                     size_t maxBonesPerVert)
    : MeshShader(v, f), maxBones(maxBones), maxBonesPerVert(maxBonesPerVert) {
    std::cout << "initialized skinned mesh shader @ " << this << std::endl;
}

SkinnedMeshShader skinnedShader("assets/shaders/skinned.vert",
                                "assets/shaders/id.frag",
                                24,
                                4);

void SkinnedMeshShader::init() {
    defines["MAX_BONES"] = std::to_string(maxBones);
    defines["MAX_BONES_PER_VERT"] = std::to_string(maxBonesPerVert);

    MeshShader::init();
}
