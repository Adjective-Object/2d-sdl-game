#include <iostream>
#include <vector>
#include "engine/renderer/multimeshrenderer.hpp"
#include "engine/renderer/meshrenderer.hpp"
#include "engine/shader/basicshader.hpp"
#include "model.hpp"

Model::Model(std::vector<MaterialMesh> meshes) : meshes(meshes) {}

MultiMeshRenderer* Model::makeRenderer() {
    std::cout << "making renderer for model" << std::endl;
    std::vector<MeshRenderer*> renderers;
    for (MaterialMesh m : meshes) {
        BasicShader* s =
            m.material->hasTexture() ? &textureShader : &basicShader;
        renderers.push_back(new MeshRenderer(s, m.mesh, m.material));
    }

    return new MultiMeshRenderer(renderers);
}
