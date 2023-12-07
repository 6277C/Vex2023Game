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
bool launcherToggle = true;
bool toggle = false;
bool latch = false;
bool toggle1 = false;
bool latch1 = false;
bool toggle2 = false;
bool latch2 = false;
bool toggle3 = false;
bool latch3 = false;
bool driverChoice = false;
bool autoChoice = false;
int current_auton_selection = 0;
bool auto_started = false;
int driver;
bool drawToggle = false;
bool autoLoopStop = false;

void pre_auton(void)
{

  vexcodeInit();
  default_constants();
  drawGUI();
  while (auto_started == false)
  {
    // Logic for driver selector
    if (Brain.Screen.pressing() && driverChoice == false && autoChoice == false)
    {
      int x = Brain.Screen.xPosition();
      int y = Brain.Screen.yPosition();

      if (x < 240 && x > 0 && y > 0 && y < 120)
      {
        driver = 1;
        driverChoice = true;
      }
      else if (x > 240 && x < 480 && y > 0 && y < 120)
      {
        driver = 2;
        driverChoice = true;
      }
      else if (x < 240 && x > 0 && y > 120 && y < 240)
      {
        driver = 3;
        driverChoice = true;
      }
      else if (x > 240 && x < 480 && y > 120 && y < 240)
      {
        driver = 4;
        driverChoice = true;
      }
    }
    // Print the 6 auto selector buttons if driver 1 is selected
    if (driverChoice == true && drawToggle == false && (driver == 1 or driver == 2))
    {
      drawAutoButtons();
      drawToggle = true;
      wait(.5, sec);
    }
    // Logic for auto buttons
    if (Brain.Screen.pressing() && driverChoice == true && autoChoice == false && (driver == 1 or driver == 2))
    {
      int xpos = Brain.Screen.xPosition();
      int ypos = Brain.Screen.yPosition();

      if (xpos > 0 && xpos < 146 && ypos > 0 && ypos < 105)
      {
        current_auton_selection = 0;
        autoChoice = true;
      }
      else if (xpos > 0 && xpos < 146 && ypos > 115 && ypos < 220)
      {
        current_auton_selection = 1;
        autoChoice = true;
      }
      else if (xpos > 156 && xpos < 302 && ypos > 0 && ypos < 105)
      {
        current_auton_selection = 2;
        autoChoice = true;
      }
      else if (xpos > 156 && xpos < 302 && ypos > 115 && ypos < 220)
      {
        current_auton_selection = 3;
        autoChoice = true;
      }
      else if (xpos > 312 && xpos < 458 && ypos > 0 && ypos < 105)
      {
        current_auton_selection = 4;
        autoChoice = true;
      }
      else if (xpos > 312 && xpos < 458 && ypos > 115 && ypos < 220)
      {
        current_auton_selection = 5;
        autoChoice = true;
      }
    }
    // After selecting auto, display the name of the auto across the whole screen
    if (autoChoice == true && autoLoopStop == false && (driver == 1 or driver == 2))
    {
      Brain.Screen.clearScreen();
      switch (current_auton_selection)
      {
      case 0:
        Brain.Screen.printAt(10, 120, "Far Auto WITHOUT touch");
        autoLoopStop = true;
        auto_started = true;
        break;
      case 1:
        Brain.Screen.printAt(10, 120, "Close Auto WITHOUT touch");
        autoLoopStop = true;
        auto_started = true;
        break;
      case 2:
        Brain.Screen.printAt(10, 120, "Far Auto WITH touch");
        autoLoopStop = true;
        auto_started = true;
        break;
      case 3:
        Brain.Screen.printAt(10, 120, "CLose Auto WITH touch");
        autoLoopStop = true;
        auto_started = true;
        break;
      case 4:
        Brain.Screen.printAt(10, 120, "Far Auto Elimination");
        autoLoopStop = true;
        auto_started = true;
        break;
      case 5:
        Brain.Screen.printAt(10, 120, "Close Auto Elimination");
        autoLoopStop = true;
        auto_started = true;
        break;
      }
    }
    // If driver 2 is selected, then choose the skills auto
    if (driver == 3 or driver == 4)
    {
      current_auton_selection = 6;
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(propXL);
      Brain.Screen.setFillColor(black);
      Brain.Screen.printAt(10, 120, "Skills Autonomous");
      auto_started = true;
    }
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
    rightAutoElimination();
    break;
  case 5:
    leftAutoElimination();
    break;
  case 6:
    skillsAuto();
    break;
  }
}

