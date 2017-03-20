#ifndef __ENGINE_SCENE
#define __ENGINE_SCENE
#include <SDL.h>
#include <vector>

#include "entity.hpp"
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>


class Scene {
   protected:
    // SCENE INTERNAL STATE
    std::vector<Entity*> entities;
    glm::mat4 projectionMatrix;
    glm::mat4 cameraMatrix;

   public:
    // INTERFACE

    // called by Game to initialize the scene's content
    virtual void init();

    /**
     * Starts the game's main loop
     */
    virtual void start();

    /**
     * Update step of the scene's main loop
     */
    virtual void update();

    /**
     * Render step of the scene's main loop
     **/
    virtual void render();

    Scene();
    ~Scene();
};

#endif
