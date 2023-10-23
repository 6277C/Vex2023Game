#include "vex.h"

void skillsAuto()
{
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  intake.spin(reverse, 100, percent);
  wait(.5, sec);
  intake.stop(brake);
chassis.drive_distance(13);
chassis.left_swing_to_angle(45);
chassis.drive_distance(20);
chassis.drive_distance(-14);
chassis.turn_to_angle(135);
chassis.drive_distance(10);
chassis.turn_to_angle(-55);
leftBlocker = true;
chassis.drive_distance(5);
catapult.spin(forward,70,percent);
wait(50, sec);
catapult.stop(brake);
/*
wait(1, sec);
leftBlocker = false;
chassis.drive_distance(-5);
chassis.turn_to_angle(0);
chassis.drive_distance(-15);
chassis.left_swing_to_angle(-46);
///// drive under bar
chassis.set_drive_exit_conditions(1.5, 300, 3000);
chassis.set_turn_exit_conditions(1, 300, 3000);
chassis.set_swing_exit_conditions(1, 300, 3000);
chassis.drive_distance(-80);

chassis.set_drive_exit_conditions(1.5, 300, 1000);
chassis.set_turn_exit_conditions(1, 300, 1000);
chassis.set_swing_exit_conditions(1, 300, 1000);
chassis.left_swing_to_angle(-47);
chassis.set_drive_exit_conditions(1.5, 300, 3000);
chassis.set_turn_exit_conditions(1, 300, 3000);
chassis.set_swing_exit_conditions(1, 300, 3000);

chassis.set_drive_exit_conditions(1.5, 300, 1000);
chassis.set_turn_exit_conditions(1, 300, 1000);
chassis.set_swing_exit_conditions(1, 300, 1000);
///////////// rest of code
chassis.left_swing_to_angle(0);
leftBlocker = true;
rightBlocker = true;
chassis.left_swing_to_angle(90);
chassis.drive_distance(16);
chassis.right_swing_to_angle(48);
chassis.drive_distance(20);
chassis.drive_distance(-20);
chassis.drive_distance(20);
chassis.drive_distance(-20);
*/

}



void rightAutoNoTouch()
{
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  rightBlocker = true;
  intake.spin(reverse, 100, percent);
  wait(.5, sec);
  intake.stop(brake);
  chassis.drive_distance(7.5);
  chassis.turn_to_angle(-40);
  chassis.turn_to_angle(-25);
  rightBlocker = false;
  chassis.drive_distance(30);
  chassis.drive_distance(-15);
  default_constants();
  chassis.turn_to_angle(-92);
  intake.spin(reverse, 100, percent);
  chassis.drive_distance(60);
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  chassis.right_swing_to_angle(42);
  leftBlocker = true;
  chassis.drive_distance(32);
  intake.stop(brake);
  chassis.drive_distance(-10);
}

void leftAutoNoTouch()
{
/////////for elimination
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  chassis.drive_distance(-10);
chassis.right_swing_to_angle(45);
chassis.drive_distance(-15);

chassis.drive_distance(5);


/*
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  intake.spin(reverse, 100, percent);
  wait(0.5, sec);
  intake.stop(brake);
  chassis.drive_distance(13);
  chassis.left_swing_to_angle(45);
  /////
  use after quals
  chassis.drive_distance(20);
  chassis.drive_distance(-15);
  ////
  chassis.drive_distance(10);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(180);
  rightBlocker = true;
  chassis.drive_distance(14);
  chassis.left_swing_to_angle(145);
  rightBlocker = false;
  chassis.drive_distance(5);
  chassis.turn_to_angle(70);
  intake.spin(reverse, 90, percent);
  chassis.drive_distance(62);
  wait(1, sec);
  intake.stop(brake);
  chassis.turn_to_angle(130);
  chassis.drive_distance(10);
  intake.spin(forward, 90, percent);
  wait(0.5, sec);
  chassis.drive_distance(10);
  intake.stop(brake);
*/


}

void rightAutoTouch()
{
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  rightBlocker = true;
  intake.spin(reverse, 100, percent);
  wait(.5, sec);
  intake.stop(brake);
  chassis.drive_distance(7.5);
  chassis.turn_to_angle(-40);
  chassis.turn_to_angle(-25);
  chassis.drive_distance(30);
  rightBlocker = false;
  chassis.turn_to_angle(180);
  chassis.drive_distance(26);
  chassis.turn_to_angle(-145);
  chassis.drive_distance(28);
}

void leftAutoTouch()
{
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 1000);
  intake.spin(reverse, 100, percent);
  wait(0.5, sec);
  intake.stop(brake);
  chassis.drive_distance(13);
  chassis.left_swing_to_angle(45);
/*
  use after quals
  chassis.drive_distance(20);
  chassis.drive_distance(-15);
  */
  chassis.drive_distance(10);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(180);
  rightBlocker = true;
  chassis.drive_distance(12);
  chassis.left_swing_to_angle(145);
  rightBlocker = false;
  chassis.drive_distance(45);
}



void default_constants()
{
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants()
{
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test()
{
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test()
{
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test()
{
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test()
{
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test()
{
  chassis.set_coordinates(0, 0, 0);
  while (1)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0, 50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0, 70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0, 90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0, 110, "ForwardTracker: %f",
                         chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0, 130, "SidewaysTracker: %f",
                         chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24, 24);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}
