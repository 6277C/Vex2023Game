#include "vex.h"

void intakeVoid()
{
    intake.spin(reverse, 100, percent);
}

void revIntakeVoid()
{
    intake.spin(forward, 100, percent);
}

void intakeStop()
{
    intake.stop(coast);
}

void plowOutVoid()
{
    leftBlocker = true;
    rightBlocker = true;
}

void plowInVoid()
{
    leftBlocker = false;
    rightBlocker = false;
}

void catapultVoid()
{
    catapult.spin(forward, 100, percent);
}