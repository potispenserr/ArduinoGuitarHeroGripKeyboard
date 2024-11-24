#include "Keyboard.h"
const int bluePin = 11;    
const int yellowPin = 10;  
const int redPin = 9;
const int greenPin = 8;    

int buttonState = 0;

void setup() {

  pinMode(bluePin, INPUT);
  pinMode(yellowPin, INPUT);
  pinMode(redPin, INPUT);
  pinMode(greenPin, INPUT);
}

void loop() {
  delay(300);

  int blue = digitalRead(bluePin);
  int yellow = digitalRead(yellowPin);
  int red = digitalRead(redPin);
  int green = digitalRead(greenPin);


  byte buttonState = 0b00000000;
  Serial.println(buttonState, BIN);
  bitWrite(buttonState, 0, blue);  // write the state to the least significant bit of buttonState
  bitWrite(buttonState, 1, yellow);  // write the state to the second least significant bit of buttonState
  bitWrite(buttonState, 2, red);  // write the state to the third least significant bit of buttonState
  bitWrite(buttonState, 3, green);  // write the state to the fourth least significant bit of buttonState

  int buttonInt = abs(buttonState - 15);
  Serial.println(buttonInt);
  if(buttonInt != 0){
    int button2 = buttonInt + 96;
    char buttonChar = button2;
    Serial.println(buttonChar);
    Keyboard.write(buttonChar);
  
  }

  // Serial.print(digitalRead(bluePin));
  // Serial.print("\t");

  // Serial.print(digitalRead(yellowPin));
  // Serial.print("\t");

  // Serial.print(digitalRead(redPin));
  // Serial.print("\t");

  // Serial.print(digitalRead(greenPin));
  // Serial.print("\t");

  Serial.println();


}
