#include "meshrenderer.hpp"
#include <vector>
#include <iostream>
#include "engine/gl.h"
#include "engine/game.hpp"
#include "engine/mesh/staticmesh.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

MeshRenderer::MeshRenderer(BasicShader* shader, StaticMesh* mesh, Material * material)
    : mesh(mesh), shader(shader), material(material) {}

void MeshRenderer::render(mat4& baseTransform) {
    // Draw the triangles
    glUseProgram(shader->programId);

    // get base transform and pass to the shader
    mat4 compoundTransform = baseTransform * modelTransform;
    glUniformMatrix4fv(shader->uniforms.baseTransform, 1, GL_FALSE,
                       &compoundTransform[0][0]);


    // if the shader has a texture and the model has UVs, load them
    if (material && material->hasTexture() && mesh->hasUvs()) {
        glActiveTexture(GL_TEXTURE0); 
        glBindTexture(GL_TEXTURE_2D, material->glAmbientTexture);
        glUniform1i(
                shader->uniforms.ambientTexture,
                0);

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

    if (mesh->hasVertexColors()) {
        glEnableVertexAttribArray(shader->attributes.color);
        glBindBuffer(GL_ARRAY_BUFFER, mesh->colorbuffer);
        glVertexAttribPointer(shader->attributes.color,
                              3,         // size
                              GL_FLOAT,  // typ& e
                              GL_FALSE,  // normalized?
                              0,         // stride
                              (void*)0   // array buffer offset
                              );
    }

    glDrawArrays(GL_TRIANGLES, 0, mesh->num_points);
    glDisableVertexAttribArray(shader->attributes.position);
    glDisableVertexAttribArray(shader->attributes.color);
    glDisableVertexAttribArray(shader->attributes.uvs);
}

void MeshRenderer::setModelTransform(mat4 t) {
    modelTransform = t;
}
