//
// Created by adjective on 4/28/17.
//

#ifndef SDL_GAME_SKINNEDMESHSHADER_H
#define SDL_GAME_SKINNEDMESHSHADER_H

#include <cstddef>
#include "engine/gl.h"
#include "meshshader.hpp"
#include "primitiveshader.hpp"

class SkinnedMeshShader : public MeshShader {
   public:
    size_t maxBones;
    size_t maxBonesPerVert;

    SkinnedMeshShader(const char* vec,
                      const char* frag,
                      size_t max_bones,
                      size_t max_bones_per_vert);

    void init() override;
};

extern SkinnedMeshShader skinnedShader;

#endif  // SDL_GAME_SKINNEDMESHSHADER_H
