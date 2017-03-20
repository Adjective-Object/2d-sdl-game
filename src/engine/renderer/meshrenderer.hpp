#ifndef __ENGINE_MESH_RENDERER
#define __ENGINE_MESH_RENDERER
#include "abstractrenderer.hpp"
#include "engine/model/staticmesh.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

class BasicShader {
public:
	GLuint programId;
    struct {
        GLint baseTransform;
    } uniforms;
    struct {
        GLint color;
        GLint position;
    } attributes;
	BasicShader();
};

class MeshRenderer : public AbstractRenderer {
    StaticMesh mesh;
    BasicShader shader;
    glm::mat4 modelTransform;

   public:
    MeshRenderer(StaticMesh mesh);
    virtual void render(glm::mat4 & baseTransform) override;
    void setModelTransform(glm::mat4 newModelTransform);
};

#endif
