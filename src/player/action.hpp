#ifndef __GAME_ACTION_HPP
#define __GAME_ACTION_HPP
class Player;

typedef enum LandType {
    NORMAL,
    KNOCKDOWN,
    SPECIAL,
} LandType;

typedef enum JumpType {
    NO_JUMP,
    JUMP_STICK,
    JUMP_BUTTON,
} JumpType;


class Action {
public:
    virtual void step(Player & p) = 0;
    virtual LandType getLandType(Player & p);
    virtual void onLanding(Player & p);
};

typedef enum {
    WALK,
    WAIT,
    FALL,
    LANDING,
    KNEEBEND,
    JUMPF,
    JUMPB,
    ESCAPEAIR,
    __NUM_ACTION_STATES,
} ActionState;
const char * actionStateName(ActionState);

extern Action* ACTIONS[__NUM_ACTION_STATES];

#endif

