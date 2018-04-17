#include "meshanim.hpp"
#include <cmath>
#include <vector>

MeshAnim::MeshAnim(std::vector<Keyframe*> frames) : frames(frames) {}

void MeshAnim::getTransform(const float time, glm::mat4* out) const {
    int i;
    for (i = 0; i < frames.size(); i++) {
        if (frames[i]->time >= time) {
            break;
        }
    }
    int previousFrame = std::max(i - 1, 0);
    float prevTime = frames[previousFrame]->time;
    float curTime = frames[i]->time;
    float timeDiff = curTime - prevTime;
    if (timeDiff == 0) {
        for (int x = 0; x < frames[i]->transforms.size(); x++) {
            out[x] = frames[i]->transforms[x];
        }
        return;
    }

    float ratio = (time - previousFrame) / timeDiff;
    for (int x = 0; x < frames[i]->transforms.size(); x++) {
        out[x] = frames[i]->transforms[x] * ratio +
                 frames[prevTime]->transforms[x] * (1 - ratio);
    }
}

float MeshAnim::getDuration() const {
    return frames[frames.size() - 1]->time;
}

size_t MeshAnim::getNumFrames() const {
    return frames.size();
}