void usercontrol(void)
{
  Brain.Screen.clearScreen();
  auto_started = true;
  FR.setStopping(coast);
  MR.setStopping(coast);
  BR.setStopping(coast);
  FL.setStopping(coast);
  ML.setStopping(coast);
  BL.setStopping(coast);
  // Blake Match
  if (driver == 1)
  {
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(0, 0, 240, 120);
    while (1)
    {
      // flywheel code
      if (Controller1.ButtonL1.pressing() && launcherToggle == true)
      {
        launcherToggle = false;
        flyWheelP = true;
        flyWheelM.spin(forward, 100, percent);
        while (Controller1.ButtonL1.pressing())
        {
        }
      }
      else if (Controller1.ButtonL1.pressing() && launcherToggle == false)
      {
        launcherToggle = true;
        flyWheelP = false;
        flyWheelM.stop(brake);
        wait(1, sec);
        flyWheelM.stop(coast);
        while (Controller1.ButtonL1.pressing())
        {
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
        intakeL.spin(reverse, 100, percent);
        intakeR.spin(reverse, 100, percent);
      }
      else
      {
        intakeL.stop(brake);
        intakeR.stop(brake);
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
        intakeL.spin(forward, 100, percent);
        intakeR.spin(forward, 100, percent);
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
  // Meaghan Match
  else if (driver == 2)
  {
    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(0, 0, 240, 120);
    while (1)
    {
      // flywheel code
      if (Controller1.ButtonR2.pressing() && launcherToggle == true)
      {
        launcherToggle = false;
        flyWheelP = true;
        flyWheelM.spin(forward, 100, percent);
        while (Controller1.ButtonR2.pressing())
        {
        }
      }
      else if (Controller1.ButtonR2.pressing() && launcherToggle == false)
      {
        launcherToggle = true;
        flyWheelP = false;
        flyWheelM.stop(brake);
        wait(1, sec);
        flyWheelM.stop(coast);
        while (Controller1.ButtonR2.pressing())
        {
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
        intakeR.spin(reverse, 100, percent);
        intakeL.spin(reverse, 100, percent);
      }
      else
      {
        intakeR.stop(brake);
        intakeL.stop(brake);
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
        intakeR.spin(forward, 100, percent);
        intakeL.spin(forward, 100, percent);
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
  // Blake Skills
  else if (driver == 3)
  {
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(0, 0, 240, 120);
    while (1)
    {
      // flywheel code
      if (Controller1.ButtonL1.pressing() && launcherToggle == true)
      {
        launcherToggle = false;
        flyWheelP = true;
        flyWheelM.spin(forward, 100, percent);
        while (Controller1.ButtonL1.pressing())
        {
        }
      }
      else if (Controller1.ButtonL1.pressing() && launcherToggle == false)
      {
        launcherToggle = true;
        flyWheelP = false;
        flyWheelM.stop(brake);
        wait(1, sec);
        flyWheelM.stop(coast);
        while (Controller1.ButtonL1.pressing())
        {
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
        intakeR.spin(reverse, 100, percent);
        intakeL.spin(reverse, 100, percent);
      }
      else
      {
        intakeL.stop(brake);
        intakeR.stop(brake);
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
        intakeL.spin(forward, 100, percent);
        intakeR.spin(forward, 100, percent);
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

      if (Controller1.ButtonDown.pressing())
      {
        skillsAutoShort();
        toggle1 = true;
        while (Controller1.ButtonDown.pressing())
        {
        }
      }
      chassis.control_tank();

      wait(20, msec);
    }
  }
  // Meaghan Skills
  else if (driver == 4)
  {
    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(0, 0, 240, 120);
    while (1)
    {
      // flywheel code
      if (Controller1.ButtonR2.pressing() && launcherToggle == true)
      {
        launcherToggle = false;
        flyWheelP = true;
        flyWheelM.spin(forward, 100, percent);
        while (Controller1.ButtonR2.pressing())
        {
        }
      }
      else if (Controller1.ButtonR2.pressing() && launcherToggle == false)
      {
        launcherToggle = true;
        flyWheelP = false;
        flyWheelM.stop(brake);
        wait(1, sec);
        flyWheelM.stop(coast);
        while (Controller1.ButtonR2.pressing())
        {
        }
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

      if (Controller1.ButtonL1.pressing() or Controller1.ButtonL2.pressing())
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
        intakeL.spin(reverse, 100, percent);
        intakeR.spin(reverse, 100, percent);
      }
      else
      {
        intakeR.stop(brake);
        intakeL.stop(brake);
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
        intakeL.spin(forward, 100, percent);
        intakeR.spin(forward, 100, percent);
      }
    
      if (Controller1.ButtonDown.pressing())
      {
        skillsAutoShort();
        toggle1=true;
        while (Controller1.ButtonDown.pressing())
        {
        }
      }
      chassis.control_arcade();

      wait(20, msec);
    }
  }
}

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
