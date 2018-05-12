// lib
#include <iostream>
// assimp
#include <assimp/mesh.h>
// locals
#include "boneweightloader.hpp"
#include "engine/gl.h"

BoneWeightLoader::BoneWeightLoader() {}
BoneWeightLoader::~BoneWeightLoader() {}
bool BoneWeightLoader::isInitialized() const {
    return initialized;
}

const uint8_t* BoneWeightLoader::getBoneCounts() const {
    return &vertBoneCounts[0];
}

const uint16_t* BoneWeightLoader::getBoneIndecies() const {
    return &vertBoneIndecies[0];
}

const GLfloat* BoneWeightLoader::getBoneWeights() const {
    return &vertBoneWeights[0];
}

const std::vector<uint8_t> BoneWeightLoader::getBoneCountsVec() const {
    return vertBoneCounts;
}

const std::vector<uint16_t> BoneWeightLoader::getBoneIndeciesVec() const {
    return vertBoneIndecies;
}

const std::vector<GLfloat> BoneWeightLoader::getBoneWeightsVec() const {
    return vertBoneWeights;
}

bool BoneWeightLoader::loadMeshBoneWeights(const aiMesh* mesh,
                                           const size_t max_bones_per_vert) {
    if (mesh->HasBones()) {
        this->max_bones_per_vert = max_bones_per_vert;
        size_t numWeights = mesh->mNumVertices * max_bones_per_vert;

        // prepare bone count matrix
        vertBoneCounts = std::vector<uint8_t>(mesh->mNumVertices);
        std::fill(vertBoneCounts.begin(), vertBoneCounts.end(), 0);

        // prepare bone index matrix
        vertBoneIndecies = std::vector<uint16_t>(numWeights);
        std::fill(vertBoneIndecies.begin(), vertBoneIndecies.end(), 0xFFFF);

        // prepare bone weight matrix
        vertBoneWeights = std::vector<GLfloat>(numWeights);
        std::fill(vertBoneWeights.begin(), vertBoneWeights.end(), 0);

        numBones = mesh->mNumBones;
        if (mesh->mNumBones >= 0xFFFF) {
            std::cout << "error: mesh has more than 0xFFFF bones. ignoring em"
                      << std::endl;
            numBones = 0xFFFF;
        }

        for (uint16_t boneIndex = 0; boneIndex < numBones; boneIndex++) {
            aiBone* bone = mesh->mBones[boneIndex];
            for (size_t weightIndex = 0; weightIndex < bone->mNumWeights;
                 weightIndex++) {
                aiVertexWeight weight = bone->mWeights[weightIndex];
                size_t currBones = vertBoneCounts[weight.mVertexId];
                if (currBones == max_bones_per_vert) {
                    std::cout << "error: vertex " << weight.mVertexId
                              << "has more than " << max_bones_per_vert
                              << " bone weights. "
                              << "Discarding additional bone weights "
                              << "(bone " << boneIndex << ")" << std::endl;
                    continue;
                }

                vertBoneIndecies[weight.mVertexId * max_bones_per_vert +
                                 currBones] = boneIndex;
                vertBoneWeights[weight.mVertexId * max_bones_per_vert +
                                currBones] = weight.mWeight;
                vertBoneCounts[weight.mVertexId]++;
            }
        }
        initialized = true;
        return true;
    }
    return false;
}
