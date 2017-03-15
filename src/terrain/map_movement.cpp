#include "util.hpp"
#include "engine/util.hpp"
#include "constants.hpp"
#include <iostream>
#include "engine/game.hpp"
#include "widthbuf.hpp"
#include "map.hpp"
#include "map_movement.hpp"

using namespace Terrain;

#define _debug(...) \
    {}

inline Pair const& getEcbSideRight(Ecb const& e) {
    return e.right;
}

inline void setEcbSideRight(Ecb& e, Pair pos) {
    return e.setRight(pos);
}

inline Pair const& getEcbSideLeft(Ecb const& e) {
    return e.left;
}

inline void setEcbSideLeft(Ecb& e, Pair pos) {
    return e.setLeft(pos);
}

inline Pair const& getEcbBottom(Ecb const& e) {
    return e.bottom;
}

inline Pair const& getEcbTop(Ecb const& e) {
    return e.top;
}

inline void setEcbTop(Ecb& e, Pair const pos) {
    return e.setTop(pos);
}

inline double getX(Pair const& pos) {
    return pos.x;
}

inline double getY(Pair const& pos) {
    return pos.y;
}

inline void setX(Pair& pos, const double val) {
    pos.x = val;
}

inline void setY(Pair& pos, const double val) {
    pos.y = val;
}

/** Adjusts the projected ecb's position
 *
 * Takes the difference between the nestStepEcb and the position that the ecb
 * would be in at equivalend y() had no collision occured, and applies that
 * difference to projectedEcb.
 *
 */
template <double (*x)(Pair const& pos),
          double (*y)(Pair const& pos),
          void (*xSet)(Pair& pos, const double val)>

void rollback(Player const& player,
              Ecb const& currentEcb,
              Ecb const& nextStepEcb,
              Ecb& projectedEcb) {
    // move the goal back by taking the X difference between the
    // position without collision at the new Y and the position
    // after wall sliding

    // get the relative positions of the destination with and
    // without collision
    Pair relPosNoColl = projectedEcb.origin - currentEcb.origin;
    Pair relPosColl = nextStepEcb.origin - currentEcb.origin;

    if (y(relPosNoColl) == 0 || player.isGrounded()) {
        _debug(out << "rollback grounded " << nextStepEcb << std::endl;);
        projectedEcb.setOrigin(nextStepEcb.origin);
    } else {
        relPosNoColl *= y(relPosColl) / y(relPosNoColl);

        _debug(out << relPosNoColl << " " << relPosColl << std::endl;);

        double noCollisionDistance = x(relPosColl) - x(relPosNoColl);
        if (currentEcb.origin == nextStepEcb.origin) {
            // we collide with the wall at the next step. only slide.
            noCollisionDistance = x(currentEcb.origin) - x(projectedEcb.origin);
        }

        _debug(out << "noCollisionDistance " << noCollisionDistance
                   << std::endl;);

        Pair rollbackAmount = Pair(0, 0);
        xSet(rollbackAmount, noCollisionDistance);
        Pair rollbackPosition = projectedEcb.origin + rollbackAmount;

        _debug(out << "rollback position: " << rollbackPosition << std::endl;);

        // update the player position and projected ECB
        projectedEcb.setOrigin(rollbackPosition);
    }
}

/** Perform a collision with the wall
 *
 */
template <Pair const& (*getEcbSide)(Ecb const&),
          void (*setEcbSide)(Ecb&, Pair const pos),
          double (*x)(Pair const& pos),
          double (*y)(Pair const& pos),
          void (*setBlockingAxis)(Pair& pos, double val),
          void (*setNonblockingAxis)(Pair& pos, double value),
          TerrainCollisionType expectedCollisionType>
