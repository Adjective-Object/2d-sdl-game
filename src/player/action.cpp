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
    if (sign(p.joystick->axis(0)) == p.face &&
        std::abs(p.joystick->axis(0)) > 0.79) {

        std::cout << "initiating dash " 
            << p.joystick->axis(0) << " "
            << p.face << std::endl;

        p.changeAction(DASH);
        return true;
    }
    return false;
}

bool interruptWithTiltTurn(Player & p) {
    if (p.joystick->axis(0) * p.face < -0.3) {
        p.changeAction(TURN);
        return true;
    }
    return false;
}

bool interruptWithWalk(Player & p) {
    if (p.joystick->axis(0) * p.face > 0.3) {
        p.changeAction(WALK);
        return true;
    }
    return false;
}

bool interruptWithWait(Player & p) {
    if (std::abs(p.joystick->axis(0)) < 0.1) {
        p.changeAction(WAIT);
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
        if (std::abs(p.cVel.x) > std::abs(requestedWalkSpeed)) {
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
        return
            interruptWithWait(p) ||
            interruptWithJump(p) ||
            (p.timer <= 1 && interruptWithDash(p)) ||
            interruptWithTiltTurn(p);
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
            || interruptWithTiltTurn(p)
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
            if (p.joystick->axis(0) * p.face > -0.2) {
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
        return interruptWithAirdodge(p);
    }
};

class Turn : public Action {
    void step(Player &p) override {
        if (interrupt(p)) return;

        if (p.timer == p.config.getAttribute("turn_duration")) {
            std::cout << "rolling back, p.timer=" << p.timer << std::endl;
            p.face = -p.face;
            p.changeAction(WAIT);
        }
    }

    bool interrupt(Player &p) {
        return interruptWithJump(p) ||
            (p.timer <= 1 && interruptWithDash(p));
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


class Dash : public Action {
    void step (Player & p) override {

        if (p.timer == 0) {
            p.cVel.x += p.face * p.config.getAttribute("dash_initial_velocity");
        }

        if (interrupt(p)) return;

        if (p.timer > 1) {
            if (std::abs(p.joystick->axis(0)) < 0.3) {
                applyTraction(p);
            } else {
                double dashVelocityMax = p.joystick->axis(0) *
                    p.config.getAttribute("run_max_velocity");
                double dashAcceleration = p.joystick->axis(0) *
                    p.config.getAttribute("run_acceleration");

                p.cVel.x += dashAcceleration;

                // if the player is moving too fast, slow them down
                if (sign(dashVelocityMax) == sign(p.cVel.x) &&
                    std::abs(dashVelocityMax) < std::abs(p.cVel.x)) {
                    applyTraction(p);
                    p.cVel.x = sign(p.cVel.x) * std::min(std::abs(p.cVel.x), std::abs(dashVelocityMax));
                }
                // if the player is moving within bounds, speed them up more
                else {
                    p.cVel.x += dashAcceleration;
                    p.cVel.x = sign(p.cVel.x) * std::min(std::abs(p.cVel.x), std::abs(dashVelocityMax));
                }
            }
        }

        if (p.timer > 30) {
            double controllerDashThresh = p.joystick->axis(0) * p.face;
            if (controllerDashThresh > 0.62) {
                p.changeAction(RUN);
                return;
            } else {
                p.changeAction(WAIT);
                return;
            }
        }
    }

    bool interrupt(Player &p) {
        double thisDir = p.joystick->axis(0) * p.face;
        // if we switched directions (i.e. one pos one neg, switch to wait)
        // this is to allow for pivots and dash dancing
        if (thisDir <= 0) {
            std::cout << "swithcing wait due to turn" << thisDir << std::endl;
            p.changeAction(WAIT);
            p.face = -p.face;
            return true;
        }
        return interruptWithJump(p);
    }


};

class Run : public Action {
    void step (Player & p) override {
        if (interrupt(p)) return;
        // TODO RUNBRAKE and RUNTURN
    }

    bool interrupt(Player &p) {
        return interruptWithJump(p);
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
        case TURN: return "TURN";
        case DASH: return "DASH";
        case RUN: return "RUN";
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
    new Turn(),
    new Dash(),
    new Run(),
};

