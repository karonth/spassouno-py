/*
  (S)passoUno

  Hardware:
  https://123d.circuits.io/circuits/1926939-spassunouno-kids-interface

  8    Nuovo fotogramma             SPACE_KEY
  10   Diminuisci velocità          DOWN_KEY
  9    Aumenta velocità             UP_KEY
  11   Nuova storia                 SPACE_KEY
  12   Cancella ultimo fotogramma   X_KEY
  6 Buzzer

*/

#include "Keyboard.h"

int newFrame = 8;
int speedUp = 9;
int speedDown = 10;
int newStory = 11;
int deleteLastFrame = 12;

int timeDelay = 200;


void setup() {

  Serial.begin(9600);

  pinMode(newFrame, INPUT);
  pinMode(speedUp, INPUT);
  pinMode(speedDown, INPUT);
  pinMode(newStory, INPUT);
  pinMode(deleteLastFrame, INPUT);

  Keyboard.begin();
}


void loop() {

  int stateNewFrame = digitalRead(newFrame);
  int stateSpeedUp = digitalRead(speedUp);
  int stateSpeedDown = digitalRead(speedDown);
  int stateNewStory = digitalRead(newStory);
  int stateDeleteLastFrame = digitalRead(deleteLastFrame);


   if (stateNewFrame == 1) {
    tone(6, 20);
    Keyboard.press(' ');
    delay(2);
    Keyboard.release(' ');
    delay(timeDelay);
   /*
    #define SPACE (0x20)
    Keyboard.press(SPACE);
    Keyboard.release(SPACE);
  */
    
    noTone(6);
  }
  else if (stateSpeedUp == 1) {
    tone(6, 200);
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_UP_ARROW);
    delay(timeDelay);
    noTone(6);
  }

  else if (stateSpeedDown == 1) {

    tone(6, 200);
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(timeDelay);
    noTone(6);

  }
  else if (stateNewStory == 1) {
    tone(6, 20);
    Keyboard.press('d');
    Keyboard.release('d');
    delay(timeDelay);
    noTone(6);
  }
  else if (stateDeleteLastFrame == 1) {
    tone(6, 20);
    Keyboard.press('x');
    Keyboard.release('d');
    delay(timeDelay);
    noTone(6);
  }

  delay(10);
}



