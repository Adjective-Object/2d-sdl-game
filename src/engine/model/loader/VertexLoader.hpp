#ifndef __ENGINE_VERTEXLOADER_H
#define __ENGINE_VERTEXLOADER_H
#include <vector>
#include "engine/gl.h"
#include "engine/model/modelmesh.hpp"
// assimp
#include <assimp/mesh.h>

class VertexLoader {
   private:
    std::vector<GLfloat> verts;
    std::vector<WORLDSPACE_MESH_INDEX_TYPE> indecies;
    const aiMesh* mesh;

   public:
    VertexLoader(const aiMesh* mesh);
    void loadMeshVerticiesAndIndecies();
    const std::vector<GLfloat>* getVerts() const;
    const std::vector<WORLDSPACE_MESH_INDEX_TYPE>* getIndecies() const;
};

#endif
