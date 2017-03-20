#ifndef __ENGINE_ABSTRACT_RENDERER
#define __ENGINE_ABSTRACT_RENDERER

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class AbstractRenderer {
   public:
    virtual void render(glm::mat4 & baseTransform) = 0;
};

#endif
