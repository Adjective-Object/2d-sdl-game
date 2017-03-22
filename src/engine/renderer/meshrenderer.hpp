#ifndef __ENGINE_MESH_RENDERER
#define __ENGINE_MESH_RENDERER
#include "abstractrenderer.hpp"
#include "engine/model/staticmesh.hpp"
#include "engine/shader/basicshader.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

class MeshRenderer : public AbstractRenderer {
    StaticMesh* mesh;
    BasicShader* shader;
    glm::mat4 modelTransform;

   public:
    MeshRenderer(BasicShader* shader, StaticMesh* mesh);
    virtual void render(glm::mat4& baseTransform) override;
    void setModelTransform(glm::mat4 newModelTransform);
};

#endif
