#include "intake.h"
#include "robot-config.h"

void intakein(pros::Controller& controller) {
    const bool running = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    IntakeMotor.move(running ? 127 : 0);
}
