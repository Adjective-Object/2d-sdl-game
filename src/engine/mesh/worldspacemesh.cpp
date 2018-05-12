#include "worldspacemesh.hpp"
#include <glm/detail/type_mat.hpp>
#include <iostream>
#include <limits>
#include "engine/gl.h"

void WorldspaceMesh::init(const GLfloat* verts,
                          const WORLDSPACE_MESH_INDEX_TYPE* indecies,
                          const GLfloat* colors,
                          const GLfloat* uvs,
                          size_t num_points,
                          size_t num_tris) {
    this->num_points = num_points;
    this->num_tris = num_tris;
    size_t max_indexable_points =
        std::numeric_limits<WORLDSPACE_MESH_INDEX_TYPE>::max();
    if (num_points > max_indexable_points) {
        throw std::invalid_argument("More points in mesh than can be indexed");
    }

    if (verts == nullptr || indecies == nullptr) {
        throw std::invalid_argument(
            "verts and indecies must both be specified");
    }

    _glGenBuffers(1, &vertexbuffer);
    _glGenVertexArrays(1, &vertexArray);
    _glGenBuffers(1, &indexBuffer);

    if (colors) {
        _glGenBuffers(1, &colorbuffer);
        _glGenVertexArrays(1, &colorArray);
    }

    if (uvs) {
        _glGenBuffers(1, &uvBuffer);
        _glGenVertexArrays(1, &uvArray);
    }

    updateMesh(verts, indecies, colors, uvs);
}

void WorldspaceMesh::initSkeleton(const uint8_t* vertBoneCounts,
                                  const uint16_t* vertBoneIndecies,
                                  const GLfloat* boneWeights,
                                  size_t num_weights_per_point,
                                  size_t num_bones) {
    _glGenBuffers(1, &boneWeightBuffer);
    _glGenVertexArrays(1, &boneWeightArray);

    _glGenBuffers(1, &boneIndexBuffer);
    _glGenVertexArrays(1, &boneIndexArray);

    _glGenBuffers(1, &boneCountBuffer);
    _glGenVertexArrays(1, &boneCountArray);

    updateSkeleton(vertBoneCounts, vertBoneIndecies, boneWeights,
                   num_weights_per_point, num_bones);
}

void WorldspaceMesh::updateMesh(const GLfloat* verts,
                                const WORLDSPACE_MESH_INDEX_TYPE* indecies,
                                const GLfloat* colors,
                                const GLfloat* uvs) {
    if (verts) {
        std::cout << "num_pts: " << num_points << std::endl;
        _glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        _glBufferData(GL_ARRAY_BUFFER, num_points * 3 * sizeof(GLfloat), verts,
                      GL_STATIC_DRAW);
    }

    if (indecies) {
        std::cout << "num_tris: " << num_tris << std::endl;
        _glBindBuffer(GL_ARRAY_BUFFER, indexBuffer);
        _glBufferData(GL_ARRAY_BUFFER,
                      num_tris * 3 * sizeof(WORLDSPACE_MESH_INDEX_TYPE),
                      indecies, GL_STATIC_DRAW);
    }

    if (colors) {
        _glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        _glBufferData(GL_ARRAY_BUFFER, num_points * 3 * sizeof(GLfloat), colors,
                      GL_STATIC_DRAW);
    }

    if (uvs) {
        _glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
        _glBufferData(GL_ARRAY_BUFFER, num_points * 2 * sizeof(GLfloat), uvs,
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

    std::cout << "vertBoneIndecies:";
    for (int i = 0; i < num_weights_per_point * num_points; i++) {
        std::cout << vertBoneIndecies[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "vertBoneWeights:";
    for (int i = 0; i < num_weights_per_point * num_points; i++) {
        std::cout << vertBoneWeights[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "vertBoneCounts:";
    for (int i = 0; i < num_points; i++) {
        std::cout << (int)(vertBoneCounts[i]) << ", ";
    }
    std::cout << std::endl;

    std::cout << "buffering bone counts to " << boneCountBuffer << std::endl;
    _glBindBuffer(GL_ARRAY_BUFFER, boneCountBuffer);
    _glBufferData(GL_ARRAY_BUFFER, num_points * sizeof(uint8_t), vertBoneCounts,
                  GL_STATIC_DRAW);

    std::cout << "buffering bone indecies to " << boneIndexBuffer << std::endl;
    _glBindBuffer(GL_ARRAY_BUFFER, boneIndexBuffer);
    _glBufferData(GL_ARRAY_BUFFER,
                  num_weights_per_point * num_points * sizeof(uint16_t),
                  vertBoneIndecies, GL_STATIC_DRAW);

    std::cout << "buffering bone weights to " << boneWeightBuffer << std::endl;
    _glBindBuffer(GL_ARRAY_BUFFER, boneWeightBuffer);
    _glBufferData(GL_ARRAY_BUFFER,
                  num_weights_per_point * num_points * sizeof(GLfloat),
                  vertBoneWeights, GL_STATIC_DRAW);

    if (boneTransforms != NULL) {
        delete[] boneTransforms;
    }
    boneTransforms = new glm::mat4[num_bones];
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
