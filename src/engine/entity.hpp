#ifndef __ENGINE_ENTITY
#define __ENGINE_ENTITY

#include <SDL.h>
#include "engine/renderer/abstractrenderer.hpp"

class Entity {
   public:
    virtual ~Entity();
    virtual void init() = 0;

    virtual void preUpdate() = 0;
    virtual void update() = 0;
    virtual void postUpdate() = 0;

    virtual AbstractRenderer* getRenderer();
};

#endif
