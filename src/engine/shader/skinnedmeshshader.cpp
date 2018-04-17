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
    : MeshShader(v, f), maxBones(maxBones), maxBonesPerVert(maxBonesPerVert) {}

SkinnedMeshShader skinnedShader("assets/shaders/skinned.vert",
                                "assets/shaders/fallback.frag",
                                24,
                                4);
