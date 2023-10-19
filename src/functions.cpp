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
    }
    else if (x >= 240)
    {
        driver = 2;
        choice = true;
    }

    if (choice == true)
    {

        Brain.Screen.clearScreen();
        autonSelector();
    }
    wait(10, msec);
}

void autonSelector()
{
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    while (auto_started == false)
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