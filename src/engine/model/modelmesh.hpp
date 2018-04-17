#ifndef __ENGINE_MODELMESH_H
#define __ENGINE_MODELMESH_H

#include <map>
#include <string>
#include "engine/material/material.hpp"
#include "engine/mesh/worldspacemesh.hpp"
#include "engine/meshanim/meshanim.hpp"

class ModelMesh {
   public:
    Material* material;
    WorldspaceMesh* mesh;
    std::map<std::string, MeshAnim*> animations;
};

#endif
