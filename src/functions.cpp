#include "vex.h"

void drawGUI()
{
    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(0, 0, 240, 120);
    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(240, 0, 240, 120);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(0, 120, 240, 120);
    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(240, 120, 240, 120);
    Brain.Screen.setFont(propM);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.printAt(60, 60, "Blake Match");
    Brain.Screen.setFillColor(purple);
    Brain.Screen.printAt(290, 60, "Meaghan Match");
    Brain.Screen.setFillColor(blue);
    Brain.Screen.printAt(60, 180, "Blake Skills");
    Brain.Screen.setFillColor(purple);
    Brain.Screen.printAt(290, 180, "Meaghan Skills");
}

// Brain Screen is 480 x 272 pixels (*240 with menu bar*)
//  156 x 115
void drawAutoButtons()
{
    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 480, 240);
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(10, 10, 146, 105);
    Brain.Screen.drawRectangle(10, 125, 146, 105);
    Brain.Screen.drawRectangle(166, 10, 146, 105);
    Brain.Screen.drawRectangle(166, 125, 146, 105);
    Brain.Screen.drawRectangle(322, 10, 146, 105);
    Brain.Screen.drawRectangle(322, 125, 146, 105);
    Brain.Screen.setFont(monoXS);
    Brain.Screen.printAt(20, 60, "Far Auto NO touch");
    Brain.Screen.printAt(20, 175, "Close Auto NO touch");
    Brain.Screen.printAt(176, 60, "Far Auto touch");
    Brain.Screen.printAt(176, 175, "Close Auto touch");
    Brain.Screen.printAt(332, 60, "Far Auto Elimination");
    Brain.Screen.printAt(332, 175, "Close Auto Elimination");
    Brain.Screen.setFont(propXL);
}

void skillsAutoShort()
{
    chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  intakeL.spin(reverse, 100, percent);
  intakeR.spin(reverse, 100, percent);
  wait(.5, sec);
  intakeL.stop(brake);
  intakeR.stop(brake);
  chassis.drive_distance(6);
  chassis.left_swing_to_angle(45);
  chassis.drive_distance(10);
  chassis.drive_distance(-7);
  chassis.turn_to_angle(155);
  chassis.drive_distance(5);
  chassis.turn_to_angle(-70);
  chassis.drive_distance(3);
  leftBlocker = true;
  flyWheelP = true;
  flyWheelM.spin(forward, 85, percent);
}