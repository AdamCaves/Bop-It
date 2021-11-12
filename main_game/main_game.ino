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

int BLUE = 7;
int RED = 6;
int YELLOW = 8;
int SUCCESS_LIGHT = 1;
int FAIL_LIGHT = 1;
int val = 0;
int del1 = 200;
int del2 = 500;
int SPEAKER = 3;
int SCORE = 0;
bool proceed;

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
  pinMode(FAIL_LIGHT, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  Serial.begin(9600); // open the serial port at 9600 bps:
  Wire.begin();
  
  //gyro calibration
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");

  //setup timer
  timerSetup();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //HAVE NOT WRITTEN MAIN CODE YET... MUST FINISH SUB FUNCTIONS FIRST
  bool k = whip_task();
  delay(1000);
  Serial.print("\n");
  Serial.print(k);
  while (k==0)
  {
    k = digitalRead(RED);
  }
  delay(500);
}
