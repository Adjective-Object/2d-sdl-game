#include "multirenderer.hpp"
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

MultiRenderer::MultiRenderer(std::vector<AbstractRenderer*> renderers)
    : renderers(renderers) {}

void MultiRenderer::render(glm::mat4& baseTransform) {
    for (AbstractRenderer* r : renderers) {
        r->render(baseTransform);
    }
}
