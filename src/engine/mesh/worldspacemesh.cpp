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

void WorldspaceMesh::initSkeleton(const uint8_t* vertBoneCounts,
                                  const uint16_t* vertBoneIndecies,
                                  const GLfloat* boneWeights,
                                  size_t num_weights_per_point,
                                  size_t num_bones) {
    glGenBuffers(1, &boneWeightBuffer);
    glGenBuffers(1, &boneIndexBuffer);
    glGenBuffers(1, &boneCountBuffer);
    updateSkeleton(vertBoneCounts, vertBoneIndecies, boneWeights,
                   num_weights_per_point, num_bones);
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

void WorldspaceMesh::updateSkeleton(const uint8_t* vertBoneCounts,
                                    const uint16_t* vertBoneIndecies,
                                    const GLfloat* vertBoneWeights,
                                    size_t num_weights_per_point,
                                    size_t num_bones) {
    this->num_bones = num_bones;
    this->num_weights_per_point = num_weights_per_point;

    glBindBuffer(GL_ARRAY_BUFFER, boneCountBuffer);
    glBufferData(GL_ARRAY_BUFFER, num_points * sizeof(uint8_t), vertBoneCounts,
                 GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, boneIndexBuffer);
    glBufferData(GL_ARRAY_BUFFER,
                 num_weights_per_point * num_points * sizeof(uint16_t),
                 vertBoneIndecies, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, boneWeightBuffer);
    glBufferData(GL_ARRAY_BUFFER,
                 num_weights_per_point * num_points * sizeof(GLfloat),
                 vertBoneWeights, GL_STATIC_DRAW);
}

bool WorldspaceMesh::hasUvs() const {
    return uvBuffer != -1;
}

bool WorldspaceMesh::hasVertexColors() const {
    return colorbuffer != -1;
}

bool WorldspaceMesh::hasSkeleton() const {
    return boneWeightBuffer != -1;
}
