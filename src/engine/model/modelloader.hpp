#ifndef __ENGINE_MODEL_LOADER
#define __ENGINE_MODEL_LOADER

// assimp
#include <scene.h>
#include <Importer.hpp>
#include "model.hpp"

class ModelLoader {
    const aiScene* scene = NULL;
    Assimp::Importer importer;

   public:
    ModelLoader();
    bool load(const char* fpath);
    Model* queryScene(const char* scenepath);
};

#endif
