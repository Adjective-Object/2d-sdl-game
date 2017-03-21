#include "staticmesh.hpp"
#include "engine/gl.h"

StaticMesh makeStaticMesh(const GLfloat* verts,
                          const GLfloat* colors,
                          size_t num_tris) {
    StaticMesh mesh;

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &mesh.vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, num_tris * 3 * sizeof(float), verts,
                 GL_STATIC_DRAW);

    glGenBuffers(1, &mesh.colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, num_tris * 3 * sizeof(float), colors,
                 GL_STATIC_DRAW);

    mesh.num_points = num_tris;

    return mesh;
}
