#include <set>
#include "AnimationLoader.hpp"

const aiBone* getBoneFromNodeName(const aiMesh* mesh, const aiString name) {
    for (size_t i = 0; i < mesh->mNumBones; i++) {
        if (mesh->mBones[i]->mName == name) {
            return mesh->mBones[i];
        }
    }
    return NULL;
}

glm::mat4 glmMat4FromAiMat4(aiMatrix4x4& mat) {
    return glm::mat4(mat.a1, mat.a2, mat.a3, mat.a4, mat.b1, mat.b2, mat.b3,
                     mat.b4, mat.c1, mat.c2, mat.c3, mat.c4, mat.d1, mat.d2,
                     mat.d3, mat.d4);
}

MeshAnim* AnimationLoader::makeModelAnimation(const aiMesh* mesh,
                                              const aiAnimation* animation) {
    // get times of all keyframes in a way we can actually iterate over
    size_t numPosKeys[animation->mNumChannels];
    size_t curPosKeys[animation->mNumChannels] = {0};
    size_t numRotKeys[animation->mNumChannels];
    size_t curRotKeys[animation->mNumChannels] = {0};
    size_t numSclKeys[animation->mNumChannels];
    size_t curSclKeys[animation->mNumChannels] = {0};
    std::set<float> keyframeTimes;
    for (size_t i = 0; i < animation->mNumChannels; i++) {
        aiNodeAnim* nodeAnim = animation->mChannels[i];
        for (size_t y = 0; y < nodeAnim->mNumPositionKeys; y++) {
            float time = (float)(nodeAnim->mPositionKeys[y].mTime);
            keyframeTimes.insert(time);
        }
        for (size_t y = 0; y < nodeAnim->mNumRotationKeys; y++) {
            float time = (float)(nodeAnim->mRotationKeys[y].mTime);
            keyframeTimes.insert(time);
        }
        for (size_t y = 0; y < nodeAnim->mNumScalingKeys; y++) {
            float time = (float)(nodeAnim->mScalingKeys[y].mTime);
            keyframeTimes.insert(time);
        }
    }

    // sort the list of keyframe times
    std::vector<float> keyframeTimesOrdered = std::vector<float>();
    std::copy(keyframeTimes.begin(), keyframeTimes.end(),
              std::back_inserter(keyframeTimesOrdered));
    std::sort(keyframeTimesOrdered.begin(), keyframeTimesOrdered.end());

    std::vector<glm::mat4> frameTransforms[keyframeTimesOrdered.size()];
    for (int t = 0; t < keyframeTimesOrdered.size(); t++) {
        float keyTime = keyframeTimesOrdered[t];
        for (size_t i = 0; i < animation->mNumChannels; i++) {
            aiNodeAnim* nodeAnim = animation->mChannels[i];
            float ratio;

            const aiBone* bone = getBoneFromNodeName(mesh, nodeAnim->mNodeName);
            if (bone == NULL) {
                // we ignore animation keys for bones not inside this mesh
                continue;
            }
            aiMatrix4x4 baseTransformAi = bone->mOffsetMatrix;
            glm::mat4 baseTransform = glmMat4FromAiMat4(baseTransformAi);
            if (numRotKeys[i] == 0) {
                // no keyframes, push the base transform matrix
                frameTransforms[t].push_back(baseTransform);
                continue;
            }

            aiQuatKey curRotKey = nodeAnim->mRotationKeys[curRotKeys[i]];
            aiQuatKey nextRotKey = nodeAnim->mRotationKeys[std::min(
                curRotKeys[i] + 1, numRotKeys[i] - 1)];
            ratio = (float)((curRotKey.mTime - keyTime) /
                            (nextRotKey.mTime - curRotKey.mTime));
            aiQuaternion rotation;
            aiQuaternion::Interpolate(rotation, curRotKey.mValue,
                                      nextRotKey.mValue, ratio);

            aiVectorKey curPosKey = nodeAnim->mPositionKeys[curPosKeys[i]];
            aiVectorKey nextPosKey = nodeAnim->mPositionKeys[std::min(
                curPosKeys[i] + 1, numPosKeys[i] - 1)];
            ratio = (float)((curPosKey.mTime - keyTime) /
                            (nextPosKey.mTime - curPosKey.mTime));
            aiVector3D position =
                ratio * curPosKey.mValue + (1 - ratio) * nextPosKey.mValue;

            aiVectorKey curSclKey = nodeAnim->mScalingKeys[curSclKeys[i]];
            aiVectorKey nextSclKey =
                nodeAnim
                    ->mScalingKeys[min(curSclKeys[i] + 1, numSclKeys[i] - 1)];
            ratio = (float)((curSclKey.mTime - keyTime) /
                            (nextSclKey.mTime - curSclKey.mTime));
            aiVector3D scale =
                ratio * curSclKey.mValue + (1 - ratio) * nextSclKey.mValue;

            aiMatrix3x3 rotateMatrix3 = rotation.GetMatrix();
            aiMatrix4x4 rotateMatrix = aiMatrix4x4(rotateMatrix3);

            aiMatrix4x4 scaleMatrix, positionMatrix;
            aiMatrix4x4::Scaling(scale, scaleMatrix);
            aiMatrix4x4::Translation(position, positionMatrix);

            aiMatrix4x4 transform = rotateMatrix * scaleMatrix * positionMatrix;
            glm::mat4 animTransform = glmMat4FromAiMat4(transform);

            frameTransforms[t].push_back(animTransform * baseTransform);
        }
    }

    // build keyframes vector form the list of frame transforms
    std::vector<Keyframe*> frames(keyframeTimesOrdered.size());
    for (int t = 0; t < keyframeTimesOrdered.size(); t++) {
        frames[t] = new Keyframe;
        frames[t]->time = keyframeTimesOrdered[t];
        frames[t]->transforms = frameTransforms[t];
    }

    return new MeshAnim(frames);
}
