#include "robot-config.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mg({-1, -2, -3});
pros::MotorGroup right_mg({4, 5, 6});
pros::Motor motor20(20);

lemlib::Drivetrain drivetrain(
    &left_mg,
    &right_mg,
    12,
    lemlib::Omniwheel::NEW_325,
    360,
    2
);

lemlib::OdomSensors sensors(
    nullptr, nullptr, nullptr, nullptr, nullptr
);

lemlib::ControllerSettings lateral_controller(
    10, 0, 3,
    3, 100,
    3, 500,
    20
);

lemlib::ControllerSettings angular_controller(
    2, 0, 10,
    1, 100,
    3, 500,
    0
);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);