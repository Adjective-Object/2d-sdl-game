#ifndef __ENGINE_MODEL
#define __ENGINE_MODEL

#include <map>
#include <string>
#include "engine/mesh/worldspacemesh.hpp"
#include "engine/material/material.hpp"
#include "engine/renderer/multimeshrenderer.hpp"
#include <vector>
#include "engine/meshanim/meshanim.hpp"
#include "modelmesh.h"

class Model {
    std::vector<ModelMesh> meshes;

   public:
    Model(std::vector<ModelMesh>);
    MultiMeshRenderer* makeRenderer();
};

#endif
