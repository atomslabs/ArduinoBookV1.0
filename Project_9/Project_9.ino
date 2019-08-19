////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 9 /////////
////////////////////////////////////////////
const int redPin = 11; 
const int bluePin =10; 
const int greenPin = 9;
const int switchPin = 2; 

const int xPin = A0; 
const int yPin = A1;
const int PotentiometerPin= A2;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("X-axis: ");
  Serial.print(analogRead(xPin));
  Serial.println("Y-axis: ");
  Serial.println(analogRead(yPin));
  Serial.println("Potentiometer: ");
  Serial.println(analogRead(PotentiometerPin));
  
  int r = map(analogRead(xPin), 0, 1023, 0, 255);
  int g = map(analogRead(yPin), 0, 1023, 0, 255);
  int b = map(analogRead(PotentiometerPin),0,1023,0,255);
  
  Serial.print(r);
  Serial.print(" , ");
  Serial.print(g);
  Serial.print(" , ");
  Serial.println(b);
  analogWrite(redPin, r);  
  analogWrite(greenPin, g);
  analogWrite(bluePin, b); 
  delay(1000);
}
