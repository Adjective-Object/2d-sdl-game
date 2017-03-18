#ifndef __ENGINE_MESH_RENDERER
#define __ENGINE_MESH_RENDERER
#include "abstractrenderer.hpp"
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

class MeshRenderer : public AbstractRenderer {
    GLuint vertexbuffer;
    GLuint shaderId;

   public:
    MeshRenderer();
    virtual void render();
    void setBaseTransform();
};

#endif
