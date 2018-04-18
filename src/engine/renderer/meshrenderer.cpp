#include "meshrenderer.hpp"
#include <iostream>
#include <vector>
#include "engine/game.hpp"
#include "engine/gl.h"
#include "engine/mesh/worldspacemesh.hpp"

#define GLM_FORCE_RADIANS
#include <engine/shader/meshshader.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

MeshRenderer::MeshRenderer(MeshShader* shader,
                           WorldspaceMesh* mesh,
                           Material* material)
    : mesh(mesh), shader(shader), material(material) {}

void MeshRenderer::render(mat4& baseTransform) {
    // Draw using this specific shader
    _glUseProgram(shader->programId);

    // get base transform and pass to the shader
    mat4 compoundTransform = baseTransform * modelTransform;
    _glUniformMatrix4fv(shader->uniforms.baseTransform, 1, GL_FALSE,
                       &compoundTransform[0][0]);

    // if the shader has a texture and the model has UVs, load them
    if (material && material->hasTexture() && mesh->hasUvs() &&
        shader->hasAttribute(uvs)) {
        _glActiveTexture(GL_TEXTURE0);
        _glBindTexture(GL_TEXTURE_2D, material->ambientTexture->getTextureID());
        _glUniform1i(shader->uniforms.ambientTexture, 0);

        _glBindBuffer(GL_ARRAY_BUFFER, mesh->uvBuffer);
        _glEnableVertexAttribArray(shader->attributes.uvs);
        _glVertexAttribPointer(shader->attributes.uvs,
                              2,         // size
                              GL_FLOAT,  // type
                              GL_FALSE,  // normalized?
                              0,         // stride
                              (void*)0   // array buffer offset
        );
    }

    _glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexbuffer);
    _glBindVertexArray(mesh->vertexArray);
    _glEnableVertexAttribArray(shader->attributes.position);
    _glVertexAttribPointer(shader->attributes.position,
                          3,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
    );

    if (mesh->hasVertexColors() && shader->hasAttribute(vertexColor)) {
        _glBindBuffer(GL_ARRAY_BUFFER, mesh->colorbuffer);
        _glEnableVertexAttribArray(shader->attributes.vertexColor);
        _glVertexAttribPointer(shader->attributes.vertexColor,
                              3,         // size
                              GL_FLOAT,  // type
                              GL_FALSE,  // normalized?
                              0,         // stride
                              (void*)0   // array buffer offset
        );
    }

    if (mesh->hasSkeleton() && shader->hasAttribute(boneCount) &&
        shader->hasAttribute(inBoneIndex) &&
        shader->hasAttribute(inBoneWeights) &&
        shader->hasUniform(boneMatrixArray) &&
        shader->hasUniform(boneMatrixArrayInverseTrans)) {
        // load bone attributes
        _glBindBuffer(GL_ARRAY_BUFFER, mesh->boneCountBuffer);
        _glEnableVertexAttribArray(shader->attributes.boneCount);
        _glVertexAttribPointer(shader->attributes.boneCount, 1, GL_INT, GL_FALSE,
                              0, (void*)0);

        _glBindBuffer(GL_ARRAY_BUFFER, mesh->boneIndexBuffer);
        _glEnableVertexAttribArray(shader->attributes.inBoneIndex);
        _glVertexAttribPointer(shader->attributes.inBoneIndex,
                              shader->bonesPerVertex, GL_INT, GL_FALSE, 0,
                              (void*)0);

        _glBindBuffer(GL_ARRAY_BUFFER, mesh->boneWeightBuffer);
        _glEnableVertexAttribArray(shader->attributes.inBoneWeights);
        _glVertexAttribPointer(shader->attributes.inBoneWeights,
                              shader->bonesPerVertex, GL_FLOAT, GL_FALSE, 0,
                              (void*)0);

        // load bone transform uniforms
        // TODO avoid doing this repeatedly for models with same skeletons
        _glUniformMatrix4fv(shader->uniforms.boneMatrixArray, mesh->num_bones, 0,
                           (GLfloat*)mesh->boneTransforms);
    }

    _glDrawArrays(GL_TRIANGLES, 0, mesh->num_points);
}

void MeshRenderer::setModelTransform(mat4 t) {
    modelTransform = t;
}
