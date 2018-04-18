#include "screenrenderer.hpp"
#include <SDL.h>
#include "abstractrenderer.hpp"
#include "engine/game.hpp"
#include "engine/gl.h"
#include "engine/shader/screenspaceshader.hpp"

ScreenRenderer::ScreenRenderer(Texture* texture, ScreenSpaceQuad* mesh)
    : mesh(mesh) {
    material.setAmbientTexture(texture);
}

void ScreenRenderer::render(glm::mat4& baseTransform) {
    ScreenShader* shader = &screenShader;
    _glUseProgram(shader->programId);

    // pass screen dimensions to the shader
    SDL_Rect screenBounds = EnG->getScreenBounds();
    _glUniform2f(shader->uniforms.screenDimensions, screenBounds.w,
                screenBounds.h);

    // pass texture to the shader
    _glActiveTexture(GL_TEXTURE0);
    _glBindTexture(GL_TEXTURE_2D, material.ambientTexture->getTextureID());
    _glUniform1i(shader->uniforms.ambientTexture, 0);

    // pass vertex data to the shader
    _glEnableVertexAttribArray(shader->attributes.pixelPosition);
    _glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    _glVertexAttribPointer(shader->attributes.pixelPosition,
                          2,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
    );

    // pass uv data to she shader
    _glEnableVertexAttribArray(shader->attributes.uvs);
    _glBindBuffer(GL_ARRAY_BUFFER, mesh->uvBuffer);
    _glVertexAttribPointer(shader->attributes.uvs,
                          2,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void*)0   // array buffer offset
    );

    _glDrawArrays(GL_TRIANGLES, 0, ScreenSpaceQuad::num_points);
    _glDisableVertexAttribArray(shader->attributes.uvs);
    _glDisableVertexAttribArray(shader->attributes.pixelPosition);
    _glDisableVertexAttribArray(shader->uniforms.ambientTexture);
    _glDisableVertexAttribArray(shader->uniforms.screenDimensions);
}
