#include <set>
#include "AnimationLoader.hpp"
#include <iostream>
#include <glm/gtx/string_cast.hpp>

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
    size_t numPosKeys[animation->mNumChannels] = {0};
    size_t curPosKeys[animation->mNumChannels] = {0};
    size_t numRotKeys[animation->mNumChannels] = {0};
    size_t curRotKeys[animation->mNumChannels] = {0};
    size_t numSclKeys[animation->mNumChannels] = {0};
    size_t curSclKeys[animation->mNumChannels] = {0};
    std::set<float> keyframeTimes;
    for (size_t i = 0; i < animation->mNumChannels; i++) {
        aiNodeAnim* nodeAnim = animation->mChannels[i];
        numPosKeys[i] = nodeAnim->mNumPositionKeys;
        for (size_t y = 0; y < nodeAnim->mNumPositionKeys; y++) {
            float time = (float)(nodeAnim->mPositionKeys[y].mTime);
            keyframeTimes.insert(time);
        }
        numRotKeys[i] = nodeAnim->mNumRotationKeys;
        for (size_t y = 0; y < nodeAnim->mNumRotationKeys; y++) {
            float time = (float)(nodeAnim->mRotationKeys[y].mTime);
            keyframeTimes.insert(time);
        }
        numSclKeys[i] = nodeAnim->mNumScalingKeys;
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
            aiVector3D position, scaling;
            aiQuaternion rotation;
            baseTransformAi.Decompose(scaling, rotation, position);
            if (numRotKeys[i] != 0) {
                aiQuatKey curRotKey = nodeAnim->mRotationKeys[curRotKeys[i]];
                aiQuatKey nextRotKey = nodeAnim->mRotationKeys[std::min(
                    curRotKeys[i] + 1, numRotKeys[i] - 1)];
                std::cout << curRotKey.mTime << std::endl;
                std::cout << keyTime << std::endl;
                std::cout << nextRotKey.mTime << std::endl;
                ratio = (float)((keyTime - curRotKey.mTime) /
                                (nextRotKey.mTime - curRotKey.mTime));
                aiQuaternion::Interpolate(rotation, curRotKey.mValue,
                                          nextRotKey.mValue, ratio);

                // if we reached this keyframe's timestamp, advance
                if (nextRotKey.mTime <= keyTime &&
                    curRotKeys[i] < numRotKeys[i] - 1) {
                    std::cout << "adnvance rotation from " << curRotKeys[i]
                              << " to ";
                    curRotKeys[i]++;
                    std::cout << curRotKeys[i] << std::endl;
                }
            }

            if (numPosKeys[i] != 0) {
                aiVectorKey curPosKey = nodeAnim->mPositionKeys[curPosKeys[i]];
                aiVectorKey nextPosKey = nodeAnim->mPositionKeys[std::min(
                    curPosKeys[i] + 1, numPosKeys[i] - 1)];
                ratio = (float)((keyTime - curPosKey.mTime) /
                                (nextPosKey.mTime - curPosKey.mTime));
                position =
                    (1 - ratio) * curPosKey.mValue + ratio * nextPosKey.mValue;

                std::cout << "cur: " << curPosKeys[i] << std::endl;
                std::cout << "next: "
                          << std::min(curPosKeys[i] + 1, numPosKeys[i] - 1)
                          << std::endl;
                std::cout << "ratio: " << ratio << std::endl;

                // if we reached this keyframe's timestamp, advance
                if (nextPosKey.mTime <= keyframeTimesOrdered[t] &&
                    curPosKeys[i] < numPosKeys[i] - 1) {
                    std::cout << "adnvance position from " << curPosKeys[i]
                              << " to ";
                    curPosKeys[i]++;
                    std::cout << curPosKeys[i] << std::endl;
                }
            }

            if (numSclKeys[i] != 0) {
                aiVectorKey curSclKey = nodeAnim->mScalingKeys[curSclKeys[i]];
                aiVectorKey nextSclKey = nodeAnim->mScalingKeys[std::min(
                    curSclKeys[i] + 1, numSclKeys[i] - 1)];
                ratio = (float)((keyTime - curSclKey.mTime) /
                                (nextSclKey.mTime - curSclKey.mTime));
                scaling =
                    (1 - ratio) * curSclKey.mValue + ratio * nextSclKey.mValue;

                // if we reached this keyframe's timestamp, advance
                if (nextSclKey.mTime <= keyframeTimesOrdered[t] &&
                    curSclKeys[i] < numSclKeys[i] - 1) {
                    curSclKeys[i]++;
                }
            }

            aiMatrix3x3 rotateMatrix3 = rotation.GetMatrix();
            aiMatrix4x4 rotateMatrix = aiMatrix4x4(rotateMatrix3);

            aiMatrix4x4 scaleMatrix, positionMatrix;
            aiMatrix4x4::Scaling(scaling, scaleMatrix);
            aiMatrix4x4::Translation(position, positionMatrix);

            aiMatrix4x4 composedTransform =
                rotateMatrix * scaleMatrix * positionMatrix;
            glm::mat4 animTransform = glmMat4FromAiMat4(composedTransform);
            glm::mat4 baseTransform = glmMat4FromAiMat4(baseTransformAi);

            glm::mat4 r = glmMat4FromAiMat4(rotateMatrix);
            glm::mat4 s = glmMat4FromAiMat4(scaleMatrix);
            glm::mat4 p = glmMat4FromAiMat4(positionMatrix);

            std::cout << "t: " << t << " (" << keyTime << ")" << std::endl;
            std::cout << "  r: " << glm::to_string(r) << std::endl;
            std::cout << "  s: " << glm::to_string(s) << std::endl;
            std::cout << "  p: " << glm::to_string(p) << std::endl;
            std::cout << "  anim: " << glm::to_string(animTransform)
                      << std::endl;
            std::cout << "  base: " << glm::to_string(baseTransform)
                      << std::endl;

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
