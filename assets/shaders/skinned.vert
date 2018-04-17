#version 410 core

// @require MAX_BONES_PER_VERT
// @require MAX_BONES

uniform mat4 baseTransform;
uniform mat4 boneMatrixArray[MAX_BONES];
uniform mat3 boneMatrixArrayInverseTrans[MAX_BONES];

in vec3 position;
in vec2 uvs;

in int boneCount;
in int inBoneIndex[MAX_BONES_PER_VERT];
in float inBoneWeights[MAX_BONES_PER_VERT];

void main()
{
    vec4 skinnedPosition = vec4(0,0,0,0);
    for (int i=0; i<MAX_BONES_PER_VERT; i++) {
        // if (i < boneCount) {
        //     mat4 boneMatrix = boneMatrixArray[i];
        //     mat3 normalMatrix = boneMatrixArrayInverseTrans[i];
        //     float boneWeight = inBoneWeights[i];

        //     skinnedPosition += 
        //         boneMatrix *
        //         vec4(position, 1) *
        //         boneWeight;
        // }

        mat4 boneMatrix = boneMatrixArray[0];
        float boneWeight = inBoneWeights[0];

        skinnedPosition += 
            boneMatrix *
            vec4(position, 1) *
            boneWeight;

        break;
    }

    gl_Position = baseTransform * skinnedPosition;
}

void init() {

}
