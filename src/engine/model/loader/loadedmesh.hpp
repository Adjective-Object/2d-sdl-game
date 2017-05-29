#ifndef __ENGINE_LOADEDMESH_H
#define __ENGINE_LOADEDMESH_H

#include <engine/model/modelmesh.hpp>
// assimp
#include <mesh.h>

class LoadedMesh {
   public:
    LoadedMesh(ModelMesh, const aiMesh*);
    ModelMesh loadedMesh;
    const aiMesh* sourceMesh;
};

#endif
