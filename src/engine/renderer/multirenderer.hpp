#ifndef __ENGINE_MULTI_RENDERER
#define __ENGINE_MULTI_RENDERER

#include "abstractrenderer.hpp"
#include <vector>
#include <iostream>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

template <class T>
class MultiRenderer : public AbstractRenderer {
    protected:
    std::vector<T*> renderers;

   public:
    MultiRenderer(std::vector<T*> renderers)
        : renderers(renderers) {}

    MultiRenderer(T* renderer[])
        : renderers(std::vector<T*>(renderers)) {}

    void render(glm::mat4& baseTransform) override {
        for (AbstractRenderer* r : renderers) {
            r->render(baseTransform);
        }
    }

};


typedef MultiRenderer<AbstractRenderer> AbstractMultiRenderer;

#endif
