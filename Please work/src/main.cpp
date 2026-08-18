#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/motors.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

pros::Controller master(pros::E_CONTROLLER_MASTER);

// Left side: ports 1, 2, 3
pros::MotorGroup left_mg({-1, -2, -3});

// Right side: -4, -5, -6
pros::MotorGroup right_mg({4, 5, 6});

<<<<<<< Updated upstream
// Motor 2 for independent control
pros::Motor motor2(-2);
=======
pros::Motor motor20(20);
>>>>>>> Stashed changes

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "testing! 12");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */






void opcontrol(){

    const int DEAD_BAND = 5;

    while (true) {
        // Read joysticks
        int forwardSpeed = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turnSpeed = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // Prevent joystick drift
        if (abs(forwardSpeed) < DEAD_BAND) {
            forwardSpeed = 0;
        }

        if (abs(turnSpeed) < DEAD_BAND) {
            turnSpeed = 0;
        }

        // Arcade drive calculations
        int leftSpeed = forwardSpeed + turnSpeed;
        int rightSpeed = forwardSpeed - turnSpeed;

        // Clamp to valid controller range (-127 to 127)
        if (leftSpeed > 127) leftSpeed = 127;
        if (leftSpeed < -127) leftSpeed = -127;

        if (rightSpeed > 127) rightSpeed = 127;
        if (rightSpeed < -127) rightSpeed = -127;

        // Move motors
        left_mg.move(leftSpeed);
        right_mg.move(rightSpeed);
<<<<<<< Updated upstream
        
        // Check if bumper switch button is pressed
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            motor2.move(20);
        }
        //dhfsoidhfo
        //test for jakeyyy
        

        
=======
        motor20.move(127);
>>>>>>> Stashed changes

        pros::delay(20);
    }
}
