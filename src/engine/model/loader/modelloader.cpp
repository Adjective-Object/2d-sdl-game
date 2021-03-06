// clib
#include <cstring>
#include <iostream>
#include <random>
#include <set>
#include <string>
// sdl
#include <SDL.h>
#include <SDL_image.h>
// assimp
#include <Importer.hpp>
#include <scene.h>
#include <postprocess.h>
#include <quaternion.h>
// locals
#include "engine/mesh/worldspacemesh.hpp"
#include "engine/material/material.hpp"
#include "modelloader.hpp"
#include "engine/meshanim/meshanim.hpp"
#include "boneweightloader.hpp"
#include "AnimationLoader.hpp"

using namespace std;
using namespace Assimp;

ModelLoader::ModelLoader(SDL_Renderer* renderCtx) : renderCtx(renderCtx) {}

bool ModelLoader::load(const char* fpath) {
    std::cout << "load(" << fpath << ")" << std::endl;

    scene = importer.ReadFile(
        fpath, aiProcess_CalcTangentSpace | aiProcess_Triangulate |
                   aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

    return scene != NULL;
}

LoadedMesh::LoadedMesh(ModelMesh m, const aiMesh* a)
    : loadedMesh(m), sourceMesh(a) {}

#define MAX_BONES_PER_VERT 16
LoadedMesh* makeModel(SDL_Renderer* renderCtx,
                      const aiScene* scene,
                      const aiMesh* mesh) {
    GLfloat* verts = new GLfloat[mesh->mNumFaces * 9];
    GLfloat* colors = NULL;
    GLfloat* uvs = NULL;

    if (mesh->HasVertexColors(0)) {
        std::cout << "mesh has vertex colors" << std::endl;
        colors = new GLfloat[mesh->mNumFaces * 9];
    }

    if (mesh->HasTextureCoords(0)) {
        std::cout << "mesh has uvs" << std::endl;
        uvs = new GLfloat[mesh->mNumFaces * 6];
    }

    size_t tri = 0;
    for (size_t f = 0; f < mesh->mNumFaces; f++) {
        aiFace face = mesh->mFaces[f];
        for (size_t ind = 0; ind < face.mNumIndices; ind++) {
            size_t vertexIndex = face.mIndices[ind];

            aiVector3D vert = mesh->mVertices[vertexIndex];
            verts[tri * 3] = vert.x;
            verts[tri * 3 + 1] = vert.y;
            verts[tri * 3 + 2] = vert.z;

            if (colors) {
                aiColor4D color = mesh->mColors[0][vertexIndex];
                colors[tri * 3] = color.r;
                colors[tri * 3 + 1] = color.g;
                colors[tri * 3 + 2] = color.b;
            }

            if (uvs) {
                aiVector3D uv = mesh->mTextureCoords[0][vertexIndex];
                uvs[tri * 2] = uv.x;
                uvs[tri * 2 + 1] = uv.y;
            }

            tri++;
        }
    }

    // build an array of bone weights if the model has bones
    BoneWeightLoader boneWeights;
    boneWeights.loadMeshBoneWeights(mesh, MAX_BONES_PER_VERT);

    // assemble the final mesh
    WorldspaceMesh* outMesh = new WorldspaceMesh();
    outMesh->init(verts, colors, uvs, tri);
    if (boneWeights.isInitialized()) {
        outMesh->initSkeleton(
            boneWeights.getBoneCounts(), boneWeights.getBoneIndecies(),
            boneWeights.getBoneWeights(), boneWeights.max_bones_per_vert,
            boneWeights.numBones);
    }

    // construct a material from the corresponding aiMaterial
    aiMaterial* loadedMaterial = scene->mMaterials[mesh->mMaterialIndex];
    Material* material = new Material();
    if (loadedMaterial->GetTextureCount(aiTextureType_AMBIENT)) {
        std::cout << "material has an ambient texture" << std::endl;
        aiString path;
        if (loadedMaterial->GetTexture(aiTextureType_AMBIENT, 0, &path)) {
            std::cout << "failed to load texture" << std::endl;
        } else {
            std::cout << "ambient texture @ " << path.C_Str() << std::endl;
            SDL_Surface* loadedSurface = IMG_Load(path.C_Str());
            SDL_Texture* loadedTexture =
                SDL_CreateTextureFromSurface(renderCtx, loadedSurface);
            material->setAmbientTexture(loadedTexture);
        }
    }

    LoadedMesh* m = new LoadedMesh(
        ModelMesh{
            .material = material,
            .mesh = outMesh,
            .animations = std::map<std::string, MeshAnim*>(),
        },
        mesh);
    return m;
}

Model* ModelLoader::queryScene(const char* scenePath) {
    std::cout << "queryScene(" << scenePath << ")" << std::endl;
    if (scene == NULL) {
        return NULL;
    }

    std::vector<LoadedMesh*> loadedMeshes;
    for (size_t i = 0; i < scene->mNumMeshes; i++) {
        std::cout << "querying mesh" << i << " of " << scene->mNumMeshes
                  << std::endl;
        const aiMesh* mesh = scene->mMeshes[i];
        std::cout << "query " << mesh->mName.C_Str() << "? " << scenePath
                  << std::endl;
        if (0 == strcmp(mesh->mName.C_Str(), scenePath)) {
            std::cout << "loading a mesh with " << mesh->mNumVertices
                      << " verts"
                      << ", " << mesh->mNumFaces << " faces" << std::endl;

            if (mesh->mNumFaces != 0) {
                loadedMeshes.push_back(makeModel(renderCtx, scene, mesh));
            }
        }
    }

    if (loadedMeshes.size() == 0) {
        return NULL;
    }

    // create an ordered set of bone names
    std::vector<ModelMesh> meshes;
    for (LoadedMesh* mesh : loadedMeshes) {
        for (size_t i = 0; i < scene->mNumAnimations; i++) {
            aiAnimation* animation = scene->mAnimations[i];
            MeshAnim* modelAnimation = AnimationLoader::makeModelAnimation(
                mesh->sourceMesh, animation);
            std::string name = std::string(animation->mName.C_Str());
            mesh->loadedMesh.animations[name] = modelAnimation;
            meshes.push_back(mesh->loadedMesh);
        }
    }

    return new Model(meshes);
}

