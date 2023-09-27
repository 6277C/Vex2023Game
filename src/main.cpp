#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial10           inertial      10
// FR                   motor         11
// MR                   motor         12
// BR                   motor         13
// FL                   motor         20
// ML                   motor         19
// BL                   motor         18
// DigitalOutA          digital_out   A
// Controller1          controller
// catapult             motor         8
// catapultRot          rotation      2
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;
/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(
    ZERO_TRACKER_ODOM,
    // Left Motors:
    motor_group(FL, ML, BL),

    // Right Motors:
    motor_group(FR, MR, BR),

    // Inertial Sensor
    PORT10,

    // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
    3.25,

    // Drive Ratio
    0.6,

    // Gyro Scale
    360,

    // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD
    // TRACKER CENTER DISTANCE.

    // FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is
    // only necessary for holonomic drives, otherwise this section can be left
    // alone. LF:      //RF:
    PORT1, -PORT2,

    // LB:      //RB:
    PORT3, -PORT4,

    // If you are using position tracking, this is the Forward Tracker port (the
    // tracker which runs parallel to the direction of the chassis). If this is
    // a rotation sensor, enter it in "PORT1" format, inputting the port below.
    // If this is an encoder, enter the port as an integer. Triport A will be a
    // "1", Triport B will be a "2", etc.
    3,

    // Input the Forward Tracker diameter (reverse it to make the direction
    // switch):
    2.75,

    // Input Forward Tracker center distance (a positive distance corresponds to
    // a tracker on the right side of the robot, negative is left.) For a zero
    // tracker tank drive with odom, put the positive distance from the center
    // of the robot to the right side of the drive. This distance is in inches:
    5,

    // Input the Sideways Tracker Port, following the same steps as the Forward
    // Tracker Port:
    1,

    // Sideways tracker diameter (reverse to make the direction switch):
    -2.75,

    // Sideways tracker center distance (positive distance is behind the center
    // of the robot, negative is in front):
    5.5

);

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void)
{
  vexcodeInit();
  default_constants();

  while (
      auto_started ==
      false)
  {
    Brain.Screen.clearScreen();
    switch (current_auton_selection)
    {
    case 0:
      Brain.Screen.printAt(50, 50, "Drive Test");
      break;
    case 1:
      Brain.Screen.printAt(50, 50, "Drive Test");
      break;
    case 2:
      Brain.Screen.printAt(50, 50, "Turn Test");
      break;
    case 3:
      Brain.Screen.printAt(50, 50, "Swing Test");
      break;
    case 4:
      Brain.Screen.printAt(50, 50, "Full Test");
      break;
    case 5:
      Brain.Screen.printAt(50, 50, "Odom Test");
      break;
    case 6:
      Brain.Screen.printAt(50, 50, "Tank Odom Test");
      break;
    case 7:
      Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
      break;
    }
    if (Brain.Screen.pressing())
    {
      while (Brain.Screen.pressing())
      {
      }
      current_auton_selection++;
    }
    else if (current_auton_selection == 8)
    {
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void)
{

  auto_started = true;
  switch (current_auton_selection)
  {
  case 0:
    odom_test();
    break;
  case 1:
    drive_test();
    break;
  case 2:
    turn_test();
    break;
  case 3:
    swing_test();
    break;
  case 4:
    full_test();
    break;
  case 5:
    odom_test();
    break;
  case 6:
    tank_odom_test();
    break;
  case 7:
    holonomic_odom_test();
    break;
  }
}

void usercontrol(void)
{
  bool catapultToggle = false;
  bool toggle = false;
  bool latch = false;
  bool toggle1 = false;
  bool latch1 = false;
  while (1)
  {
    // Code for catapult
    if (Controller1.ButtonR2.pressing())
    {
      catapult.spin(forward);
      wait(500, msec);
      catapultToggle = false;
    }
    else
    {
      if (catapultRot.position(degrees) < 57 && catapultToggle == false)
      {
        catapult.spin(forward);
      }
      else
      {
        catapult.stop(coast);
        catapultToggle = true;
      }
    }

    // Code for blocker
    if (toggle)
    {
      DigitalOutA = false;
    }
    else
    {
      DigitalOutA = true;
    }

    if (Controller1.ButtonL2.pressing())
    {
      if (!latch)
      {
        toggle = !toggle;
        latch = true;
      }
    }
    else
    {
      latch = false;
    }

//Side Blocker
    if (toggle1)
    {
      DigitalOutB = false;
    }
    else
    {
      DigitalOutB = true;
    }

    if (Controller1.ButtonL1.pressing())
    {
      if (!latch1)
      {
        toggle1 = !toggle1;
        latch1 = true;
      }
    }
    else
    {
      latch1 = false;
    }

    // Intake Code

    if (Controller1.ButtonX.pressing())
    {
      intake.spin(forward, 100, percent);
    }
    else if (Controller1.ButtonY.pressing())
    {

      intake.spin(reverse, 100, percent);
    }
    else
    {
      intake.stop(coast);
    }
    // Replace this line with chassis.control_tank(); for tank drive
    chassis.control_arcade();

    wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
