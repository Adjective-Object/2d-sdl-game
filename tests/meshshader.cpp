#include <engine/shader/meshshader.hpp>
#include "gtest/gtest.h"
//
// Created by adjective on 5/29/17.
//

class TEST_MeshShader : public MeshShader {
    // expose some mesh shader stuff for testing transparently
    // mesh shader contains its own file-loading logic which means
    // programmatic shaders are an issue. Rather than redo this
    // for testing (as programmatic shaders aren't really something
    // in scope at the moment), we expose the internals for testing.
public:
    TEST_MeshShader() : MeshShader ("", "") {
    }
    void setUniformStruct(MeshShaderUniforms u) {
        uniforms = u;
    }
    void setAttributeStruct(MeshShaderAttributes a) {
        attributes = a;
    }
};

TEST(MeshShader, hasUniform) {
    TEST_MeshShader shader;
    shader.setUniformStruct((MeshShaderUniforms){
        .baseTransform = -1,
        .ambientTexture = -1,
        .boneMatrixArray = -1,
        .boneMatrixArrayInverseTrans = -1,
    });

    EXPECT_FALSE(shader.hasUniform(baseTransform));
    EXPECT_FALSE(shader.hasUniform(ambientTexture));
    EXPECT_FALSE(shader.hasUniform(boneMatrixArray));
    EXPECT_FALSE(shader.hasUniform(boneMatrixArrayInverseTrans));

    shader.setUniformStruct((MeshShaderUniforms){
            .baseTransform = 1,
            .ambientTexture = -1,
            .boneMatrixArray = 1,
            .boneMatrixArrayInverseTrans = -1,
    });

    EXPECT_TRUE(shader.hasUniform(baseTransform));
    EXPECT_FALSE(shader.hasUniform(ambientTexture));
    EXPECT_TRUE(shader.hasUniform(boneMatrixArray));
    EXPECT_FALSE(shader.hasUniform(boneMatrixArrayInverseTrans));

}


TEST(MeshShader, hasAttribute) {
    TEST_MeshShader shader;
    shader.setAttributeStruct((MeshShaderAttributes){
        .position = -1,
        .uvs = -1,
        .vertexColor = -1,
        .boneCount = -1,
        .inBoneIndex = -1,
        .inBoneWeights = -1,
    });

    EXPECT_FALSE(shader.hasAttribute(position));
    EXPECT_FALSE(shader.hasAttribute(uvs));
    EXPECT_FALSE(shader.hasAttribute(vertexColor));
    EXPECT_FALSE(shader.hasAttribute(boneCount));
    EXPECT_FALSE(shader.hasAttribute(inBoneIndex));
    EXPECT_FALSE(shader.hasAttribute(inBoneWeights));

    shader.setAttributeStruct((MeshShaderAttributes){
            .position = -1,
            .uvs = 1,
            .vertexColor = 1,
            .boneCount = -1,
            .inBoneIndex = -1,
            .inBoneWeights = 1,
    });

    EXPECT_FALSE(shader.hasAttribute(position));
    EXPECT_TRUE(shader.hasAttribute(uvs));
    EXPECT_TRUE(shader.hasAttribute(vertexColor));
    EXPECT_FALSE(shader.hasAttribute(boneCount));
    EXPECT_FALSE(shader.hasAttribute(inBoneIndex));
    EXPECT_TRUE(shader.hasAttribute(inBoneWeights));

}

