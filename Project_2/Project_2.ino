////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 2 //////////
////////////////////////////////////////////

#include "dht.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;
#define dht_apin 3 

void setup(){
 
  Serial.begin(9600);
    delay(500);//Delay to let system boot
  // put your setup code here, to run once:

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);

  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}
 
void loop(){  
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    lcd.setCursor(0, 0);
     lcd.print("Humidity:");
    lcd.print(DHT.humidity);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp : ");
    lcd.print(DHT.temperature); 
    lcd.println("  C ");
 
    delay(5000);
}
