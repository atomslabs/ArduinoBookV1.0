////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 1 //////////
////////////////////////////////////////////

const int lm35_pin = A0;
const int greenLED_pin = 6;
const int redLED_pin = 7;
const int maxTemp = 30;

void setup() {
  Serial.begin(9600);
   pinMode(redLED_pin, OUTPUT);
    pinMode(greenLED_pin, OUTPUT);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
 
  if(temp_val>=maxTemp)
  {
    digitalWrite(redLED_pin, HIGH);
    digitalWrite(greenLED_pin, LOW);
    Serial.println("High Temprature: Red LED is ON, Green LED is off");
  }
  else
  {
    digitalWrite(redLED_pin, LOW);
    digitalWrite(greenLED_pin, HIGH);
    Serial.println("Normal Temprature: Green LED is ON, Ref LED is off");
  }
  delay(5000);
}
