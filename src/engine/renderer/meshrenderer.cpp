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
    glUseProgram(shader->programId);
    CHECK_GL_ERROR(glUseProgram);

    // get base transform and pass to the shader
    mat4 compoundTransform = baseTransform * modelTransform;
    glUniformMatrix4fv(shader->uniforms.baseTransform, 1, GL_FALSE,
                       &compoundTransform[0][0]);
    CHECK_GL_ERROR(glUniformMatrix4fv);

    // if the shader has a texture and the model has UVs, load them
    if (material && material->hasTexture() && mesh->hasUvs() &&
        shader->hasAttribute(uvs)) {
        glActiveTexture(GL_TEXTURE0);
        CHECK_GL_ERROR(glActiveTexture);
        glBindTexture(GL_TEXTURE_2D, material->ambientTexture->getTextureID());
        CHECK_GL_ERROR(glBindTexture);
        glUniform1i(shader->uniforms.ambientTexture, 0);
        CHECK_GL_ERROR(glUniform1i);

        glEnableVertexAttribArray(shader->attributes.uvs);
        CHECK_GL_ERROR(glEnableVertexAttribArray);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->uvBuffer);
        CHECK_GL_ERROR(glBindBuffer);
        glVertexAttribPointer(shader->attributes.uvs,
                              2,         // size
                              GL_FLOAT,  // type
                              GL_FALSE,  // normalized?
                              0,         // stride
                              (void*)0   // array buffer offset
        );
        CHECK_GL_ERROR(glVertexAttribPointer);
    }

    glEnableVertexAttribArray(shader->attributes.position);
    CHECK_GL_ERROR(glEnableVertexAttribArray);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexbuffer);
    CHECK_GL_ERROR(glBindBuffer);
    glVertexAttribPointer(shader->attributes.position,
                          3,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
    );
    CHECK_GL_ERROR(glVertexAttribPointer);

    if (mesh->hasVertexColors() && shader->hasAttribute(vertexColor)) {
        glEnableVertexAttribArray(shader->attributes.vertexColor);
        CHECK_GL_ERROR(glEnableVertexAttribArray);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->colorbuffer);
        CHECK_GL_ERROR(glBindBuffer);
        glVertexAttribPointer(shader->attributes.vertexColor,
                              3,         // size
                              GL_FLOAT,  // type
                              GL_FALSE,  // normalized?
                              0,         // stride
                              (void*)0   // array buffer offset
        );
        CHECK_GL_ERROR(glVertexAttribPointer);
    }

    if (mesh->hasSkeleton() && shader->hasAttribute(boneCount) &&
        shader->hasAttribute(inBoneIndex) &&
        shader->hasAttribute(inBoneWeights) &&
        shader->hasUniform(boneMatrixArray) &&
        shader->hasUniform(boneMatrixArrayInverseTrans)) {
        // load bone attributes
        glEnableVertexAttribArray(shader->attributes.boneCount);
        CHECK_GL_ERROR(glEnableVertexAttribArray);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->boneCountBuffer);
        CHECK_GL_ERROR(glBindBuffer);
        glVertexAttribPointer(shader->attributes.boneCount, 1, GL_INT, GL_FALSE,
                              0, (void*)0);
        CHECK_GL_ERROR(glVertexAttribPointer);

        glEnableVertexAttribArray(shader->attributes.inBoneIndex);
        CHECK_GL_ERROR(glEnableVertexAttribArray);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->boneIndexBuffer);
        CHECK_GL_ERROR(glBindBuffer);
        glVertexAttribPointer(shader->attributes.inBoneIndex,
                              shader->bonesPerVertex, GL_INT, GL_FALSE, 0,
                              (void*)0);
        CHECK_GL_ERROR(glVertexAttribPointer);

        glEnableVertexAttribArray(shader->attributes.inBoneWeights);
        CHECK_GL_ERROR(glEnableVertexAttribArray);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->boneWeightBuffer);
        CHECK_GL_ERROR(glBindBuffer);
        glVertexAttribPointer(shader->attributes.inBoneWeights,
                              shader->bonesPerVertex, GL_FLOAT, GL_FALSE, 0,
                              (void*)0);
        CHECK_GL_ERROR(glVertexAttribPointer);

        // load bone transform uniforms
        // TODO avoid doing this repeatedly for models with same skeletons
        glUniformMatrix4fv(shader->uniforms.boneMatrixArray, mesh->num_bones, 0,
                           (GLfloat*)mesh->boneTransforms);
        CHECK_GL_ERROR(glUniformMatrix4fv);
    }

    glDrawArrays(GL_TRIANGLES, 0, mesh->num_points);
    glDisableVertexAttribArray(shader->attributes.position);
    glDisableVertexAttribArray(shader->attributes.vertexColor);
    glDisableVertexAttribArray(shader->attributes.uvs);
}

void MeshRenderer::setModelTransform(mat4 t) {
    modelTransform = t;
}
