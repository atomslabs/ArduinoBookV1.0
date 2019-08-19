////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 7 //////////
////////////////////////////////////////////
#include <Stepper.h>
#define STEPS 2038 
Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 1 rpm
  stepper.setSpeed(1); 
  Serial.println("Do a full revolution of 2083 steps with 1 RPM speed in 1 minute");
  stepper.step(2038); 
  Serial.println("Finished, Wait for a second");
  delay(1000); 
  stepper.setSpeed(6); 
  Serial.println("Do a backward revolution of 2083 steps with 6 RPM speed in 10 seconds");
  stepper.step(-2038); 
}
