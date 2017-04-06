#ifndef __ENGINE_SCREEN_RENDERER
#define __ENGINE_SCREEN_RENDERER

#include <SDL.h>
#include "abstractrenderer.hpp"
#include "engine/material/material.hpp"
#include "engine/mesh/staticmesh.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ScreenRenderer : public AbstractRenderer {
    Material material;
    StaticMesh mesh;
    SDL_Texture* texture;
    SDL_Rect screenBoundsPixels;
    GLfloat *verts, *uvs;

    void makeBoundsMesh(SDL_Rect& bounds);

   public:
    void updateMesh(SDL_Rect& bounds);
    ScreenRenderer(SDL_Texture* texture, SDL_Rect bounds);
    void render(glm::mat4& baseTransform) override;
};

#endif
