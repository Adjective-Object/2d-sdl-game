#include "staticmesh.hpp"
#include "engine/gl.h"
#include <iostream>

void StaticMesh::init(const GLfloat* verts,
                      const GLfloat* colors,
                      const GLfloat* uvs,
                      size_t num_points) {
    this->num_points = num_points;

    if (verts) {
        glGenBuffers(1, &vertexbuffer);
    }

    if (colors) {
        glGenBuffers(1, &colorbuffer);
    }

    if (uvs) {
        glGenBuffers(1, &uvBuffer);
    }

    updateMesh(verts, colors, uvs);
}

void StaticMesh::updateMesh(const GLfloat* verts,
                            const GLfloat* colors,
                            const GLfloat* uvs) {
    if (verts) {
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, num_points * 3 * sizeof(GLfloat), verts,
                     GL_STATIC_DRAW);
    }

    if (colors) {
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, num_points * 3 * sizeof(GLfloat), colors,
                     GL_STATIC_DRAW);
    }

    if (uvs) {
        std::cout << "buffering uvs" << std::endl;
        for (int i = 0; i < num_points * 2; i += 2) {
            std::cout << "uv " << i / 2 << ": " << uvs[i] << ", " << uvs[i + 1]
                      << std::endl;
        }
        glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
        glBufferData(GL_ARRAY_BUFFER, num_points * 2 * sizeof(GLfloat), uvs,
                     GL_STATIC_DRAW);
    }
}

bool StaticMesh::hasUvs() {
    return uvBuffer != -1;
}

bool StaticMesh::hasVertexColors() {
    return colorbuffer != -1;
}
