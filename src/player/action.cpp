#include <iostream>
#include "action.hpp"
#include "util.hpp"
#include "terrain/ledge.hpp"
#include "./player.hpp"
#include "inputhandler.hpp"

using namespace InputMapping;

JumpType checkJumpInput(InputHandler& i) {
    if (i.down(JUMP))
        return JUMP_BUTTON;
    if (i.axis(MOVEMENT_AXIS_Y) < -0.66 && i.axis(MOVEMENT_AXIS_Y, 1) > -0.2)
        return JUMP_STICK;
    return NO_JUMP;
}

bool interruptWithJump(Player& p) {
    JumpType jump = checkJumpInput(*(p.input));
    if (jump != NO_JUMP) {
        p.jumpType = jump;
        p.changeAction(KNEEBEND);
        return true;
    }
    return false;
}

bool interruptWithDJump(Player& p) {
    JumpType jump = checkJumpInput(*(p.input));
    if (jump != NO_JUMP && p.times_jumped < p.getAttribute("number_of_jumps")) {
        p.changeAction((sign(p.input->axis(MOVEMENT_AXIS_X)) == sign(p.face))
                           ? JUMPAIRF
                           : JUMPAIRB);
        p.fastfalled = false;
        return true;
    }
    return false;
}

bool interruptWithAirdodge(Player& p) {
    if (p.input->down(SHIELD_BUTTON)) {
        p.changeAction(ESCAPEAIR);
        return true;
    }
    return false;
}

bool interruptWithDash(Player& p) {
    if (p.getXInput() > 0.79) {
        // std::cout << "initiating dash "
        //     << p.input->axis(MOVEMENT_AXIS_X) << " "
        //     << p.face << std::endl;

        p.changeAction(DASH);
        return true;
    }
    return false;
}

bool interruptWithSmashTurn(Player& p) {
    if (p.getXInput() < -0.79 &&
        p.input->axis(MOVEMENT_AXIS_X, 2) * p.face > -0.3) {
        p.changeAction(SMASHTURN);
        return true;
    }
    return false;
}

bool interruptWithTiltTurn(Player& p) {
    if (p.getXInput() < -0.3) {
        p.changeAction(TURN);
        return true;
    }
    return false;
}

bool interruptWithRunBrake(Player& p) {
    if (std::abs(p.input->axis(MOVEMENT_AXIS_X)) < 0.62) {
        p.changeAction(RUNBRAKE);
        return true;
    }
    return false;
}

bool interruptWithRunTurn(Player& p) {
    if (p.getXInput() < -0.3) {
        p.changeAction(RUNTURN);
        return true;
    }
    return false;
}

bool interruptWithWalk(Player& p) {
    if (p.getXInput() > 0.3) {
        p.changeAction(WALK);
        return true;
    }
    return false;
}

bool interruptWithWait(Player& p) {
    if (std::abs(p.input->axis(MOVEMENT_AXIS_X)) < 0.1) {
        p.changeAction(WAIT);
        return true;
    }
    return false;
}

bool interruptWithPass(Player& p) {
    if ((p.input->axis(MOVEMENT_AXIS_Y) > 0.65 ||
         p.input->axis(MOVEMENT_AXIS_Y, 1) > 0.65 ||
         p.input->axis(MOVEMENT_AXIS_Y, 2) > 0.65) &&
        p.input->axis(MOVEMENT_AXIS_Y, 6) < 0.3 &&
        p.getCurrentPlatform()->isPassable()) {
        p.changeAction(PASS);
        return true;
    }
    return false;
}

bool interruptWithSquat(Player& p) {
    if (p.input->axis(MOVEMENT_AXIS_Y) > 0.69) {
        p.changeAction(SQUAT);
        return true;
    }
    return false;
}

bool interruptWithSquatRv(Player& p) {
    if (p.input->axis(MOVEMENT_AXIS_Y) < 0.69) {
        p.changeAction(SQUATRV);
        return true;
    }
    return false;
}

void applyTraction(Player& p, double multiplier = 1.0) {
    double friction = p.getAttribute("friction");
    if (p.cVel.x > 0) {
        p.cVel.x = std::max(0.0, p.cVel.x - friction * multiplier);
    } else {
        p.cVel.x = std::min(0.0, p.cVel.x + friction * multiplier);
    }
}

LandType Action::getLandType(Player&) {
    return NORMAL_LANDING;
}

void Action::onLanding(Player&) {
    std::cerr << "no action registered on landing" << std::endl;
}

bool Action::isGrounded(Player const&) {
    return true;
}

