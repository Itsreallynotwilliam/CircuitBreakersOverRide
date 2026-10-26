#include "lift.h"
#include "pros/misc.h"
#include "robot-config.h"

void lift_movement(pros::Controller& controller) {
    LeftLiftMotor.move(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    RightLiftMotor.move(-master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
}
