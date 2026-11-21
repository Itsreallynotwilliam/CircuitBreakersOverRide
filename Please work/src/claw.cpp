#include "claw.h"
#include "robot-config.h"

void claw_update(pros::Controller& controller) {
    bool in = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    bool out = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);

    if (in && !out) {
        ClawMotor.move(127);
    } else if (out && !in) {
        ClawMotor.move(-127);
    } else {
        ClawMotor.move(0);
    }
}