bool Action::isLandable(Player const&, Platform const*) {
    return true;
}

bool Action::canWalkOff(Player const&) {
    return true;
}

bool Action::canGrabLedge(Player const&) {
    return false;
}

class Walk : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            float walkInitialVelocity = p.getAttribute("walk_initial_velocity");
            float initialWalk = walkInitialVelocity * p.face;
            if ((initialWalk > 0 && p.cVel.x < initialWalk) ||
                (initialWalk < 0 && p.cVel.x > initialWalk)) {
                p.cVel.x += initialWalk;
            }
        }

        if (interrupt(p))
            return;

        // Current Walk Acceleration = ((MaxWalkVel * Xinput) -
        // PreviousFrameVelocity) * (1/(MaxWalkVel * 2)) * (InitWalkVel *
        // WalkAcc)
        float walkSpeedMax = p.getAttribute("walk_maximum_velocity");
        float walkAcc = p.getAttribute("walk_acceleration");

        float requestedWalkSpeed =
            walkSpeedMax * p.input->axis(MOVEMENT_AXIS_X);
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

    bool interrupt(Player& p) {
        return interruptWithWait(p) || interruptWithJump(p) ||
               (p.timer <= 1 && interruptWithDash(p)) ||
               interruptWithTiltTurn(p);
    }
};

class Wait : public Action {
    void step(Player& p) override {
        if (interrupt(p))
            return;
        applyTraction(p);
    }

    bool interrupt(Player& p) {
        return interruptWithJump(p) || interruptWithDash(p) ||
               interruptWithSmashTurn(p) || interruptWithTiltTurn(p) ||
               interruptWithWalk(p) || interruptWithSquat(p);
    }
};

class Fall : public Action {
    void init(Player& p) {}

    void step(Player& p) override {
        if (interrupt(p))
            return;

        p.fall();
        p.aerialDrift();
    }

    bool interrupt(Player& p) {
        return interruptWithAirdodge(p) || interruptWithDJump(p);
    }

    bool isLandable(Player const& p, Platform const* plat) override {
        return !(plat->isPassable() && p.input->axis(MOVEMENT_AXIS_Y) > 0.67);
    }

    bool isGrounded(Player const& p) override { return false; }
    bool canGrabLedge(Player const& p) override { return true; }
};

class SpecialFall : public Action {
    void init(Player& p) {}

    void step(Player& p) override {
        p.fall();
        p.aerialDrift();
    }

    bool isGrounded(Player const& p) override { return false; }
    bool canGrabLedge(Player const& p) override { return true; }
};

// normal landing
class Landing : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            p.fastfalled = false;
        }
        if (p.timer > 4) {
            p.changeAction(WAIT);
        }
        if (interrupt(p))
            return;
        applyTraction(p, 2);
    }
    bool interrupt(Player& p) { return interruptWithJump(p); }
};

class KneeBend : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            p.isShortHop = false;
        }

        if (p.jumpType == JUMP_STICK &&
            p.input->axis(MOVEMENT_AXIS_Y) > -0.67) {
            p.isShortHop = true;
        } else if (p.jumpType == JUMP_BUTTON &&
                   !(p.input->held(JUMP) || p.input->held(JUMP))) {
            p.isShortHop = true;
        }

        if (p.timer > p.getAttribute("jump_startup_lag")) {
            if (p.getXInput() > -0.2) {
                p.changeAction(JUMPF);
            } else {
                p.changeAction(JUMPB);
            }
        }
    }

    bool canWalkOff(Player const&) override { return false; }
};

void startGroundedJump(Player& p, bool isShort) {
    p.cVel.y -= p.getAttribute(isShort ? "shorthop_v_initial_velocity"
                                       : "jump_v_initial_velocity");

    p.fixEcbBottom(10, 0);

    double maxJumpVel = p.getAttribute("jump_h_max_velocity");

    p.cVel.x = p.cVel.x * p.getAttribute("ground_air_jump_momentum_mult");
    if (std::abs(p.cVel.x) > maxJumpVel) {
        p.cVel.x = sign(p.cVel.x) * maxJumpVel;
    }

    p.times_jumped++;
}

class JumpB : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            startGroundedJump(p, p.isShortHop);
        }

        if (interrupt(p))
            return;

        p.fall();
        p.aerialDrift();

        if (p.timer > 20) {
            p.changeAction(FALL);
        }
    }

    bool interrupt(Player& p) {
        return interruptWithAirdodge(p) || interruptWithDJump(p);
    }

    bool isGrounded(Player const& p) override { return false; }
};

