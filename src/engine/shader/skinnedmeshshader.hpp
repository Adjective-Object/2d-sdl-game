//
// Created by adjective on 4/28/17.
//

#ifndef SDL_GAME_SKINNEDMESHSHADER_H
#define SDL_GAME_SKINNEDMESHSHADER_H

#include <cstddef>
#include "engine/gl.h"
#include "primitiveshader.hpp"

class SkinnedMeshShader : public PrimitiveShader {
   public:
    size_t maxBones;
    size_t maxBonesPerVert;

    struct {
        GLint baseTransform;
        GLint boneCount;
        GLint boneMatrixArray;
        GLint boneMatrixArrayInverseTrans;
    } uniforms;
    struct {
        GLint position;
        GLint uvs;
        GLint inBoneIndex;
        GLint inBoneWeights;
    } attributes;

    SkinnedMeshShader(const char* vec,
                      const char* frag,
                      size_t max_bones,
                      size_t max_bones_per_vert);
    void init();
};

extern SkinnedMeshShader skinnedShader;

#endif  // SDL_GAME_SKINNEDMESHSHADER_H

