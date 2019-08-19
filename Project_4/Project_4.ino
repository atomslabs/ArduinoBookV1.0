////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 4 //////////
////////////////////////////////////////////

const int flameSensorPin = A0;     // the cell and 10K pulldown are connected to a0
int flameSensorReading;     // the analog reading from the analog resistor divider

const int photoresistorPin = A1;     // the cell and 10K pulldown are connected to a0
int photoresistorReading;     // the analog reading from the analog resistor divider

const int buzzerPin = 7;
 
void setup(void) { 
  Serial.begin(9600); 
}
 
void loop(void) {
  flameSensorReading = analogRead(flameSensorPin);  
  photoresistorReading = analogRead(photoresistorPin);  
  
  Serial.print("Flame reading = ");
  Serial.print(flameSensorReading);     // the raw analog reading
 
  Serial.print(" Light reading = ");
  Serial.println(photoresistorReading);     // the raw analog reading

  if(flameSensorReading >0)
    tone(buzzerPin, 100, 1000);

  if(photoresistorReading<100)  
    tone(buzzerPin, 1000, 1000);
    
  delay(1000);
}
