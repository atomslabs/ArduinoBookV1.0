////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 10 //////////
#include "SevSeg.h"
SevSeg sevseg; 

void setup() {
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {9,10,11,12};
  byte segmentPins[] = {2,3,4,5,6,7,8,13};
  // 'false' means resistors are on digit pins
  bool resistorsOnSegments = false; 
  byte hardwareConfig = COMMON_CATHODE; 
  // Default 'false' is Recommended
  bool updateWithDelays = false; 
  // Use 'true' if you'd like to keep the leading zeros
  bool leadingZeros = false; 
  // Use 'true' if your decimal point doesn't exist or isn't connected
  bool disableDecPoint = true; 
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins
  , resistorsOnSegments,updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  
  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }
 
  sevseg.refreshDisplay(); // Must run repeatedly
  Serial.println(deciSeconds);
}
