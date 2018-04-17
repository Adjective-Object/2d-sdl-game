#ifndef __GAME_BASICSHADER
#define __GAME_BASICSHADER

#include "engine/gl.h"
#include "primitiveshader.hpp"

// define the attribtues of a mesh shader generically in macro form

#define MESH_SHADER_ATTRIBUTES                                \
    attribute(position) attribute(uvs) attribute(vertexColor) \
        attribute(boneCount) attribute(inBoneIndex) attribute(inBoneWeights)

#define MESH_SHADER_UNIFORMS                                                \
    uniform(baseTransform) uniform(ambientTexture) uniform(boneMatrixArray) \
        uniform(boneMatrixArrayInverseTrans)

// define the attribute and uniform structures
#define attribute(name) GLint name;
#define uniform(name) GLint name;

typedef struct {
    MESH_SHADER_UNIFORMS
} MeshShaderUniforms;

typedef struct {
    MESH_SHADER_ATTRIBUTES
} MeshShaderAttributes;

#undef attribute
#undef uniform

// enumerate the attributes and uniforms a mesh shader can consume
#define attribute(name) \
    name = (offsetof(MeshShaderAttributes, name) / sizeof(GLint)),
#define uniform(name) \
    name = (offsetof(MeshShaderUniforms, name) / sizeof(GLint)),

enum MESH_SHADER_UNIFORM { MESH_SHADER_UNIFORMS __NUM_UNIFORMS };

enum MESH_SHADER_ATTRIBUTE { MESH_SHADER_ATTRIBUTES __NUM_ATTRIBUTES };

// declare the shader class consuming the above structs and enums
class MeshShader : public PrimitiveShader {
   public:
    size_t bonesPerVertex = 4;
    size_t maxBones = 16;

    MeshShaderUniforms uniforms;
    MeshShaderAttributes attributes;

    MeshShader(const char* vec, const char* frag);
    void init();

    bool hasAttribute(MESH_SHADER_ATTRIBUTE);
    bool hasUniform(MESH_SHADER_UNIFORM);
};

extern MeshShader vertexColorShader;
extern MeshShader textureShader;
extern MeshShader fallbackShader;

#undef attribute
#undef uniform

#endif
