#version 330 core

// @require MAX_BONES_PER_VERT
// @require MAX_BONES

in vec3 position;
in vec2 uvs;
uniform mat4 baseTransform;

in mediump float inBoneIndex[MAX_BONES_PER_VERT];
in mediump float inBoneWeights[MAX_BONES_PER_VERT];

uniform mediump int boneCount;
uniform highp mat4 boneMatrixArray[MAX_BONES];
uniform highp mat3 boneMatrixArrayInverseTrans[MAX_BONES];

out vec2 texCoord;

void main()
{
    highp vec4 skinnedPosition = vec4(0,0,0,0);
    bool bSkinningApplied = false;
    for (lowp int i=0; i<MAX_BONES_PER_VERT; i++) {
        if (i < boneCount) {
            highp mat4 boneMatrix = boneMatrixArray[i];
            mediump mat3 normalMatrix = boneMatrixArrayInverseTrans[i];

            skinnedPosition += boneMatrix * vec4(position, 1) * boneWeights.x;
        }
    }

    gl_Position = baseTransform * skinnedPosition;
    texCoord = uvs;
}

void init() {

}
