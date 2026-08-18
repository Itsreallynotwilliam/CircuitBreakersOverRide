#pragma once
#include "lemlib/api.hpp"
#include "pros/imu.hpp"
#include "pros/motors.hpp"
#include "pros/misc.hpp"

extern pros::Controller master;
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;
extern pros::Motor motor20;
extern pros::IMU imu;

extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;