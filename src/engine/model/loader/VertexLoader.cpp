#include "./VertexLoader.hpp"
#include <exception>

VertexLoader::VertexLoader(const aiMesh* mesh) : mesh(mesh) {
    // 3 floats per Vector3
    this->verts = std::vector<GLfloat>(mesh->mNumVertices * 3);
    for (size_t f = 0; f < mesh->mNumFaces; f++) {
        aiFace face = mesh->mFaces[f];
        if (face.mNumIndices != 3) {
            throw new std::invalid_argument(
                "All faces of the mesh must be triagles");
        }
    }
    this->indecies = std::vector<WORLDSPACE_MESH_INDEX_TYPE>(mesh->mNumFaces * 3);
}

void VertexLoader::loadMeshVerticiesAndIndecies() {
    size_t totalVertexIndices = 0;
    size_t totalVertices = 0;
    for (size_t currentFaceIndex = 0; currentFaceIndex < mesh->mNumFaces;
         currentFaceIndex++) {
        aiFace currentFace = mesh->mFaces[currentFaceIndex];
        for (size_t currentVertexIndexInFace = 0;
             currentVertexIndexInFace < currentFace.mNumIndices;
             currentVertexIndexInFace++) {
            this->indecies[totalVertexIndices++] =
                currentFace.mIndices[currentVertexIndexInFace];
        }
    }
    for (size_t vertexIndex = 0; vertexIndex < mesh->mNumVertices;
         vertexIndex++) {
        aiVector3D originalVertex = mesh->mVertices[vertexIndex];
        this->verts[totalVertices++] = originalVertex.x;
        this->verts[totalVertices++] = originalVertex.y;
        this->verts[totalVertices++] = originalVertex.z;
    }
}

const std::vector<GLfloat>* VertexLoader::getVerts() const {
    return &(this->verts);
}

const std::vector<WORLDSPACE_MESH_INDEX_TYPE>* VertexLoader::getIndecies() const {
    return &(this->indecies);
}
