#include "claw.h"
/*
* Initalize variables needed for operation,
* ALWAYS EXPLICITLY call this after initalization.
*/
void Claw::init() {
  enc = 0;
  desired = 0;
  _cm = 0;
}

void Claw::setDesired(int des) {
  desired = des;
}

/*
* Move claw to value speified by desiredLift
* start on seperate thread for continious control
* in autonomous mode
*/
void Claw::moveTo() {

}


/*
* Debug
*/
void Claw::debug() {
  //printf("LEFT %d", );
  //printf("RIGHT %d", getHeight('r')-startLiftR);
}

/*
* Emergency stop all motors and deallocate
* memory to be called on failure event
*/
int Claw::eStop() {
  setAll(0);
  return 0;
}

/*
* Main control loop with user input
*/
void Claw::iterateCtl() {
  if (joystickGetDigital(1, 5, JOY_UP) && joystickGetDigital(1, 5, JOY_DOWN)) {
    setMotor(0, 30);
  }
  else if(joystickGetDigital(1, 5, JOY_UP)) {
    setMotor(0, 80);
  } else if (joystickGetDigital(1, 5, JOY_DOWN)) {
    setMotor(0, -80);
  } else {
    setMotor(0, 0);
  
  }
}
