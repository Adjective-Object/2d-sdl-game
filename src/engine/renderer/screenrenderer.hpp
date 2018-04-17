#ifndef __ENGINE_SCREEN_RENDERER
#define __ENGINE_SCREEN_RENDERER

#include <SDL.h>
#include "abstractrenderer.hpp"
#include "engine/material/material.hpp"
#include "engine/mesh/worldspacemesh.hpp"

#define GLM_FORCE_RADIANS
#include <engine/mesh/screenspacequad.hpp>
#include <engine/texture/texture.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ScreenRenderer : public AbstractRenderer {
    Material material;
    ScreenSpaceQuad* mesh;

   public:
    ScreenRenderer(Texture* texture, ScreenSpaceQuad* bounds);
    void render(glm::mat4& baseTransform) override;
};

#endif
