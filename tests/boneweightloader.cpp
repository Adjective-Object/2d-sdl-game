#include "gtest/gtest.h"
#include "engine/gl.h"
// assimp includes
#include <assimp/mesh.h>
#include <engine/model/loader/boneweightloader.hpp>

aiBone* makeBone(const char* name,
                 aiVertexWeight weights[],
                 unsigned int numWeights) {
    aiVertexWeight* heapedWeights = new aiVertexWeight[numWeights];
    memcpy(heapedWeights, weights, numWeights * sizeof(aiVertexWeight));

    aiBone* bone = new aiBone();
    bone->mName = aiString(name);
    bone->mNumWeights = numWeights;
    bone->mOffsetMatrix = aiMatrix4x4();
    bone->mWeights = heapedWeights;

    return bone;
}

void makeMesh(aiMesh& mesh,
              unsigned int numPoints,
              aiBone* bonesStack[],
              unsigned int numBones) {
    mesh.mNumVertices = numPoints;
    mesh.mNumBones = numBones;
    mesh.mBones = new aiBone*[numBones];
    memcpy(mesh.mBones, bonesStack, sizeof(aiBone*) * numBones);
}

// construct a dummy model and assert that the weights are being loaded
// appropriately
// note that when using assimp bones, we must always be using heaped values, as
// the destructors for these objects free their internal buffers.
TEST(BoneWeightLoader, loadMeshBoneWeights_SingleBone) {
    aiMesh mesh;
    aiVertexWeight bone1Weights[] = {
        aiVertexWeight(// vertex 1
          1, // mVertexId,
          0.5 //mWeight
          ),

        aiVertexWeight(// vertex 2
          3, // mVertexId,
          0.3 //mWeight
          ),

        aiVertexWeight(// vertex 3
          0, // mVertexId,
          0.2 //mWeight
          ),
    };
    aiBone* b1 = makeBone("bone1", bone1Weights, 3);
    aiBone* bonesStack[] = {b1};
    makeMesh(mesh, 4, bonesStack, 1);

    // initialize the bone weight set

    BoneWeightLoader boneWeights;
    bool loaded = boneWeights.loadMeshBoneWeights(&mesh, 8);
    ASSERT_TRUE(loaded);

    // check output is valid

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

TEST(BoneWeightLoader, loadMeshBoneWeights_MultiBone) {
    aiMesh mesh;
    aiVertexWeight bone1Weights[] = {
        aiVertexWeight(// vertex 1
          1, // mVertexId,
          0.5 //mWeight
          ),

        aiVertexWeight(// vertex 2
          3, // mVertexId,
          0.3 //mWeight
          ),

        aiVertexWeight(// vertex 3
          0, // mVertexId,
          0.2 //mWeight
          ),
    };
    aiBone* b1 = makeBone("bone1", bone1Weights, 3);

    aiVertexWeight bone2Weights[] = {
        aiVertexWeight(// vertex 2
          3, // mVertexId,
          0.9 //mWeight
          ),

        aiVertexWeight(// vertex 3
          0, // mVertexId,
          1.0 //mWeight
          ),
    };
    aiBone* b2 = makeBone("bone2", bone2Weights, 2);
    aiBone* bonesStack[] = {b1, b2};

    makeMesh(mesh, 4, bonesStack, 2);

    // initialize the bone weight set

    BoneWeightLoader boneWeights;
    bool loaded = boneWeights.loadMeshBoneWeights(&mesh, 8);
    ASSERT_TRUE(loaded);

    // check output is valid

    std::vector<uint8_t> expectedBoneCounts = {
        2, 1, 0, 2,
    };

    std::vector<uint16_t> expectedBoneIndecies = {
        0,      1,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0,      1,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    };

    std::vector<GLfloat> expectedBoneWeights = {
        0.2, 1.0, 0, 0, 0, 0, 0, 0, 0.5, 0.0, 0, 0, 0, 0, 0, 0,
        0.0, 0.0, 0, 0, 0, 0, 0, 0, 0.3, 0.9, 0, 0, 0, 0, 0, 0,
    };

    EXPECT_EQ(boneWeights.getBoneCountsVec(), expectedBoneCounts);
    EXPECT_EQ(boneWeights.getBoneIndeciesVec(), expectedBoneIndecies);
    EXPECT_EQ(boneWeights.getBoneWeightsVec(), expectedBoneWeights);
}
