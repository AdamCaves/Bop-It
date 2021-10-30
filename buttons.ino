#include "pitches.h"
int GREEN = 7;
int RED = 6;
int val = 0;
int del1 = 200;
int del2 = 500;
int SPEAKER = 3;

#include "pitches.h"

int SPEAK = 3;
int melody[] = {
  NOTE_C4, NOTE_C5
};
int noteDurations[] = {

  4, 4
};

void setup() {
  // put your setup code here, to run once:
pinMode(GREEN, OUTPUT);
pinMode(RED, OUTPUT);
Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  // put your main code here, to run repeatedly:
  val = random(1, 3);
  Serial.print(val);
  if (val == 1) {
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    // generate task
    digitalWrite(GREEN, HIGH);
    delay(del1);
    digitalWrite(GREEN, LOW);
    delay(del2);
    digitalWrite(RED, HIGH);
    delay(del1);
    digitalWrite(RED, LOW);
    delay(del2);
    
    //look for input
    pinMode(GREEN, INPUT);
    pinMode(RED, INPUT);
    while(digitalRead(GREEN) == 0) {
    }
    while(digitalRead(RED) == 0) {
    }
    //Success
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, HIGH);
    delay(1000);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    for (int i = 0; i < 2; i ++) {
      int dur = 1000/noteDurations[i];
      tone(SPEAK, melody[i], dur);
      int pause = dur * 1.30;
      delay(pause);
      noTone(SPEAK);
    }
    delay(200);
  } 
  if (val == 2) {
    // generate task
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    digitalWrite(RED, HIGH);
    delay(del1);
    digitalWrite(RED, LOW);
    delay(del2);
    digitalWrite(GREEN, HIGH);
    delay(del1);
    digitalWrite(GREEN, LOW);
    delay(del2);
    
    //look for input
    pinMode(GREEN, INPUT);
    pinMode(RED, INPUT);
    while(digitalRead(RED) == 0) {
    }
    while(digitalRead(GREEN) == 0) {
    }
     //Success
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, HIGH);
    delay(1000);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    for (int i = 0; i < 2; i ++) {
      int dur = 1000/noteDurations[i];
      tone(SPEAK, melody[i], dur);
      int pause = dur * 1.30;
      delay(pause);
      noTone(SPEAK);
    }
    delay(200);
  }
}
