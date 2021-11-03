#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

char array1[]="SunFounder mydicksmol"; //the string to print on the LCD
char array2[]="JERK IT!  "; //the string to print on the LCD
char array3[]="STROKE IT! "; //the string to print on the LCD
char array4[]="EAT MY ASS IT!   "; //the string to print on the LCD
int val = 0;
int tim = 1000; //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open the serial port at 9600 bps:
  lcd.init();
  lcd.backlight();
}

void loop() {
  val = random(1, 4);
  Serial.print(val);
  lcd.setCursor(3, 0);
  if (val == 1) {
    lcd.print(array2);
    delay(tim);
    lcd.clear();
  }
 
  if (val == 2) {
    lcd.print(array3);
    delay(tim);
    lcd.clear();
  }
  
  if (val == 3) {
    lcd.print(array4);
    delay(tim);
    lcd.clear();
  }


  //reference code!
//  // put your main code here, to run repeatedly:
//  lcd.setCursor(1,0); // set the cursor to column 15, line 0
//  for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
//  {
//    lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
//    lcd.print(array1[positionCounter1]); // Print a message to the LCD.
//    delay(tim); //wait for 250 microseconds
//  }
//  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left  corner.
//  lcd.setCursor(15,1); // set the cursor to column 15, line 1
//  for (int positionCounter = 0; positionCounter < 26; positionCounter++)
//  {
//    lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
//    lcd.print(array2[positionCounter]); // Print a message to the LCD.
//    delay(tim); //wait for 250 microseconds
//  }
//  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left corner.
}
