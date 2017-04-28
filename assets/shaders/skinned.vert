#version 110

// this program uses jinja2 as a templating engine to insert variables
// and needs to be preprocessed before running.
//
// note that because MAX_BONES_PER_VERT and MAX_BONES are both
// used as array size declarations, they are subject to the arraysize
// constraints of whatever hardware you are targeting (typically <=16)
#define MAX_BONES_PER_VERT {{maxBonesPerVert}}
#define MAX_BONES {{maxBones}}

attribute vec3 position;
uniform mat4 baseTransform;

attribute mediump float inBoneIndex[MAX_BONES_PER_VERT];
attribute mediump float inBoneWeights[MAX_BONES_PER_VERT];

uniform mediump int boneCount;
uniform highp mat4 boneMatrixArray[MAX_BONES];
uniform highp mat3 boneMatrixArrayInverseTrans[MAX_BONES];

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
}

void init() {

}
