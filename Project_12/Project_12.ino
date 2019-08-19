////////////////////////////////////////////
///////// Atoms Labs -  @atomslabs /////////
///////// Arduino Kit - Project 12 //////////
////////////////////////////////////////////
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = 
{
   {'D','*','0','#'},
   {'9','A','B','C'},
   {'5','6','7','8'},
   {'1','2','3','4'}
};
//connect to the row pinouts of the keypad
byte rowPins[ROWS] = { 4, 5, 6, 7}; 
//connect to the column pinouts of the keypad
byte colPins[COLS] = { 8, 9, 10, 11}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
String password="4836";
String userPassword="";
const int relayPin = 3;
void setup()
{
  Serial.begin(9600);
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin,LOW);
}
void loop()
{
  char customKey = customKeypad.getKey();
 
  if(customKey =='*'){
   Serial.println("Type Password");
   digitalWrite(relayPin,LOW);
   userPassword="";
  }
  else{
    if(customKey=='#'){
      if(userPassword==password){
        Serial.println("Correct password");
        digitalWrite(relayPin,HIGH);
      }
      else{
        Serial.println("incorrect password, try again");
      }
      userPassword="";
    }
    else{
      if(customKey!='\0' && customKey!='\n')
        {
          Serial.println(customKey);
          userPassword.concat(customKey);
        }
    }
  }
}
