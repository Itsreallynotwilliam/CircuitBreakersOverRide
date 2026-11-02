#include "pneumatics.h"
#include "robot-config.h" // claw and long_claw are declared here

static bool claw_state = false;
static bool x_was_pressed = false;

static bool long_claw_state = false;
static bool y_was_pressed = false;

void pneumatics_update(pros::Controller& controller) {
	// Toggle state is kept between calls; "was_pressed" gives edge detection
	// so holding a button only toggles once.

	// X button toggles the claw
	bool x_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
	if (x_pressed && !x_was_pressed) {
		claw_state = !claw_state;
		claw.set_value(claw_state);
	}
	x_was_pressed = x_pressed;

	// Y button toggles the long claw
	bool y_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
	if (y_pressed && !y_was_pressed) {
		long_claw_state = !long_claw_state;
		long_claw.set_value(long_claw_state);
	}
	y_was_pressed = y_pressed;
}