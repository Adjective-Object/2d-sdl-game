#ifndef __ENGINE_BONEWEIGHTSET
#define __ENGINE_BONEWEIGHTSET

#include <vector>
#include "engine/gl.h"
// assimp
#include <mesh.h>

class BoneWeightLoader {
    bool initialized = false;
    std::vector<uint8_t> vertBoneCounts;
    std::vector<uint16_t> vertBoneIndecies;
    std::vector<GLfloat> vertBoneWeights;

   public:
    size_t max_bones_per_vert = 0;
    size_t numBones;

    //---

    BoneWeightLoader();
    ~BoneWeightLoader();
    bool loadMeshBoneWeights(const aiMesh* mesh,
                             const size_t max_bones_per_vert);
    bool isInitialized() const;
    const uint8_t* getBoneCounts() const;
    const uint16_t* getBoneIndecies() const;
    const GLfloat* getBoneWeights() const;

    const std::vector<uint8_t> getBoneCountsVec() const;
    const std::vector<uint16_t> getBoneIndeciesVec() const;
    const std::vector<GLfloat> getBoneWeightsVec() const;
};

#endif
