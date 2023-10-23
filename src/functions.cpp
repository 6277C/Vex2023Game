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
    Brain.Screen.setFillColor("#FFC0CB");
    Brain.Screen.drawRectangle(240, 0, 240, 240);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.printAt(120, 60, "Blake");
    Brain.Screen.setFillColor("#FFC0CB");
    Brain.Screen.printAt(360, 60, "Meaghan");
}