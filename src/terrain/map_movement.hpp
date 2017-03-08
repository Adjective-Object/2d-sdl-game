#ifndef __GAME_MAP_MOVEMENT
#define __GAME_MAP_MOVEMENT
#include "map.hpp"

namespace Terrain {

#define WALL_COLL_ARGS                                                \
    Map const &m, Player const &player, const Pair expectedDirection, \
        Ecb &currentEcb, Ecb &nextStepEcb, Ecb &projectedEcb,         \
        double &distance, PlatformSegment &lastWallCollision

extern bool (*rightWallCollision)(WALL_COLL_ARGS);
extern bool (*leftWallCollision)(WALL_COLL_ARGS);
extern bool (*ceilingCollision)(WALL_COLL_ARGS);

#define EDGE_COLL_ARGS                                                     \
    Map const &m, Player const &player, Ecb &currentEcb, Ecb &nextStepEcb, \
        Ecb &projectedEcb, double &distance

extern bool (*topRightEdgeCollision)(EDGE_COLL_ARGS);
extern bool (*bottomRightEdgeCollision)(EDGE_COLL_ARGS);
extern bool (*bottomLeftEdgeCollision)(EDGE_COLL_ARGS);
extern bool (*topLeftEdgeCollision)(EDGE_COLL_ARGS);

bool performFloorCollision(Map const& m,
                           Player& player,
                           Ecb& currentEcb,
                           Ecb& nextStepEcb,
                           Ecb& projectedEcb,
                           const Platform*& currentPlatform,
                           double& distance);
}

#endif
