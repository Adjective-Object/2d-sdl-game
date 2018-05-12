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

    // std::cout << "checking Shader @ " << shader << std::endl;
    // std::cout << mesh->hasSkeleton() << ", " <<
    // shader->hasAttribute(boneCount)
    //           << ", " << shader->hasAttribute(inBoneIndex) << ", "
    //           << shader->hasAttribute(inBoneWeights) << ", "
    //           << shader->hasUniform(boneMatrixArray) << ", "
    //           << shader->hasUniform(boneMatrixArrayInverseTrans) <<
    //           std::endl;
    if (mesh->hasSkeleton()) {
        // load bone attributes

        if (shader->hasAttribute(boneCount)) {
            // std::cout << "buffering bone counts from " << mesh->boneCountBuffer
            //           << std::endl;
            _glBindBuffer(GL_ARRAY_BUFFER, mesh->boneCountBuffer);
            _glEnableVertexAttribArray(shader->attributes.boneCount);
            _glVertexAttribPointer(shader->attributes.boneCount,
                                   1,                 // size
                                   GL_UNSIGNED_BYTE,  // type
                                   GL_FALSE,          // normalized?
                                   0,                 // stride
                                   (void*)0);         // array buffer offset
        }

        if (shader->hasAttribute(inBoneIndex)) {
            // std::cout << "buffering bone indecies from "
            //           << mesh->boneIndexBuffer << std::endl;
            _glBindBuffer(GL_ARRAY_BUFFER, mesh->boneIndexBuffer);
            _glEnableVertexAttribArray(shader->attributes.inBoneIndex);
            _glVertexAttribPointer(shader->attributes.inBoneIndex,
                                   shader->bonesPerVertex,  // size per call
                                   GL_UNSIGNED_SHORT,       // type
                                   GL_FALSE,                // normalized?
                                   0,                       // stride
                                   (void*)0  // array buffer offset
            );
        }
        if (shader->hasAttribute(inBoneWeights)) {
            // std::cout << "buffering bone weights from "
            //           << mesh->boneWeightBuffer << std::endl;
            _glBindBuffer(GL_ARRAY_BUFFER, mesh->boneWeightBuffer);
            _glEnableVertexAttribArray(shader->attributes.inBoneWeights);
            _glVertexAttribPointer(shader->attributes.inBoneWeights,
                                   shader->bonesPerVertex,  // size per call
                                   GL_FLOAT,                // type
                                   GL_FALSE,                // normalized
                                   0,                       // stride
                                   (void*)0  // array buffer offset
            );
        }

        // load bone transform uniforms
        // TODO avoid doing this repeatedly for models with same skeletons
        if (shader->hasUniform(boneMatrixArray)) {
            _glUniformMatrix4fv(shader->uniforms.boneMatrixArray,
                                mesh->num_bones, 0,
                                (GLfloat*)mesh->boneTransforms);
        }
    }

    _glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    _glDrawElements(GL_TRIANGLES,                     // mode
                    mesh->num_tris * 3,               // count
                    WORLDSPACE_MESH_INDEX_TYPE_NAME,  // type
                    (void*)0                          // offset
    );
}

void MeshRenderer::setModelTransform(mat4 t) {
    modelTransform = t;
}
