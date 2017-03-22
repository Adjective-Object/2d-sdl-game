#ifndef __GAME_MESH_ECB
#define __GAME_MESH_ECB

#include "engine/model/staticmesh.hpp"
#include "player/ecb.hpp"
#include "engine/gl.h"

class EcbMesh : public StaticMesh {
    GLfloat vectorBuffer[36];
    GLfloat colorBuffer[36];

   public:
    void init(Ecb& e);
    void update(Ecb& e);
};

#endif
