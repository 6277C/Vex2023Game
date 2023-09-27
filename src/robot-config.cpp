#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
inertial Inertial10 = inertial(PORT10);
motor FR = motor(PORT11, ratio6_1, false);
motor MR = motor(PORT12, ratio6_1, false);
motor BR = motor(PORT13, ratio6_1, false);
motor FL = motor(PORT20, ratio6_1, true);
motor ML = motor(PORT19, ratio6_1, true);
motor BL = motor(PORT18, ratio6_1, true);
digital_out DigitalOutA = digital_out(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);
motor catapult = motor(PORT8, ratio36_1, false);
rotation catapultRot = rotation(PORT2, false);
motor intake = motor(PORT17, ratio6_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}