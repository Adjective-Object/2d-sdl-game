#ifndef __ENGINE_SCREENSPACEMESH_H
#define __ENGINE_SCREENSPACEMESH_H

#include <SDL.h>
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

/**
 * Mesh class for managing a quad in screen space
 *
 * Maintains its own internal vertex and uv buffers
 */

#define QUAD_VERTEX_BUFFER_SIZE (3 * 2 * 2)
#define QUAD_UV_BUFFER_SIZE (3 * 2 * 2)

class ScreenSpaceQuad {
   public:
    GLfloat verts[QUAD_VERTEX_BUFFER_SIZE];
    GLfloat uvs[QUAD_UV_BUFFER_SIZE];
    GLuint vertexBuffer = 0;
    GLuint uvBuffer = 0;
    static const unsigned int num_points = 6;

    void init(const SDL_Rect& bounds,
              const int textureWidth,
              const int textureHeight);

    void updateMesh(const SDL_Rect& bounds,
                    const int textureWidth,
                    const int textureHeight);
};

#endif
