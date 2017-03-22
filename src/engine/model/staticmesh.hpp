#ifndef __ENGINE_STATICMESH
#define __ENGINE_STATICMESH

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

class StaticMesh {
   public:
    void init(const GLfloat* verts, const GLfloat* colors, size_t num);
    void updateMesh(const GLfloat* verts, const GLfloat* colors);

    GLuint vertexbuffer;
    GLuint colorbuffer;
    size_t num_points;
};

#endif
