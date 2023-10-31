#include "vex.h"

// make bool true for plows to go out and make bool false for plows to pull in
void plowVoid(bool trans)
{
    if (trans == true)
    {
        leftBlocker = true;
        rightBlocker = true;
    }
    else
    {
        leftBlocker = false;
        rightBlocker = false;
    }
}

void catapultVoid()
{
    catapult.spin(forward, 100, percent);
}

void drawGUI()
{
    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(0, 0, 240, 240);
    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(240, 0, 240, 240);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.printAt(120, 60, "Blake");
    Brain.Screen.setFillColor(purple);
    Brain.Screen.printAt(360, 60, "Meaghan");
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
    Brain.Screen.printAt(20, 60, "Right Auto NO touch");
    Brain.Screen.printAt(20, 175, "Left Auto NO touch");
    Brain.Screen.printAt(176, 60, "Right Auto touch");
    Brain.Screen.printAt(176, 175, "Left Auto touch");
    Brain.Screen.printAt(332, 60, "Right Auto Elimination");
    Brain.Screen.printAt(332, 175, "Left Auto Elimination");
    Brain.Screen.setFont(propXL);
}