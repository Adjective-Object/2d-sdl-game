#include <iostream>
#include <SDL.h>
#include "abstractrenderer.hpp"
#include "screenrenderer.hpp"
#include "engine/shader/screenspaceshader.hpp"
#include "engine/mesh/worldspacemesh.hpp"
#include "engine/game.hpp"

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void updateGeometry(SDL_Rect& bounds,
                    GLfloat* verts,
                    GLfloat* uvs,
                    int textureWidth,
                    int textureHeight) {
    size_t i = 0, j = 0;
    verts[i++] = bounds.x;
    verts[i++] = bounds.y;
    verts[i++] = 0;
    uvs[j++] = 0;
    uvs[j++] = 0;

    verts[i++] = bounds.x;
    verts[i++] = bounds.y + bounds.h;
    verts[i++] = 0;
    uvs[j++] = 0;
    uvs[j++] = (GLfloat)(bounds.h) / textureHeight;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y;
    verts[i++] = 0;
    uvs[j++] = (GLfloat)(bounds.w) / textureWidth;
    uvs[j++] = 0;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y;
    verts[i++] = 0;
    uvs[j++] = (GLfloat)(bounds.w) / textureWidth;
    uvs[j++] = 0;

    verts[i++] = bounds.x;
    verts[i++] = bounds.y + bounds.h;
    verts[i++] = 0;
    uvs[j++] = 0;
    uvs[j++] = (GLfloat)(bounds.h) / textureHeight;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y + bounds.h;
    verts[i++] = 0;
    uvs[j++] = (GLfloat)(bounds.w) / textureWidth;
    uvs[j++] = (GLfloat)(bounds.h) / textureHeight;
}

void ScreenRenderer::makeBoundsMesh(SDL_Rect& bounds) {
    // 3 floats per point, 3 points per tri, 2 triangles
    verts = new GLfloat[3 * 3 * 2];
    uvs = new GLfloat[3 * 2 * 2];
    updateGeometry(bounds, verts, uvs, -1, -1);

    mesh.init(verts, NULL, uvs, 6);
}

void ScreenRenderer::updateMesh(SDL_Rect& bounds) {
    int width, height, access;
    Uint32 format;
    SDL_QueryTexture(texture, &format, &access, &width, &height);
    updateGeometry(bounds, verts, uvs, width, height);
    mesh.updateMesh(verts, NULL, uvs);
}

ScreenRenderer::ScreenRenderer(SDL_Texture* texture, SDL_Rect bounds)
    : texture(texture) {
    makeBoundsMesh(bounds);
    material.setAmbientTexture(texture);
}

void ScreenRenderer::render(glm::mat4& baseTransform) {
    ScreenShader* shader = &screenShader;
    glUseProgram(shader->programId);

    // pass screen dimensions to the shader
    SDL_Rect screenBounds = EnG->getScreenBounds();
    glUniform2f(shader->uniforms.screenDimensions, screenBounds.w,
                screenBounds.h);

    // pass texture to the shader
    glActiveTexture(GL_TEXTURE0);
    SDL_GL_BindTexture(material.ambientTexture, NULL, NULL);
    glUniform1i(shader->uniforms.ambientTexture, 0);

    // pass vertex data to the shader
    glEnableVertexAttribArray(shader->attributes.pixelPosition);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexbuffer);
    glVertexAttribPointer(shader->attributes.pixelPosition,
                          3,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
                          );

    // pass uv data to she shader
    glEnableVertexAttribArray(shader->attributes.uvs);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.uvBuffer);
    glVertexAttribPointer(shader->attributes.uvs,
                          2,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
                          );

    glDrawArrays(GL_TRIANGLES, 0, mesh.num_points);
    glDisableVertexAttribArray(shader->attributes.uvs);
    glDisableVertexAttribArray(shader->attributes.pixelPosition);
    glDisableVertexAttribArray(shader->uniforms.ambientTexture);
    glDisableVertexAttribArray(shader->uniforms.screenDimensions);
}
