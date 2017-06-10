//
// Created by adjective on 4/28/17.
//

#include "skinnedmeshshader.hpp"
#include "primitiveshader.hpp"
#include "lib/loadshaders.hpp"
#include "meshshader.hpp"
#include "engine/gl.h"

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
#define MAX_BONES_PER_VERT GL_MAX_VERTEX_UNIFORM_VECTORS
#else
#warning "GL_MAX_VERTEX_UNIFORM_VECTORS not set, assuming 16"
#define MAX_BONES_PER_VERT 16
#endif

SkinnedMeshShader::SkinnedMeshShader(const char* v,
                                     const char* f,
                                     size_t maxBones,
                                     size_t maxBonesPerVert)
    : MeshShader(v, f), maxBones(maxBones), maxBonesPerVert(maxBonesPerVert) {}

SkinnedMeshShader skinnedShader("assets/shaders/skinned.vert",
                                "assets/shaders/fallback.frag",
                                MAX_BONES_PER_VERT,
                                4);
