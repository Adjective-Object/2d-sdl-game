#include <map>
#include <iostream>
#include "action.hpp"
#include "player.hpp"
#include "../util.hpp"

JumpType checkJumpInput(Joystick & j) {
    if (j.down(1) || j.down(2)) return JUMP_BUTTON;
    if (j.axis(1) < -0.66 && j.axis(1, 1) > -0.2) return JUMP_STICK;
    return NO_JUMP;
}

bool interruptWithJump(Player & p) {
    JumpType jump = checkJumpInput(*(p.joystick));
    if (jump != NO_JUMP) {
        p.jumpType = jump;
        p.changeAction(KNEEBEND);
        return true;
    }
    return false;
}

bool interruptWithAirdodge(Player & p) {
    if (p.joystick->down(4) || p.joystick->down(5)) {
        p.changeAction(ESCAPEAIR);
        return true;
    }
    return false;
}

bool interruptWithDash(Player & p) {
    return false;
}

bool interruptWithWalk(Player & p) {
    if (std::abs(p.joystick->axis(0)) > 0.3) {
        p.changeAction(WALK);
        return true;
    }
    return false;
}

void applyTraction(Player & p, double multiplier = 1.0) {
    double friction = p.config.getAttribute("friction");
    if (p.cVel.x > 0) {
        p.cVel.x = std::max(0.0, p.cVel.x - friction * multiplier);
    } else {
        p.cVel.x = std::min(0.0, p.cVel.x + friction * multiplier);
    }
}

LandType Action::getLandType(Player &) {
    return NORMAL;
}

void Action::onLanding(Player &) {
    std::cerr << "no action registered on landing" << std::endl;
}

class Walk : public Action {
    void step (Player & p) override {
        if (p.timer == 0) {
            float walkInitialVelocity = p.config.getAttribute("walk_initial_velocity");
            float initialWalk = walkInitialVelocity * p.face;
            if ((initialWalk > 0 && p.cVel.x < initialWalk) ||
                (initialWalk < 0 && p.cVel.x > initialWalk)) {
                p.cVel.x += initialWalk;
            }
        }
 
        if (interrupt(p)) return;

        //Current Walk Acceleration = ((MaxWalkVel * Xinput) - PreviousFrameVelocity) * (1/(MaxWalkVel * 2)) * (InitWalkVel * WalkAcc)
        float walkSpeedMax = p.config.getAttribute("walk_maximum_velocity");
        float walkAcc = p.config.getAttribute("walk_acceleration");
      
        float requestedWalkSpeed = walkSpeedMax * p.joystick->axis(0);
        if (abs(p.cVel.x) > abs(requestedWalkSpeed)) {
            applyTraction(p, 2);
        } else {
            float requestedWalkAcc =
                (requestedWalkSpeed - p.cVel.x) * (0.5 / walkSpeedMax) +
                walkAcc;

            p.cVel.x += requestedWalkAcc;

            // cap the speed at the requested walk speed
            if (p.cVel.x * p.face > requestedWalkSpeed * p.face) {
               p.cVel.x = requestedWalkSpeed;
            }
        }
    }

    bool interrupt(Player & p) {
        return interruptWithJump(p);
    }
};


class Wait : public Action {
    void step (Player & p) override {
        if (interrupt(p)) return;
        applyTraction(p);
    }

    bool interrupt(Player & p) {
        return interruptWithJump(p)
            || interruptWithDash(p)
            || interruptWithWalk(p);
    }
};

class Fall : public Action {
    void init(Player & p) {
    }

    void step (Player & p) override {
        if (interrupt(p)) return;

        p.fall();
        p.aerialDrift();
    }

    bool interrupt(Player & p) {
        return interruptWithAirdodge(p);
    }
};

// normal landing 
class Landing : public Action {
    void step (Player & p) override {
        if (p.timer == 0) {
            p.fastfalled = false;
        }
        if (p.timer > 4) {
            p.changeAction(WAIT);
        }
        if (interrupt(p)) return;
        applyTraction(p, 2);
    }
    bool interrupt(Player & p) {
        return interruptWithJump(p);
    }
};

class KneeBend : public Action {
    void step (Player & p) override {
        if (p.timer == 0) {
            p.isShortHop = false;
        }

        if (p.jumpType == JUMP_STICK && p.joystick->axis(1) > -0.67) {
            p.isShortHop = true;
        } else if (p.jumpType == JUMP_BUTTON && 
            !(p.joystick->held(1) || p.joystick->held(2))) {
            std::cout << "breaking short hopt" << std::endl;
            p.isShortHop = true;
        }

        if (p.timer > p.config.getAttribute("jump_startup_lag")) {
            if (p.joystick->axis(0) * p.facing > -0.3) {
                p.changeAction(JUMPF);
            } else {
                p.changeAction(JUMPB);
            }
        }
    }
};

void startJump(Player &p, bool isShort) {
    p.cVel.y -= p.config.getAttribute(
        isShort
        ? "shorthop_v_initial_velocity"
        : "jump_v_initial_velocity");

    double maxJumpVel = p.config.getAttribute("jump_h_max_velocity");

    p.cVel.x = p.cVel.x * p.config.getAttribute("ground_air_jump_momentum_mult");
    if (std::abs(p.cVel.x) > maxJumpVel) {
        p.cVel.x = sign(p.cVel.x) * maxJumpVel;
    }
}

class JumpB : public Action {
    void step (Player & p) override {
        if (p.timer == 0) {
            startJump(p, p.isShortHop);
        }

        if (interrupt(p)) return;

        p.fall();
        p.aerialDrift();
    }

    bool interrupt(Player & p) {
        if (interruptWithAirdodge(p)) return true;
        return false;
    }
};

class JumpF : public Action {
    void step (Player & p) override {
        if (p.timer == 0) {
            startJump(p, p.isShortHop);
        }

        if (interrupt(p)) return;

        p.fall();
        p.aerialDrift();
    }

    bool interrupt(Player & p) {
        if (interruptWithAirdodge(p)) return true;
        return false;
    }
};

#define PI 3.14159265

class EscapeAir : public Action {
    void step (Player & p) override {
        if (p.timer == 0) {
            dodgeVelocity(p);
            p.fastfalled = false;
            // p.landingMultiplier = 3;
        }

        if (p.timer < 30) {
            p.cVel.x *= 0.9;
            p.cVel.y *= 0.9;
        } else {
            p.aerialDrift();
            p.fall();
        }
    }

    void dodgeVelocity(Player & p) {
        double x = p.joystick->axis(0);
        double y = p.joystick->axis(1);

        if (std::abs(x) > 0.3 || std::abs(y) > 0.3) {
          double ang = atan2(y, x);
          p.cVel.x = 3.1 * std::cos(ang);
          p.cVel.y = 3.1 * std::sin(ang);
        } else {
          p.cVel.x = 0;
          p.cVel.y = 0;
        }
    }
};

const char * actionStateName(ActionState state) {
    switch(state) {
        case WALK: return "WALK";
        case WAIT: return "WAIT";
        case FALL: return "FALL";
        case LANDING: return "LANDING";
        case KNEEBEND: return "KNEEBEND (Jump Squat)";
        case JUMPF: return "JUMPF";
        case JUMPB: return "JUMPB";
        case ESCAPEAIR: return "ESCAPEAIR";
        default: return "??";
    }
}

Action* ACTIONS[__NUM_ACTION_STATES] = {
    new Walk(),
    new Wait(),
    new Fall(),
    new Landing(),
    new KneeBend(),
    new JumpF(),
    new JumpB(),
    new EscapeAir(),
};

