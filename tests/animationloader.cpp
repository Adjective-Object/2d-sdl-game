#include <gtest/gtest.h>
#include <glm/gtx/string_cast.hpp>
// assimp
#include <scene.h>
#include <Importer.hpp>
#include <engine/model/loader/AnimationLoader.hpp>

#define EXPECT_MATRIX_NEAR(a, b, msg)                                       \
    {                                                                       \
        float diff = 0;                                                     \
        for (size_t x = 0; x < 4; x++) {                                    \
            for (size_t y = 0; y < 4; y++) {                                \
                diff += std::abs(a[x][y] - b[x][y]);                        \
            }                                                               \
        }                                                                   \
                                                                            \
        EXPECT_NEAR(diff, 0, 0.00001) << msg << std::endl                   \
                                      << glm::to_string(b - a) << std::endl \
                                      << glm::to_string(a) << std::endl     \
                                      << glm::to_string(b);                 \
    }

TEST(AnimationLoader, loadEmptyAnimation) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile("test-assets/cube_move.dae", 0);
    // check that the file has some constraints we expect
    ASSERT_EQ(scene->mNumMeshes, 1);
    ASSERT_EQ(std::string(scene->mMeshes[0]->mName.C_Str()), "Cube");
    ASSERT_EQ(scene->mMeshes[0]->mNumBones, 1);
    ASSERT_EQ(scene->mNumAnimations, 1);

    // grab the things we care about and import them

    const aiMesh* mesh = scene->mMeshes[0];
    const aiAnimation* animation = scene->mAnimations[0];

    MeshAnim* loadedAnimation =
        AnimationLoader::makeModelAnimation(mesh, animation);

    ASSERT_EQ(loadedAnimation->getNumFrames(), 2);

    glm::mat4 expectedInitialTrans =
        glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    glm::mat4 expectedMiddleTransform =
        glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0.865774, 0, 0, 0, 1);

    glm::mat4 expectedFinalTrans =
        glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1.731548, 0, 0, 0, 1);

    // check that the transforms were saved correctly
    glm::mat4 savedInitialTransform = loadedAnimation->frames[0]->transforms[0];
    glm::mat4 savedFinalTransform = loadedAnimation->frames[1]->transforms[0];
    EXPECT_MATRIX_NEAR(savedInitialTransform, expectedInitialTrans,
                       "saved initial transform");
    EXPECT_MATRIX_NEAR(savedFinalTransform, expectedFinalTrans,
                       "saved final transform");

    // check that the transforms are interpolated properly
    glm::mat4 animTrans;
    loadedAnimation->getTransform(0, &animTrans);
    EXPECT_MATRIX_NEAR(animTrans, expectedInitialTrans,
                       "interpolated initial transform");

    loadedAnimation->getTransform(loadedAnimation->getDuration() / 2,
                                  &animTrans);
    EXPECT_MATRIX_NEAR(animTrans, expectedMiddleTransform,
                       "interpolated middle transform");

    loadedAnimation->getTransform(loadedAnimation->getDuration(), &animTrans);
    EXPECT_MATRIX_NEAR(animTrans, expectedFinalTrans,
                       "interpolated final transform");
}