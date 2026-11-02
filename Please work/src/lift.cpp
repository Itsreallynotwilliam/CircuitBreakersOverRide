#include "lift.h"
#include "pros/misc.h"
#include "robot-config.h"

void lift_movement(pros::Controller& controller) {
    int power = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    LeftLiftMotor.move(-power);
    RightLiftMotor.move(power);
}
