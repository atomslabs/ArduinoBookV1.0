////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 6 //////////
////////////////////////////////////////////
 
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
const int buzzerPin = 5;
const int greedLed = 6;
const int redLed = 7;
// Create MFRC522 instance.
MFRC522 mfrc522(SS_PIN, RST_PIN);   
void setup() 
{
  // Initiate a serial communication
  Serial.begin(9600);   
  pinMode(buzzerPin,OUTPUT);
  pinMode(greedLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  digitalWrite(buzzerPin,LOW);
  digitalWrite(greedLed,LOW);
  digitalWrite(redLed,LOW);
  // Initiate  SPI bus
  SPI.begin();      
  // Initiate MFRC522
  mfrc522.PCD_Init();   
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  //change here the UID of the card/cards that you want to give access
  if (content.substring(1) == "F3 11 40 33") 
  {
    Serial.println("Authorized access");
    Serial.println();
    tone(buzzerPin,100,500);
    digitalWrite(greedLed,HIGH);
    digitalWrite(redLed,LOW);
  }
 else   {
    Serial.println(" Access denied");
    tone(buzzerPin,1000,500);
    digitalWrite(greedLed,LOW);
    digitalWrite(redLed,HIGH);
  }
  delay(3000);
  digitalWrite(greedLed,LOW);
  digitalWrite(redLed,LOW);
} 
