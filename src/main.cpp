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

Drive chassis(
    ZERO_TRACKER_ODOM,
    // Left Motors:
    motor_group(FL, ML, BL),

    // Right Motors:
    motor_group(FR, MR, BR),

    // Inertial Sensor
    PORT16,

    // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
    3.25,

    // Drive Ratio
    0.6,

    // Gyro Scale
    360,

    // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD
    // TRACKER CENTER DISTANCE.

    // LF:      //RF:
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

    // the positive distance from the center
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

// Variables
int current_auton_selection = 0;
bool auto_started = false;
bool catapultToggle = false;
bool toggle = false;
bool latch = false;
bool toggle1 = false;
bool latch1 = false;
bool catapultPrime = false;
bool toggle2 = false;
bool latch2 = false;
bool toggle3 = false;
bool latch3 = false;
int driver;

void pre_auton(void)
{
  vexcodeInit();
  default_constants();
  drawGUI();

  
  while (
      auto_started ==
      false)
  {
    Brain.Screen.clearScreen();
    switch (current_auton_selection)
    {
    case 0:
      Brain.Screen.printAt(50, 50, "Right Auto WITHOUT Touch");
      break;
    case 1:
      Brain.Screen.printAt(50, 50, "Left Auto WITHOUT Touch");
      break;
    case 2:
      Brain.Screen.printAt(50, 50, "Right Auto With Touch");
      break;
    case 3:
      Brain.Screen.printAt(50, 50, "Left Auto With Touch");
      break;
    case 4:
      Brain.Screen.printAt(50, 50, "Skills Auto");
      break;
    }
    if (Brain.Screen.pressing())
    {
      while (Brain.Screen.pressing())
      {
      }
      current_auton_selection++;
    }
    else if (current_auton_selection == 5)
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
    rightAutoNoTouch();
    break;
  case 1:
    leftAutoNoTouch();
    break;
  case 2:
    rightAutoTouch();
    break;
  case 3:
    leftAutoTouch();
    break;
  case 4:
    skillsAuto();
  }
}

void usercontrol(void)
{

  FR.setStopping(coast);
  MR.setStopping(coast);
  BR.setStopping(coast);
  FL.setStopping(coast);
  ML.setStopping(coast);
  BL.setStopping(coast);
  if (driver == 1)
  {
    while (1)
    {
      // Catapult Prime
      if (Controller1.ButtonUp.pressing())
      {
        catapultPrime = true;
      }
      // Code for catapult
      if (catapultPrime == true)
      {
        if (Controller1.ButtonL1.pressing())
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
      }
      // Code for back blocker
      if (toggle)
      {
        backBlocker = true;
      }
      else
      {
        backBlocker = false;
      }

      if (Controller1.ButtonX.pressing())
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

      // Code for Side Blocker
      if (toggle1)
      {
        leftBlocker = true;
        rightBlocker = true;
      }
      else
      {
        rightBlocker = false;
        leftBlocker = false;
      }

      if (Controller1.ButtonL2.pressing())
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

      if (toggle2)
      {
        intake.spin(reverse, 100, percent);
      }
      else
      {
        intake.stop(coast);
      }

      if (Controller1.ButtonR1.pressing())
      {
        if (!latch2)
        {
          toggle2 = !toggle2;
          latch2 = true;
        }
      }
      else
      {
        latch2 = false;
      }

      if (Controller1.ButtonR2.pressing())
      {
        intake.spin(forward, 100, percent);
      }
      // Ratchet
      if (Controller1.ButtonLeft.pressing())
      {

        ratchet = true;
      }
      else
      {
        ratchet = false;
      }
      // hang
      if (toggle3)
      {
        hang = true;
      }
      else
      {
        hang = false;
      }

      if (Controller1.ButtonB.pressing())
      {
        if (!latch3)
        {
          toggle3 = !toggle3;
          latch3 = true;
        }
      }
      else
      {
        latch3 = false;
      }
      chassis.control_tank();

      wait(20, msec);
    }
  }
  else if (driver == 2)
  {
    while (1)
    {
      // Catapult Prime
      if (Controller1.ButtonX.pressing())
      {
        catapultPrime = true;
      }
      // Code for catapult
      if (catapultPrime == true)
      {
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
      }
      // Code for back blocker
      if (toggle)
      {
        backBlocker = true;
      }
      else
      {
        backBlocker = false;
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

      // Code for Side Blocker
      if (toggle1)
      {
        leftBlocker = true;
        rightBlocker = true;
      }
      else
      {
        rightBlocker = false;
        leftBlocker = false;
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

      if (toggle2)
      {
        intake.spin(reverse, 100, percent);
      }
      else
      {
        intake.stop(coast);
      }

      if (Controller1.ButtonR1.pressing())
      {
        if (!latch2)
        {
          toggle2 = !toggle2;
          latch2 = true;
        }
      }
      else
      {
        latch2 = false;
      }

      if (Controller1.ButtonY.pressing())
      {
        intake.spin(forward, 100, percent);
      }
      // Ratchet
      if (Controller1.ButtonB.pressing())
      {

        ratchet = true;
      }
      else
      {
        ratchet = false;
      }
      // hang
      if (toggle3)
      {
        hang = true;
      }
      else
      {
        hang = false;
      }

      if (Controller1.ButtonDown.pressing())
      {
        if (!latch3)
        {
          toggle3 = !toggle3;
          latch3 = true;
        }
      }
      else
      {
        latch3 = false;
      }
      chassis.control_arcade();

      wait(20, msec);
    }
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