class JumpF : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            startGroundedJump(p, p.isShortHop);
        }

        if (interrupt(p))
            return;

        p.fall();
        p.aerialDrift();

        if (p.timer > 20) {
            p.changeAction(FALL);
        }
    }

    bool interrupt(Player& p) {
        return interruptWithAirdodge(p) || interruptWithDJump(p);
    }

    bool isGrounded(Player const& p) override { return false; }
};

void startDoubleJump(Player& p) {
    p.fixEcbBottom(10, -0.1);

    p.cVel.y = -p.getAttribute("jump_v_initial_velocity") *
               p.getAttribute("air_jump_multiplier");

    p.cVel.x =
        p.input->axis(MOVEMENT_AXIS_X) * p.getAttribute("air_jump_h_momentum");

    double maxJumpVel = p.getAttribute("jump_h_max_velocity");

    p.cVel.x = p.cVel.x * p.getAttribute("ground_air_jump_momentum_mult");
    if (std::abs(p.cVel.x) > maxJumpVel) {
        p.cVel.x = sign(p.cVel.x) * maxJumpVel;
    }

    p.times_jumped++;
}

class JumpAir : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            startDoubleJump(p);
        }

        if (interrupt(p))
            return;

        p.fall();
        p.aerialDrift();

        if (p.timer > 20) {
            p.changeAction(FALL);
        }
    }

    bool interrupt(Player& p) {
        return interruptWithAirdodge(p) ||
               (p.timer != 0 && interruptWithDJump(p));
    }

    bool isGrounded(Player const& p) override { return false; }
};

class Turn : public Action {
    void step(Player& p) override {
        if (p.timer == 6) {
            p.face = -p.face;
        }

        if (interrupt(p))
            return;

        if (p.timer == p.getAttribute("turn_duration")) {
            std::cout << "rolling back, p.timer=" << p.timer << std::endl;
            p.changeAction(WAIT);
        }

        applyTraction(p);
    }

    bool interrupt(Player& p) {
        return interruptWithJump(p) || (p.timer <= 1 && interruptWithDash(p));
    }

    bool isGrounded(Player const& p) override { return false; }
};

#define PI 3.14159265

class EscapeAir : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            dodgeVelocity(p);
            p.fastfalled = false;
            // p.landingMultiplier = 3;
        }

        if (p.timer < 30) {
            p.cVel.x *= 0.9;
            p.cVel.y *= 0.9;
        } else {
            p.changeAction(SPECIALFALL);
        }
    }

    void dodgeVelocity(Player& p) {
        double x = p.input->axis(MOVEMENT_AXIS_X);
        double y = p.input->axis(MOVEMENT_AXIS_Y);

        if (std::abs(x) > 0.3 || std::abs(y) > 0.3) {
            double ang = atan2(y, x);
            p.cVel.x = 3.1 * std::cos(ang);
            p.cVel.y = 3.1 * std::sin(ang);
        } else {
            p.cVel.x = 0;
            p.cVel.y = 0;
        }
    }

    bool isGrounded(Player const& p) override { return false; }
};

#define DASH_FRAME_MIN 14
#define DASH_FRAME_MAX 26
#define DASH_FRAME_END 30

class Dash : public Action {
    void step(Player& p) override {
        if (interrupt(p))
            return;
        double dMaxV = p.getAttribute("run_max_velocity");
        double dAccA = p.getAttribute("stopturn_initial_velocity");

        if (p.timer == 1) {
            p.cVel.x += p.face * p.getAttribute("dash_initial_velocity");
            if (std::abs(p.cVel.x) > std::abs(dMaxV)) {
                p.cVel.x = dMaxV * p.face;
            }
        }

        if (p.timer > 0) {
            if (std::abs(p.input->axis(MOVEMENT_AXIS_X)) < 0.3) {
                applyTraction(p);
            } else {
                double tempMax = p.input->axis(MOVEMENT_AXIS_X) * dMaxV;
                double tempAcc = p.input->axis(MOVEMENT_AXIS_X) * dAccA;

                p.cVel.x += tempAcc;
                // if the player is moving too fast, slow them down
                if (sign(tempMax) == sign(p.cVel.x) &&
                    std::abs(tempMax) < std::abs(p.cVel.x)) {
                    applyTraction(p);

                    // cap at tempMax
                    p.cVel.x = sign(p.cVel.x) *
                               std::max(std::abs(p.cVel.x), std::abs(tempMax));
                }
                // if the player is moving within bounds, speed them up more
                else {
                    p.cVel.x += dAccA;

                    // cap at tempMax
                    p.cVel.x = sign(p.cVel.x) *
                               std::min(std::abs(p.cVel.x), std::abs(tempMax));
                }
            }
        }
    }

