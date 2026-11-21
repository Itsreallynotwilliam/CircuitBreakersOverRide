#include "intake.h"
#include "pros/misc.h"
#include "robot-config.h"

void intakein(pros::Controller& controller) {
    bool in = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
    bool out = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);

    if (in && !out) {
        IntakeMotor.move(127);
    } else if (out && !in) {
        IntakeMotor.move(-127);
    } else {
        IntakeMotor.move(0);
    }
}
