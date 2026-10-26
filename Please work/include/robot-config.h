#ifndef _PROS_ROBOT_CONFIGS_H_
#define _PRO_ROBOT_CONFIGS_H_
#include "main.h"
#include "lemlib/api.hpp"


extern pros::Controller master;

//drivetrain stuff
extern pros::MotorGroup left_motor_group;
extern pros::MotorGroup right_motor_group;
extern lemlib::Chassis chassis;

//bot motors
extern pros::Motor motor1;
extern pros::Motor motor20;

extern pros::Motor LeftLiftMotor;
extern pros::Motor RightLiftMotor;


extern pros::Imu imu;


extern pros::Rotation horizontal_encoder;
extern pros::Rotation vertical_encoder;



extern pros::adi::Pneumatics claw;
extern pros::adi::Pneumatics long_claw;


extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
#endif