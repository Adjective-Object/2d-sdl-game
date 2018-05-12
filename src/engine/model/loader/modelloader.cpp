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
#include <assimp/postprocess.h>
#include <assimp/quaternion.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
// locals
#include "AnimationLoader.hpp"
#include "VertexLoader.hpp"
#include "boneweightloader.hpp"
#include "engine/material/material.hpp"
#include "engine/mesh/worldspacemesh.hpp"
#include "engine/meshanim/meshanim.hpp"
#include "modelloader.hpp"

using namespace std;
using namespace Assimp;

ModelLoader::ModelLoader() {}

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
LoadedMesh* makeModel(const aiScene* scene, const aiMesh* assimpMesh) {
    GLfloat* verts = new GLfloat[assimpMesh->mNumFaces * 9];
    GLfloat* colors = NULL;
    GLfloat* uvs = NULL;

    if (assimpMesh->HasVertexColors(0)) {
        std::cout << "assimpMesh has vertex colors" << std::endl;
        colors = new GLfloat[assimpMesh->mNumFaces * 9];
    }

    if (assimpMesh->HasTextureCoords(0)) {
        std::cout << "assimpMesh has uvs" << std::endl;
        uvs = new GLfloat[assimpMesh->mNumFaces * 6];
    }

    VertexLoader vertexLoader(assimpMesh);
    vertexLoader.loadMeshVerticiesAndIndecies();

    // build an array of bone weights if the model has bones
    BoneWeightLoader boneWeights;
    boneWeights.loadMeshBoneWeights(assimpMesh, MAX_BONES_PER_VERT);

    // assemble the final mesh
    WorldspaceMesh* outMesh = new WorldspaceMesh();
    outMesh->init(&(vertexLoader.getVerts()->front()),     // verts
                  &(vertexLoader.getIndecies()->front()),  // indecies
                  colors, uvs,
                  vertexLoader.getVerts()->size() / 3,     // num_verts
                  vertexLoader.getIndecies()->size() / 3   // num_tris
    );
    if (boneWeights.isInitialized()) {
        outMesh->initSkeleton(
            boneWeights.getBoneCounts(), boneWeights.getBoneIndecies(),
            boneWeights.getBoneWeights(), boneWeights.max_bones_per_vert,
            boneWeights.numBones);
    }

    // construct a material from the corresponding aiMaterial
    aiMaterial* loadedMaterial = scene->mMaterials[assimpMesh->mMaterialIndex];
    Material* material = new Material();
    if (loadedMaterial->GetTextureCount(aiTextureType_AMBIENT)) {
        std::cout << "material has an ambient texture" << std::endl;
        aiString path;
        if (loadedMaterial->GetTexture(aiTextureType_AMBIENT, 0, &path)) {
            std::cout << "failed to load texture" << std::endl;
        } else {
            std::cout << "ambient texture @ " << path.C_Str() << std::endl;
            SDL_Surface* loadedSurface = IMG_Load(path.C_Str());
            Texture* loadedTexture = Texture::fromSurface(loadedSurface);
            delete loadedSurface;
            material->setAmbientTexture(loadedTexture);
        }
    }

    LoadedMesh* m = new LoadedMesh(
        ModelMesh{
            .material = material,
            .mesh = outMesh,
            .animations = std::map<std::string, MeshAnim*>(),
        },
        assimpMesh);
    return m;
}

Model* ModelLoader::queryScene(const char* scenePath) {
    std::cout << "queryScene(" << scenePath << ")" << std::endl;
    if (scene == NULL) {
        return NULL;
    }

    std::vector<LoadedMesh*> loadedMeshes;
    for (size_t i = 0; i < scene->mNumMeshes; i++) {
        const aiMesh* mesh = scene->mMeshes[i];
        std::cout << "considering mesh " << i << " of " << scene->mNumMeshes
                  << ". name: \"" << mesh->mName.C_Str() << "\"" << std::endl;
        if (0 == strcmp(mesh->mName.C_Str(), scenePath)) {
            std::cout << "loading a mesh with " << mesh->mNumVertices
                      << " verts"
                      << ", " << mesh->mNumFaces << " faces" << std::endl;

            if (mesh->mNumFaces != 0) {
                loadedMeshes.push_back(makeModel(scene, mesh));
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
            if (name == "") {
                name = "anima_" + std::to_string(i);
            }
            mesh->loadedMesh.animations[name] = modelAnimation;
            meshes.push_back(mesh->loadedMesh);
        }
    }

    return new Model(meshes);
}
