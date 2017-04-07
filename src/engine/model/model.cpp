#include <iostream>
#include <vector>
#include "engine/renderer/multimeshrenderer.hpp"
#include "engine/renderer/meshrenderer.hpp"
#include "engine/shader/meshshader.hpp"
#include "model.hpp"

Model::Model(std::vector<MaterialMesh> meshes) : meshes(meshes) {}

MultiMeshRenderer* Model::makeRenderer() {
    std::cout << "making renderer for model" << std::endl;
    std::vector<MeshRenderer*> renderers;
    for (MaterialMesh m : meshes) {
        MeshShader* s;
        if (m.material->hasTexture()) {
            s = &textureShader;
        } else if (m.mesh->hasVertexColors()) {
            s = &vertexColorShader;
        } else {
            s = &fallbackShader;
        }
        renderers.push_back(new MeshRenderer(s, m.mesh, m.material));
    }

    return new MultiMeshRenderer(renderers);
}