    bool interrupt(Player& p) {
        if (interruptWithJump(p))
            return true;
        if (p.timer > 4 && interruptWithSmashTurn(p)) {
            p.cVel.x *= 0.25;
            return true;
        } else if (p.timer > DASH_FRAME_MAX && p.getXInput() > 0.79 &&
                   p.getXInput(2) < 0.3) {
            p.changeAction(DASH);
            return true;
        } else if (p.timer > DASH_FRAME_MIN && p.getXInput() > 0.62) {
            p.changeAction(RUN);
            return true;
        } else if (p.timer > DASH_FRAME_END) {
            p.changeAction(WAIT);
            return true;
        }
        return false;
    }
};

#define RUN_DURATION 20
class Run : public Action {
    void step(Player& p) override {
        if (interrupt(p))
            return;
        // TODO RUNBRAKE and RUNTURN
        double rMaxV = p.getAttribute("run_max_velocity");
        double rAccA = p.getAttribute("stopturn_initial_velocity");
        double rAccB = p.getAttribute("walk_acceleration");
        double xInput = p.input->axis(MOVEMENT_AXIS_X);

        double tempMax = xInput * rMaxV;

        p.cVel.x += (rMaxV * xInput - p.cVel.x) * (0.25 / rMaxV) *
                    (rAccA + rAccB / sign(xInput));

        if (xInput * p.face > tempMax * p.face) {
            p.cVel.x = tempMax;
        }

        // // animation scaling
        // double time = p.cVel.x * p.face / dMaxV;
        // if (time > 0) {
        //     p.timer += time;
        // }
    }

    bool interrupt(Player& p) {
        return interruptWithJump(p) || interruptWithSquat(p) ||
               interruptWithRunBrake(p) || interruptWithRunTurn(p);
    }
};

#define RUNBRAKE_DURATION 20
class RunBrake : public Action {
    void step(Player& p) {
        if (interruptWithJump(p) || interruptWithRunTurn(p))
            return;

        applyTraction(p, 2.0);

        if (p.timer > RUNBRAKE_DURATION) {
            p.changeAction(WAIT);
        }
    }
};

#define RUNTURN_DURATION 20
class RunTurn : public Action {
    void step(Player& p) {
        // state transitions
        if (interruptWithJump(p))
            return;
        if (p.timer > RUNTURN_DURATION) {
            p.changeAction(p.getXInput() > 0.6 ? RUN : WAIT);
        }

        // behavior in turn
        int breakPoint = p.getAttribute("runturn_break_point");
        if (p.timer == breakPoint) {
            p.face *= -1;
        }

        if (p.timer < breakPoint && p.getXInput() < -0.3) {
            double dAccA = p.getAttribute("stopturn_initial_velocity");
            double tempAcc =
                p.face * dAccA * std::abs(p.input->axis(MOVEMENT_AXIS_X));
            p.cVel.x -= tempAcc;
        } else if (p.timer >= breakPoint && p.getXInput() < 0.3) {
            double dAccA = p.getAttribute("stopturn_initial_velocity");
            double tempAcc =
                p.face * dAccA * std::abs(p.input->axis(MOVEMENT_AXIS_X));
            p.cVel.x += tempAcc;
        } else {
            applyTraction(p, 2.0);
        }

        if (p.timer == breakPoint - 1 && p.cVel.x * p.face > 0) {
            p.timer--;
        }
    }
};

class SmashTurn : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            p.face *= -1;
        }
        if (interrupt(p))
            return;
        // TODO RUNBRAKE and RUNTURN
        applyTraction(p, 2.0);
    }

    bool interrupt(Player& p) {
        return interruptWithJump(p) || (p.timer == 1 && interruptWithDash(p)) ||
               (p.timer > 10 && interruptWithWait(p));
    }
};

#define PASS_DURATION 15
class Pass : public Action {
    void step(Player& p) override {
        if (p.timer < 0)
            return;
        if (p.timer == 0) {
            p.fixEcbBottom(10, 0);
        }
        if (interrupt(p))
            return;

        if (p.fastfalled) {
        } else {
            p.cVel.y += p.getAttribute("gravity");
            if (p.cVel.y > p.getAttribute("terminal_velocity")) {
                p.cVel.y = p.getAttribute("terminal_velocity");
            }
            if (p.input->axis(MOVEMENT_AXIS_Y) > 0.67 &&
                p.input->axis(MOVEMENT_AXIS_Y, 5) < 0.3) {
                p.fall(true);
            }
        }
        p.aerialDrift();
        if (p.timer >= PASS_DURATION) {
            p.changeAction(FALL);
        }
    }

