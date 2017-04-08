#ifndef __ENGINE_STATICMESH
#define __ENGINE_STATICMESH

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

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

    bool hasSkeleton() const;
    bool hasUvs() const;
    bool hasVertexColors() const;
};

#endif
