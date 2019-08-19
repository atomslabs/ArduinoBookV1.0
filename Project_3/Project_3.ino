////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 3 //////////
////////////////////////////////////////////

#define water_sensor_pin A0 
const int red_pin = 4;
const int yellow_pin = 3;
const int green_pin = 2;

void setup(){
  Serial.begin(9600);
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  digitalWrite(red_pin, LOW);
  digitalWrite(yellow_pin, LOW);
  digitalWrite(green_pin, LOW);
}
 
void loop(){  
  //Read data from analog pin and store it to value variable
  int value = analogRead(water_sensor_pin); 
  Serial.print("Water Level Sensor reading "); 
  Serial.print(value); 
  Serial.print(" | Tank Status: "); 
  
  if (value>=0 && value<=150)
  { 
    Serial.println("Low water level"); 
    digitalWrite(red_pin, HIGH);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, LOW);
  }
  else if (value>150 && value<=275){ 
    Serial.println("Mid water level");  
    digitalWrite(red_pin, LOW);
    digitalWrite(yellow_pin, HIGH);
    digitalWrite(green_pin, LOW);
  }
  else if (value>275 && value<=500){ 
    Serial.println("Normal water level"); 
    digitalWrite(red_pin, LOW);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, HIGH);
  }
 
  delay(500);
}
