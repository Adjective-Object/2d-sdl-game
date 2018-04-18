#ifndef __ENGINE_STATICMESH
#define __ENGINE_STATICMESH

#include <stddef.h>
#include <glm/mat4x4.hpp>
#include "engine/gl.h"

/**
 * Represnts a 3d mesh within worldspace
 */
class WorldspaceMesh {
   public:
    void init(const GLfloat* verts,
              const GLfloat* colors,
              const GLfloat* uvs,
              size_t num);

    void initSkeleton(const uint8_t* vertBoneCounts,
                      const uint16_t* vertBoneIndecies,
                      const GLfloat* boneWeights,
                      size_t num_weights_per_point,
                      size_t num);

    void updateMesh(const GLfloat* verts,
                    const GLfloat* colors,
                    const GLfloat* uvs);

    void updateSkeleton(const uint8_t* vertBoneCounts,
                        const uint16_t* vertBoneIndecies,
                        const GLfloat* boneWeights,
                        size_t num_weights_per_point,
                        size_t num_bones);

    GLuint vertexbuffer = -1;
    GLuint colorbuffer = -1;
    GLuint uvBuffer = -1;
    size_t num_points;

    GLuint boneWeightBuffer = -1;
    GLuint boneIndexBuffer = -1;
    GLuint boneCountBuffer = -1;
    size_t num_bones;
    size_t num_weights_per_point;

    GLuint vertexArray = -1;
    GLuint colorArray = -1;
    GLuint uvArray = -1;
    GLuint boneWeightArray = -1;
    GLuint boneIndexArray = -1;
    GLuint boneCountArray = -1;

    glm::mat4* boneTransforms = NULL;

    bool hasSkeleton() const;
    bool hasUvs() const;
    bool hasVertexColors() const;
};

#endif
