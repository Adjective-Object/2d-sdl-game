#ifndef __ENGINE_MESHANIM
#define __ENGINE_MESHANIM

#include <vector>
#include "engine/gl.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

typedef struct {
    std::vector<glm::mat4> transforms;
    float time;
} Keyframe;

class MeshAnim {
    float duration;
    public:
    MeshAnim(std::vector<Keyframe *> frames);
    std::vector<Keyframe *> frames;
    void getTransform(const float time, glm::mat4 * out) const;
    float getDuration() const;
    size_t getNumFrames() const;
};

#endif
