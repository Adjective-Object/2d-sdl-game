// clib
#include <cstring>
#include <iostream>
#include <random>
// assimp
#include <Importer.hpp>
#include <scene.h>
#include <postprocess.h>
// locals
#include "staticmesh.hpp"
#include "modelloader.hpp"

using namespace std;
using namespace Assimp;

StaticMeshLoader::StaticMeshLoader() {}

bool StaticMeshLoader::load(const char* fpath) {
    std::cout << "load(" << fpath << ")" << std::endl;

    scene = importer.ReadFile(
        fpath, aiProcess_CalcTangentSpace | aiProcess_Triangulate |
                   aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

    return scene != NULL;
}

StaticMesh* makeMesh(const aiMesh* mesh) {
    GLfloat* verts = new GLfloat[mesh->mNumFaces * 9];
    GLfloat* colors = new GLfloat[mesh->mNumFaces * 9];
    size_t tri = 0;
    for (size_t f = 0; f < mesh->mNumFaces; f++) {
        aiFace face = mesh->mFaces[f];
        for (size_t ind = 0; ind < face.mNumIndices; ind++) {
            size_t vertexIndex = face.mIndices[ind];

            aiVector3D vert = mesh->mVertices[vertexIndex];
            verts[tri * 3] = vert.x;
            verts[tri * 3 + 1] = vert.y;
            verts[tri * 3 + 2] = vert.z;

            colors[tri * 3] = ((double)rand() / (RAND_MAX));
            colors[tri * 3 + 1] = ((double)rand() / (RAND_MAX));
            colors[tri * 3 + 2] = ((double)rand() / (RAND_MAX));
            tri++;
        }
    }

    for (size_t k = 0; k < tri; k += 3) {
        std::cout << verts[k] << ", " << verts[k + 1] << ", " << verts[k + 2]
                  << std::endl;
    }

    StaticMesh* m = new StaticMesh();
    m->init(verts, colors, tri);
    return m;
}

StaticMesh* StaticMeshLoader::queryScene(const char* scenePath) {
    std::cout << "queryScene(" << scenePath << ")" << std::endl;
    if (scene == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < scene->mNumMeshes; i++) {
        std::cout << "querying mesh" << i << " of " << scene->mNumMeshes
                  << std::endl;
        const aiMesh* mesh = scene->mMeshes[i];
        std::cout << "query" << mesh->mName.C_Str() << "? " << scenePath
                  << std::endl;
        if (0 == strcmp(mesh->mName.C_Str(), scenePath)) {
            std::cout << "loading a mesh with " << mesh->mNumVertices
                      << " verts"
                      << ", " << mesh->mNumFaces << " faces" << std::endl;
            ;

            if (mesh->mNumFaces != 0) {
                return makeMesh(mesh);
            }
        }
    }
    return NULL;
}
