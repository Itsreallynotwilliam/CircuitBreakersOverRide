#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "robot-config.h"
// #include "pneumatics.h"


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */


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
// initialize function. Runs on program startup

// void initialize() {
//     pros::lcd::initialize(); // initialize brain screen
//     chassis.calibrate(); // calibrate sensors
//     // print position to brain screen
//     pros::Task screen_task([&]() {
//         while (true) {
//             // print robot location to the brain screen
// 			pros::lcd::print(1, "Rotation Sensor: %i", horizontal_encoder.get_position());

//             pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
//             pros::lcd::print(2, "Y: %f", chassis.getPose().y); // y
//             pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // heading
//             // delay to save resources
//             pros::delay(20);
//         }
//     });
// }
void initialize() {
    pros::lcd::initialize();

    pros::Task screen_task([]() {
        while (true) {
            lemlib::Pose pose = chassis.getPose();
            pros::lcd::print(1, "X: %.2f  Y: %.2f", pose.x, pose.y);
            pros::lcd::print(2, "Theta: %.2f", pose.theta);
            pros::lcd::print(3, "IMU: %.2f", imu.get_heading()); // remove if your IMU has a different name
            pros::delay(50);
        }
    });

    pros::lcd::set_text(5, "Calibrating...");
    chassis.calibrate();   // keep the robot completely still here
    pros::lcd::set_text(5, "Calibrated!");
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
void autonomous() {
    // 1. Reset the robot's coordinates to 0,0 heading 0
    chassis.setPose(0, 0, 0); //

    // 2. Command the robot to drive 15 inches straight forward 
    // Arguments: X-coordinate, Y-coordinate, timeout in milliseconds
    chassis.moveToPoint(0, 60, 4000); //
}
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

void opcontrol() {
    autonomous();
    while (true) {
        // Read joysticks
		// autonomous();
        int forwardSpeed = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turnSpeed = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        chassis.arcade(forwardSpeed, turnSpeed);

        // Jakes test
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            motor20.move(20);
        } else {
            motor20.move(0);
        }
        
        // Right Trigger turns claw on
        static bool claw_state = false;
        static bool x_was_pressed = false;

        bool x_pressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_X);
        if (x_pressed && !x_was_pressed) {
            claw_state = !claw_state;
            claw.set_value(claw_state);
        }
        x_was_pressed = x_pressed;

        static bool claw_state2 = false;
        static bool y_was_pressed = false;

        bool y_pressed = master.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
        if (y_pressed && !y_was_pressed) {
            claw_state2 = !claw_state2;
            long_claw.set_value(claw_state2);
        }
        y_was_pressed = y_pressed;

        motor1.move_velocity(200);

       
	
        

 
        pros::delay(20);



    }
}

