#ifndef __ENGINE_MODEL
#define __ENGINE_MODEL

#include <map>
#include <string>
#include <vector>
#include "engine/material/material.hpp"
#include "engine/mesh/worldspacemesh.hpp"
#include "engine/meshanim/meshanim.hpp"
#include "engine/renderer/multimeshrenderer.hpp"
#include "modelmesh.hpp"

/*
 * Model : Handles a number of associated meshes with shared animations
 */
class Model {
   public:
    Model(std::vector<ModelMesh>);
    MultiMeshRenderer* makeRenderer();

    std::vector<ModelMesh> meshes;

    void applyAnimation(std::string name, float time);
    float getAnimationDuration(std::string name) const;
};

#endif