int performWallCollision(Map const& m,
                          Player const& player,
                          const Pair expectedDirection,
                          Ecb& currentEcb,
                          Ecb& nextStepEcb,
                          Ecb& projectedEcb,
                          double& distance,
                          PlatformSegment& lastWallCollision) {
    CollisionDatum collision;
    int priority = 10;

    // ignore collision if the collision is coming from the wrong direction
    if (Dot((projectedEcb.origin - currentEcb.origin), expectedDirection) < 0) {
        return 0;
    }

    Ecb _currentEcb = currentEcb;
    if (!m.getClosestCollision(getEcbSide(_currentEcb),
                               getEcbSide(projectedEcb), collision,
                               lastWallCollision, expectedCollisionType)) {
        return 0;
    }

    double directionY = y(projectedEcb.origin) - y(_currentEcb.origin);
    double lineDirectionY = sign(
        (*collision.segment.firstPoint() - *collision.segment.secondPoint()).y);

    // ignore collisions if we would instead collide on an edge
    if (*collision.segment.firstPoint() == collision.position &&
        lineDirectionY == sign(directionY)) {
        _debug(
            out << "reducing collision with wall because the edge might collide"
                << std::endl;);
        priority = 1;
    }

    // ignore collisions if we would instead collide on an edge
    if (*collision.segment.secondPoint() == collision.position &&
        lineDirectionY != sign(directionY)) {
        _debug(
            out << "reducing collision with wall because the edge might collide"
                << std::endl;);
        priority = 1;
    }

    lastWallCollision = collision.segment;

    distance = (getEcbSide(currentEcb) - collision.position).euclid();

    _debug(out << "colliding with wall " << collision.segment.getPlatform()
               << " at " << collision.position << std::endl;);

    Pair wallSlidePosition = collision.position;

    // perform sliding if the player is not grounded
    if (!player.isGrounded()) {
        double slidePosition =
            (directionY > 0)
                ? std::min(std::max(y(*collision.segment.secondPoint()),
                                    y(*collision.segment.firstPoint())),
                           y(getEcbSide(projectedEcb)))
                : std::max(std::min(y(*collision.segment.secondPoint()),
                                    y(*collision.segment.firstPoint())),
                           y(getEcbSide(projectedEcb)));

        double wallSlidePercent = (slidePosition - y(*collision.segment.firstPoint())) /
            (y(*collision.segment.secondPoint()) - y(*collision.segment.firstPoint()));
        wallSlidePosition =
            *collision.segment.firstPoint() + (
                    (*collision.segment.secondPoint() - *collision.segment.firstPoint()) * wallSlidePercent);
    }

    _debug(out << "position after sliding " << wallSlidePosition << std::endl;);

    // slide the ecb along the wall and update the next position w/o
    // movement
    setEcbSide(currentEcb, collision.position);
    setEcbSide(nextStepEcb, wallSlidePosition);

    _debug(out << "ecbs " << currentEcb.origin << ".." << projectedEcb.origin
               << std::endl;);

    rollback<x, y, setBlockingAxis>(player, currentEcb, nextStepEcb,
                                    projectedEcb);
    return priority;
}

class Line {
   public:
    Pair start;
    Pair end;
    Line(){};
    Line(Pair start, Pair end) : start(start), end(end){};
};

template <Pair const& (*getForwardEdge)(Ecb const&),
          Pair const& (*getBackEdge)(Ecb const&),
          void (*setForwardEdge)(Ecb&, Pair const pos),
          Line (*getEdge)(Ecb const&),
          void (*setEdge)(Ecb&, Line edge)>
