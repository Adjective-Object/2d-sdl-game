#include <SDL.h>
#include "abstractrenderer.hpp"
#include "screenrenderer.hpp"
#include "engine/shader/screenspaceshader.hpp"
#include "engine/mesh/staticmesh.hpp"
#include "engine/game.hpp"

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

StaticMesh makeBoundsMesh(SDL_Rect bounds) {
    // 3 floats per point, 3 points per tri, 2 triangles
    GLfloat* verts = new GLfloat[3 * 3 * 2];
    GLfloat* uvs = new GLfloat[2 * 3 * 2];
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
    uvs[j++] = 1;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y;
    verts[i++] = 0;
    uvs[j++] = 1;
    uvs[j++] = 0;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y;
    verts[i++] = 0;
    uvs[j++] = 1;
    uvs[j++] = 0;

    verts[i++] = bounds.x;
    verts[i++] = bounds.y + bounds.h;
    verts[i++] = 0;
    uvs[j++] = 0;
    uvs[j++] = 1;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y + bounds.h;
    verts[i++] = 0;
    uvs[j++] = 1;
    uvs[j++] = 1;

    StaticMesh m;
    m.init(verts, NULL, uvs, 6);
}

ScreenRenderer::ScreenRenderer(SDL_Texture* texture, SDL_Rect bounds)
    : texture(texture) {
    mesh = makeBoundsMesh(bounds);
    material.setAmbientTexture(texture);
}

void ScreenRenderer::render(glm::mat4& baseTransform) {
    ScreenShader* shader = &screenShader;

    SDL_Rect screenBounds = EnG->getScreenBounds();
    glUniform2f(shader->uniforms.screenDimensions, screenBounds.w,
                screenBounds.h);

    glActiveTexture(GL_TEXTURE0);
    SDL_GL_BindTexture(material.ambientTexture, NULL, NULL);
    glUniform1i(shader->uniforms.ambientTexture, 0);

    glEnableVertexAttribArray(shader->attributes.pixelPosition);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexbuffer);
    glVertexAttribPointer(shader->attributes.pixelPosition,
                          3,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
                          );

    glEnableVertexAttribArray(shader->attributes.uvs);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.uvBuffer);
    glVertexAttribPointer(shader->attributes.uvs,
                          2,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
                          );
}
