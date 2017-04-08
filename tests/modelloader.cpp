#include "gtest/gtest.h"
#include "engine/gl.h"
// assimp includes
#include <mesh.h>
#include <matrix4x4.h>
#include <engine/model/boneweightset.hpp>

// construct a dummy model and assert tht the weights are being loaded
// appropriately
// note that when using assimp bones, we must always be using heaped values, as
// the destructors for these objects free their internal buffers.
TEST(ModelLoader, loadMeshBoneWeights_SingleBone) {
    aiMesh mesh;
    mesh.mNumBones = 1;
    mesh.mNumVertices = 4;
    aiVertexWeight bone1Weights[] = {
        {// vertex 1
         .mVertexId = 1,
         .mWeight = 0.5},

        {// vertex 2
         .mVertexId = 3,
         .mWeight = 0.3},

        {// vertex 3
         .mVertexId = 0,
         .mWeight = 0.2},
    };
    aiVertexWeight* bone1WeightsHeap = new aiVertexWeight[3];
    memcpy(bone1WeightsHeap, &bone1Weights, sizeof(aiVertexWeight) * 3);

    aiBone* b1 = new aiBone();
    b1->mName = aiString("bone1");
    b1->mNumWeights = 3;
    b1->mOffsetMatrix = aiMatrix4x4();
    b1->mWeights = bone1WeightsHeap;

    aiBone** bones = new aiBone*[1];
    bones[0] = b1;

    mesh.mBones = bones;

    BoneWeightSet boneWeights;
    bool loaded = boneWeights.loadMeshBoneWeights(&mesh, 8);
    ASSERT_TRUE(loaded);

    std::vector<uint8_t> expectedBoneCounts = {
        1, 1, 0, 1,
    };

    std::vector<uint16_t> expectedBoneIndecies = {
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    };

    std::vector<GLfloat> expectedBoneWeights = {
        0.2, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0,
        0.0, 0, 0, 0, 0, 0, 0, 0, 0.3, 0, 0, 0, 0, 0, 0, 0,
    };

    EXPECT_EQ(boneWeights.getBoneCountsVec(), expectedBoneCounts);
    EXPECT_EQ(boneWeights.getBoneIndeciesVec(), expectedBoneIndecies);
    EXPECT_EQ(boneWeights.getBoneWeightsVec(), expectedBoneWeights);
}