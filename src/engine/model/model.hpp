#ifndef __ENGINE_MODEL
#define __ENGINE_MODEL

#include <map>
#include <string>
#include "engine/mesh/worldspacemesh.hpp"
#include "engine/material/material.hpp"
#include "engine/renderer/multimeshrenderer.hpp"
#include <vector>
#include "engine/meshanim/meshanim.hpp"
#include "modelmesh.hpp"

class Model {
   public:
    Model(std::vector<ModelMesh>);
    MultiMeshRenderer* makeRenderer();

    std::vector<ModelMesh> meshes;

    void applyAnimation(std::string name, float time);
    float getAnimationDuration(std::string name) const;
};

#endif
