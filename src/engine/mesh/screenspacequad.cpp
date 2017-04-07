//
// Created by adjective on 4/7/17.
//

#include "screenspacequad.hpp"

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

void ScreenSpaceQuad::updateMesh(const SDL_Rect& bounds,
                                 const int textureWidth,
                                 const int textureHeight) {
    size_t i = 0, j = 0;
    verts[i++] = bounds.x;
    verts[i++] = bounds.y;
    uvs[j++] = 0;
    uvs[j++] = 0;

    verts[i++] = bounds.x;
    verts[i++] = bounds.y + bounds.h;
    uvs[j++] = 0;
    uvs[j++] = (GLfloat)(bounds.h) / textureHeight;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y;
    uvs[j++] = (GLfloat)(bounds.w) / textureWidth;
    uvs[j++] = 0;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y;
    uvs[j++] = (GLfloat)(bounds.w) / textureWidth;
    uvs[j++] = 0;

    verts[i++] = bounds.x;
    verts[i++] = bounds.y + bounds.h;
    uvs[j++] = 0;
    uvs[j++] = (GLfloat)(bounds.h) / textureHeight;

    verts[i++] = bounds.x + bounds.w;
    verts[i++] = bounds.y + bounds.h;
    uvs[j++] = (GLfloat)(bounds.w) / textureWidth;
    uvs[j++] = (GLfloat)(bounds.h) / textureHeight;

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, QUAD_VERTEX_BUFFER_SIZE * sizeof(GLfloat),
                 verts, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glBufferData(GL_ARRAY_BUFFER, QUAD_UV_BUFFER_SIZE * sizeof(GLfloat), uvs,
                 GL_STATIC_DRAW);
}

void ScreenSpaceQuad::init(const SDL_Rect& bounds,
                           const int textureWidth,
                           const int textureHeight) {
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &uvBuffer);
    updateMesh(bounds, textureWidth, textureHeight);
}