int performWallEdgeCollision(Map const& m,
                              Player const& player,
                              Ecb& currentEcb,
                              Ecb& nextStepEcb,
                              Ecb& projectedEcb,
                              double& distance) {
    int priority = 10;
    Pair currentForward = getForwardEdge(currentEcb);
    Pair projectedForward = getForwardEdge(projectedEcb);

    Pair move = projectedForward - currentForward;

    // out << "current ecb: " << *currentEcb << std::endl;
    // out << "projected ecb: " << *projectedEcb << std::endl;

    // out << "currentForward: " << currentForward << std::endl;
    // out << "currentBack: " << currentBack << std::endl;
    // out << "projectedForward: " << projectedForward << std::endl;
    // out << "projectedBack: " << projectedBack << std::endl;

    // out << "line: " << line << std::endl;
    // out << "move: " << move << std::endl;

    if (move == Pair(0, 0))
        return 0;

    Line currentEdge = getEdge(currentEcb);
    Line projectedEdge = getEdge(projectedEcb);
    EdgeCollision collision;

    if (!m.getClosestEdgeCollision(currentEdge.start, currentEdge.end,
                                   projectedEdge.start, projectedEdge.end,
                                   collision)) {
        return 0;
    }

    Line collisionLine =
        Line(collision.collisionLine1, collision.collisionLine2);

    Pair collisionLine1 = collision.collisionLine1;
    Pair collisionLine2 = collision.collisionLine2;
    Pair collisionPoint = collision.cornerPosition;

    _debug(out << "collision line " << collisionLine1 << ".." << collisionLine2
               << std::endl;);

    setEdge(nextStepEcb, collisionLine);
    _debug(out << "next step " << nextStepEcb << std::endl;);

    // update the position w/o collision to the initial collision position
    currentEcb = nextStepEcb;

    distance = (collisionLine1 - currentEdge.start).euclid();

    // perform vertical sliding if the player is not grounded
    if (!player.isGrounded()) {
        // we want to slide this edge of the ecb along the point. It can slide
        //
        // - the remaining length of the ecb side
        // - until the Y of the projected point is the same as the Y of  slid
        //   point
        //

        // direction of slide is determined by:
        // if the angle between the direction of the side and the
        // angle of motion is > 90 degrees, we slide backwards. Otherwise.
        // we slide forwards
        double dot = Dot(move, currentEdge.end - currentEdge.start);

        Pair slide = (dot < 0) ? collisionPoint - collisionLine2
                               : collisionPoint - collisionLine1;

        // if the direction of sliding is into the platform, don't slide
        double averagePlatformY =
            (collision.s1.firstPoint()->y + collision.s1.secondPoint()->y +
             collision.s2.firstPoint()->y + collision.s2.secondPoint()->y) /
                4 -
            collision.cornerPosition.y;

        _debug(out << "platform y is on average" << averagePlatformY
                   << std::endl;);

        if ((collisionPoint == collisionLine1 ||
             collisionPoint == collisionLine2) &&
            sign(averagePlatformY) == sign(slide.y)) {
            _debug(out << "ignoring because we collided on a corner and the "
                          "slide is in the same direction as platform"
                       << std::endl;);
            return 0;
        }

        if (std::abs(slide.y - 0) < COLLISION_EPSILON) {
            return 0;
        }

        // scale the slide back if the destination Y is less than the
        // destination slide

        _debug(out << "unscaled slide: " << slide << std::endl;);

        double ySlide = projectedEcb.origin.y - currentEcb.origin.y;
        _debug(out << "initial vertical slide: " << ySlide << std::endl;);
        ySlide = sign(ySlide) * std::min(std::abs(ySlide), std::abs(slide.y));
        _debug(out << "minimal vertical slide: " << ySlide << std::endl;);

        slide *= ySlide / slide.y;

        _debug(out << "current start " << currentEdge.start << std::endl;
               out << "current end   " << currentEdge.end << std::endl;
               out << "slide: " << slide << std::endl;);

        nextStepEcb.setOrigin(nextStepEcb.origin + slide);
        // deal with clipping due to floating point errors
        if (std::abs(getForwardEdge(nextStepEcb).x - collisionPoint.x) <
            COLLISION_EPSILON) {
            Pair newOrigin = getForwardEdge(nextStepEcb);
            newOrigin.x = collisionPoint.x;
            setForwardEdge(nextStepEcb, newOrigin);
        }
    }

    _debug(out << "projected  " << projectedEcb << std::endl;
           out << "collided  " << nextStepEcb << std::endl;);

    rollback<getX, getY, setX>(player, currentEcb, nextStepEcb, projectedEcb);

    _debug(out << "rolled back projected " << projectedEcb << std::endl;);

    return priority;
}

