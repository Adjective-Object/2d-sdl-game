#version 410 core

// @require MAX_BONES_PER_VERT
// @require MAX_BONES

uniform mat4 baseTransform;
uniform mat4 boneMatrixArray[MAX_BONES];
uniform mat3 boneMatrixArrayInverseTrans[MAX_BONES];

in vec3 position;
in vec2 uvs;

in lowp int boneCount;
in mediump int inBoneIndex[MAX_BONES_PER_VERT];
in float inBoneWeights[MAX_BONES_PER_VERT];

in vec3 vertexColor;
out vec3 fragmentColor;

void main()
{
    // vec4 skinnedPosition = vec4(0,0,0,0);
    // for (int i=0; i<MAX_BONES_PER_VERT; i++) {
    //     if (i < boneCount) {
    //         mat4 boneMatrix = boneMatrixArray[i];
    //         mat3 normalMatrix = boneMatrixArrayInverseTrans[i];
    //         float boneWeight = inBoneWeights[i];

    //         skinnedPosition += 
    //             boneMatrix *
    //             vec4(position, 1) *
    //             boneWeight;
    //     }
    // }

    fragmentColor = vec3(0);
    if (boneCount != 1) {
        fragmentColor = vec3(1, 0, boneCount / 9999999.0);
    } else {
        if (boneCount > 0) {
            fragmentColor.x = inBoneIndex[0] * inBoneWeights[0];
        }
        if (boneCount > 1) {
            fragmentColor.y = inBoneIndex[1] * inBoneWeights[1];
        }
        if (boneCount > 2) {
            fragmentColor.z = inBoneIndex[2] * inBoneWeights[2];
        }            
    }
    // fragmentColor = vec3(boneCount / 100.0);
    // fragmentColor = boneIndecies;
    gl_Position = baseTransform * vec4(position, 1.0);
}
