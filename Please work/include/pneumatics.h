#pragma once

#include "main.h"
 
/**
 * Handles all pneumatics controls. Call once per loop from opcontrol().
 *
 *  X button -> toggles claw
 *  Y button -> toggles long_claw
 */
void pneumatics_update(pros::Controller& controller);
 
