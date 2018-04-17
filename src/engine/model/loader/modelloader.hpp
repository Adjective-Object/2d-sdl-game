#ifndef __ENGINE_MODEL_LOADER
#define __ENGINE_MODEL_LOADER

// assimp
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include "engine/model/model.hpp"
#include "loadedmesh.hpp"

class ModelLoader {
    const aiScene* scene = NULL;
    Assimp::Importer importer;

   public:
    ModelLoader();
    bool load(const char* fpath);
    Model* queryScene(const char* scenepath);
};

#endif
