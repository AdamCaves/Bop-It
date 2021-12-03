//Joystick task game!
bool joystick_task() {
  
  bool joystick_success = true;
  int xMap, yMap, xValue, yValue;
  char *flickArray[] = {"Up", "Down", "Left", "Right"};
  
  
  //randomize the flick call
  int joyid = random(0, 4);
  Serial.print("\n\n");
  Serial.print(flickArray[joyid]);
  Serial.print("\n\n");

  //Display task
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(joystickString);
  lcd.setCursor(11, 0);
  lcd.print(*flickArray[joyid]);
  lcd.setCursor(3, 1);
  lcd.print("SCORE: ");
  lcd.setCursor(11, 1);
  lcd.print(SCORE);
  
  //CALIBRATE GYRO
  int count = 10;
  int cal1 = 0;
  for (int i = 0; i < count; i ++) 
  {
    mpu.update();
    cal1 += mpu.getAngleZ();
    //Serial.print(mpu.getAngleZ());
  }
  cal1 = cal1/count;
  
  //start the timer
  startTimer();
  
  //check for inputs
  if (flickArray[joyid] == "Right") {
    while (map(analogRead(joyY), 0, 1023, maxbound, -maxbound) < thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyY), 0, 1023, 50, -50) < -thresh || map(analogRead(joyX), 0, 1023, 50, -50) < -thresh || map(analogRead(joyX), 0, 1023, 50, -50) > thresh || check_wrong_match() || check_wrong_whip(cal1)) {
        return task_fail();
      }
      //check for timer
      if (timerFail)
      {
        return timer_fail();
      }
    }
    //check for inputs
  } else if (flickArray[joyid] == "Left") {
    while (map(analogRead(joyY), 0, 1023, maxbound, -maxbound) > -thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyY), 0, 1023, 50, -50) > thresh || map(analogRead(joyX), 0, 1023, 50, -50) < -thresh || map(analogRead(joyX), 0, 1023, 50, -50) > thresh  || check_wrong_match() || check_wrong_whip(cal1)) {
        return task_fail();
      }
      //check for timer
      if (timerFail)
      {
        return timer_fail();
      }
    }
    //check for inputs
  } else if (flickArray[joyid] == "Down") {
    while (map(analogRead(joyX), 0, 1023, maxbound, -maxbound) > -thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyX), 0, 1023, 50, -50) > thresh || map(analogRead(joyY), 0, 1023, 50, -50) < -thresh || map(analogRead(joyY), 0, 1023, 50, -50) > thresh  || check_wrong_match() || check_wrong_whip(cal1)) {
        return task_fail();
      }
      //check for timers
      if (timerFail)
      {
        return timer_fail();
      }
    }
    //check for inputs
  } else {
    while (map(analogRead(joyX), 0, 1023, maxbound, -maxbound) < thresh) {
      //check for incorrect inputs
      if (map(analogRead(joyX), 0, 1023, 50, -50) < -thresh || map(analogRead(joyY), 0, 1023, 50, -50) < -thresh || map(analogRead(joyY), 0, 1023, 50, -50) > thresh  || check_wrong_match() || check_wrong_whip(cal1)) {
        return task_fail();
      }
      //check for timer
      if (timerFail)
      {
        return timer_fail();
      }
    }
  }
  //stop the timer
  stopTimer();
  //call success function and return true boolean
  return task_success();
//  delay(200);
} 
