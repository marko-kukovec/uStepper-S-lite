#include <uStepperSLite.h>

#define MICROSTEP 16//microstep setting of uStepper
#define RES (200.0*MICROSTEP)/360.0//calculate step pr. degree
#define STEPPRMM 53.55//step pr. mm for the rail used in the demo
#define MMPRSTEP 1/STEPPRMM//mm pr. step
#define MMPRDEG MMPRSTEP*RES//mm pr. degree

uStepperSLite stepper;

void setup() {
  // put your setup code here, to run once:
  stepper.setup();
  stepper.setCurrent(50.0);//use software current setting
  stepper.setMaxAcceleration(20000);
  stepper.setMaxVelocity(4000);
  Serial.begin(115200);
}

void loop() {
  float railLength;

  stepper.moveToEnd(CW);      //Reset to CW endpoint
  Serial.println(railLength*MMPRDEG);//find end positions and read out the recorded end position
  railLength = stepper.moveToEnd(CCW);    //Go to CCW end
  Serial.println(railLength*MMPRDEG);//find end positions and read out the recorded end position
  
  while(1);
}