////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 8 //////////
////////////////////////////////////////////
#include <IRremote.h>
#include <Servo.h>

int irSensorPin = 7; 
int servoMotorPin = 9; 

IRrecv irrecv(irSensorPin);
decode_results signals;

Servo baseServo;
int angle=0;

void setup()
{
  Serial.begin(9600);
  // enable input from IR receiver
  irrecv.enableIRIn(); 
   baseServo.attach(servoMotorPin);
}

void loop() {
if (irrecv.decode(&signals)) {
    Serial.println(signals.value, HEX);
    //if number 2 is pressed
    if(signals.value==0xFF18E7)
    angle+=30;
    //if number 1 is pressed
    if(signals.value==0xFF30CF)
      angle-=30;
    //if angle out of range (0-180)
    if(angle>=180 || angle<0)
      angle=0;
  
    baseServo.write(angle);
    Serial.print("Rotating with angle: "); 
    Serial.println(angle); 
    
    // get the next signal
    irrecv.resume(); 
  }
}