namespace Terrain {

bool performFloorCollision(Map const& m,
                           Player& player,
                           Ecb& currentEcb,
                           Ecb& nextStepEcb,
                           Ecb& projectedEcb,
                           const Platform*& currentPlatform,
                           double& distance) {
    CollisionDatum collision;
    PlatformSegment currentPlatformAsSegment = PlatformSegment();

    if (!m.getClosestCollision(currentEcb.bottom, projectedEcb.bottom,
                               collision, currentPlatformAsSegment,
                               FLOOR_COLLISION)) {
        return false;
    }
    if (collision.type != FLOOR_COLLISION)
        return false;
    if (!player.canLand(collision.segment.getPlatform()))
        return false;

    distance = (currentEcb.bottom - collision.position).euclid();

    // player landing alters ECB as well
    currentPlatform = collision.segment.getPlatform();
    nextStepEcb = player.getLandedEcb(currentPlatform);
    nextStepEcb.setBottom(collision.position);
    currentEcb = nextStepEcb;
    projectedEcb = nextStepEcb;
    _debug(out << nextStepEcb << std::endl;);

    return true;
}

int (*rightWallCollision)(WALL_COLL_ARGS) =
    performWallCollision<getEcbSideRight,
                         setEcbSideRight,
                         getX,
                         getY,
                         setX,
                         setY,
                         WALL_COLLISION>;
int (*leftWallCollision)(WALL_COLL_ARGS) =
    performWallCollision<getEcbSideLeft,
                         setEcbSideLeft,
                         getX,
                         getY,
                         setX,
                         setY,
                         WALL_COLLISION>;
int (*ceilingCollision)(WALL_COLL_ARGS) = performWallCollision<getEcbTop,
                                                                setEcbTop,
                                                                getY,
                                                                getX,
                                                                setY,
                                                                setX,
                                                                CEIL_COLLISION>;

inline Line getTopRightEdge(Ecb const& e) {
    return Line(e.top, e.right);
}

inline Line getBottomRightEdge(Ecb const& e) {
    return Line(e.right, e.bottom);
}

inline Line getBottomLeftEdge(Ecb const& e) {
    return Line(e.bottom, e.left);
}

inline Line getTopLeftEdge(Ecb const& e) {
    return Line(e.left, e.top);
}

inline void setTopRightEdge(Ecb& e, Line l) {
    e.setRight(l.end);
}

inline void setBottomRightEdge(Ecb& e, Line l) {
    e.setRight(l.start);
}

inline void setBottomLeftEdge(Ecb& e, Line l) {
    e.setLeft(l.end);
}

inline void setTopLeftEdge(Ecb& e, Line l) {
    e.setLeft(l.start);
}

int (*topRightEdgeCollision)(EDGE_COLL_ARGS) =
    performWallEdgeCollision<getEcbSideRight,
                             getEcbTop,
                             setEcbSideRight,
                             getTopRightEdge,
                             setTopRightEdge>;

int (*bottomRightEdgeCollision)(EDGE_COLL_ARGS) =
    performWallEdgeCollision<getEcbSideRight,
                             getEcbBottom,
                             setEcbSideRight,
                             getBottomRightEdge,
                             setBottomRightEdge>;

int (*bottomLeftEdgeCollision)(EDGE_COLL_ARGS) =
    performWallEdgeCollision<getEcbSideLeft,
                             getEcbBottom,
                             setEcbSideLeft,
                             getBottomLeftEdge,
                             setBottomLeftEdge>;

int (*topLeftEdgeCollision)(EDGE_COLL_ARGS) =
    performWallEdgeCollision<getEcbSideLeft,
                             getEcbTop,
                             setEcbSideLeft,
                             getTopLeftEdge,
                             setTopLeftEdge>;
}
