#include <vector>
#include "multimeshrenderer.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

MultiMeshRenderer::MultiMeshRenderer(std::vector<MeshRenderer*> v)
    : MultiRenderer<MeshRenderer>(v) {}
void MultiMeshRenderer::setModelTransform(glm::mat4& baseTransform) {
    for (MeshRenderer* r : renderers) {
        r->setModelTransform(baseTransform);
    }
}
