#ifndef __ENGINE_MULTI_RENDERER
#define __ENGINE_MULTI_RENDERER

#include "abstractrenderer.hpp"
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class MultiRenderer : public AbstractRenderer {
    std::vector<AbstractRenderer*> renderers;

   public:
    MultiRenderer(std::vector<AbstractRenderer*> renderers);
    void render(glm::mat4& baseTransform) override;
};

#endif
