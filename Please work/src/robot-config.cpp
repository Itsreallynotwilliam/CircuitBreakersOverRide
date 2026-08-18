#include "robot-config.h"
#include "pros/imu.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mg({-1, -2, -3});
pros::MotorGroup right_mg({4, 5, 6});
pros::Motor motor20(20);
pros::IMU imu(11);

lemlib::Drivetrain drivetrain(
    &left_mg,
    &right_mg,
    12,
    lemlib::Omniwheel::NEW_325,
    360,
    2
);

lemlib::OdomSensors sensors(
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr, 
    imu
);

// kP, kI, kD, windupRange, smallError, smallErrorTimeout, largeError, largeErrorTimeout, slew
lemlib::ControllerSettings lateral_controller(
    10,   // kP
    0,    // kI
    3,    // kD
    3,    // windupRange
    1,    // smallError (inches)
    100,  // smallErrorTimeout (ms)
    3,    // largeError (inches)
    500,  // largeErrorTimeout (ms)
    20    // slew (max acceleration)
);

lemlib::ControllerSettings angular_controller(
    2,    // kP
    0,    // kI
    10,   // kD
    3,    // windupRange
    1,    // smallError (degrees)
    100,  // smallErrorTimeout (ms)
    3,    // largeError (degrees)
    500,  // largeErrorTimeout (ms)
    0     // slew (max acceleration)
);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);