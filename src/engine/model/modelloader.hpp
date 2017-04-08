#ifndef __ENGINE_MODEL_LOADER
#define __ENGINE_MODEL_LOADER

// assimp
#include <scene.h>
#include <mesh.h>
#include <Importer.hpp>
#include "model.hpp"

class LoadedMesh {
   public:
    LoadedMesh(ModelMesh, const aiMesh*);
    ModelMesh loadedMesh;
    const aiMesh* sourceMesh;
};

class ModelLoader {
    const aiScene* scene = NULL;
    Assimp::Importer importer;
    SDL_Renderer* renderCtx;

   public:
    ModelLoader(SDL_Renderer* renderCtx);
    bool load(const char* fpath);
    Model* queryScene(const char* scenepath);
};

#endif