    bool interrupt(Player& p) {
        return interruptWithAirdodge(p) || interruptWithDJump(p);
    }

    bool isGrounded(Player const& p) override { return false; }
    bool isLandable(Player const& p, Platform const* plat) override {
        return plat != p.getCurrentPlatform();
    }
};

#define SQUAT_DURATION 6
#define SQUAT_RV_DURATION 6

class Squat : public Action {
    void step(Player& p) override {
        if (interrupt(p))
            return;
        if (p.timer == SQUAT_DURATION) {
            p.changeAction(SQUATWAIT);
        }
        applyTraction(p, 2.0);
    }

    bool interrupt(Player& p) {
        return (p.timer == 4 && interruptWithPass(p)) || interruptWithJump(p);
    }
};

class SquatWait : public Action {
    void step(Player& p) override {
        if (interrupt(p))
            return;
        applyTraction(p, 2.0);
    }

    bool interrupt(Player& p) {
        return interruptWithSquatRv(p) || interruptWithJump(p) ||
               interruptWithDash(p) || interruptWithSmashTurn(p);
    }
};

class SquatRv : public Action {
    void step(Player& p) override {
        if (interrupt(p))
            return;
        if (p.timer == SQUAT_RV_DURATION) {
            p.changeAction(WAIT);
        }
        applyTraction(p, 2.0);
    }

    bool interrupt(Player& p) {
        return interruptWithJump(p) || interruptWithDash(p) ||
               interruptWithSmashTurn(p) || interruptWithWalk(p);
    }
};

#define CLIFFCATCH_DURATION 4

class CliffCatch : public Action {
    void step(Player& p) override {
        if (p.timer == 0) {
            p.times_jumped = 0;
        }
        if (p.timer == CLIFFCATCH_DURATION) {
            p.changeAction(CLIFFWAIT);
        }
        // fix self to the ledge
        const Ledge* l = p.currentLedge;

        // character offset
        Pair target = l->position + Pair(-0.08 * p.face, 0.38);

        p.setPosition(target);
        p.cVel = Pair(0, 0);
    }

    bool isGrounded(Player const& p) override { return false; }
};

class CliffWait : public Action {
    void step(Player& p) override {
        if (interrupt(p))
            return;
        p.cVel = Pair(0, 0);
    }

    bool interrupt(Player& p) {
        if ((p.getXInput() < -0.2 && p.getXInput(1) >= -0.2) ||
            (p.input->axis(MOVEMENT_AXIS_Y) > 0.2 &&
             p.input->axis(MOVEMENT_AXIS_Y, 1) >= -0.2)) {
            p.times_jumped++;
            p.ledgeRegrabCounter = 30;
            p.changeAction(FALL);
            return true;
        }
        return false;
    }

    bool isGrounded(Player const& p) override { return false; }
};

const char* actionStateName(ActionState state) {
    if (state < __NUM_ACTION_STATES) {
        return ACTION_STATE_NAMES[state];
    } else {
        return "??";
    }
}

Action* ACTIONS[__NUM_ACTION_STATES] = {
        [WALK] = new Walk(),
        [ WAIT ] = new Wait(),
        [ FALL ] = new Fall(),
        [ SPECIALFALL ] = new SpecialFall(),
        [ LANDING ] = new Landing(),
        [ KNEEBEND ] = new KneeBend(),
        [ JUMPF ] = new JumpF(),
        [ JUMPB ] = new JumpB(),
        [ JUMPAIRF ] = new JumpAir(),
        [ JUMPAIRB ] = new JumpAir(),
        [ ESCAPEAIR ] = new EscapeAir(),
        [ TURN ] = new Turn(),
        [ DASH ] = new Dash(),
        [ RUN ] = new Run(),
        [ SMASHTURN ] = new SmashTurn(),
        [ RUNBRAKE ] = new RunBrake(),
        [ RUNTURN ] = new RunTurn(),
        [ PASS ] = new Pass(),
        [ SQUAT ] = new Squat(),
        [ SQUATWAIT ] = new SquatWait(),
        [ SQUATRV ] = new SquatRv(),
        [ CLIFFCATCH ] = new CliffCatch(),
        [ CLIFFWAIT ] = new CliffWait(),
};

#define ACTION_STATE(x) #x,
const char* ACTION_STATE_NAMES[__NUM_ACTION_STATES + 1] = {
#include "actionstates"
};
#undef ACTION_STATE
