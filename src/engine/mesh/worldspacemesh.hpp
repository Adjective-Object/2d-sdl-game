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

    void initSkeleton(const GLfloat* boneWeights, size_t num);

    void updateMesh(const GLfloat* verts,
                    const GLfloat* colors,
                    const GLfloat* uvs);

    void updateSkeleton(const GLfloat* verts, size_t num_bones);

    GLuint vertexbuffer = -1;
    GLuint colorbuffer = -1;
    GLuint uvBuffer = -1;
    size_t num_points;

    GLuint boneWeightBuffer = -1;
    size_t num_bones;

    bool hasUvs();
    bool hasVertexColors();
};

#endif
