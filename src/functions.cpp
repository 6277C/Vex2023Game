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
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 240, 240);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(240, 0, 240, 240);
    Brain.Screen.setFillColor(red);
    Brain.Screen.printAt(120, 60, "Blake");
    Brain.Screen.setFillColor(blue);
    Brain.Screen.printAt(360, 60, "Meaghan");
}

void driverSelector()
{
    int x = Brain.Screen.xPosition();
    bool choice = false;

    if (x <= 240)
    {
        driver = 1;
        choice = true;
        choseDriver = true;
    }
    else if (x >= 240)
    {
        driver = 2;
        choice = true;
        choseDriver = true;
    }

    if (choice == true){

        Brain.Screen.clearScreen();
    }
wait(10, msec);
}