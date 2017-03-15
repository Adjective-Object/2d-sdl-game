#ifndef __GAME_MAP_MOVEMENT
#define __GAME_MAP_MOVEMENT
#include "map.hpp"

namespace Terrain {

#define WALL_COLL_ARGS                                                \
    Map const &m, Player const &player, const Pair expectedDirection, \
        Ecb &currentEcb, Ecb &nextStepEcb, Ecb &projectedEcb,         \
        double &distance, PlatformSegment &lastWallCollision

extern int (*rightWallCollision)(WALL_COLL_ARGS);
extern int (*leftWallCollision)(WALL_COLL_ARGS);
extern int (*ceilingCollision)(WALL_COLL_ARGS);

#define EDGE_COLL_ARGS                                                     \
    Map const &m, Player const &player, Ecb &currentEcb, Ecb &nextStepEcb, \
        Ecb &projectedEcb, double &distance

extern int (*topRightEdgeCollision)(EDGE_COLL_ARGS);
extern int (*bottomRightEdgeCollision)(EDGE_COLL_ARGS);
extern int (*bottomLeftEdgeCollision)(EDGE_COLL_ARGS);
extern int (*topLeftEdgeCollision)(EDGE_COLL_ARGS);

bool performFloorCollision(Map const& m,
                           Player& player,
                           Ecb& currentEcb,
                           Ecb& nextStepEcb,
                           Ecb& projectedEcb,
                           const Platform*& currentPlatform,
                           double& distance);
}

#endif
