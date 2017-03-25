#ifndef __ENGINE_MODEL_LOADER
#define __ENGINE_MODEL_LOADER

// assimp
#include <scene.h>
#include <Importer.hpp>
// mesh loaders
#include "staticmesh.hpp"

class StaticMeshLoader {
    const aiScene* scene = NULL;
    Assimp::Importer importer;

   public:
    StaticMeshLoader();
    bool load(const char* fpath);
    StaticMesh* queryScene(const char* scenepath);
};

#endif
