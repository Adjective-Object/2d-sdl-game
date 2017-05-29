#include <iostream>
#include <vector>
#include "engine/renderer/multimeshrenderer.hpp"
#include "model.hpp"

Model::Model(std::vector<ModelMesh> meshes) : meshes(meshes) {}

MultiMeshRenderer* Model::makeRenderer() {
    std::cout << "making renderer for model" << std::endl;
    std::vector<MeshRenderer*> renderers;
    for (ModelMesh m : meshes) {
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

void Model::applyAnimation(std::string name, float time) {
    // apply animation to relevant parts of the body
    for (const ModelMesh & mesh : meshes) {
        if (mesh.animations.count(name) != 0) {
            const MeshAnim * animation = (*(mesh.animations.find(name))).second;
            animation->getTransform(time, mesh.mesh->boneTransforms);
        }
    }
}

float Model::getAnimationDuration(std::string name) const {
    float duration = 0;
    for (const ModelMesh & mesh : meshes) {
        if (mesh.animations.count(name) != 0) {
            const MeshAnim * animation = (*(mesh.animations.find(name))).second;
            float animDuration = animation->getDuration();
            if (animDuration > duration) {
                duration = animDuration;
            }
        }
    }
    return duration;
}