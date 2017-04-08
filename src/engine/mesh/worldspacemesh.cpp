#include "worldspacemesh.hpp"
#include "engine/gl.h"
#include <iostream>

void WorldspaceMesh::init(const GLfloat* verts,
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

void WorldspaceMesh::initSkeleton(const GLfloat* boneWeights,
                                  size_t num_bones) {
    glGenBuffers(1, &boneWeightBuffer);
    this->num_bones = num_bones;
    updateSkeleton(boneWeights, num_bones);
}

void WorldspaceMesh::updateMesh(const GLfloat* verts,
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
        glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
        glBufferData(GL_ARRAY_BUFFER, num_points * 2 * sizeof(GLfloat), uvs,
                     GL_STATIC_DRAW);
    }
}

void WorldspaceMesh::updateSkeleton(const GLfloat* verts, size_t num_bones) {
    glBindBuffer(GL_ARRAY_BUFFER, boneWeightBuffer);
    glBufferData(GL_ARRAY_BUFFER, num_points * num_bones * sizeof(GLfloat),
                 verts, GL_STATIC_DRAW);
}

bool WorldspaceMesh::hasUvs() {
    return uvBuffer != -1;
}

bool WorldspaceMesh::hasVertexColors() {
    return colorbuffer != -1;
}
