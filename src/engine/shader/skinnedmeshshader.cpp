//
// Created by adjective on 4/28/17.
//

#include "skinnedmeshshader.hpp"
#include "primitiveshader.hpp"
#include "lib/loadshaders.hpp"
#include "meshshader.hpp"
#include "engine/gl.h"

SkinnedMeshShader::SkinnedMeshShader(const char* v,
                                     const char* f,
                                     size_t maxBones,
                                     size_t maxBonesPerVert)
    : MeshShader(v, f), maxBones(maxBones), maxBonesPerVert(maxBonesPerVert) {}

SkinnedMeshShader skinnedShader("assets/shaders/skinned.vert",
                                "assets/shaders/fallback.frag",
                                24,
                                4);
