//Joystick task game!
bool joystick_task() {
  
  bool joystick_success = true;
  int xMap, yMap, xValue, yValue;
  char *flickArray[] = {"up", "down", "left", "right"};
  
  
  //randomize the flick call
  int joyid = random(0, 4);
  Serial.print("\n\n");
  Serial.print(flickArray[joyid]);
  Serial.print("\n\n");

  //Display task
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print(joystickString + *flickArray[joyid]);
  lcd.setCursor(8, 0);
  lcd.print("SCORE: " + SCORE);
  
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
  if (flickArray[joyid] == "up") {
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
  } else if (flickArray[joyid] == "down") {
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
  } else if (flickArray[joyid] == "left") {
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
