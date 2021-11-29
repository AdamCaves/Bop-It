//main method to control game sequence
//this main function defines all the variables usedf or sub functions. Refer to this file for variable names and definitions

#include "pitches.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <MPU6050_light.h>

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
MPU6050 mpu(Wire);
unsigned long timer = 0;

#define joyX A0
#define joyY A1

int BLUE = 9;
int RED = 10;
int YELLOW = 11;
int START = 12;
int SUCCESS_LIGHT = 4;
int FAIL_LIGHT = 2;

int val = 0;
int del1 = 200;
int del2 = 500;
int SPEAKER = 3;
int SCORE = 0;
bool proceed;

//joystick global variables
int thresh = 25;
int maxbound = 50;
  
int timeAllowed = 0xFF; // Variable to store allowed time
bool timerFail = 0; // Bool for tracking timer fails

char matchString[] = "MATCH IT!";
char joystickString[] = "FLICK IT!";
char whipString[] = "WHIP IT!";

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
  lcd.init();
  lcd.backlight();
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(SUCCESS_LIGHT, OUTPUT);
  digitalWrite(SUCCESS_LIGHT, LOW);
  pinMode(FAIL_LIGHT, OUTPUT);
  digitalWrite(FAIL_LIGHT, LOW);
  pinMode(SPEAKER, OUTPUT);
  pinMode(START, INPUT);

 
  
  Serial.begin(9600); // open the serial port at 9600 bps:
  Wire.begin();
  
  //gyro calibration
  byte status = mpu.begin();
  //Serial.print(F("MPU6050 status: "));
  //Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050

  //testing
  digitalWrite(RED, HIGH);
  delay(500);
  digitalWrite(RED, LOW);
  
  //Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  //Serial.println("Done!\n");
  
  //setup timer
  timerSetup();
  
}

void loop() {
//  pinMode(SUCCESS_LIGHT, OUTPUT);
//  digitalWrite(SUCCESS_LIGHT, LOW);
//  pinMode(FAIL_LIGHT, OUTPUT);
//  digitalWrite(FAIL_LIGHT, LOW);
  // put your main code here, to run repeatedly:
  //HAVE NOT WRITTEN MAIN CODE YET... MUST FINISH SUB FUNCTIONS FIRST
  lcd.clear();
  bool k = matching_task();
  //bool k = joystick_task();
  delay(1000);
//  Serial.print("\n");
//  Serial.print(k);
  while (k==0)
  {
    k = digitalRead(START);
  }
  delay(500);
  digitalWrite(SUCCESS_LIGHT, LOW);
  digitalWrite(FAIL_LIGHT, LOW);
  digitalWrite(1, LOW);
}
