#include "entity.hpp"
#include "renderer/abstractrenderer.hpp"

// destructors cannot be pure virtual
Entity::~Entity() {}

AbstractRenderer* Entity::getRenderer() {
    return NULL;
}
