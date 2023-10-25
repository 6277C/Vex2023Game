using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial Inertial10;
extern motor FR;
extern motor MR;
extern motor BR;
extern motor FL;
extern motor ML;
extern motor BL;
extern motor intake;
extern digital_out backBlocker;
extern digital_out rightBlocker;
extern digital_out leftBlocker;
extern digital_out ratchet;
extern controller Controller1;
extern motor catapult;
extern rotation catapultRot;
extern digital_out hang;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);