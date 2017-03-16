#ifndef __GAME_PLATFORM_MOVEMENT
#define __GAME_PLATFORM_MOVEMENT

typedef struct PlatformMovementState {
    bool initialized = false;
    const Platform *platform;
    int currentSegment;
    int direction;
    double currentPlatformPercent;
    double remainingDistance;
} PlatformMovementState;

#endif

