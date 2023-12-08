#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
inertial Inertial = inertial(PORT11);
motor FR = motor(PORT3, ratio6_1, false);
motor MR = motor(PORT2, ratio6_1, false);
motor BR = motor(PORT1, ratio6_1, false);
motor FL = motor(PORT9, ratio6_1, true);
motor ML = motor(PORT7, ratio6_1, true);
motor BL = motor(PORT8, ratio6_1, true);
digital_out backBlocker = digital_out(Brain.ThreeWirePort.A);
digital_out rightBlocker = digital_out(Brain.ThreeWirePort.B);
digital_out flyWheelP = digital_out(Brain.ThreeWirePort.C);
digital_out hang = digital_out(Brain.ThreeWirePort.E);
digital_out leftBlocker = digital_out(Brain.ThreeWirePort.D);
controller Controller1 = controller(primary);
motor flyWheelM = motor(PORT20, ratio36_1, false);
motor intakeR = motor(PORT5, ratio18_1, true);
motor intakeL = motor(PORT6, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  // nothing to initialize
}