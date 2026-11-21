#include "lift.h"
#include "pros/misc.h"
#include "robot-config.h"

void lift_movement(pros::Controller& controller) {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        LeftLiftMotor.move(-127);
        RightLiftMotor.move(127);
    } else {
        LeftLiftMotor.move(0);
        RightLiftMotor.move(0);
    }

    bool up = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    bool down = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);

    if (up && !down) {
        LeftLiftMotor.move(127);
        RightLiftMotor.move(-127);

    } else if (down && !up) {
        LeftLiftMotor.move(-127);
        RightLiftMotor.move(127);
    } else {
        LeftLiftMotor.move(0);
        RightLiftMotor.move(0);
    }
}