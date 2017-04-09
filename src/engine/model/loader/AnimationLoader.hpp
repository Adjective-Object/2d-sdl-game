#ifndef __ENGINE_ANIMATIONLOADER_H
#define __ENGINE_ANIMATIONLOADER_H

#include <engine/meshanim/meshanim.hpp>
// assimp
#include <mesh.h>
#include <anim.h>

class AnimationLoader {
   public:
    // utility methods exposed for testing
    static MeshAnim* makeModelAnimation(const aiMesh* mesh,
                                        const aiAnimation* animation);
};

#endif
