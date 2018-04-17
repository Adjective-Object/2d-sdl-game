#include "meshrenderer.hpp"
#include <vector>
#include <iostream>
#include "engine/gl.h"
#include "engine/game.hpp"
#include "engine/mesh/worldspacemesh.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/shader/meshshader.hpp>

using namespace glm;

MeshRenderer::MeshRenderer(MeshShader* shader,
                           WorldspaceMesh* mesh,
                           Material* material)
    : mesh(mesh), shader(shader), material(material) {}

void MeshRenderer::render(mat4& baseTransform) {
    // Draw using this specific shader
    glUseProgram(shader->programId);

    // get base transform and pass to the shader
    mat4 compoundTransform = baseTransform * modelTransform;
    glUniformMatrix4fv(shader->uniforms.baseTransform, 1, GL_FALSE,
                       &compoundTransform[0][0]);

    // if the shader has a texture and the model has UVs, load them
    if (material && material->hasTexture() && mesh->hasUvs() &&
        shader->hasAttribute(uvs)) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, material->ambientTexture->getTextureID());
        glUniform1i(shader->uniforms.ambientTexture, 0);

        glEnableVertexAttribArray(shader->attributes.uvs);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->uvBuffer);
        glVertexAttribPointer(shader->attributes.uvs,
                              2,         // size
                              GL_FLOAT,  // type
                              GL_FALSE,  // normalized?
                              0,         // stride
                              (void*)0   // array buffer offset
                              );
    }

    glEnableVertexAttribArray(shader->attributes.position);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexbuffer);
    glVertexAttribPointer(shader->attributes.position,
                          3,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
                          );

    if (mesh->hasVertexColors() && shader->hasAttribute(vertexColor)) {
        glEnableVertexAttribArray(shader->attributes.vertexColor);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->colorbuffer);
        glVertexAttribPointer(shader->attributes.vertexColor,
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
        glEnableVertexAttribArray(shader->attributes.boneCount);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->boneCountBuffer);
        glVertexAttribPointer(shader->attributes.boneCount, 1, GL_INT, GL_FALSE,
                              0, (void*)0);

        glEnableVertexAttribArray(shader->attributes.inBoneIndex);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->boneIndexBuffer);
        glVertexAttribPointer(shader->attributes.inBoneIndex,
                              shader->bonesPerVertex, GL_INT, GL_FALSE, 0,
                              (void*)0);

        glEnableVertexAttribArray(shader->attributes.inBoneWeights);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->boneWeightBuffer);
        glVertexAttribPointer(shader->attributes.inBoneWeights,
                              shader->bonesPerVertex, GL_FLOAT, GL_FALSE, 0,
                              (void*)0);

        // load bone transform uniforms
        // TODO avoid doing this repeatedly for models with same skeletons
        glUniformMatrix4fv(shader->uniforms.boneMatrixArray, mesh->num_bones, 0,
                           (GLfloat*)mesh->boneTransforms);
    }

    glDrawArrays(GL_TRIANGLES, 0, mesh->num_points);
    glDisableVertexAttribArray(shader->attributes.position);
    glDisableVertexAttribArray(shader->attributes.vertexColor);
    glDisableVertexAttribArray(shader->attributes.uvs);
}

void MeshRenderer::setModelTransform(mat4 t) {
    modelTransform = t;
}
