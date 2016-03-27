#ifndef __ENGINE_ENTITY
#define __ENGINE_ENTITY

#include <SDL.h>

class Entity {
public:
    virtual ~Entity();
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif
