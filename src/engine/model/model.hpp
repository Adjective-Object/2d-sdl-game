#ifndef __ENGINE_MODEL
#define __ENGINE_MODEL

#include "engine/mesh/worldspacemesh.hpp"
#include "engine/material/material.hpp"
#include "engine/renderer/multimeshrenderer.hpp"
#include <vector>

struct MaterialMesh {
    Material* material;
    WorldspaceMesh* mesh;
};

class Model {
    std::vector<MaterialMesh> meshes;

   public:
    Model(std::vector<MaterialMesh>);
    MultiMeshRenderer* makeRenderer();
};

#endif
