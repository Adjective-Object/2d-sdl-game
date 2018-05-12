#ifndef __GAME_MESH_ECB
#define __GAME_MESH_ECB

#include "engine/gl.h"
#include "engine/mesh/worldspacemesh.hpp"
#include "player/ecb.hpp"

class EcbMesh : public WorldspaceMesh {
    GLfloat vectorBuffer[36];
    GLfloat colorBuffer[36];
    WORLDSPACE_MESH_INDEX_TYPE indexBuffer[36];

   public:
    void init(Ecb& e);
    void update(Ecb& e);
};

#endif
