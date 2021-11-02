//main method to control game sequence
//this main function defines all the variables usedf or sub functions. Refer to this file for variable names and definitions

#include "pitches.h"

#define joyX A0
#define joyY A1

int BLUE = 7;
int RED = 6;
int YELLOW = 8;
int SUCCESS_LIGHT = 1;
int FAIL_LIGHT = 1;
int val = 0;
int del1 = 200;
int del2 = 500;
int SPEAKER = 3;
bool proceed;

int success_tone[] = {
  NOTE_C4, NOTE_C6
};

int fail_tone[] = {
  NOTE_C4, NOTE_C2
};

int noteDurations[] = {
  4, 4
};

void setup() {
  // put your setup code here, to run once:
pinMode(BLUE, OUTPUT);
pinMode(RED, OUTPUT);
pinMode(YELLOW, OUTPUT);
pinMode(SUCCESS_LIGHT, OUTPUT);
pinMode(FAIL_LIGHT, OUTPUT);
pinMode(SPEAKER, OUTPUT);

Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  // put your main code here, to run repeatedly:
  //HAVE NOT WRITTEN MAIN CODE YET... MUST FINISH SUB FUNCTIONS FIRST
}
