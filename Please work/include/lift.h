#pragma once

 
#include "main.h"
 
/**
 * Handles all pneumatics controls. Call once per loop from opcontrol().
 *
 *  X button -> toggles claw
 *  Y button -> toggles long_claw
 */
void lift_movement(pros::Controller& controller);
 
