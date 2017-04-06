#ifndef __ENGINE_MULTI_MESHRENDERER
#define __ENGINE_MULTI_MESHRENDERER

#include "multirenderer.hpp"
#include "meshrenderer.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class MultiMeshRenderer : public MultiRenderer<MeshRenderer> {
   public:
    MultiMeshRenderer(std::vector<MeshRenderer*>);
    void setModelTransform(glm::mat4& newModelTransform);
};

#endif
