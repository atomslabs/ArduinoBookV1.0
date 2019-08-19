////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 5 //////////
////////////////////////////////////////////

const int irSensorPin=2;
const int greenSensorPin=3;
const int redSensorPin=4;

void setup() {  
  Serial.begin(9600);               
  pinMode(greenSensorPin, OUTPUT);     
  pinMode(redSensorPin, OUTPUT);     
  pinMode(irSensorPin,INPUT);
}

void loop() {
  //High output means there is no car
  if(digitalRead(irSensorPin)==HIGH)      
  {
    Serial.println("Sensor output : HIGH; no car");
    digitalWrite(redSensorPin, HIGH);  
    digitalWrite(greenSensorPin, LOW); 
  }
  //Low output means there is a car
  else
  {
    Serial.println("Sensor output : Low; car parked");
    digitalWrite(greenSensorPin, HIGH);
    digitalWrite(redSensorPin, LOW); 
  }
  delay(1000);
}
